package src.ast.ast_bool;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.prog.Prog;

import java.awt.Point;

public class ASTBoolValue extends ASTBool
{
    private final boolean bool;

    public ASTBoolValue(Point begin, Point end, boolean bool)
    {
        super(begin, end);
        this.bool = bool;
    }

    public boolean evalExpr(Prog prog)
    {
        return (this.bool);
    }

    public void checkSemantic(SemanticAnalyser sa) throws SemanticAnalyserException
    {
        return;
    }

    public String getTag()
    {
        return bool + "";
    }

    public String toTikz()
    {
        String res = "[ " + bool + " ]";

        return (res);
    }
}
