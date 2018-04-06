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

import javafx.stage.Screen;

public class Menus extends ScenePlus
{
	private Parent view;
	private Parent prec;

	private static int screenWidth  = (int)Screen.getPrimary().getVisualBounds().getMaxX();
	private static int screenHeight = (int)Screen.getPrimary().getVisualBounds().getMaxY();

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

			final Button   buttonCreate   = addBigButton("Create");
			final Button   buttonLoad     = addBigButton("Load");
			final Button   buttonCampaign = addBigButton("Campaign");
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

			final Button buttonPrevious = addSmallButton("Previous");

			final Slider   slidery = new Slider(0, 100, 20);
			final Slider   sliderx = new Slider(0, 100, 20);
			final Slider   sliderZ = new Slider(1, 5, 1);
			final Slider[] sliders = { slidery, sliderx, sliderZ };
			final String[] names   = { "Y axis", "X axis", "Stage" };
			for (int i = 0; i < sliders.length; i++)
			{
				Label label = new Label(names[i]);
				label.setId("create");
				getChildren().add(label);

				sliders[i].setBlockIncrement(1);
				getChildren().add(sliders[i]);
				sliders[i].setShowTickMarks(true);
				sliders[i].setShowTickLabels(true);
				sliders[i].setMajorTickUnit((i != 2) ? 10 : 1);
				if (i == 2)
				{
					sliders[i].setMinorTickCount(0);
				}
			}
			final Button buttonCreate = addSmallButton("Create randomly");

			buttonPrevious.setOnAction(event->{
				view = new MenuStart();
				changeView(view);
			});

			buttonCreate.setOnAction(event->{
				Algo al = null;
				try
				{
					al = new AlgoBackTracker((int)sliders[0].getValue(), (int)sliders[1].getValue(), (int)sliders[2].getValue());
				}
				catch (Exception e)
				{
					e.printStackTrace();
					System.exit(1);
				}
				v.con.createMaze(al);
				v.showGame();
			});

			final Button buttonCreator = addSmallButton("Creator");
			buttonCreator.setOnAction(event->{
				v.changeScene(new Creator(v, (int)sliders[0].getValue(), (int)sliders[1].getValue(), (int)sliders[2].getValue()));
			});

			putMsg();
		}
	}

	public class MenuCampaign extends Menu
	{
		public MenuCampaign()
		{
			super();

			final Button level1 = addSmallButton("Level 1");
			final Button level2 = addSmallButton("Level 2");
			final Button level3 = addSmallButton("Level 3");
			final Button level4 = addSmallButton("Level 4");
			final Button level5 = addSmallButton("Level 5");
			final Button level6 = addSmallButton("Level 6");
			final Button level7 = addSmallButton("Level 7");

			final Button buttonPrevious = addBigButton("Previous");

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

	public class MenuCampaign2 extends Menu
	{
		public MenuCampaign2()
		{
			super();
			addLevelButtons();
			final Button buttonPrevious = addBigButton("Previous");
			buttonPrevious.setOnAction(event->{
				view = new MenuStart();
				changeView(view);
			});
		}

		public void addLevelButtons()
		{
			File[] list = getLevels();
			for (File f : list)
			{
				String nom = f.getPath();
				Button b   = addSmallButton(nom);
				b.setOnAction(event->{
					v.con.loadMaze(f);
				});
			}
		}

		public File[] getLevels()
		{
			File dossier = new File("model/maps/");

			return (dossier.listFiles((file, name)->{
				int i = name.lastIndexOf('.');
				if (i > 0)
				{
					return name.substring(i + 1).equals("maze");
				}
				return false;
			}));
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
