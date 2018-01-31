package src.view;

import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.geometry.Rectangle2D;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.stage.Screen;

public class Menu extends VBox
{
	protected Rectangle2D primaryScreenBounds;
	protected Label msg;

	public Menu()
	{
		super();

		setPadding(new Insets(10));
		setSpacing(15);
		setAlignment(Pos.CENTER);

		primaryScreenBounds = Screen.getPrimary().getVisualBounds();

		msg = new Label();
		msg.setTextFill(Color.web("#DC143C"));
		msg.setFont(new Font("Arial", 30));
	}

	protected Button addButton(String name)
	{
		Button b = new Button(name);

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
}
