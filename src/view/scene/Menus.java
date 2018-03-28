package src.view.scene;

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

import java.io.File;

import src.controller.Controller;
import src.model.gen.Algo;
import src.model.gen.AlgoBackTracker;

import src.model.maps.MapIntroBuilder;

import src.model.parser.Parser;
import src.view.Menu;
import src.view.Msg;
import src.view.scene.creator.Creator;
import src.view.View;

import javafx.scene.text.Text;

public class Menus extends ScenePlus
{
	private Parent view;
	private Parent prec;

	public Menus(View v)
	{
		super(new Group(), v);
		((Group)getRoot()).getChildren().add(new MenuStart());
		getStylesheets().add("menuStyle.css");
	}

	public Menus(View v, Menu m)
	{
		super(m, v);
		this.view = m;
		getStylesheets().add("menuStyle.css");
	}

	public class MenuStart extends Menu
	{
		public MenuStart()
		{
			super();

			Text label = new Text("Hello the Maze");
			label.setId("hello");
			getChildren().add(label);

			final Button   buttonCreate   = addButton("Create");
			final Button   buttonLoad     = addButton("Load");
			final Button   buttonCampaign = addButton("Campaign");
			final Button[] buttons        = { buttonLoad, buttonCreate, buttonCampaign };
			for (Button b: buttons)
			{
				b.setPrefWidth(primaryScreenBounds.getWidth() / 3);
				b.setPrefHeight(primaryScreenBounds.getHeight() / 13);
			}

			buttonLoad.setOnAction(event->{
				File file = new FileChooser().showOpenDialog(v.stage);
				if (file != null)
				{
					v.con.loadMaze(file);
					v.showGame();
				}
			});

			buttonCreate.setOnAction(event->{
				changeView((Parent) new MenuCreation());
			});

			buttonCampaign.setOnAction(event->{
				changeView((Parent) new MenuCampaign());
			});

			addButtonQuit();

			putMsg();
		}
	}

	public class MenuCreation extends Menu
	{
		public MenuCreation()
		{
			super();

			final Button buttonPrevious = addButton("Previous");

			final Slider slidery = new Slider(0, 100, 20);
			final Slider sliderx = new Slider(0, 100, 20);

			final Slider[] sliders = { slidery, sliderx };
			final String[] names   = { "Y axis", "X axis" };
			for (int i = 0; i < sliders.length; i++)
			{
				Label label = new Label(names[i]);
				label.setId("create");
				getChildren().add(label);

				sliders[i].setBlockIncrement(1);
				getChildren().add(sliders[i]);
				sliders[i].setShowTickMarks(true);
				sliders[i].setShowTickLabels(true);
				sliders[i].setMajorTickUnit(10);
			}
			final Button buttonCreate = addButton("Create randomly");

			buttonPrevious.setOnAction(event->{
				view = new MenuStart();
				changeView(view);
			});

			buttonCreate.setOnAction(event->{
				Algo al = null;
				try
				{
					al = new AlgoBackTracker((int)sliders[0].getValue(), (int)sliders[1].getValue());
				    //al = MapIntroBuilder.getMapIntro(6);
				}
				catch (Exception e)
				{
					setMsg(e.getMessage());
					putMsg();
				}
				v.con.createMaze(al);
				v.showGame();
			});

			final Button buttonCreator = addButton("Creator");
			buttonCreator.setOnAction(event->{
				v.changeScene(new Creator(v, (int)sliders[0].getValue(), (int)sliders[1].getValue()));
			});

			putMsg();
		}
	}

	public class MenuCampaign extends Menu
	{
		public MenuCampaign()
		{
			super();

			final Button level1 = addButton("Level 1");
			final Button level2 = addButton("Level 2");
			final Button level3 = addButton("Level 3");
			final Button level4 = addButton("Level 4");
			final Button level5 = addButton("Level 5");
			final Button level6 = addButton("Level 6");
			final Button level7 = addButton("Level 7");

			final Button buttonPrevious = addButton("Previous");

			final Button[] buttons = { level1, level2, level3, level4, level5, level6, level7 };

			for (int i = 1; i <= 7; i++)
			{
				int j = i;
				buttons[i - 1].setOnAction(event->{
					Algo al = null;
					try
					{
						al = MapIntroBuilder.getMapIntro(j);
					}
					catch (Exception e)
					{
						setMsg(e.getMessage());
						putMsg();
					}
					System.out.println(al);
					v.con.createMaze(al);
					v.showGame();
				});

				buttonPrevious.setOnAction(event->{
					view = new MenuStart();
					changeView(view);
				});
			}
		}
	}

	private void changeView(Parent m)
	{
		prec = view;
		view = m;
		setRoot(view);
	}

	/**
	 * Set the message box text
	 * @param str The string
	 */
	public void setMsg(String str)
	{
		if (this.view instanceof Msg)
		{
			((Msg)this.view).setMsg(str);
		}
	}
}
