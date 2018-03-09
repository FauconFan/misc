package src.view.scene;

import src.view.Menu;
import src.view.View;

import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.Group;
import javafx.scene.Scene;

public class Winner extends ScenePlus
{
	public Winner(View v)
	{
		super(new Group(), v);
		((Group)getRoot()).getChildren().add(new MenuWin());
	}

	public class MenuWin extends Menu
	{
		public MenuWin()
		{
			super();

			Label l = new Label("YOU WIN");
			getChildren().add(l);

			Button buttonNew = addButton("New game");

			buttonNew.setOnAction(event->{
				v.changeScene(new Menus(v));
			});

			addButtonQuit();
		}
	}
}
