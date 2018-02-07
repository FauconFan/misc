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
import javafx.scene.shape.DrawMode;
import javafx.scene.Scene;
import javafx.scene.SubScene;
import javafx.scene.transform.Rotate;
import javafx.scene.transform.Translate;
import javafx.stage.Stage;


public class ViewIngameDeux extends Group
{
	private Scene scene;


	public ViewIngameDeux()
	{
		//Creation et rajout de scene
		Scene scene = new Scene(this);

		this.getChildren().add(scene);
		this.scene = scene;
		//Creation de la camera
		final PerspectiveCamera camera = new PerspectiveCamera(True);
		camera.getTransforms().addAll(
			new Rotate(-20, Rotate.Y_AXIS),
			new Rotate(-20, Rotate.X_AXIS),
			new Translate(0, 0, -15));
		this.getChildren().add(camera);
		this.scene.setCamera(camera);
		//Key controller
		this.scene.addEventHandler(KeyEvent.KEY_PRESSED, (key)->{
			if (key.getCode() == KeyCode.LEFT)
			{
				System.out.println("You pressed left");
				rotateX.setAngle(rotateX.getAngle() - 10);
				System.out.println("You turned left for 10");
			}
			if (key.getCode() == KeyCode.D)
			{
				System.out.println("You pressed right");
				rotateX.setAngle(rotateX.getAngle() + 10);
				System.out.println("You turned right for 10");
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

	public Scene getScene()
	{
		return (this.scene);
	}
}
