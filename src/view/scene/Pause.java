package src.view.scene;

import java.io.File;

import javafx.scene.control.Button;
import javafx.scene.control.ToggleButton;
import javafx.scene.Group;
import javafx.scene.input.KeyEvent;
import javafx.scene.text.Text;
import javafx.stage.FileChooser;

import src.view.Menu;
import src.view.scene.creator.Creator;
import src.view.scene.game.Game;
import src.view.View;

public class Pause extends ScenePlus.ScenePlusMenu
{
	private Game previous;

	public Pause(View v, Game p)
	{
		super(new Group(), v);
		this.previous = p;
		((Group)getRoot()).getChildren().add(new MenuPause());
	}

	public class MenuPause extends Menu
	{
		public MenuPause()
		{
			Text paused = new Text("PAUSED");

			paused.setId("title");
			getChildren().add(paused);

			Button buttonUnPause = addBigButton("Unpause");

			buttonUnPause.setOnAction(event->{
				v.changeScene(previous);
				previous.startTimer();
			});

			ToggleButton buttonGhostMode = new ToggleButton("Ghost Mode");
			buttonGhostMode.setId("ghostmodeoff");
			buttonGhostMode.setPrefWidth(primaryScreenBounds.getWidth() / 3);
			buttonGhostMode.setPrefHeight(primaryScreenBounds.getHeight() / 15);
			getChildren().add(buttonGhostMode);
			buttonGhostMode.setSelected(previous.getMaze().getPlayer().getGhostMode());
			buttonGhostMode.setOnAction(event->{
				previous.getMaze().getPlayer().setGhostMode(buttonGhostMode.isSelected());
				if (buttonGhostMode.isSelected())
				{
					buttonGhostMode.setId("ghostmodeon");
				}
				else
				{
					buttonGhostMode.setId("ghostmodeoff");
				}
			});

			Button buttonSave = addBigButton("Save");
			buttonSave.setOnAction(event->{
				File f = new FileChooser().showSaveDialog(v.stage);
				if (f != null)
				{
					v.con.saveMaze(f.getAbsolutePath());
				}
			});

			Button buttonCreator = addBigButton("Creator");
			buttonCreator.setOnAction(event->{
				v.changeScene(new Creator(v, previous));
			});

			Button buttonReturn = addSmallButton("Return to Menu");
			buttonReturn.setOnAction(event->{
				v.changeScene(new Menus(v));
			});

			//Key controller
			addEventHandler(KeyEvent.KEY_PRESSED, (key)->{
				switch (key.getCode())
				{
				case ESCAPE: v.changeScene(previous); previous.startTimer(); break;
				}
			});

			addButtonQuit();
		}
	}
}
