package src.view.scene;

import src.view.Menu;
import src.view.View;

import javafx.scene.control.Button;
import javafx.scene.Group;
import javafx.scene.text.Text;

public class EndMenu extends ScenePlus.ScenePlusMenu
{
	public EndMenu(View v, long sec)
	{
		super(new Group(), v);
		((Group)getRoot()).getChildren().add(new MenuWin(sec));
	}

	public EndMenu(View v)
	{
		super(new Group(), v);
		((Group)getRoot()).getChildren().add(new MenuLost());
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
