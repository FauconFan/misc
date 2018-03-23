package src.view;

import javafx.application.Platform;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.geometry.Rectangle2D;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.stage.Screen;

import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.layout.BackgroundImage;
import javafx.scene.layout.BackgroundPosition;
import javafx.scene.layout.BackgroundRepeat;
import javafx.scene.layout.BackgroundSize;
import javafx.stage.Screen;
import javafx.stage.Window;

public class Menu extends VBox implements Msg
{
	protected Rectangle2D primaryScreenBounds;
	protected Label msg;

	private static int screenWidth  = (int)Screen.getPrimary().getBounds().getWidth();
	private static int screenHeight = (int)Screen.getPrimary().getBounds().getHeight();

	public Menu()
	{
		super();
		this.setPrefSize(800, 600);

		setPadding(new Insets(10));
		setSpacing(15);
		setAlignment(Pos.CENTER);

		//BackgroundImage myBI= new BackgroundImage(new Image("assets/menuBackground.jpg", 800, 600, false, true), BackgroundRepeat.REPEAT, BackgroundRepeat.NO_REPEAT, BackgroundPosition.DEFAULT, BackgroundSize.DEFAULT);
		//setBackground(new Background(myBI));
		setStyle("-fx-background-color: #CCFF99;");

		primaryScreenBounds = Screen.getPrimary().getVisualBounds();

		msg = new Label();
		msg.setTextFill(Color.web("#DC143C"));
		msg.setFont(new Font("Arial", 30));
	}

	protected Button addButton(String name)
	{
		Button b = new Button(name);

		b.setStyle("-fx-text-fill: #D2691E; -fx-background-color: #DFB951; -fx-border-radius: 20; -fx-background-radius: 20;-fx-padding: 5;");

		getChildren().add(b);
		return (b);
	}

	/**
	 * To be called at the end of a constructor, to add the msg at the end
	 */
	protected void putMsg()
	{
		getChildren().add(this.msg);
	}

	public void setMsg(String str)
	{
		this.msg.setText(str);
	}

	public void addButtonQuit()
	{
		Button b = addButton("Quit");

		b.setOnAction(event->{
			Platform.exit();
		});
	}
}
