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

public class ViewIngame extends Scene
{
	public ViewIngame()
	{
		super(new Group());
		setFill(Color.GREY);
		Group root = (Group)this.getRoot();

		root.getChildren().add(new Box(300.00, 300.00, 300.00));

		//Creation de la camera
		final PerspectiveCamera camera = new PerspectiveCamera(true);

		setCamera(camera);

		//Key controller
		addEventHandler(KeyEvent.KEY_PRESSED, (key)->{
			if (key.getCode() == KeyCode.Q)
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
}
