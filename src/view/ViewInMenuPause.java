package src.view;

import javafx.application.Platform;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.geometry.Rectangle2D;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.Slider;
import javafx.scene.Group;
import javafx.scene.layout.VBox;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.text.Font;
import javafx.stage.FileChooser;
import javafx.stage.Screen;
import javafx.stage.Stage;

class ViewInMenuPause extends Scene
{
	private Scene previous;
	private final View v;

	public ViewInMenuPause(View v, Scene p)
	{
		super(new Group());
		((Group)getRoot()).getChildren().add(new MenuPause());
		this.v        = v;
		this.previous = p;
	}

	public class MenuPause extends Menu
	{
		public MenuPause()
		{
			Button buttonUnPause = addButton("Unpause");

			buttonUnPause.setOnAction(event->{
				v.changeScene(previous);
			});

			Button buttonReturn = addButton("Return to Menu");
			buttonReturn.setOnAction(event->{
				v.changeScene(new ViewInMenu(v));
			});

			putMsg();
		}
	}
}
