package src.lexer_parser.tokens;

import src.lexer_parser.Sym;

public class CompareOpToken extends Token
{
    private String op;

    public CompareOpToken(Sym s, String compareOp, int line, int column)
    {
        super(s, line, column);

        if (compareOp.equals("<=") || compareOp.equals(">=") || compareOp.equals("<") || compareOp.equals(">") || compareOp.equals("==") || compareOp.equals("!="))
            op = compareOp;
        else
            throw new RuntimeException("Invalid comparison operator line " + line + " at position " + column);
    }

    public String getOp()
    {
        return (this.op);
    }
}