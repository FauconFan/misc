package src.prog;

public class SemanticAnalyserException extends Exception
{
	public SemanticAnalyserException(String message)
	{
		super("SemanticAnalyser : " + message);
	}
}
