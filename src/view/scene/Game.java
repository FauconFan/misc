package src.view.scene;

import java.io.FileInputStream;
import javafx.application.Application;
import javafx.scene.AmbientLight;
import javafx.scene.Cursor;
import javafx.scene.Group;
import javafx.scene.image.Image;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.Node;
import javafx.scene.paint.Color;
import javafx.scene.paint.Material;
import javafx.scene.paint.PhongMaterial;
import javafx.scene.Parent;
import javafx.scene.PerspectiveCamera;
import javafx.scene.PointLight;
import javafx.scene.shape.Box;
import javafx.scene.shape.Box;
import javafx.scene.shape.DrawMode;
import javafx.scene.Scene;
import javafx.scene.transform.Rotate;
import javafx.scene.transform.Scale;
import javafx.scene.transform.Translate;
import javafx.stage.Stage;

//Pour remettre le curseur au centre de l'ecran
import java.awt.AWTException;
import java.awt.Robot;
import javafx.stage.Screen;

import java.util.function.Consumer;

import src.model.board.Case;
import src.model.board.LineWall;
import src.model.ContentMaze;
import src.model.MainMaze;
import src.model.MazeDimension;
import src.model.Player;

import src.view.View;

public class Game extends ScenePlus
{
	private final MainMaze maze;

	//Dimensions de l'ecran
	private static int screenWidth  = (int)Screen.getPrimary().getBounds().getWidth();
	private static int screenHeight = (int)Screen.getPrimary().getBounds().getHeight();
	private static int screenOffset = 0;

	// Anciennes positions de la souris
	private double mousePosX = (double)(screenWidth / 2);
	private double mousePosY = (double)(screenHeight / 2);

	//Hauteur des murs
	private final int hauteur = 20;

	// Scale pour les murs
	private final Scale sc = new Scale(30, 1, 30);

	// Constantes de déplacements
	private final float change = 0.1f;
	private final float goUp   = 1f;
	private final int rot      = 5; // En degré

	private final GroupCameraPlus groupCameraPlus = new GroupCameraPlus();

	private final Group walls;

	public Game(View v, MainMaze m)
	{
		super(new Group(), screenWidth, screenHeight, true, v);
		final Group root = (Group)this.getRoot();
		maze = m;

		setFill(Color.GREY);
		setCursor(Cursor.NONE);

		// AmbientLight
		AmbientLight al = new AmbientLight(Color.WHITE);
		root.getChildren().add(al);

		// Ajoute le sol
		Group floors = makeFloors();
		floors.getChildren().add(makeEndCase());
		root.getChildren().add(floors);

		/* Le plafond est juste un sol décalé vers le haut
		 * final Group roof = makeFloors();
		 * roof.setTranslateY(-1 * hauteur);
		 * root.getChildren().add(roof);*/

		// Ajoute les murs
		walls = makeWalls();
		root.getChildren().add(walls);

		// Ajoute la caméra
		root.getChildren().add(groupCameraPlus);

		// Défini la camera pour la scène
		setCamera(groupCameraPlus.camera);

		// Met le joueur sur la startCase
		updatePlayer(false);

		//Key controller
		addEventHandler(KeyEvent.KEY_PRESSED, (key)->{
			boolean reallyMove = false;
			switch (key.getCode())
			{
			case Q: setTr(-90, change); reallyMove = true; break;

			case D: setTr(90, change); reallyMove = true; break;

			case Z: setTr(0, change); reallyMove = true; break;

			case S: setTr(180, change); reallyMove = true; break;

			// Le déplacement vertical ne demande pour l'instant aucun calcul particulié
			case F: maze.movePlayer(0, 0, goUp);  break;

			case R: maze.movePlayer(0, 0, -1 * goUp); break;

			case LEFT: maze.getPlayer().addHorizontalAngle(-1 * rot); break;

			case RIGHT: maze.getPlayer().addHorizontalAngle(1 * rot); break;

			case UP: maze.getPlayer().addVerticalAngle(1 * rot); break;

			case DOWN: maze.getPlayer().addVerticalAngle(-1 * rot); break;

			case ESCAPE: v.changeScene(new Pause(v, this)); break;

			case T: centerMouse(); break;

			case G: this.maze.getPlayer().setGhostMode(!this.maze.getPlayer().getGhostMode()); break;

			case H: makeTransparentWallsOrNot(); break;
			}

			updatePlayer(reallyMove);
		});


		//Mouse controller
		//screenOffset : decalage en Y par rapport au centre de l'ecran

		setOnMouseMoved((mm)->{
			final double rotateConst = 0.1;
			int screenOffset         = (int)Screen.getPrimary().getVisualBounds().getMaxY() - (int)getHeight();
			double newX = mm.getSceneX();
			double newY = mm.getSceneY();
			double dX   = newX - mousePosX;
			double dY   = newY - mousePosY + screenOffset;
			if (dX != 0 || dY != 0)
			{
				centerMouse();
			}
			maze.getPlayer().addHorizontalAngle((float)(dX * rotateConst));
			maze.getPlayer().addVerticalAngle((float)(-1 * dY * rotateConst));
			updatePlayer(false);
		});
	}

	//Place le curseur au centre de l'ecran
	private void centerMouse()
	{
		try{
			Robot robo = new Robot();
			robo.mouseMove(screenWidth / 2, screenHeight / 2);
		}catch (AWTException e) {
			e.printStackTrace();
		}
	}

	/**
	 * Set the translate
	 * @param diff la différence à ajouter à l'angle
	 * @param change Le déplacement
	 */
	private void setTr(int diff, float change)
	{
		final double r1 = Math.toRadians(groupCameraPlus.rx.getAngle() + diff);

		maze.movePlayer((float)(Math.sin(r1) * change), (float)(Math.cos(r1) * change), 0);
	}

	/**
	 * Update the camera position according to the player
	 * @param b Si le joueur a vraiment bougé
	 */
	private void updatePlayer(boolean b)
	{
		final Player p = maze.getPlayer();

		groupCameraPlus.tr.setZ(p.getPosY() * sc.getZ());
		groupCameraPlus.tr.setX(p.getPosX() * sc.getX());
		groupCameraPlus.tr.setY(p.getPosZ() * sc.getY());
		groupCameraPlus.rx.setAngle(p.getHorizontalAngle());
		groupCameraPlus.ry.setAngle(p.getVerticalAngle());

		if (b)
		{
			checkWin();
		}
	}

	/**
	 *  Teste si on a gagné et agit en conséquence
	 */
	private void checkWin()
	{
		if (maze.getPlayer().hasWin(maze.getContentMaze().getSpecialCases()))
		{
			v.changeScene(new Winner(v));
		}
	}

	/**
	 * Dessine les murs du Maze
	 * @return Le groupe contenant les murs
	 */
	private Group makeWalls()
	{
		Material mat;

		try{
			Image img = new Image(new FileInputStream("assets/Wall_Stone_003_COLOR.jpg"), 400, 400, true, false);
			Image nrm = null;//new Image(new FileInputStream("assets/Wall_Stone_003_NRM.jpg"),400,400,true, false);
			mat = new PhongMaterial(Color.WHITE, img, null, nrm, null);
		}
		catch (Exception e) {
			mat = new PhongMaterial(Color.GREEN);
		}
		Group walls = new Group();

		// On scale les murs
		walls.getTransforms().add(sc);
		final LineWall[] lineWalls = maze.getContentMaze().getLineWalls();
		final float      delta     = 0.001f;
		for (LineWall l: lineWalls)
		{
			Box w = new Box();

			Consumer <Float> setEpais;
			Consumer <Float> setLarg;

			float  largeur;
			double trX;
			double trZ;
			if (!l.isHorizontal())                                                // Mur "vertical" dans le plan
			{
				largeur  = l.getY2() - l.getY1() + l.getEpaisseur() - 2 * delta;
				setLarg  = w::setDepth;
				setEpais = w::setWidth;
				trX      = l.getX1() + l.getEpaisseur() / 2.0 - delta;
				trZ      = l.getY1() + largeur / 2.0;
			}
			else     // Mur horizontal
			{
				largeur  = l.getX2() - l.getX1() + l.getEpaisseur() - 2 * delta;
				setLarg  = w::setWidth;
				setEpais = w::setDepth;
				trX      = l.getX1() + largeur / 2.0;
				trZ      = l.getY1() + l.getEpaisseur() / 2.0 - delta;
			}

			w.setHeight(hauteur);
			setEpais.accept(l.getEpaisseur());
			setLarg.accept(largeur);
			w.setTranslateX(trX);
			w.setTranslateZ(trZ);

			w.setMaterial(mat);
			walls.getChildren().add(w);
		}
		return (walls);
	}

	/**
	 * Dessine le sol
	 * @return Un groupe contenant le sol
	 */
	public Group makeFloors()
	{
		final Group floors = new Group();

		floors.getTransforms().add(sc);

		for (MazeDimension.RectInMaze md: maze.getMazeDimension().list_rectmaze)
		{
			final int w = md.x2 - md.x1;
			final int h = md.y2 - md.y1;
			Box       f = new Box(w, 0.5, h);
			f.setTranslateX(md.x1 + w / 2.0);
			f.setTranslateZ(md.y1 + h / 2.0);
			f.setMaterial(new PhongMaterial(Color.color(0.15, 0.15, 0.15)));
			f.setTranslateY(hauteur / 2.0);
			floors.getChildren().add(f);
		}
		return (floors);
	}

	public MainMaze getMaze()
	{
		return (this.maze);
	}

	// Une camera avec les bons attributs pour la déplacer, et une lumière associée
	private static class GroupCameraPlus extends Group
	{
		//Transforms pour la camera
		public final Translate tr             = new Translate();
		public final Rotate rx                = new Rotate(0, Rotate.Y_AXIS);
		public final Rotate ry                = new Rotate(0, Rotate.X_AXIS);
		public final PerspectiveCamera camera = new PerspectiveCamera(true);

		public GroupCameraPlus()
		{
			camera.setNearClip(0.1);
			camera.setFarClip(1000.0);

			getChildren().add(camera);

			// On met les tranforms sur la camera
			getTransforms().addAll(tr, rx, ry);
		}
	}

	private Box makeEndCase()
	{
		final Case  ec  = this.maze.getEndCase();
		final float tc  = Case.getTailleCase();
		final Box   res = new Box(tc, 0.01f, tc);

		res.setTranslateX(ec.getX() + tc / 2.0);
		res.setTranslateZ(ec.getY() + tc / 2.0);
		res.setTranslateY(hauteur / 2 - 1);
		res.setMaterial(new PhongMaterial(Color.GREEN));
		return (res);
	}

	private void makeTransparentWallsOrNot()
	{
		for (Node n : walls.getChildren())
		{
			PhongMaterial ph = (PhongMaterial)((Box)n).getMaterial();
			if (ph.getDiffuseColor() == Color.WHITE)
			{
				ph.setDiffuseColor(new Color(1, 1, 1, 0.25));
			}
			else
			{
				ph.setDiffuseColor(Color.WHITE);
			}
			((Box)n).setMaterial(ph);
		}
	}
}
