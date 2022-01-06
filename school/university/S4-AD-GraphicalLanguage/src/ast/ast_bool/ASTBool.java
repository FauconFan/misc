package src.ast.ast_bool;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.ast.ASTSuperClass;
import src.prog.Prog;

import java.awt.Point;

public abstract class ASTBool extends ASTSuperClass
{
    public ASTBool(Point begin, Point end)
    {
        super(begin, end);
    }

    public abstract boolean evalExpr(Prog prog);
}
