package src;

import java.io.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Main
{
	private static void initAndShow(String filename)
	{
		JFrame frame = new JFrame("ADS4");

		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		frame.getContentPane().setPreferredSize(new Dimension(800, 600));
		frame.getContentPane().add(new MyCanvas(filename));

		frame.pack();
		frame.setVisible(true);
	}

	public static void main(String[] args)
	{
		javax.swing.SwingUtilities.invokeLater(new Runnable()
		{
			public void run()
			{
				if (args.length != 1)
				{
					System.err.println("Must give one file as argument");
					System.exit(1);
				}
				initAndShow(args[0]);
			}
		});
	}
}

@SuppressWarnings("serial")
class MyCanvas extends JComponent
{
	String filename;

	public MyCanvas(String fname)
	{
		filename = fname;
	}

	@Override
	public void paintComponent(Graphics g)
	{
		if (g instanceof Graphics2D)
		{
			Graphics2D g2d = (Graphics2D)g;

			// A compléter.
			// Appelez ici votre analyseur et interpréteur, en leur fournissant
			// l'objet g2d de type Graphics2D. Ils pourront ainsi appeler les fonctions
			// g2d.drawCircle, g2d.setColor, etc...
			
			try
			{
				File input = new File(filename);
				Reader reader = new FileReader(input);
				LexerFlex lexer = new LexerFlex(reader);
				LookAhead1 look = new LookAhead1(lexer);
				Parser parser = new Parser(look);
				parser.walkThrough();
				// AST ast = parser.progNonTerm();
				// ast.exec(g2d);
			}
			catch (Exception e)
			{
				System.err.println(e.getMessage());
				e.printStackTrace();
				System.exit(1);
			}
		}
	}
}
