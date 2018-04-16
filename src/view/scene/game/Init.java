package src.view.scene.game;

import javafx.scene.Group;
import javafx.scene.image.Image;
import javafx.scene.paint.Color;
import javafx.scene.paint.Material;
import javafx.scene.paint.PhongMaterial;
import javafx.scene.shape.Box;
import javafx.scene.shape.Shape3D;
import javafx.scene.shape.Sphere;
import javafx.scene.transform.Scale;

import java.io.FileInputStream;


import java.util.ArrayList;
import java.util.function.Consumer;

import src.model.board.Case;
import src.model.board.LineWall;
import src.model.ContentMaze;
import src.model.MainMaze;
import src.model.MazeDimension;

import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.scene.transform.Scale;

/**
 * Static class for the Game init
 */
public class Init
{
	private static String DEFAULT_TEXTURE_WALL  = "assets/Brick_wall_002_COLOR.jpg";
	private static String DEFAULT_TEXTURE_FLOOR = "assets/Wood_plancks_004_COLOR.jpg";

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
	 * Make the floor
	 * @return A group with the floor
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
			Material mat;
			try{
				String texturePath = DEFAULT_TEXTURE_FLOOR;          //Default

				Image img = new Image(new FileInputStream(texturePath), 400, 400, true, false);
				mat = new PhongMaterial(Color.WHITE, img, null, null, null);
			}
			catch (Exception e) {
				mat = new PhongMaterial(Color.GREEN);
			}


			final int w = md.x2 - md.x1;
			final int h = md.y2 - md.y1;
			for (int i = 0; i < w; i++)
			{
				for (int j = 0; j < h; j++)
				{
					Box f = new Box(1, 0.05, 1);
					f.setTranslateX((md.x1 + i + 0.5));
					f.setTranslateZ((md.y1 + j + 0.5));
					f.setMaterial(mat);
					res.getChildren().add(f);
				}
			}
		}
		return (res);
	}

	/**
	 * Create the walls
	 * @return A group with the walls
	 */
	public static Group makeWalls(Scale sc, MainMaze maze)
	{
		Material mat;
		Group    walls = new Group();

		walls.getTransforms().add(sc);
		final float   delta = 0.001f;
		ContentMaze[] cms   = maze.getContentMaze();
		for (int i = 0; i < cms.length; i++)
		{
			try{
				String texturePath = cms[i].getWallTexturePath();
				if (texturePath == null)
				{
					texturePath = DEFAULT_TEXTURE_WALL;      //Default
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
