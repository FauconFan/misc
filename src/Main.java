package src;

import java.io.*;
import javax.swing.*;

import src.lexer_parser.Parser;
import src.lexer_parser.LexerFlex;
import src.lexer_parser.LookAhead1;

import src.ast.AST;

import src.prog.SemanticAnalyser;

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

	public static void runAstRepProg(String filename)
	{
		try
		{
			File             input  = new File(filename);
			Reader           reader = new FileReader(input);
			LexerFlex        lexer  = new LexerFlex(reader);
			LookAhead1       look   = new LookAhead1(lexer);
			Parser           parser = new Parser(look);
			AST              ast    = parser.buildProg();
			SemanticAnalyser sa     = new SemanticAnalyser();
			sa.checkAST(ast);
			if (ast != null)
			{
				ToTikz.printTikz(ast);
			}
		}
		catch (Exception e)
		{
			System.err.println(e.getMessage());
			System.exit(1);
		}
	}

	public static void quietModeActivated(String filename)
	{
		try
		{
			File             input  = new File(filename);
			Reader           reader = new FileReader(input);
			LexerFlex        lexer  = new LexerFlex(reader);
			LookAhead1       look   = new LookAhead1(lexer);
			Parser           parser = new Parser(look);
			AST              ast    = parser.buildProg();
			SemanticAnalyser sa     = new SemanticAnalyser();
			sa.checkAST(ast);
			if (ast != null)
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
		boolean quietMode  = false;
		boolean helpMode   = false;
		boolean astRepTex = false;
		String  filename   = null;

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
			else if (str.equals("--ast-tex"))
			{
				astRepTex = true;
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

		if (helpMode == true ||
			filename == null ||
			(quietMode == true && astRepTex == true))
		{
			displayHelp();
		}
		else if (quietMode)
		{
			quietModeActivated(filename);
		}
		else if (astRepTex)
		{
			runAstRepProg(filename);
		}
		else
		{
			runProg(filename);
		}
	}

	public static void displayHelp()
	{
		String helpMessage = "";

		helpMessage += "java -jar ./GraphTXT.jar [-h|--help] [-q|--quiet] [--ast-tex] filename\n";
		helpMessage += "\n";
		helpMessage += "--help : display this message\n";
		helpMessage += "--quiet : do not open a frame, just display it on terminal\n";
		helpMessage += "--ast : display a graphic representation of the AST\n";
		helpMessage += "\n";
		helpMessage += "\n";
		helpMessage += "Every filename musts end with the extension gtxt...\n";
		helpMessage += "--ast-tex and --quiet can be called at the same time\n";

		System.out.print(helpMessage);
	}
}
