package src.lexer_parser.tokens;

import src.lexer_parser.Sym;

public class EqOpToken extends Token
{
    private final String op;

    public EqOpToken (Sym c, String eqOp, int line, int column)
    {
        super(c, line, column);
        if (eqOp.equals("==") || eqOp.equals("!="))
            op = eqOp;
        else
            throw new RuntimeException("Invalid boolean operator line " + line + " at position " + column);
    }

    public String getOp()
    {
        return op;
    }
}
