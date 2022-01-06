package src.ast.ast_bool;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.prog.Prog;
import src.lexer_parser.LocatedException;

import java.awt.Point;

public class ASTBoolOp extends ASTBool
{
    private final ASTBool left;
    private final String op;
    private final ASTBool right;

    public ASTBoolOp(Point begin, Point end, ASTBool left, String op, ASTBool right)
    {
        super(begin, end);
        this.left  = left;
        this.op    = op;
        this.right = right;
    }

    public boolean evalExpr(Prog prog)
    {
        boolean a;
        boolean b;

        a = this.left.evalExpr(prog);
        b = this.right.evalExpr(prog);

        if (this.op.equals("=="))
        {
            return (a == b);
        }
        else if (this.op.equals("!="))
        {
            return (a != b);
        }
        else if (this.op.equals("&&"))
        {
            return (a && b);
        }
        else if (this.op.equals("||"))
        {
            return (a || b);
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
        return (op);
    }

    public String toTikz()
    {
        String res = "[ " + this.op;

        res += this.left.toTikz();
        res += this.right.toTikz();
        res += "]";
        return (res);
    }
}
