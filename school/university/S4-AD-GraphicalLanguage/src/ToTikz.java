package src;

import src.ast.AST;

public class ToTikz
{
	private static String getHeader()
	{
		return ("\\documentclass{standalone}\n\\usepackage{forest}\n\\begin{document}\n\\begin{forest}for tree={draw=black}");
	}

	private static String getFooter()
	{
		return ("\\end{forest}\n\\end{document}");
	}

	public static void printTikz(AST ast)
	{
		System.out.println(ToTikz.getHeader() + ast.toTikz() + ToTikz.getFooter());
	}
}
