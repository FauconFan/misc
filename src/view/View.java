package src.view;

import javafx.application.Platform;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.geometry.Rectangle2D;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.Slider;
import javafx.scene.layout.VBox;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Screen;

import src.controller.Controller;


public class View
{
	private final Controller con;
	private Parent view;
	private Parent prec;
	private Scene scene;

	public View(Controller con)
	{
		this.con   = con;
		this.view  = new MenuStart();
		this.scene = new Scene((Parent)view);
	}

	public Scene getScene()
	{
		return (this.scene);
	}

	public class MenuStart extends Menu
	{
		public MenuStart()
		{
			super();

			Label label = new Label("Hello the Maze");
			getChildren().add(label);

			Button   buttonCreate = addButton("Create");
			Button   buttonLoad   = addButton("Load");
			Button   buttonExit   = addButton("Exit");
			Button[] buttons      = { buttonLoad, buttonCreate, buttonExit };
			for (Button b: buttons)
			{
				b.setPrefWidth(primaryScreenBounds.getWidth() / 1.5);
				b.setPrefHeight(primaryScreenBounds.getHeight() / 15);
			}

			buttonLoad.setOnAction(event->{
				//TODO POPUP to ask a path
				con.loadMaze("");
			});

			buttonCreate.setOnAction(event->{
				changeView((Parent) new MenuCreation());
			});

			buttonExit.setOnAction(event->{
				Platform.exit();
			});
		}
	}

	public class MenuCreation extends Menu
	{
		public MenuCreation()
		{
			super();

			Button buttonPrevious = addButton("Previous");

			Slider slidery = new Slider(0, 100, 50);
			Slider sliderx = new Slider(0, 100, 50);

			Slider[] sliders = { slidery, sliderx };
			String[] names   = { "Y axis", "X axis" };
			for (int i = 0; i < sliders.length; i++)
			{
				Label label = new Label(names[i]);
				getChildren().add(label);

				sliders[i].setBlockIncrement(1);
				getChildren().add(sliders[i]);
				sliders[i].setShowTickMarks(true);
				sliders[i].setShowTickLabels(true);
				sliders[i].setMajorTickUnit(10);
			}
			Button buttonCreate = new Button("Create");
			getChildren().add(buttonCreate);

			buttonPrevious.setOnAction(event->{
				view = prec;
				changeView(view);
			});

			buttonCreate.setOnAction(event->{
				//TODO
				//changeView(null);
			});
		}
	}

	public class MenuPause extends Menu
	{
		public MenuPause()
		{
			Button buttonUnPause = addButton("Unpause");

			buttonUnPause.setOnAction(event->{
				view = prec;
				changeView(view);
			});

			Button buttonReturn = addButton("Return to Menu");
			buttonReturn.setOnAction(event->{
				changeView(new MenuStart());
			});
		}
	}

	private void changeView(Parent m)
	{
		prec = view;
		view = m;
		scene.setRoot(view);
	}
}
