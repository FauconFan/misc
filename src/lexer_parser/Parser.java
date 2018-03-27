package src.lexer_parser;

import java.io.*;
import java.awt.Color;
import java.awt.Point;

import src.lexer_parser.tokens.Token;
import src.lexer_parser.tokens.IdentifierToken;
import src.lexer_parser.tokens.NumberToken;
import src.lexer_parser.tokens.ColorToken;
import src.lexer_parser.tokens.OperatorToken;

import src.ast.AST;
import src.ast.ast_expr.ASTExpr;
import src.ast.ast_expr.ASTExprCalculus;
import src.ast.ast_expr.ASTExprIdentifier;
import src.ast.ast_expr.ASTExprNumber;
import src.ast.ast_instr.ast_instr_exec.ASTInstrExec;
import src.ast.ast_instr.ast_instr_exec.ASTInstrExecDrawCircle;
import src.ast.ast_instr.ast_instr_exec.ASTInstrExecFillCircle;
import src.ast.ast_instr.ast_instr_exec.ASTInstrExecDrawRect;
import src.ast.ast_instr.ast_instr_exec.ASTInstrExecFillRect;
import src.ast.ast_instr.ASTInstr;
import src.ast.ast_instr.ASTInstrIf;
import src.ast.ast_instr.ASTInstrWhile;
import src.ast.ast_instr.ASTInstrDecl;
import src.ast.ast_instr.ASTInstrAssign;
import src.ast.ast_instr.ASTInstrBeginEnd;

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
			res = new ASTExprCalculus(left.begin(), right.end(), left, op, right);
		}
		else if (reader.check(Sym.NUMBER))
		{
			NumberToken nt = (NumberToken)reader.pop(Sym.NUMBER);
			res = new ASTExprNumber(nt.getLocation(), nt.getLocation(), nt.getValue());
		}
		else if (reader.check(Sym.IDENTIFIER))
		{
			IdentifierToken identifier = (IdentifierToken)reader.pop(Sym.IDENTIFIER);
			res = new ASTExprIdentifier(identifier.getLocation(), identifier.getLocation(), identifier.getValue());
		}
		else
		{
			throw new Exception("Expecting an expression line " + reader.getLign() + " at position " + reader.getColumn());
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

			Point begin = reader.pop(Sym.DRAWCIRCLE).getLocation();
			reader.eat(Sym.LPAR);
			args[0] = expr();
			reader.eat(Sym.COMMA);
			args[1] = expr();
			reader.eat(Sym.COMMA);
			args[2] = expr();
			reader.eat(Sym.COMMA);
			colors[0] = ((ColorToken)reader.pop(Sym.COLOR)).getValue();
			Point end = reader.pop(Sym.RPAR).getLocation();

			res = new ASTInstrExecDrawCircle(begin, end, args, colors);
		}
		else if (reader.check(Sym.FILLCIRCLE))
		{
			ASTExpr[] args   = new ASTExpr[3];
			Color[]   colors = new Color[1];

			Point begin = reader.pop(Sym.FILLCIRCLE).getLocation();
			reader.eat(Sym.LPAR);
			args[0] = expr();
			reader.eat(Sym.COMMA);
			args[1] = expr();
			reader.eat(Sym.COMMA);
			args[2] = expr();
			reader.eat(Sym.COMMA);
			colors[0] = ((ColorToken)reader.pop(Sym.COLOR)).getValue();
			Point end = reader.pop(Sym.RPAR).getLocation();

			res = new ASTInstrExecFillCircle(begin, end, args, colors);
		}
		else if (reader.check(Sym.DRAWRECT))
		{
			ASTExpr[] args   = new ASTExpr[4];
			Color[]   colors = new Color[1];

			Point begin = reader.pop(Sym.DRAWRECT).getLocation();
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
			Point end = reader.pop(Sym.RPAR).getLocation();

			res = new ASTInstrExecDrawRect(begin, end, args, colors);
		}
		else if (reader.check(Sym.FILLRECT))
		{
			ASTExpr[] args   = new ASTExpr[4];
			Color[]   colors = new Color[1];

			Point begin = reader.pop(Sym.FILLRECT).getLocation();
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
			Point end = reader.pop(Sym.RPAR).getLocation();

			res = new ASTInstrExecFillRect(begin, end, args, colors);
		}
		// Control Instruction
		else if (reader.check(Sym.BEGIN))
		{
			AST next;

			Point begin = reader.pop(Sym.BEGIN).getLocation();
			next = instruction_next();
			Point end = reader.pop(Sym.END).getLocation();

			res = new ASTInstrBeginEnd(begin, end, next);
		}
		else if (reader.check(Sym.IF))
		{
			ASTExpr    expr;
			ASTInstr   instr;
			ASTInstrIf follow;

			Point begin = reader.pop(Sym.IF).getLocation();
			expr = expr();
			reader.eat(Sym.THEN);
			instr  = instruction();
			follow = if_follow();

			res = new ASTInstrIf(begin, follow.end(), expr, instr, follow);
		}
		else if (reader.check(Sym.WHILE))
		{
			ASTExpr  expr;
			ASTInstr instr;

			Point begin = reader.pop(Sym.WHILE).getLocation();
			expr = expr();
			reader.eat(Sym.DO);
			instr = instruction();
			Point end = reader.pop(Sym.DONE).getLocation();

			res = new ASTInstrWhile(begin, end, expr, instr);
		}
		// Imp Instruction
		else if (reader.check(Sym.CONST))
		{
			String  identifier;
			ASTExpr expr;

			Point begin = reader.pop(Sym.CONST).getLocation();
			identifier = ((IdentifierToken)reader.pop(Sym.IDENTIFIER)).getValue();
			reader.eat(Sym.EQUALS);
			expr = expr();

			res = new ASTInstrDecl(begin, expr.end(), true, identifier, expr);
		}
		else if (reader.check(Sym.VAR))
		{
			String  identifier;
			ASTExpr expr;

			Point begin = reader.pop(Sym.VAR).getLocation();
			identifier = ((IdentifierToken)reader.pop(Sym.IDENTIFIER)).getValue();
			reader.eat(Sym.EQUALS);
			expr = expr();

			res = new ASTInstrDecl(begin, expr.end(), false, identifier, expr);
		}
		else if (reader.check(Sym.IDENTIFIER))
		{
			IdentifierToken identifier;
			ASTExpr         expr;

			identifier = (IdentifierToken)reader.pop(Sym.IDENTIFIER);
			reader.eat(Sym.EQUALS);
			expr = expr();

			res = new ASTInstrAssign(identifier.getLocation(), expr.end(), identifier.getValue(), expr);
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
			Point begin = reader.pop(Sym.ELIF).getLocation();
			expr = expr();
			reader.eat(Sym.THEN);
			instr  = instruction();
			follow = if_follow();
			res    = new ASTInstrIf(begin, follow.end(), expr, instr, follow);
		}
		else if (reader.check(Sym.ELSE))
		{
			Point begin = reader.pop(Sym.ELSE).getLocation();
			instr = instruction();
			res   = new ASTInstrIf(begin, instr == null ? begin : instr.end(), instr);
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
