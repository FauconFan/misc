package src.view.scene;

import src.view.Menu;
import src.view.View;

import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.text.Text;

public class MenuGameOver extends ScenePlus
{
	public MenuGameOver(View v)
	{
		super(new Group(), v);
		((Group)getRoot()).getChildren().add(new MenuLost());
		getStylesheets().add("menuStyle.css");
	}

	public class MenuLost extends Menu
	{
		public MenuLost()
		{
			super();

			Text l = new Text("GAME OVER");
			getChildren().add(l);
			l.setId("title");


			Button buttonNew = addBigButton("Back to menu");

			buttonNew.setOnAction(event->{
				v.changeScene(new Menus(v));
			});

			addButtonQuit();
		}
	}
}
