package src.view.scene.game;

import javafx.scene.Camera;
import javafx.scene.Camera;
import javafx.scene.Group;
import javafx.scene.ParallelCamera;
import javafx.scene.PerspectiveCamera;
import javafx.scene.transform.Rotate;
import javafx.scene.transform.Translate;

/**
 * Une caméra et ses attributs
 */
public class GroupCameraPlus extends Group
{
	public Translate tr = new Translate();
	public Rotate rx    = new Rotate(0, Rotate.Y_AXIS);
	public Rotate ry    = new Rotate(0, Rotate.X_AXIS);
	public Rotate rz    = new Rotate(0, Rotate.Z_AXIS);
	public Camera camera;

	private void create(Camera c)
	{
		this.camera = c;
		getChildren().add(camera);
		getTransforms().addAll(tr, rx, ry, rz);
	}

	public GroupCameraPlus(ParallelCamera c)
	{
		create(c);
	}

	public GroupCameraPlus(PerspectiveCamera p)
	{
		create(p);
		camera.setNearClip(0.1);
		camera.setFarClip(500);
	}
}
