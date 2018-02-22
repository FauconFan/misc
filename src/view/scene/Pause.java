package src.view.scene;

import javafx.application.Platform;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.geometry.Rectangle2D;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.Slider;
import javafx.scene.control.ToggleButton;
import javafx.scene.Group;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.layout.VBox;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.text.Font;
import javafx.stage.FileChooser;
import javafx.stage.Screen;
import javafx.stage.Stage;

import src.view.Menu;
import src.view.View;

class Pause extends Scene
{
	private Game previous;
	private final View v;

	public Pause(View v, Game p)
	{
		super(new Group());
		this.previous = p;
		((Group)getRoot()).getChildren().add(new MenuPause());
		this.v = v;
	}

	public class MenuPause extends Menu
	{
		public MenuPause()
		{
			Button buttonUnPause = addButton("Unpause");

			buttonUnPause.setOnAction(event->{
				v.changeScene(previous);
			});

			ToggleButton buttonGhostMode = new ToggleButton("Ghost Mode");
			getChildren().add(buttonGhostMode);
			buttonGhostMode.setSelected(previous.getMaze().getPlayer().getGhostMode());
			buttonGhostMode.setOnAction(event->{
				previous.getMaze().getPlayer().setGhostMode(buttonGhostMode.isSelected());
			});

			Button buttonReturn = addButton("Return to Menu");
			buttonReturn.setOnAction(event->{
				v.changeScene(new Menus(v));
			});

			//Key controller
			addEventHandler(KeyEvent.KEY_PRESSED, (key)->{
				switch (key.getCode())
				{
				case ESCAPE: v.changeScene(previous); break;
				}
			});

			putMsg();
		}
	}
}
