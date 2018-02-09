package src.view;

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.paint.Color;
import javafx.scene.paint.PhongMaterial;
import javafx.scene.Parent;
import javafx.scene.PerspectiveCamera;
import javafx.scene.shape.Box;
import javafx.scene.shape.Box;
import javafx.scene.shape.DrawMode;
import javafx.scene.Scene;
import javafx.scene.SubScene;
import javafx.scene.transform.Rotate;
import javafx.scene.transform.Translate;
import javafx.stage.Stage;

import src.model.board.LineWall;
import src.model.ContentMaze;

public class ViewIngame extends Scene
{
	private final Group root;
	private final ContentMaze maze;
	public ViewIngame(ContentMaze m)
	{
		super(new Group());
		root = (Group)this.getRoot();
		maze = m;

		setFill(Color.GREY);

		renderMaze();

		//root.getChildren().add(new Box(100.00, 100.00, 100.00));

		//Creation de la camera
		final PerspectiveCamera camera = new PerspectiveCamera(true);

		// Défini la camera pour la scène
		setCamera(camera);

		// On tourne par rapport à Y
		camera.setRotationAxis(Rotate.Y_AXIS);

		// constantes de déplacements
		final int change = 1;
		final int rot    = 1; // En degré

		// Recule la caméra pour la voir l'objet initalement
		camera.setTranslateZ(-15);

		//Key controller
		addEventHandler(KeyEvent.KEY_PRESSED, (key)->{
			if (key.getCode() == KeyCode.Q)
			{
				camera.setRotate(camera.getRotate() - rot);

				System.out.println("You pressed left");
			}
			if (key.getCode() == KeyCode.D)
			{
				camera.setRotate(camera.getRotate() + rot);
				System.out.println("You pressed right");
			}
			if (key.getCode() == KeyCode.Z)
			{
				camera.setTranslateZ(camera.getTranslateZ() + (Math.cos(Math.toRadians(camera.getRotate()))) * change);
				camera.setTranslateX(camera.getTranslateX() + (Math.sin(Math.toRadians(camera.getRotate()))) * change);

				System.out.println("You pressed forward");
			}
			if (key.getCode() == KeyCode.S)
			{
				camera.setTranslateZ(camera.getTranslateZ() - (Math.cos(Math.toRadians(camera.getRotate()))) * change);
				camera.setTranslateX(camera.getTranslateX() - (Math.sin(Math.toRadians(camera.getRotate()))) * change);

				System.out.println("You pressed backward");
			}
		});

		//Mouse controller

		/*this.scene.setOnMouseDragged(new EventHadler<MouseEvent>() {
		 *  public void hadle(MouseEvent mEv){
		 *      mouseOldX = mousePosX;
		 *      mouseOldY = mousePosY;
		 *      mousePosX = mEv.getX();
		 *      mousePosY = mEv.getY();
		 *      mouseDeltaX = mousePosX - mouseOldX;
		 *      mouseDeltaY = mousePosY - mouseOldY;
		 *
		 *  }
		 * })*/
	}

	private void renderMaze()
	{
		final int hauteur = 15;
		Group     walls   = new Group();

		root.getChildren().add(walls);
		LineWall[] lineWalls = maze.getLineWalls();
		for (LineWall l: lineWalls)
		{
			System.out.println(l);
			Box w;
			if (l.getX1() == l.getX1())                                                  // Mur "vertical" dans le plan
			{
				w = new Box(Math.abs(l.getY1() - l.getY2()), hauteur, l.getEpaisseur()); // Box(x,y,z)
			}
			else // Mur horizontal
			{
				w = new Box(l.getEpaisseur(), hauteur, Math.abs(l.getY1() - l.getY2()));
			}
			walls.getChildren().add(w);
		}
	}
}
