package src.view.scene;

import java.io.File;

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
import src.view.scene.game.Game;
import src.view.View;

public class Pause extends ScenePlus
{
	private Game previous;

	public Pause(View v, Game p)
	{
		super(new Group(), v);
		this.previous = p;
		((Group)getRoot()).getChildren().add(new MenuPause());
		getStylesheets().add("menuStyle.css");
	}

	public class MenuPause extends Menu
	{
		public MenuPause()
		{
			Button buttonUnPause = addButton("Unpause");

			buttonUnPause.setOnAction(event->{
				v.changeScene(previous);
				previous.startTimer();
			});

			ToggleButton buttonGhostMode = new ToggleButton("Ghost Mode");
			buttonGhostMode.setId("ghostmode");
			buttonGhostMode.setPrefWidth(primaryScreenBounds.getWidth() / 3);
			buttonGhostMode.setPrefHeight(primaryScreenBounds.getHeight() / 15);
			getChildren().add(buttonGhostMode);
			buttonGhostMode.setSelected(previous.getMaze().getPlayer().getGhostMode());
			buttonGhostMode.setOnAction(event->{
				previous.getMaze().getPlayer().setGhostMode(buttonGhostMode.isSelected());
			});

			Button buttonSave = addButton("Save");
			buttonSave.setPrefWidth(primaryScreenBounds.getWidth() / 3);
			buttonSave.setPrefHeight(primaryScreenBounds.getHeight() / 15);
			buttonSave.setOnAction(event->{
				File f = new FileChooser().showSaveDialog(v.stage);
				if (f != null)
				{
					v.con.saveMaze(f.getAbsolutePath());
				}
			});

			Button buttonReturn = addButton("Return to Menu");
			buttonReturn.setPrefWidth(primaryScreenBounds.getWidth() / 3);
			buttonReturn.setPrefHeight(primaryScreenBounds.getHeight() / 15);
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

			addButtonQuit();

			putMsg();
		}
	}
}
