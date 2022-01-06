package src.lexer_parser.tokens;

import src.lexer_parser.Sym;

public class BoolOpToken extends Token
{
    private String op;

    public BoolOpToken (Sym s, String boolOp, int line, int column)
    {
        super(s, line, column);

        if (boolOp.equals("&&") || boolOp.equals("||"))
            op = boolOp;
        else
            throw new RuntimeException("Invalid boolean operator line " + line + " at position " + column);
    }

    public String getOp()
    {
        return (this.op);
    }
}
