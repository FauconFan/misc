package src.lexer_parser;

import java.awt.Point;

public class LocatedException extends RuntimeException
{
	public LocatedException(String beginMessage, Point begin, Point end, String endMessage)
	{
		super(beginMessage +
			  (begin.x == end.x ?
			   (begin.y == end.y ?
				"line " + begin.x + " at position " + begin.y :
				"line " + begin.x + " between position " + begin.y + " and position " + end.y
			   ) : "between line " + begin.x + " at position " + begin.y + " and line " + end.x + " at position " + end.y
			  ) +
			  endMessage);
	}
}
