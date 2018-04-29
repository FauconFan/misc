package src.view;

import javafx.application.Platform;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.geometry.Rectangle2D;
import javafx.scene.control.Button;
import javafx.scene.layout.VBox;
import javafx.stage.Screen;

import src.view.View;

/**
 * Une VBox avec des caractéristiques de menu
 */
public class Menu extends VBox
{
	protected Rectangle2D primaryScreenBounds;

	private static int screenWidth  = (int)Screen.getPrimary().getVisualBounds().getMaxX();
	private static int screenHeight = (int)Screen.getPrimary().getVisualBounds().getMaxY();

	public Menu()
	{
		super();
		setId("pane");

		setPadding(new Insets(10));
		setSpacing(15);
		setAlignment(Pos.CENTER);

		primaryScreenBounds = Screen.getPrimary().getVisualBounds();
		setPrefSize(primaryScreenBounds.getWidth(), primaryScreenBounds.getHeight());
	}

	/**
	 * Ajoute un grand bouton
	 * @param name Le nom affiché
	 * @return le nom
	 */
	protected Button addBigButton(String name)
	{
		return (addButton(name, 3, 15));
	}

	/**
	 * Ajoute un petit bouton
	 * @param name Le nom affiché
	 * @return le nom
	 */
	protected Button addSmallButton(String name)
	{
		return (addButton(name, 10, 20));
	}

	private Button addButton(String str, int w, int h)
	{
		Button b = new Button(str);

		getChildren().add(b);
		b.setPrefWidth(screenWidth / w);
		b.setPrefHeight(screenHeight / h);

		return (b);
	}

	/**
	 * Ajoute un bouton "Quit" qui quitte l'application
	 */
	public void addButtonQuit()
	{
		Button b = addSmallButton("Quit");

		b.setOnAction(event->{
			Platform.exit();
		});
	}

	/**
	 * Ajoute un bouton pour la musique
	 */
	public void addButtonMusic(View v)
	{
		Button b = addSmallButton("Stop music");

		b.setPrefWidth(screenWidth / 10);
		b.setPrefHeight(screenHeight / 20);
		b.setOnAction(event->{
			if (b.getText().equals("Stop music"))
			{
				b.setText("Start music");
			}
			else
			{
				b.setText("Stop music");
			}
			v.startStopMusic();
		});
	}
}
