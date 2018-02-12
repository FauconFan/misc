package src.view;

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.paint.Color;
import javafx.scene.paint.PhongMaterial;
import javafx.scene.ParallelCamera;
import javafx.scene.Parent;
import javafx.scene.PerspectiveCamera;
import javafx.scene.shape.Box;
import javafx.scene.shape.Box;
import javafx.scene.shape.DrawMode;
import javafx.scene.Scene;
import javafx.scene.SubScene;
import javafx.scene.transform.Rotate;
import javafx.scene.transform.Scale;
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

		// Seul moyen d'obtenir quelque chose d'euclidien...
		Scale s = new Scale(1, 1, 0.05f);
		root.getTransforms().add(s);

		//Creation de la camera
		final PerspectiveCamera camera = new PerspectiveCamera(true);
		//final ParallelCamera camera = new ParallelCamera();
		// Défini la camera pour la scène
		setCamera(camera);

		// On tourne par rapport à Y
		camera.setRotationAxis(Rotate.Y_AXIS);

		// constantes de déplacements
		final int change = 1;
		final int rot    = 1; // En degré

		// Recule la caméra pour la voir l'objet initalement
		//camera.setTranslateZ(-10);

		renderMaze();

		//Key controller
		addEventHandler(KeyEvent.KEY_PRESSED, (key)->{
			if (key.getCode() == KeyCode.Q)
			{
				camera.setRotate(camera.getRotate() - rot);
			}
			if (key.getCode() == KeyCode.D)
			{
				camera.setRotate(camera.getRotate() + rot);
			}
			if (key.getCode() == KeyCode.Z)
			{
				camera.setTranslateZ(camera.getTranslateZ() + (Math.cos(Math.toRadians(camera.getRotate()))) * change);
				camera.setTranslateX(camera.getTranslateX() + (Math.sin(Math.toRadians(camera.getRotate()))) * change);
			}
			if (key.getCode() == KeyCode.S)
			{
				camera.setTranslateZ(camera.getTranslateZ() - (Math.cos(Math.toRadians(camera.getRotate()))) * change);
				camera.setTranslateX(camera.getTranslateX() - (Math.sin(Math.toRadians(camera.getRotate()))) * change);
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
		final int hauteur = 60;
		Group     walls   = new Group();

		final int facteur = 30;

		root.getChildren().add(walls);
		//LineWall[] lineWalls = { new LineWall(0, 0, 0, 5, (float)(0.5)), new LineWall(0, 5, 5, 5, (float)(0.5)), new LineWall(5, 5, 5, 0, (float)(0.5)), new LineWall(5, 0, 0, 0, (float)(0.5)) };
		LineWall[] lineWalls = maze.getLineWalls();

		for (LineWall l: lineWalls)
		{
			System.out.println(l);
			Box w = new Box();
			w.setHeight(hauteur);
			if (l.getX1() == l.getX2())                                            // Mur "vertical" dans le plan
			{
				w.setDepth((l.getY2() - l.getY1()) * facteur);
				w.setWidth(l.getEpaisseur() * facteur);
			}
			else // Mur horizontal
			{
				w.setWidth((l.getX2() - l.getX1()) * facteur);
				w.setDepth(l.getEpaisseur() * facteur);
			}
			w.setTranslateX(l.getX1() * facteur);
			w.setTranslateZ(l.getY1() * facteur);
			w.setMaterial(new PhongMaterial(Color.RED));
			walls.getChildren().add(w);
		}
	}
}
