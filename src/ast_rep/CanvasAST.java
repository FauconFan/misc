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
	private static final float ZOOM_RATE       = 1.1f;

	private AST ast;
	private int dx;
	private int dy;
	private float zoom;
	private BlockASTHead head;

	private Font getCurrentFont()
	{
		return (new Font(Font.MONOSPACED, Font.PLAIN, (int)(DEFAULT_SIZE_FONT * zoom)));
	}

	public CanvasAST(AST ast)
	{
		super();
		this.ast  = ast;
		this.dx   = 0;
		this.dy   = 0;
		this.zoom = 1.0f;
		this.head = new BlockASTHead(400, 100, ast);
		this.head.setParentRecu();
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
			this.head.setCoordsRecu(g2d);
			this.head.paintBlockRecu(this, g2d, null);
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
}
