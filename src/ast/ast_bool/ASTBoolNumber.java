package src.ast.ast_bool;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.prog.Prog;
import src.ast.ast_expr.ASTExpr;

import java.awt.Point;

public class ASTBoolNumber extends ASTBool
{
    private final ASTExpr expr;

    public ASTBoolNumber(Point begin, Point end, ASTExpr expr)
    {
        super(begin, end);
        this.expr = expr;
    }

    public boolean evalExpr(Prog prog)
    {
        return (this.expr.evalExpr(prog) != 0);
    }

    public void checkSemantic(SemanticAnalyser sa) throws SemanticAnalyserException
    {
        expr.checkSemantic(sa);
    }

    public String getTag()
    {
        return expr.getTag();
    }

    public String toTikz()
    {
        return expr.toTikz();
    }
}
