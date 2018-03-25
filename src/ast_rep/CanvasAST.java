package src.ast_rep;

import java.io.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

import src.lexer_parser.Parser;
import src.lexer_parser.LexerFlex;
import src.lexer_parser.LexerException;
import src.lexer_parser.LookAhead1;

import src.ast.AST;

import src.prog.SemanticAnalyser;

import java.util.ArrayList;

@SuppressWarnings("serial")
public class CanvasAST extends JComponent
{
	private static final int DEFAULT_SIZE_FONT = 15;
	private static final float ZOOM_RATE = 1.1f;

	private AST ast;
	private int dx;
	private int dy;
	private float zoom;
	private ArrayList<BlockAST> list_blocks;

	private Font getCurrentFont()
	{
		return (new Font(Font.MONOSPACED, Font.PLAIN, (int)(DEFAULT_SIZE_FONT * zoom)));
	}

	public CanvasAST(AST ast)
	{
		super();
		this.ast = ast;
		this.dx = 0;
		this.dy = 0;
		this.zoom = 1.0f;
		this.list_blocks = new ArrayList<>();

		this.list_blocks.add(new BlockAST(100, 100, "Name"));
		this.list_blocks.add(new BlockAST(200, 100, "Content"));
		this.list_blocks.add(new BlockAST(100, 200, "Test"));
	}

	public void moveRight()
	{
		this.dx += 5;
		repaint();
	}

	public void moveLeft()
	{
		this.dx -= 5;
		repaint();
	}

	public void moveUp()
	{
		this.dy -= 5;
		repaint();
	}

	public void moveDown()
	{
		this.dy += 5;
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
		if (g instanceof Graphics2D)
		{
			Graphics2D g2d;

			g2d = (Graphics2D)g;
			g2d.setFont(getCurrentFont());
			for (BlockAST bast : this.list_blocks)
			{
				CalculationPoint cp = new CalculationPoint(this, g2d, bast);
				g2d.drawString(cp.name, cp.x, cp.y);
				g2d.drawRect(cp.boxX, cp.boxY, cp.boxWidth, cp.boxHeight);
			}
		}
	}

	public static void initAndShow(String filename)
	{
		AST ast;

		ast = null;
		try
		{
			File       input  = new File(filename);
			Reader     reader = new FileReader(input);
			LexerFlex  lexer  = new LexerFlex(reader);
			LookAhead1 look   = new LookAhead1(lexer);
			Parser     parser = new Parser(look);
			ast = parser.buildProg();
			SemanticAnalyser sa = new SemanticAnalyser();
			sa.checkAST(ast);
		}
		catch (Exception e)
		{
			System.err.println(e.getMessage());
			System.exit(1);
		}
		new FrameAST(ast);
	}

	public static class CalculationPoint
	{
		public static final int deltaX = 10;
		public static final int deltaY = 5;

		public String name;
		public int x;
		public int y;
		public int boxX;
		public int boxY;
		public int boxWidth;
		public int boxHeight;

		public int getAdapted(int actu, double size, float zoom)
		{
			double dactu;
			double ecart;

			dactu = (double)actu;
			ecart = dactu - size / 2; 
			ecart *= zoom;
			ecart += size / 2;
			return ((int)(ecart));
		}

		public CalculationPoint(CanvasAST cast, Graphics2D g2d, BlockAST bast)
		{
			FontMetrics fmet;
			Dimension dim;
			int width;
			int height;

			fmet = g2d.getFontMetrics();
			dim = cast.getSize();
			this.name = bast.getName();
			this.x = bast.getX() + cast.dx;
			this.y = bast.getY() + cast.dy;
			this.x = this.getAdapted(this.x, dim.getWidth(), cast.zoom);
			this.y = this.getAdapted(this.y, dim.getHeight(), cast.zoom);
			width = fmet.stringWidth(name);
			height = fmet.getHeight();
			this.x -= width / 2;
			this.y -= height / 2;
			this.boxX = this.x - (int)(deltaX * cast.zoom);
			this.boxY = this.y - height;
			this.boxWidth = width + (int)(2 * deltaX * cast.zoom);
			this.boxHeight = height + (int)(deltaY * cast.zoom);
		}
	}
}
