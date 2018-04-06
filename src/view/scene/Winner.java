package src.view.scene;

import src.view.Menu;
import src.view.View;

import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.text.Text;

public class Winner extends ScenePlus
{
	public Winner(View v, long sec)
	{
		super(new Group(), v);
		((Group)getRoot()).getChildren().add(new MenuWin(sec));
		getStylesheets().add("menuStyle.css");
	}

	public class MenuWin extends Menu
	{
		public MenuWin(long sec)
		{
			super();

			Text l = new Text("YOU WIN");
			getChildren().add(l);
			l.setId("title");

			Text se = new Text("You solved the maze in " + sec + " seconds");
			getChildren().add(se);
			se.setId("title");

			Button buttonNew = addBigButton("Main menu");

			buttonNew.setOnAction(event->{
				v.changeScene(new Menus(v));
			});

			addButtonQuit();
		}
	}
}
