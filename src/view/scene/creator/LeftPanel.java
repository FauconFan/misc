package src.view.scene.creator;

import java.util.ArrayList;

import javafx.collections.ObservableList;
import javafx.collections.transformation.FilteredList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Orientation;
import javafx.geometry.Point2D;
import javafx.geometry.Pos;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.ChoiceBox;
import javafx.scene.control.Label;
import javafx.scene.control.ScrollBar;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.ScrollPane.ScrollBarPolicy;
import javafx.scene.control.Slider;
import javafx.scene.control.TextField;
import javafx.scene.effect.ColorAdjust;
import javafx.scene.Group;
import javafx.scene.image.Image;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.scene.Node;
import javafx.scene.paint.Color;
import javafx.scene.paint.ImagePattern;
import javafx.scene.Parent;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Line;
import javafx.scene.shape.Rectangle;
import javafx.scene.Scene;
import javafx.scene.transform.Scale;
import javafx.scene.transform.Translate;
import javafx.stage.Screen;

import javafx.beans.value.ChangeListener;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;

import src.model.*;
import src.model.board.*;
import src.model.gen.CreatorHelper;
import src.view.scene.game.CaseColor;
import src.view.scene.game.Game;
import src.view.scene.Menus;
import src.view.scene.ScenePlus;
import src.view.View;

class LeftPanel extends VBox
{
	private final Insets defaultInsets = new Insets(20, 0, 20, 0);

	public final Textures textures;

	public final VBox leftPaneGr;

	public LeftPanel(int leftPaneGrSize, ArrayList <Stage> stages, ChangeListener <Integer> listener, int width, int height, View v, boolean flyMode)
	{
		setMinSize(leftPaneGrSize, 0);
		setAlignment(Pos.TOP_CENTER);
		setPadding(defaultInsets);

		//Level
		Label chooseYourLevel = new Label("Choose your level: ");
		chooseYourLevel.setPadding(defaultInsets);

		ChoiceBox <Integer> choiceBox = new ChoiceBox <Integer>();
		for (int i = 0; i < stages.size(); i++)
		{
			choiceBox.getItems().add(i);
		}
		choiceBox.setPadding(defaultInsets);
		choiceBox.setValue(0);

		//Level button
		Button add = new Button("Add");
		add.setOnAction((ev)->{
			stages.add(new Stage());
			choiceBox.getItems().add(stages.size() - 1);
		});
		Button remove = new Button("Remove");
		remove.setOnAction((ev)->{
			stages.remove(stages.size() - 1);
			choiceBox.getItems().remove(stages.size());
		});
		HBox buttonsBox = new HBox(add, remove);
		buttonsBox.setAlignment(Pos.TOP_CENTER);
		buttonsBox.setPadding(defaultInsets);

		choiceBox.valueProperty().addListener(listener);

//Textures
		textures = new Textures(leftPaneGrSize);
		//Placeholder for case
		leftPaneGr = new VBox();
		leftPaneGr.setAlignment(Pos.TOP_CENTER);
		leftPaneGr.setPadding(defaultInsets);

		//Finish
		Button button = new Button("Finish");
		button.setOnAction((ev)->{
			CreatorHelper ch = new CreatorHelper(stages.size());
			for (int i = 0; i < stages.size(); i++)
			{
				ArrayList <LineWall> lineWalls = new ArrayList <LineWall>();
				for (Node l: stages.get(i).walls.getChildren())
				{
					LinePlus li = (LinePlus)l;
					lineWalls.add(li.lw);
				}

				ArrayList <Case> specialCases = new ArrayList <Case>();
				for (Node l: stages.get(i).cases.getChildren())
				{
					Case c = ((RectanglePlus)l).getCase();
					if (c != null)
					{
						specialCases.add(c);
					}
				}
				ch.append(i, 0, width, 0, height, lineWalls.toArray(new LineWall[0]), specialCases.toArray(new Case[0]));
			}
			try{
				v.con.setMaze(ch.buildMainMaze("", textures.currentTile.filename, flyMode));
				v.showGame();
			}
			catch (Exception e) {
				e.printStackTrace();
				Alert alert = new Alert(Alert.AlertType.ERROR, e.getMessage());
				alert.showAndWait();
			}
		});


		getChildren().addAll(button, buttonsBox, chooseYourLevel, choiceBox, textures, leftPaneGr);
	}

	/**
	 * Update the left pane according to the new case
	 */
	public void updateLeftPane(RectanglePlus startedRect)
	{
		leftPaneGr.getChildren().clear();
		Case c = startedRect.getCase();

		if (c != null)
		{
			leftPaneGr.getChildren().add(new Label(c.type + " case"));
			switch (c.type)
			{
			case TELEPORT:
				HBox      hx = new HBox(new Label("x: "));
				HBox      hy = new HBox(new Label("y: "));
				TextField tx = new TextField(Integer.toString(((TeleportCase)c).getXDest()));
				tx.setPrefColumnCount(4);
				tx.textProperty().addListener((ov, o, n)->{
					try{ ((TeleportCase)c).setXDest(Integer.parseInt(n)); }
					catch (Exception e) {}
				});                            //TODO Faire attention...
				TextField ty = new TextField(Integer.toString(((TeleportCase)c).getYDest()));
				ty.setPrefColumnCount(4);
				ty.textProperty().addListener((ov, o, n)->{
					try{ ((TeleportCase)c).setYDest(Integer.parseInt(n)); }
					catch (Exception e) {}
				});
				hx.getChildren().add(ty);
				hy.getChildren().add(tx);
				leftPaneGr.getChildren().addAll(hx, hy);
				break;

			case TIME:
				Slider slider = new Slider();
				slider.setMin(-5);
				slider.setValue(((TimeCase)c).getTimeMillis());
				slider.setMax(5);
				slider.setShowTickLabels(true);
				slider.setMajorTickUnit(0.25f);
				slider.setBlockIncrement(0.25f);
				slider.valueProperty().addListener((ov, x, z)->{
					((TimeCase)c).setTimeMilis(z.longValue());
				});
				leftPaneGr.getChildren().add(slider);
				break;

			case SPEED:
				Slider sliderS = new Slider();
				sliderS.setMin(0);
				sliderS.setValue(((SpeedCase)c).getSpeedModif());
				sliderS.setMax(5);
				sliderS.setShowTickLabels(true);
				sliderS.setMajorTickUnit(0.25f);
				sliderS.setBlockIncrement(0.25f);
				sliderS.valueProperty().addListener((ov, x, z)->{
					((SpeedCase)c).setSpeedModif(z.floatValue());
				});
				leftPaneGr.getChildren().add(sliderS);
				break;

			case JUMP:
				TextField taille = new TextField(Integer.toString(((JumpCase)c).getNbLevelJump()));
				taille.setPrefColumnCount(4);
				taille.textProperty().addListener((ov, o, n)->{
					try{ ((JumpCase)c).setNbLevelJump(Integer.parseInt(n)); }
					catch (Exception e) {}
				});
				leftPaneGr.getChildren().add(new HBox(new Label("Jump level: "), taille));
				break;
			}
		}
	}

	public void setCurrentTexture(String str)
	{
		textures.setCurrentTexture(str);
	}

	private class Textures extends GridPane
	{
		public Tile currentTile = null;

		private final int gap = 5;
		private final int numOfTilesPerLine = 2;

		Textures(int leftPaneGrSize)
		{
			setAlignment(Pos.TOP_CENTER);
			setPadding(defaultInsets);
			setVgap(gap);
			setHgap(gap);
			final int tileLength = leftPaneGrSize / numOfTilesPerLine - gap * numOfTilesPerLine;

			File[] textures = getTextures();
			for (int i = 0; i < textures.length; i++)
			{
				try{
					Tile tile = new Tile(textures[i], tileLength);
					((ColorAdjust)tile.getEffect()).setBrightness(-0.6);
					GridPane.setConstraints(tile, i % numOfTilesPerLine, i / numOfTilesPerLine);
					getChildren().add(tile);
					tile.setOnMouseClicked((ev)->{ setCurrentTile(tile); });
				}
				catch (Exception e) {}
			}
			if (textures.length != 0)
			{
				currentTile = (Tile)getChildren().get(0);
				((ColorAdjust)currentTile.getEffect()).setBrightness(0);
			}
		}

		private File[] getTextures()
		{
			File assets = new File("assets");

			return (assets.listFiles((file, name)->{
				int i = name.lastIndexOf('.');
				if (i > 0)
				{
					return name.substring(i + 1).equals("jpg");
				}
				return false;
			}));
		}

		public void setCurrentTexture(String str)
		{
			for (Node n: getChildren())
			{
				Tile t = (Tile)n;
				if (t.filename.equals(str))
				{
					setCurrentTile(t);
				}
			}
		}

		//For textures
		private class Tile extends Rectangle
		{
			private final String filename;
			public Tile(File texture, int tileLength) throws FileNotFoundException
			{
				super(tileLength, tileLength);
				filename = texture.getPath();
				setEffect(new ColorAdjust());
				setFill(new ImagePattern(new Image(new FileInputStream(texture), tileLength, tileLength, true, false)));
			}
		}

		private void setCurrentTile(Tile tile)
		{
			if (currentTile != null)
			{
				((ColorAdjust)currentTile.getEffect()).setBrightness(-0.6);
			}
			currentTile = tile;
			((ColorAdjust)currentTile.getEffect()).setBrightness(0);
		}
	}
}
