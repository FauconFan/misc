package src.view;

import javafx.scene.media.Media;
import javafx.scene.media.MediaPlayer;
import javafx.scene.media.MediaPlayer.Status;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.util.Duration;

import java.io.File;

import src.controller.Controller;

import src.view.scene.game.Game;
import src.view.scene.Menus;

/**
 * La vue
 */
public class View
{
	public static final boolean enableMusible = false;
	public final Controller con;
	private Scene scene;
	public final Stage stage;
	private final MediaPlayer mediaPlayer;

	public View(Stage stage, Controller con)
	{
		this.con         = con;
		this.scene       = new Menus(this);
		this.stage       = stage;
		this.mediaPlayer = null;

		stage.setTitle("Laby");

		if (enableMusible)
		{
			Media sound = new Media(new File("assets/music/Bg1_BXDN_Return.mp3").toURI().toString());
			mediaPlayer = new MediaPlayer(sound);
			mediaPlayer.setOnEndOfMedia(()->{ mediaPlayer.seek(Duration.ZERO); });
			mediaPlayer.setVolume(0.6);
			mediaPlayer.play();
		}

		stage.setScene(scene);
		stage.show();
	}

	public Scene getScene()
	{
		return (this.scene);
	}

	public void showGame()
	{
		scene = new Game(this, con.getMaze());
		stage.setScene(scene);
	}

	public void changeScene(Scene s)
	{
		stage.setScene(s);
		this.scene = s;
	}

	public void startStopMusic()
	{
		if (enableMusible)
		{
			if (mediaPlayer.getStatus() == Status.PAUSED)
			{
				mediaPlayer.play();
			}
			else
			{
				mediaPlayer.pause();
			}
		}
	}
}
