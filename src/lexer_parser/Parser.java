package src.lexer_parser;

import java.io.*;
import java.awt.Color;
import java.awt.Point;

import src.lexer_parser.tokens.Token;
import src.lexer_parser.tokens.IdentifierToken;
import src.lexer_parser.tokens.NumberToken;
import src.lexer_parser.tokens.ColorToken;
import src.lexer_parser.tokens.OperatorToken;
import src.lexer_parser.tokens.BoolOpToken;
import src.lexer_parser.tokens.CompareOpToken;

import src.ast.AST;
import src.ast.ast_expr.*;
import src.ast.ast_instr.ast_instr_exec.*;
import src.ast.ast_instr.*;
import src.ast.ast_bool.*;

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
		// System Instruction
		else if (reader.check(Sym.EXIT))
		{
			ASTExpr expr;

			Point begin = reader.pop(Sym.EXIT).getLocation();
			reader.eat(Sym.LPAR);
			expr = expr();
			Point end = reader.pop(Sym.RPAR).getLocation();

			res = new ASTInstrSysExit(begin, end, expr);
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
			ASTBool    expr;
			ASTInstr   instr;
			ASTInstrIf follow;

			Point begin = reader.pop(Sym.IF).getLocation();
			expr = bool();
			reader.eat(Sym.THEN);
			instr  = instruction();
			follow = if_follow();

			res = new ASTInstrIf(begin, follow.end(), expr, instr, follow);
		}
		else if (reader.check(Sym.WHILE))
		{
			ASTBool  expr;
			ASTInstr instr;

			Point begin = reader.pop(Sym.WHILE).getLocation();
			expr = bool();
			reader.eat(Sym.DO);
			instr = instruction();

			res = new ASTInstrWhile(begin, instr.end(), expr, instr);
		}
		else if (reader.check(Sym.FOR))
		{
			ASTInstr first;
			ASTBool  condition;
			ASTInstr eachLoop;
			ASTInstr content;

			Point begin = reader.pop(Sym.FOR).getLocation();
			reader.eat(Sym.LPAR);
			first = instruction();
			reader.eat(Sym.SEMICOLON);
			condition = bool();
			reader.eat(Sym.SEMICOLON);
			eachLoop = instruction();
			reader.eat(Sym.RPAR);
			reader.eat(Sym.THEN);
			content = instruction();

			res = new ASTInstrFor(begin, content.end(), first, condition, eachLoop, content);
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
		ASTBool    expr;
		ASTInstr   instr;
		ASTInstrIf follow;

		if (reader.check(Sym.ELIF))
		{
			Point begin = reader.pop(Sym.ELIF).getLocation();
			expr = bool();
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

	private ASTBool bool () throws Exception{
		if (reader.check(Sym.TRUE)){
			Token t = reader.pop(Sym.TRUE);
			return new ASTBoolValue(t.getLocation(), t.getLocation(), true);
		}else if (reader.check(Sym.FALSE)) {
			Token t = reader.pop(Sym.FALSE);
			return new ASTBoolValue(t.getLocation(), t.getLocation(), false);
		}else if (reader.check(Sym.LBRA)){
			Point begin 	= reader.pop(Sym.LBRA).getLocation();

			ASTExpr leftNum = null;
			ASTBool leftBoo = null;
			if (reader.check(Sym.NUMBER) || reader.check(Sym.LPAR) || reader.check(Sym.IDENTIFIER))
				leftNum = expr();
			else
				leftBoo = bool();

			if (reader.check(Sym.BOOLOP)){
				String op = ((BoolOpToken)reader.pop(Sym.BOOLOP)).getOp();
				ASTBool left    = leftNum == null ? leftBoo : new ASTBoolNumber(leftNum.begin(), leftNum.end(), leftNum);
				ASTBool right   = bool();
				Point end   	= reader.pop(Sym.RBRA).getLocation();
				return new ASTBoolOp(begin, end, left, op, right);
			}else{
				if (leftNum == null)
					throw new Exception("Expecting a boolean expression line " + reader.getLign() + " at position " + reader.getColumn());
				String op       = ((CompareOpToken)reader.pop(Sym.COMPAREOP)).getOp();
				ASTExpr right   = expr();
				Point end   	= reader.pop(Sym.RBRA).getLocation();
				return new ASTBoolNumberIneq(begin, end, leftNum, op, right);
			}
		}else if (reader.check(Sym.LPAR) || reader.check(Sym.NUMBER) || reader.check(Sym.IDENTIFIER)) {
			ASTExpr expr = expr();
			return new ASTBoolNumber(expr.begin(), expr.end(), expr);
		}else
			throw new Exception("Expecting a boolean expression line " + reader.getLign() + " at position " + reader.getColumn());
	}

	public AST buildProg() throws Exception
	{
		AST builtProg;

		builtProg = instruction_next();
		if (reader.isEmpty() == false)
		{
			throw new Exception("Token not expected, not handled everywhere...");
		}
		return (builtProg);
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
