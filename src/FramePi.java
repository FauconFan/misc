package src;

import java.io.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class FramePi extends JFrame implements KeyListener
{
	public static final int DEFAULT_SIZE_X = 800;
	public static final int DEFAULT_SIZE_Y = 600;

	private final CanvasPi cast;

	public FramePi()
	{
		super();
		this.cast = new CanvasPi();
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		this.getContentPane().setPreferredSize(new Dimension(DEFAULT_SIZE_X, DEFAULT_SIZE_Y));
		this.getContentPane().add(this.cast);

		this.pack();
		this.setResizable(false);
		this.setVisible(true);

		addKeyListener(this);
		createRepaintTimer();
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
		else if (e.getKeyCode() == KeyEvent.VK_ESCAPE)
		{
			System.exit(0);
		}
	}

	private void createRepaintTimer()
	{
        final Timer timer = new Timer(20, null);

        timer.addActionListener(e -> {
            if (!this.isVisible()) {
                timer.stop();
            } else {
                this.repaint();
            }
        });

        timer.start();
    }
}
