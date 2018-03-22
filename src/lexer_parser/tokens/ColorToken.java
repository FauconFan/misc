package src.lexer_parser.tokens;

import src.lexer_parser.Sym;

import java.awt.Color;

public class ColorToken extends Token
{
	private Color color;

	public ColorToken(Sym c, String v)
	{
		super(c);
		int r;
		int g;
		int b;

		if (v.length() != 7)
		{
			throw new RuntimeException("SNA constructor ColorToken");
		}
		r = Integer.parseInt(v.substring(1, 3), 16);
		g = Integer.parseInt(v.substring(3, 5), 16);
		b = Integer.parseInt(v.substring(5, 7), 16);
		this.color = new Color(r, g, b);
	}

	public Color getValue()
	{
		return (this.color);
	}
}
