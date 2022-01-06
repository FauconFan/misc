package src.lexer_parser.tokens;

import src.lexer_parser.Sym;
import java.awt.Point;

public class Token
{
	protected Sym symbol;
	protected final Point location;

	public Token(Sym s, int line, int column)
	{
		symbol   = s;
		location = new Point(line, column);
	}

	public Sym symbol()
	{
		return (this.symbol);
	}

	public String toString()
	{
		return ("Symbol : " + this.symbol);
	}

	public int getLign()
	{
		return (location.x);
	}

	public int getColumn()
	{
		return (location.y);
	}

	public Point getLocation()
	{
		return (location.getLocation());
	}
}
