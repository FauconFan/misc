package src.ast_rep;

import java.io.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

import src.ast.AST;

public class FrameAST extends JFrame implements KeyListener
{
	private final CanvasAST cast;

	public FrameAST(AST ast)
	{
		super();
		this.cast = new CanvasAST(ast);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		this.getContentPane().setPreferredSize(new Dimension(800, 600));
		this.getContentPane().add(this.cast);

		this.pack();
		this.setResizable(false);
		this.setVisible(true);

		addKeyListener(this);
	}

	public void keyReleased(KeyEvent e)
	{
	}

	public void keyTyped(KeyEvent e)
	{
	}

	public void keyPressed(KeyEvent e)
	{
		if (e.getKeyCode() == KeyEvent.VK_RIGHT)
		{
			cast.moveRight();
		}
		else if (e.getKeyCode() == KeyEvent.VK_LEFT)
		{
			cast.moveLeft();
		}
		else if (e.getKeyCode() == KeyEvent.VK_DOWN)
		{
			cast.moveDown();
		}
		else if (e.getKeyCode() == KeyEvent.VK_UP)
		{
			cast.moveUp();
		}
		else if (e.getKeyCode() == KeyEvent.VK_P)
		{
			cast.zoomPlus();
		}
		else if (e.getKeyCode() == KeyEvent.VK_M)
		{
			cast.zoomMoins();
		}
	}
}
