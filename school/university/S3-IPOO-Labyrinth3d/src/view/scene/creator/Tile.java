package src.view.scene.creator;

import javafx.scene.effect.ColorAdjust;
import javafx.scene.image.Image;
import javafx.scene.paint.ImagePattern;
import javafx.scene.shape.Rectangle;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;

/**
 * A Tile is a Rectangle corresponding to a texture
 */
public class Tile extends Rectangle
{
	public final String filename;
	public Tile(File texture, int tileLength) throws FileNotFoundException
	{
		super(tileLength, tileLength);
		filename = texture.getPath();
		setEffect(new ColorAdjust());
		setFill(new ImagePattern(new Image(new FileInputStream(texture), tileLength, tileLength, true, false)));
	}
}
