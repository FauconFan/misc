package src;

import java.util.ArrayList;
import java.awt.Color;

import java.util.Scanner;
import java.io.File;

public class DrawingPiGraph
{
	public static int normeLine = 20;

	public short[] data;
	public final ArrayList<Line> list_lines;
	public double oldX;
	public double oldY;


	public DrawingPiGraph(String filename)
	{
		this.list_lines = new ArrayList<>();
		this.oldX = 0;
		this.oldY = 0;

		try
		{
			Scanner sc = new Scanner(new File(filename));
			String line = sc.nextLine();
			this.data = new short[line.length() - 2];
			for (int i = 2; i < this.data.length; i++)
			{
				int actu = Integer.parseInt("" + line.charAt(i));
				this.data[i - 2] = (short)actu;
			}
		}
		catch(Exception e)
		{
			e.printStackTrace();
			System.exit(1);
		}

	}

	public void append_next()
	{
		int actu = data[list_lines.size() % this.data.length];

		if (list_lines.size() % 1000 == 0)
			System.out.println(list_lines.size());
		this.append(construct_next(actu));
	}

	private Color getRelatedColor(int digit)
	{
		switch (digit)
		{
			case 0: return Color.BLUE;
			case 1: return Color.CYAN;
			case 2: return Color.GRAY;
			case 3: return Color.GREEN;
			case 4: return Color.MAGENTA;
			case 5: return Color.ORANGE;
			case 6: return Color.PINK;
			case 7: return Color.RED;
			case 8: return Color.WHITE;
			case 9: return Color.YELLOW;
			default : return Color.BLACK;
		}
	}

	public Line construct_next(int digit)
	{
		Line l;
		double nextX = 0;
		double nextY = 0;
		double angle = 0;

		angle = Math.PI / 5 * digit;
		angle = Math.PI / 2 - angle;
		nextX = Math.cos(angle);
		nextY = - Math.sin(angle);
		nextX = nextX * normeLine + oldX;
		nextY = nextY * normeLine + oldY;

		l = new Line(oldX, oldY, nextX, nextY, getRelatedColor(digit));
		oldX = nextX;
		oldY = nextY;
		return (l);
	}

	public void append(Line l)
	{
		this.list_lines.add(l);
	}

	public static class Line
	{
		public Color c;
		public double x1;
		public double y1;
		public double x2;
		public double y2;

		public Line(double x1, double y1, double x2, double y2)
		{
			this(x1, y1, x2, y2, Color.BLACK);
		}

		public Line(double x1, double y1, double x2, double y2, Color c)
		{
			this.x1 = x1;
			this.y1 = y1;
			this.x2 = x2;
			this.y2 = y2;
			this.c = c;
		}

		public String toString()
		{
			return "((" + x1 + ", " + y1 + "), (" + x2 + ", " + y2 + "))";
		}
	}
}