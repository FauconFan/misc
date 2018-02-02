package src.view;

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.input.KeyCode;
import javafx.scene.paint.Color;
import javafx.scene.paint.PhongMaterial;
import javafx.scene.Parent;
import javafx.scene.PerspectiveCamera;
import javafx.scene.shape.Box;
import javafx.scene.shape.DrawMode;
import javafx.scene.Scene;
import javafx.scene.SubScene;
import javafx.scene.transform.Rotate;
import javafx.scene.transform.Translate;
import javafx.stage.Stage;



public class ViewIngame extends Scene
{
	private PerspectiveCamera cam;

	public ViewIngame()
	{
		super(createContent());

		this.addEventHandler(KeyEvent.KEY_PRESSED, (key)->{
			if (key.getCode() == KeyCode.LEFT)
			{
				System.out.println("You pressed left");
			}
			if (key.getCode() == KeyCode.D)
			{
				System.out.println("You pressed right");
			}
			if (key.getCode() == KeyCode.Z)
			{
				System.out.println("You pressed forward");
			}
			if (key.getCode() == KeyCode.S)
			{
				System.out.println("You pressed backward");
			}
		});
	}

	public Parent createContent() throws Exception
	{
		// Create and position camera
		PerspectiveCamera camera = new PerspectiveCamera(true);

		camera.getTransforms().addAll(
			new Rotate(-20, Rotate.Y_AXIS),
			new Rotate(-20, Rotate.X_AXIS),
			new Translate(0, 0, -15));

		// Build the Scene Graph
		Group root = new Group();
		root.getChildren().add(camera);

		// Use a SubScene
		SubScene subScene = new SubScene(root, 300, 300);
		subScene.setFill(Color.ALICEBLUE);
		subScene.setCamera(camera);
		Group group = new Group();
		group.getChildren().add(subScene);
		return (group);
	}
}
