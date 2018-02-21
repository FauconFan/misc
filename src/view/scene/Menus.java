package src.view.scene;

import javafx.application.Platform;
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
import src.model.gen.AlgoBackTracker;
import src.model.gen.AlgoSample;
import src.model.gen.AlgoSample2;

import src.view.Menu;
import src.view.Msg;
import src.view.View;

public class Menus extends Scene
{
	private Parent view;
	private Parent prec;
	private final View v;

	public Menus(View v)
	{
		super(new Group());
		((Group)getRoot()).getChildren().add(new MenuStart());
		this.v = v;
	}

	public Menus(View v, Menu m)
	{
		super(m);
		this.v    = v;
		this.view = m;
	}

	public class MenuStart extends Menu
	{
		public MenuStart()
		{
			super();

			Label label = new Label("Hello the Maze");
			label.setFont(new Font("Arial", 35));
			getChildren().add(label);

			final Button   buttonCreate = addButton("Create");
			final Button   buttonLoad   = addButton("Load");
			final Button   buttonExit   = addButton("Exit");
			final Button[] buttons      = { buttonLoad, buttonCreate, buttonExit };
			for (Button b: buttons)
			{
				b.setPrefWidth(primaryScreenBounds.getWidth() / 1.5);
				b.setPrefHeight(primaryScreenBounds.getHeight() / 15);
			}

			buttonLoad.setOnAction(event->{
				File file = new FileChooser().showOpenDialog(v.stage);
				if (file != null)
				{
					v.loadMaze(file);
				}
			});

			buttonCreate.setOnAction(event->{
				changeView((Parent) new MenuCreation());
			});

			buttonExit.setOnAction(event->{
				Platform.exit();
			});

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
				view = new MenuStart();
				changeView(view);
			});

			buttonCreate.setOnAction(event->{
				v.createMaze(new AlgoBackTracker((int)sliders[0].getValue(), (int)sliders[1].getValue()), 30);
			});

			putMsg();
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
