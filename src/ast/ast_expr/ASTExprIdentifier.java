package src.ast.ast_expr;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.prog.Prog;
import src.lexer_parser.LocatedException;

import java.awt.Point;

public class ASTExprIdentifier extends ASTExpr
{
	private final String identifier;

	public ASTExprIdentifier(Point begin, Point end, String identifier)
	{
		super(begin, end);
		this.identifier = identifier;
	}

	public int evalExpr(Prog prog)
	{
		try{
			return (prog.getData(this.identifier));
		}catch (Exception e) {
			throw new LocatedException("Invalid variable or constant use ", begin(), end(), " : " + e.getMessage());
		}
	}

	public void checkSemantic(SemanticAnalyser sa) throws SemanticAnalyserException
	{
		try{
			sa.can_access_var_in_registre(this.identifier);
		}catch (Exception e) {
			throw new LocatedException("Invalid variable or constant use ", begin(), end(), " : " + e.getMessage());
		}
	}

	public String getTag()
	{
		return (this.identifier);
	}

	public String toTikz()
	{
		String res = "[ " + identifier + " ] ";

		return (res);
	}
}
