package src;

import java.io.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

@SuppressWarnings("serial")
public class CanvasPi extends JComponent
{
	private static final int DEFAULT_SIZE_FONT = 15;
	private static final float ZOOM_RATE       = 1.1f;

	private DrawingPiGraph dpg;
	private int dx;
	private int dy;
	private float zoom;

	private Font getCurrentFont()
	{
		return (new Font(Font.MONOSPACED, Font.PLAIN, (int)(DEFAULT_SIZE_FONT * zoom)));
	}

	public CanvasPi()
	{
		super();
		this.dpg = new DrawingPiGraph("resources/pi1000000.txt");
		this.dx   = 0;
		this.dy   = 0;
		this.zoom = 1.0f;
	}

	public int getDX()
	{
		return (this.dx);
	}

	public int getDY()
	{
		return (this.dy);
	}

	public float getZoom()
	{
		return (this.zoom);
	}

	public void moveRight()
	{
		this.dx += 5 * 1 / this.zoom;
		repaint();
	}

	public void moveLeft()
	{
		this.dx -= 5 * 1 / this.zoom;
		repaint();
	}

	public void moveUp()
	{
		this.dy -= 5 * 1 / this.zoom;
		repaint();
	}

	public void moveDown()
	{
		this.dy += 5 * 1 / this.zoom;
		repaint();
	}

	public void zoomPlus()
	{
		this.zoom *= ZOOM_RATE;
		repaint();
	}

	public void zoomMoins()
	{
		this.zoom *= (1.0f / ZOOM_RATE);
		repaint();
	}

	@Override
	public void paintComponent(Graphics g)
	{
		this.dpg.append_next();
		if (g instanceof Graphics2D)
		{
			Graphics2D g2d;

			g2d = (Graphics2D)g;
			g2d.translate(400, 300);
			g2d.setColor(Color.BLACK);
			g2d.fillRect(-400, -300, 800, 600);
			for (DrawingPiGraph.Line l : this.dpg.list_lines)
			{
				double x1 = l.x1;
				double y1 = l.y1;
				double x2 = l.x2;
				double y2 = l.y2;

				x1 += this.dx;
				x2 += this.dx;
				y1 += this.dy;
				y2 += this.dy;
				x1 *= this.zoom;
				y1 *= this.zoom;
				x2 *= this.zoom;
				y2 *= this.zoom;
				g2d.setColor(l.c);
				g2d.drawLine((int)x1, (int)y1, (int)x2, (int)y2);
			}
		}
	}
}
