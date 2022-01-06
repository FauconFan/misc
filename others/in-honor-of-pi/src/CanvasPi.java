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

	private static final Color[] GradedColor;

	static
	{
		GradedColor = new Color[17];

		GradedColor[0] = new Color(255, 0, 0);	
	 	GradedColor[1] = new Color(255, 64, 0);
	 	GradedColor[2] = new Color(255, 128, 0);		
	 	GradedColor[3] = new Color(255, 191, 0);		 		
	 	GradedColor[4] = new Color(255, 255, 0);		 		
	 	GradedColor[5] = new Color(191, 255, 0);		 		
	 	GradedColor[6] = new Color(128, 255, 0);		 		
	 	GradedColor[7] = new Color(64, 255, 0);	
	 	GradedColor[8] = new Color(0, 255, 0);	
	 	GradedColor[9] = new Color(0, 255, 64);	
	 	GradedColor[10] = new Color(0, 255, 128);	
	 	GradedColor[11] = new Color(0, 255, 191);	
	 	GradedColor[12] = new Color(0, 255, 255);	
	 	GradedColor[13] = new Color(0, 191, 255);	
	 	GradedColor[14] = new Color(0, 128, 255);	
	 	GradedColor[15] = new Color(0, 64, 255);	
	 	GradedColor[16] = new Color(0, 0, 255);	
	}

	public Color calculateColor(float i, float max)
	{
		float r = 0;
		float g = 0;
		float b = 0;
		float actu = 0;

		actu = i % (max / 4);
		actu = actu / (max / 4);

		if (i < max / 4)
		{
			r = 1;
			g = actu;
			b = 0;
		}
		else if (i < max / 2)
		{
			r = 1 - actu;
			g = 1;
			b = 0;
		}
		else if (i < 3 * max / 4)
		{
			r = 0;
			g = 1;
			b = actu;
		}
		else
		{
			r = 0;
			g = 1 - actu;
			b = 1;
		}
		return (new Color(r, g, b));
	}

	@Override
	public void paintComponent(Graphics g)
	{
		int increase = this.dpg.list_lines.size() / 200 + 1;
		for (int i = 0; i < increase; i++)
			this.dpg.append_next();
		if (g instanceof Graphics2D)
		{
			Graphics2D g2d;

			g2d = (Graphics2D)g;
			g2d.translate(400, 300);
			g2d.setColor(Color.BLACK);
			g2d.fillRect(-400, -300, 800, 600);
			for (int i = 0; i < this.dpg.list_lines.size(); i++)
			{
				DrawingPiGraph.Line l = this.dpg.list_lines.get(i);
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
				g2d.setColor(calculateColor(i, this.dpg.list_lines.size()));
				g2d.drawLine((int)x1, (int)y1, (int)x2, (int)y2);
			}
		}
	}
}