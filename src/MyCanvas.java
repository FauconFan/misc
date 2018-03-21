package src;

import java.io.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

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
				if (parser.buildProg())
				{
					System.out.println("HALLELUJAH");
				}
				// AST ast = parser.progNonTerm();
				// ast.exec(g2d);
			}
			catch (Exception e)
			{
				System.err.println(e.getMessage());
				System.exit(1);
			}
		}
	}

	public static void initAndShow(String filename)
	{
		JFrame frame = new JFrame("ADS4");

		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		frame.getContentPane().setPreferredSize(new Dimension(800, 600));
		frame.getContentPane().add(new MyCanvas(filename));

		frame.pack();
		frame.setVisible(true);
	}
}
