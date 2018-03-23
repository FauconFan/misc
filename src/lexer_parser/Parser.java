package src.lexer_parser;

import java.io.*;
import java.awt.Color;

import src.lexer_parser.tokens.Token;
import src.lexer_parser.tokens.IdentifierToken;
import src.lexer_parser.tokens.NumberToken;
import src.lexer_parser.tokens.ColorToken;
import src.lexer_parser.tokens.OperatorToken;

import src.ast.AST;
import src.ast.ASTExpr;
import src.ast.ASTInstr;
import src.ast.ASTInstrIf;
import src.ast.ASTInstrExec;
import src.ast.ASTInstrWhile;
import src.ast.ASTInstrDecl;
import src.ast.ASTInstrAssign;
import src.ast.ASTInstrBeginEnd;

public class Parser
{
	protected LookAhead1 reader;

	public Parser(LookAhead1 r) throws IOException
	{
		reader = r;
	}

	private ASTExpr expr() throws Exception
	{
		ASTExpr res;

		if (reader.check(Sym.LPAR))
		{
			ASTExpr left;
			ASTExpr right;
			char    op;

			reader.eat(Sym.LPAR);
			left  = expr();
			op    = ((OperatorToken)reader.pop(Sym.OPERATOR)).getOp();
			right = expr();
			reader.eat(Sym.RPAR);
			res = new ASTExpr(left, op, right);
		}
		else if (reader.check(Sym.NUMBER))
		{
			int number;

			number = ((NumberToken)reader.pop(Sym.NUMBER)).getValue();
			res    = new ASTExpr(number);
		}
		else if (reader.check(Sym.IDENTIFIER))
		{
			String identifier;

			identifier = ((IdentifierToken)reader.pop(Sym.IDENTIFIER)).getValue();
			res        = new ASTExpr(identifier);
		}
		else
		{
			throw new Exception("Expected a expression here");
		}
		return (res);
	}

	// return true if it does something, or false
	private ASTInstr instruction() throws Exception
	{
		ASTInstr res = null;

		// Exec Instruction
		if (reader.check(Sym.DRAWCIRCLE))
		{
			ASTExpr[] args   = new ASTExpr[3];
			Color[]   colors = new Color[1];

			reader.eat(Sym.DRAWCIRCLE);
			reader.eat(Sym.LPAR);
			args[0] = expr();
			reader.eat(Sym.COMMA);
			args[1] = expr();
			reader.eat(Sym.COMMA);
			args[2] = expr();
			reader.eat(Sym.COMMA);
			colors[0] = ((ColorToken)reader.pop(Sym.COLOR)).getValue();
			reader.eat(Sym.RPAR);

			res = new ASTInstrExec(Sym.DRAWCIRCLE, args, colors);
		}
		else if (reader.check(Sym.FILLCIRCLE))
		{
			ASTExpr[] args   = new ASTExpr[3];
			Color[]   colors = new Color[1];

			reader.eat(Sym.FILLCIRCLE);
			reader.eat(Sym.LPAR);
			args[0] = expr();
			reader.eat(Sym.COMMA);
			args[1] = expr();
			reader.eat(Sym.COMMA);
			args[2] = expr();
			reader.eat(Sym.COMMA);
			colors[0] = ((ColorToken)reader.pop(Sym.COLOR)).getValue();
			reader.eat(Sym.RPAR);

			res = new ASTInstrExec(Sym.FILLCIRCLE, args, colors);
		}
		else if (reader.check(Sym.DRAWRECT))
		{
			ASTExpr[] args   = new ASTExpr[4];
			Color[]   colors = new Color[1];

			reader.eat(Sym.DRAWRECT);
			reader.eat(Sym.LPAR);
			args[0] = expr();
			reader.eat(Sym.COMMA);
			args[1] = expr();
			reader.eat(Sym.COMMA);
			args[2] = expr();
			reader.eat(Sym.COMMA);
			args[3] = expr();
			reader.eat(Sym.COMMA);
			colors[0] = ((ColorToken)reader.pop(Sym.COLOR)).getValue();
			reader.eat(Sym.RPAR);

			res = new ASTInstrExec(Sym.DRAWRECT, args, colors);
		}
		else if (reader.check(Sym.FILLRECT))
		{
			ASTExpr[] args   = new ASTExpr[4];
			Color[]   colors = new Color[1];

			reader.eat(Sym.FILLRECT);
			reader.eat(Sym.LPAR);
			args[0] = expr();
			reader.eat(Sym.COMMA);
			args[1] = expr();
			reader.eat(Sym.COMMA);
			args[2] = expr();
			reader.eat(Sym.COMMA);
			args[3] = expr();
			reader.eat(Sym.COMMA);
			colors[0] = ((ColorToken)reader.pop(Sym.COLOR)).getValue();
			reader.eat(Sym.RPAR);

			res = new ASTInstrExec(Sym.FILLRECT, args, colors);
		}
		// Control Instruction
		else if (reader.check(Sym.BEGIN))
		{
			AST next;

			reader.eat(Sym.BEGIN);
			next = instruction_next();
			reader.eat(Sym.END);

			res = new ASTInstrBeginEnd(next);
		}
		else if (reader.check(Sym.IF))
		{
			ASTExpr    expr;
			ASTInstr   instr;
			ASTInstrIf follow;

			reader.eat(Sym.IF);
			expr = expr();
			reader.eat(Sym.THEN);
			instr  = instruction();
			follow = if_follow();

			res = new ASTInstrIf(expr, instr, follow);
		}
		else if (reader.check(Sym.WHILE))
		{
			ASTExpr  expr;
			ASTInstr instr;

			reader.eat(Sym.WHILE);
			expr = expr();
			reader.eat(Sym.DO);
			instr = instruction();
			reader.eat(Sym.DONE);

			res = new ASTInstrWhile(expr, instr);
		}
		// Imp Instruction
		else if (reader.check(Sym.CONST))
		{
			String  identifier;
			ASTExpr expr;

			reader.eat(Sym.CONST);
			identifier = ((IdentifierToken)reader.pop(Sym.IDENTIFIER)).getValue();
			reader.eat(Sym.EQUALS);
			expr = expr();

			res = new ASTInstrDecl(true, identifier, expr);
		}
		else if (reader.check(Sym.VAR))
		{
			String  identifier;
			ASTExpr expr;

			reader.eat(Sym.VAR);
			identifier = ((IdentifierToken)reader.pop(Sym.IDENTIFIER)).getValue();
			reader.eat(Sym.EQUALS);
			expr = expr();

			res = new ASTInstrDecl(false, identifier, expr);
		}
		else if (reader.check(Sym.IDENTIFIER))
		{
			String  identifier;
			ASTExpr expr;

			identifier = ((IdentifierToken)reader.pop(Sym.IDENTIFIER)).getValue();
			reader.eat(Sym.EQUALS);
			expr = expr();

			res = new ASTInstrAssign(identifier, expr);
		}

		//null if no match
		return (res);
	}

	private ASTInstrIf if_follow() throws Exception
	{
		ASTInstrIf res = null;
		ASTExpr    expr;
		ASTInstr   instr;
		ASTInstrIf follow;

		if (reader.check(Sym.ELIF))
		{
			reader.eat(Sym.ELIF);
			expr = expr();
			reader.eat(Sym.THEN);
			instr  = instruction();
			follow = if_follow();
			res    = new ASTInstrIf(expr, instr, follow);
		}
		else if (reader.check(Sym.ELSE))
		{
			reader.eat(Sym.ELSE);
			instr = instruction();
			res   = new ASTInstrIf(instr);
		}
		return (res);
	}

	private AST instruction_next() throws Exception
	{
		ASTInstr instr;
		AST      next;

		if (reader.isEmpty())
		{
			return (new AST());
		}
		instr = instruction();
		if (instr == null)
		{
			return (new AST());
		}
		reader.eat(Sym.SEMICOLON);
		next = instruction_next();
		return (new AST(instr, next));
	}

	public AST buildProg() throws Exception
	{
		return (instruction_next());
	}

	public void walkThrough() throws Exception
	{
		while (reader.isEmpty() == false)
		{
			System.out.println(reader.walkThrough());
		}
	}

	public boolean reachEnd()
	{
		return (reader.isEmpty());
	}
}
