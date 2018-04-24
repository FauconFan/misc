package src.view.scene.creator;

import java.util.ArrayList;

import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.Button;
import javafx.scene.control.ButtonType;
import javafx.scene.control.ChoiceBox;
import javafx.scene.control.Label;
import javafx.scene.control.Slider;
import javafx.scene.control.TextField;
import javafx.scene.effect.ColorAdjust;
import javafx.scene.layout.Border;
import javafx.scene.layout.BorderStroke;
import javafx.scene.layout.BorderStrokeStyle;
import javafx.scene.layout.CornerRadii;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.Node;
import javafx.scene.paint.Color;

import java.io.File;
import java.util.function.BiConsumer;
import java.util.function.Consumer;
import java.util.Optional;

import src.model.*;
import src.model.board.*;
import src.model.gen.CreatorHelper;
import src.view.View;

/**
 * Le panneau de gauche du creator
 */
class LeftPanel extends VBox
{
	private final Insets defaultInsets = new Insets(20, 0, 20, 0);

	public final int leftPaneGrSize = 180;

	public final Textures wallTextures, floorTextures;

	public final Creator creator;

	public VBox leftPaneGr;

	public LeftPanel(Creator creator, int width, int height, View v, boolean flyMode)
	{
		setMinSize(leftPaneGrSize, 0);
		setAlignment(Pos.TOP_CENTER);
		setPadding(defaultInsets);

		this.creator = creator;
		ArrayList <Level> levels = creator.levels;

		//Level
		Label chooseYourLevel = new Label("Choose your level: ");
		chooseYourLevel.setPadding(defaultInsets);

		ChoiceBox <Integer> choiceBox = new ChoiceBox <Integer>();
		for (int i = 0; i < levels.size(); i++)
		{
			choiceBox.getItems().add(i);
		}
		choiceBox.setPadding(defaultInsets);
		choiceBox.setValue(0);

		//Level button
		Label  leve   = new Label("Level");
		Button remove = new Button("Remove");
		remove.setOnAction((ev)->{
			Alert alert = new Alert(AlertType.CONFIRMATION, "Do you really want to remove the current level ?", ButtonType.YES, ButtonType.NO);
			Optional <ButtonType> result = alert.showAndWait();
			if (result.isPresent() && result.get() == ButtonType.YES)
			{
				choiceBox.getItems().clear();                 //Reset the choice box
				for (int i = 0; i < levels.size() - 1; i++)
				{
					choiceBox.getItems().add(i);
				}
				if ((creator.currentLevel == 0))
				{
					levels.remove(0);
					choiceBox.setValue(0);
				}
				else
				{
					choiceBox.setValue(creator.currentLevel - 1);             //Trigger the change in the right panel, will change currentLevel
					levels.remove(creator.currentLevel + 1);
				}
			}
			if (levels.size() == 1)
			{
				remove.setDisable(true);
			}
		});
		if (levels.size() == 1)
		{
			remove.setDisable(true);
		}

		Button add = new Button("Add");
		add.setOnAction((ev)->{
			levels.add(new Level());
			choiceBox.getItems().add(levels.size() - 1);
			if (remove.isDisable())
			{
				remove.setDisable(false);
			}
		});


		HBox tempButton = new HBox(add, remove);
		tempButton.setAlignment(Pos.TOP_CENTER);

		VBox buttonsBox = new VBox(leve, tempButton);
		buttonsBox.setAlignment(Pos.TOP_CENTER);
		buttonsBox.setPadding(defaultInsets);

		//Textures
		wallTextures  = new Textures(leftPaneGrSize, (n, str)->{ creator.levels.get(n).setWallTexture(str); });
		floorTextures = new Textures(leftPaneGrSize, (n, str)->{ creator.levels.get(n).setFloorTexture(str); });

		choiceBox.valueProperty().addListener((ov, h, n)->{
			if (n != null)
			{
				creator.updateRightPanel(n);

				setCurrentWallTexture(levels.get(n).getWallTexture());
				setCurrentFloorTexture(levels.get(n).getFloorTexture());

				leftPaneGr.getChildren().clear();
			}
		});

		//Placeholder for case
		leftPaneGr = new VBox();
		leftPaneGr.setAlignment(Pos.TOP_CENTER);
		leftPaneGr.setPadding(defaultInsets);

		//Finish
		Button button = new Button("Finish");
		button.setOnAction((ev)->{
			CreatorHelper ch = new CreatorHelper(levels.size());
			for (int i = 0; i < levels.size(); i++)
			{
				ArrayList <LineWall> lineWalls = new ArrayList <LineWall>();
				for (Node l: levels.get(i).walls.getChildren())
				{
					LinePlus li = (LinePlus)l;
					lineWalls.add(li.lw);
				}

				ArrayList <Case> specialCases = new ArrayList <Case>();
				for (RectanglePlus l: levels.get(i).cases)
				{
					Case c = l.getCase();
					if (c != null)
					{
						specialCases.add(c);
					}
				}
				ch.append(i, 0, width, 0, height, lineWalls.toArray(new LineWall[0]), specialCases.toArray(new Case[0]), levels.get(i).getWallTexture(), levels.get(i).getFloorTexture());
			}
			try{
				v.con.setMaze(ch.buildMainMaze("", flyMode));
				v.showGame();
			}
			catch (Exception e) {
				e.printStackTrace();
				Alert alert = new Alert(Alert.AlertType.ERROR, e.getMessage());
				alert.showAndWait();
			}
		});


		getChildren().addAll(button, buttonsBox, chooseYourLevel, choiceBox, new Label("Wall texture"), wallTextures, new Label("Floor texture"), floorTextures, leftPaneGr);
	}

	public void setCurrentWallTexture(String str)
	{
		setCurrentTexture(str, wallTextures);
	}

	public void setCurrentFloorTexture(String str)
	{
		setCurrentTexture(str, floorTextures);
	}

	private void setCurrentTexture(String str, Textures t)
	{
		if (str != null&& !str.equals(""))
		{
			t.setCurrentTexture(str);
		}
		else
		{
			t.reset();
		}
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
				TextField tx = new IntTextField(((TeleportCase)c).getXDest(), ((TeleportCase)c)::setXDest);                            //TODO Faire attention...
				TextField ty = new IntTextField(((TeleportCase)c).getYDest(), ((TeleportCase)c)::setYDest);
				leftPaneGr.getChildren().addAll(new HBox(new Label("x : "), tx), new HBox(new Label("y : "), ty));
				break;

			case TIME:
				TextField tf = new IntTextField(((TimeCase)c).getTimeNano(), ((TimeCase)c)::setTimeNano);
				leftPaneGr.getChildren().add(new HBox(new Label("Time: "), tf));
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
				TextField taille = new IntTextField(((JumpCase)c).getNbLevelJump(), ((JumpCase)c)::setNbLevelJump);
				leftPaneGr.getChildren().add(new HBox(new Label("Jump level: "), taille));
				break;
			}
		}
	}

	/**
	 * There is no default field for int value
	 */
	private class IntTextField extends TextField
	{
		public IntTextField(int defaultValue, Consumer <Integer> ch)
		{
			super(Integer.toString(defaultValue));
			setPrefColumnCount(4);
			textProperty().addListener((ov, h, n)->{
				try{
					ch.accept(Integer.parseInt(n));
					setBorder(Border.EMPTY);
				}
				catch (Exception e) {
					setBorder(new Border(new BorderStroke(Color.RED, BorderStrokeStyle.SOLID, CornerRadii.EMPTY, BorderStroke.DEFAULT_WIDTHS)));
				}
			});
		}
	}

	/**
	 * Un gridPane qui est fait pour nos textures
	 */
	private class Textures extends GridPane
	{
		public Tile currentTile = null;

		private final BiConsumer <Integer, String> updateTile;

		private final int gap = 5;
		private final int numOfTilesPerLine = 2;

		Textures(int leftPaneGrSize, BiConsumer <Integer, String> updateTile)
		{
			this.updateTile = updateTile;
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
		}

		private void setCurrentTile(Tile tile)
		{
			if (currentTile != null)
			{
				((ColorAdjust)currentTile.getEffect()).setBrightness(-0.6);
			}
			currentTile = tile;
			((ColorAdjust)currentTile.getEffect()).setBrightness(0);
			updateTile.accept(creator.currentLevel, tile.filename);
			//creator.levels.get(creator.currentLevel).setTexture(tile.filename);
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
			updateTile.accept(creator.currentLevel, str);
		}

		public void reset()
		{
			if (currentTile != null)
			{
				((ColorAdjust)currentTile.getEffect()).setBrightness(-0.6);
				currentTile = null;
			}
		}
	}
}
