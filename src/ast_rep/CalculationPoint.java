package src.ast_rep;

import java.io.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class CalculationPoint
{
	public static final int deltaX = 10;
	public static final int deltaY = 5;

	public String name;
	public int x;
	public int y;
	public int width;
	public int height;
	public int boxX;
	public int boxY;
	public int boxWidth;
	public int boxHeight;

	public CalculationPoint(CanvasAST cast, Graphics2D g2d, BlockAST bast)
	{
		FontMetrics fmet;
		Dimension dim;
		int width;
		int height;

		fmet = g2d.getFontMetrics();
		dim = cast.getSize();
		this.name = bast.getName();
		this.width = fmet.stringWidth(name);
		this.height = fmet.getHeight();
		buildSizeString(cast, dim, fmet, bast);
		buildSizeBox(cast);
	}

	public void buildSizeString(CanvasAST cast, Dimension dim, FontMetrics fmet, BlockAST bast)
	{
		this.x = bast.getX() + cast.getDX();
		this.x = this.getAdapted(this.x, dim.getWidth(), cast.getZoom());
		this.x -= this.width / 2;
		this.y = bast.getY() + cast.getDY();
		this.y = this.getAdapted(this.y, dim.getHeight(), cast.getZoom());
		this.y -= this.height / 2;
	}

	private int getAdapted(int actu, double size, float zoom)
	{
		double ecart;

		ecart = (double)actu - size / 2; 
		ecart *= zoom;
		ecart += size / 2;
		return ((int)(ecart));
	}

	public void buildSizeBox(CanvasAST cast)
	{
		this.boxX = this.x - (int)(deltaX * cast.getZoom());
		this.boxY = this.y - height;
		this.boxWidth = width + (int)(2 * deltaX * cast.getZoom());
		this.boxHeight = height + (int)(deltaY * cast.getZoom());
	}

	public static int boxWidth(String name, Graphics2D g2d)
	{
		return (g2d.getFontMetrics().stringWidth(name) + 2 * deltaX);
	}

	public String getName()
	{
		return (this.name);
	}

	public int getX()
	{
		return (this.x);
	}

	public int getY()
	{
		return (this.y);
	}

	public int getWidth()
	{
		return (this.width);
	}

	public int getHeight()
	{
		return (this.height);
	}

	public int getBoxX()
	{
		return (this.boxX);
	}

	public int getBoxY()
	{
		return (this.boxY);
	}

	public int getBoxWidth()
	{
		return (this.boxWidth);
	}

	public int getBoxHeight()
	{
		return (this.boxHeight);
	}
}