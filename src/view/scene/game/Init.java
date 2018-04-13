package src.view.scene.game;

import javafx.geometry.Pos;
import javafx.scene.Camera;
import javafx.scene.Cursor;
import javafx.scene.Group;
import javafx.scene.image.Image;
import javafx.scene.Node;
import javafx.scene.paint.Color;
import javafx.scene.paint.Material;
import javafx.scene.paint.PhongMaterial;
import javafx.scene.Parent;
import javafx.scene.shape.Box;
import javafx.scene.shape.DrawMode;
import javafx.scene.shape.Line;
import javafx.scene.shape.Shape3D;
import javafx.scene.shape.Sphere;
import javafx.scene.Scene;
import javafx.scene.SubScene;
import javafx.scene.transform.Rotate;
import javafx.scene.transform.Scale;
import javafx.scene.transform.Translate;
import javafx.stage.Screen;
import javafx.stage.Stage;

import java.io.FileInputStream;

import javafx.geometry.Pos;
import javafx.scene.layout.StackPane;
import javafx.scene.shape.Rectangle;

import java.util.ArrayList;
import java.util.EnumMap;
import java.util.function.Consumer;

import src.model.board.Case;
import src.model.board.LineWall;
import src.model.ContentMaze;
import src.model.MainMaze;
import src.model.MazeDimension;
import src.model.Player;
import src.view.scene.Pause;
import src.view.scene.ScenePlus;
import src.view.scene.Winner;
import src.view.View;

import javafx.scene.control.Label;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.scene.transform.Scale;


public class Init
{
	private static String DEFAULT_TEXTURE = "assets/Brick_wall_002_COLOR.jpg";

	// Une camera avec les bons attributs pour la déplacer, et une lumière associée
	public static Group makeSpecialCases(Scale sc, MainMaze maze, boolean flyMode)
	{
		Group spc = new Group();

		ContentMaze[] cms = maze.getContentMaze();
		for (int i = 0; i < cms.length; i++)
		{
			for (Case ec: cms[i].getSpecialCases())
			{
				switch (ec.type)
				{
				case MESSAGE:
					Text message = new Text("Welcome");
					message.setTranslateX(ec.getX());
					message.setTranslateZ(ec.getY());
					//message.setTextFill(Color.web("#0076a3"));
					message.setFont(new Font("Arial", 8));
					spc.getChildren().add(message);
					break;

				default:
					final float   tailleCase = 1f;
					final Shape3D res        = (flyMode) ? new Sphere(0.1f) : new Box(tailleCase, 0.025f, tailleCase);
					res.setTranslateZ(ec.getY() + tailleCase / 2.0);
					res.setTranslateX(ec.getX() + tailleCase / 2.0);
					res.setTranslateY(-i - ((flyMode) ? 0.5 : 0.025));
					res.setMaterial(new PhongMaterial(CaseColor.getColor(ec.type)));
					spc.getChildren().add(res);
					break;
				}
			}
		}

		spc.getTransforms().add(sc);
		return (spc);
	}

	/**
	 * Dessine le sol
	 * @return Un groupe contenant le sol
	 */
	public static Group makeFloors(Scale sc, MainMaze maze, boolean flyMode)
	{
		final Group floors = new Group();

		floors.getTransforms().add(sc);
		ContentMaze[] cms = maze.getContentMaze();
		if (!flyMode)
		{
			for (int i = 0; i < cms.length; i++)
			{
				floors.getChildren().add(makeOneLevelFloor(cms[i].getMazeDimension().list_rectmaze, i));
			}
		}
		if (flyMode)
		{
			floors.getChildren().add(makeOneLevelFloor(cms[0].getMazeDimension().list_rectmaze, 0));
			floors.getChildren().add(makeOneLevelFloor(cms[cms.length - 1].getMazeDimension().list_rectmaze, cms.length));
		}
		return (floors);
	}

	private static Group makeOneLevelFloor(ArrayList <MazeDimension.RectInMaze> mds, int where)
	{
		Group res = new Group();

		res.setTranslateY(-where);
		for (MazeDimension.RectInMaze md: mds)
		{
			final int w = md.x2 - md.x1;
			final int h = md.y2 - md.y1;
			Box       f = new Box(w, 0.05, h);
			f.setTranslateX(md.x1 + w / 2.0);
			f.setTranslateZ(md.y1 + h / 2.0);
			f.setMaterial(new PhongMaterial(Color.color(0.15, 0.15, 0.15)));
			res.getChildren().add(f);
		}
		return (res);
	}

	/**
	 * Dessine les murs du Maze
	 * @return Le groupe contenant les murs
	 */
	public static Group makeWalls(Scale sc, MainMaze maze)
	{
		Material mat;
		Group    walls = new Group();

		// On scale les murs
		walls.getTransforms().add(sc);
		final float   delta = 0.001f;
		ContentMaze[] cms   = maze.getContentMaze();
		for (int i = 0; i < cms.length; i++)
		{
			try{
				String texturePath = cms[i].getTexturePath();
				if (texturePath == null)
				{
					texturePath = DEFAULT_TEXTURE;      //Default
				}
				Image img = new Image(new FileInputStream(texturePath), 400, 400, true, false);
				mat = new PhongMaterial(Color.WHITE, img, null, null, null);
			}
			catch (Exception e) {
				mat = new PhongMaterial(Color.GREEN);
			}
			for (LineWall l: cms[i].getLineWalls())
			{
				LineWall[] broken = LineWall.breakWallsIntoSimpleOnes(l);
				for (int j = 0; j < broken.length; j++)
				{
					Box w = new Box();

					Consumer <Float> setEpais;
					Consumer <Float> setLarg;

					float  largeur;
					double trX;
					double trZ;
					float  isStart = (j == 0) ? broken[j].getEpaisseur() / 2 - delta : 0;
					float  isEnd   = (j == broken.length - 1) ? broken[j].getEpaisseur() / 2 - delta : 0;
					if (!broken[j].isHorizontal())                                        // Mur "vertical" dans le plan
					{
						largeur  = broken[j].getY2() - broken[j].getY1();
						setLarg  = w::setDepth;
						setEpais = w::setWidth;
						trX      = broken[j].getX1();
						trZ      = broken[j].getY1() + largeur / 2.0;
					}
					else // Mur horizontal
					{
						largeur  = broken[j].getX2() - broken[j].getX1();
						setLarg  = w::setWidth;
						setEpais = w::setDepth;
						trX      = broken[j].getX1() + largeur / 2.0;
						trZ      = broken[j].getY1();
					}

					w.setHeight(1);
					setEpais.accept(broken[j].getEpaisseur());
					setLarg.accept(largeur + isStart + isEnd);
					w.setTranslateX(trX);
					w.setTranslateZ(trZ);
					w.setTranslateY(-i - 0.5);

					w.setMaterial(mat);
					walls.getChildren().add(w);
				}
			}
		}
		return (walls);
	}
}
