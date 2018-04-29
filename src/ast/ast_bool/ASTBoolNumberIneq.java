package src.ast.ast_bool;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.prog.Prog;
import src.lexer_parser.LocatedException;
import src.ast.ast_expr.ASTExpr;

import java.awt.Point;

public class ASTBoolNumberIneq extends ASTBool
{
    private final ASTExpr left;
    private final String ineq;
    private final ASTExpr right;

    public ASTBoolNumberIneq(Point begin, Point end, ASTExpr left, String ineq, ASTExpr right)
    {
        super(begin, end);
        this.left  = left;
        this.ineq  = ineq;
        this.right = right;
    }

    public boolean evalExpr(Prog prog)
    {
        int a;
        int b;

        a = this.left.evalExpr(prog);
        b = this.right.evalExpr(prog);

        if (this.ineq.equals("=="))
        {
            return (a == b);
        }
        else if (this.ineq.equals("!="))
        {
            return (a != b);
        }
        else if (this.ineq.equals(">"))
        {
            return (a > b);
        }
        else if (this.ineq.equals("<"))
        {
            return (a < b);
        }
        else if (this.ineq.equals("<="))
        {
            return (a <= b);
        }
        else if (this.ineq.equals(">="))
        {
            return (a >= b);
        }
        throw new LocatedException("Invalid operation ", begin(), end(), "");
    }

    public void checkSemantic(SemanticAnalyser sa) throws SemanticAnalyserException
    {
        this.left.checkSemantic(sa);
        this.right.checkSemantic(sa);
    }

    public String getTag()
    {
        return (ineq);
    }

    public String toTikz()
    {
        String res = "[ " + this.ineq;

        res += this.left.toTikz();
        res += this.right.toTikz();
        res += "]";
        return (res);
    }
}
