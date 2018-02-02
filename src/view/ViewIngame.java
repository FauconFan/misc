import javafx.application.Application;
import javafx.scene.Group;
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

import javafx.stage.Stage;


public class ViewIngame extends Scene
{
	private PerspectiveCamera cam;

	public ViewIngame()
	{
		cam = new PerspectiveCamera(true);
		this.addEventHandler(KeyEvent.KEY_PRESSED, (key)->{
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
		this.setCamera(cam);
	}
}
