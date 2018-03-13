package src.view.scene.game;

import java.io.FileInputStream;
import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.AmbientLight;
import javafx.scene.Camera;
import javafx.scene.Cursor;
import javafx.scene.Group;
import javafx.scene.image.Image;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.Node;
import javafx.scene.paint.Color;
import javafx.scene.paint.Material;
import javafx.scene.paint.PhongMaterial;
import javafx.scene.ParallelCamera;
import javafx.scene.Parent;
import javafx.scene.PerspectiveCamera;
import javafx.scene.PointLight;
import javafx.scene.shape.Box;
import javafx.scene.shape.DrawMode;
import javafx.scene.shape.Line;
import javafx.scene.shape.Rectangle;
import javafx.scene.Scene;
import javafx.scene.SubScene;
import javafx.scene.transform.Rotate;
import javafx.scene.transform.Scale;
import javafx.scene.transform.Translate;
import javafx.stage.Stage;

import src.model.board.LineWall;
import src.model.Player;

class MiniMap extends SubScene
{
	private final Translate fstTr;
	private final Scale sc2d;
	private final GroupCameraPlus groupCameraPlus2D;
	private final int w, h;

	public MiniMap(int w, int h, Scale sc, LineWall[] walls)
	{
		super(new Group(), w, h);
		this.w = w;
		this.h = h;
		Group rootMiniMap = (Group)getRoot();
		this.fstTr = new Translate(w / 2.0, h / 2.0);
		this.sc2d  = sc;

		setFill(null);

		groupCameraPlus2D = new GroupCameraPlus(new ParallelCamera(), fstTr);
		rootMiniMap.getChildren().add(groupCameraPlus2D);
		setCamera(groupCameraPlus2D.camera);
		rootMiniMap.getChildren().add(makeLineWalls(walls));
	}

	public void updateCamera(Player p)
	{
		groupCameraPlus2D.rz.setAngle(p.getHorizontalAngle());
		groupCameraPlus2D.tr.setY(p.getPosY() * sc2d.getY());
		groupCameraPlus2D.tr.setX(p.getPosX() * sc2d.getX());
	}

	private Group makeLineWalls(LineWall[] lineWalls)
	{
		final Group res = new Group();

		res.getTransforms().addAll(fstTr, sc2d);
		AmbientLight am = new AmbientLight(Color.WHITE);
		res.getChildren().add(am);
		for (LineWall l: lineWalls)
		{
			Line li = new Line(l.getX1(), l.getY1(), l.getX2(), l.getY2());
			li.setFill(Color.BLUE);
			li.setStrokeWidth(0.1f);
			res.getChildren().add(li);
		}
		return (res);
	}

	/**
	 * Destinée à être affichée au dessus de la minimap
	 */
	public class Cross extends SubScene
	{
		public Cross()
		{
			super(new Group(), w, h);
			setFill(null);
			int   larg = 15;
			Group root = (Group)this.getRoot();
			Line  hLi  = new Line(w / 2.0 - larg, h / 2.0, w / 2.0 + larg, h / 2.0);
			hLi.setStroke(Color.RED);
			hLi.setStrokeWidth(3);
			Line vLi = new Line(w / 2.0, h / 2.0 - larg, w / 2.0, h / 2.0 + larg);
			vLi.setStroke(Color.RED);
			vLi.setStrokeWidth(3);

			Rectangle r = new Rectangle(0, 0, w, h);
			r.setFill(null);
			r.setStroke(Color.BLACK);
			r.setStrokeWidth(5);

			root.getChildren().addAll(vLi, hLi, r);

			ParallelCamera p = new ParallelCamera();
			setCamera(p);
		}
	}
}
