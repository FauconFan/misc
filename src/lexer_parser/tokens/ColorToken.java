package src.lexer_parser.tokens;

import src.lexer_parser.Sym;

import java.awt.Color;

public class ColorToken extends Token
{
	private Color color;

	public ColorToken(Sym c, String v, int line, int column)
	{
		super(c, line, column);
		int r;
		int g;
		int b;

		try{
			if (v.length() != 7)
			{
				throw new Exception();
			}

			r = Integer.parseInt(v.substring(1, 3), 16);
			g = Integer.parseInt(v.substring(3, 5), 16);
			b = Integer.parseInt(v.substring(5, 7), 16);

			if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
			{
				throw new Exception();
			}
		}catch (Exception e) {
			throw new RuntimeException("Invalid color declaration line " + line + " at position " + column);
		}
		this.color = new Color(r, g, b);
	}

	public Color getValue()
	{
		return (this.color);
	}
}
