package src.lexer_parser;

public class LexerException extends Exception
{
	private static final long serialVersionUID = 954054054059L;

	public LexerException(String text, int line, int column)
	{
		super("At line " + line + ", column " + column + "\nCan't make any token with " + text);
	}
}
