package src;

import java.io.*;
import javax.swing.*;

import src.lexer_parser.Parser;
import src.lexer_parser.LexerFlex;
import src.lexer_parser.LexerException;
import src.lexer_parser.LookAhead1;

public class Main
{
	public static void runProg(String filename)
	{
		javax.swing.SwingUtilities.invokeLater(new Runnable()
		{
			public void run()
			{
				MyCanvas.initAndShow(filename);
			}
		});
	}

	public static void quietModeActivated(String filename)
	{
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
		}
		catch (Exception e)
		{
			System.err.println(e.getMessage());
			System.exit(1);
		}
	}

	public static void main(String[] args)
	{
		boolean quietMode = false;
		boolean helpMode = false;
		String filename = null;

		for (String str : args)
		{
			if (str.equals("-q") || str.equals("--quiet"))
			{
				quietMode = true;
			}
			else if (str.equals("-h") || str.equals("--help"))
			{
				helpMode = true;
			}
			else if (str.endsWith(".gtxt"))
			{
				filename = str;
			}
			else
			{
				System.err.println("Warning : unrecognised option, recall with --help for more information : " + str);
			}
		}

		if (helpMode || filename == null)
		{
			displayHelp();
			System.exit(0);
		}
		else if (quietMode)
		{
			quietModeActivated(filename);
			System.exit(0);
		}
		runProg(filename);
	}

	public static void displayHelp()
	{
		String helpMessage = "";

		helpMessage += "java -jar ./GraphTXT.jar [-h|--help] [-q|--quiet] filename\n";
		helpMessage += "\n";
		helpMessage += "--help : display this message\n";
		helpMessage += "--quiet : do not open a frame, just display it on terminal\n";
		helpMessage += "\n";
		helpMessage += "\n";
		helpMessage += "filename must end with the extension gtxt...\n";

		System.out.println(helpMessage);
	}
}
