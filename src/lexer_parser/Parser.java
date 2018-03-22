package src.lexer_parser;

import java.io.*;

public class Parser
{
	protected LookAhead1 reader;

	public Parser(LookAhead1 r) throws IOException
	{
		reader = r;
	}

	private void expr() throws Exception
	{
		if (reader.check(Sym.LPAR))
		{
			reader.eat(Sym.LPAR);
			expr();
			reader.eat(Sym.OPERATOR);
			expr();
			reader.eat(Sym.RPAR);
		}
		else if (reader.check(Sym.NUMBER))
		{
			reader.eat(Sym.NUMBER);
		}
		else if (reader.check(Sym.IDENTIFIER))
		{
			reader.eat(Sym.IDENTIFIER);
		}
		else
		{
			throw new Exception("Expected a expression here");
		}
	}

	// return true if it does something, or false
	private boolean instruction() throws Exception
	{
		// Exec Instruction
		if (reader.check(Sym.DRAWCIRCLE))
		{
			reader.eat(Sym.DRAWCIRCLE);
			reader.eat(Sym.LPAR);
			expr();
			reader.eat(Sym.COMMA);
			expr();
			reader.eat(Sym.COMMA);
			expr();
			reader.eat(Sym.COMMA);
			reader.eat(Sym.COLOR);
			reader.eat(Sym.RPAR);
		}
		else if (reader.check(Sym.FILLCIRCLE))
		{
			reader.eat(Sym.FILLCIRCLE);
			reader.eat(Sym.LPAR);
			expr();
			reader.eat(Sym.COMMA);
			expr();
			reader.eat(Sym.COMMA);
			expr();
			reader.eat(Sym.COMMA);
			reader.eat(Sym.COLOR);
			reader.eat(Sym.RPAR);
		}
		else if (reader.check(Sym.DRAWRECT))
		{
			reader.eat(Sym.DRAWRECT);
			reader.eat(Sym.LPAR);
			expr();
			reader.eat(Sym.COMMA);
			expr();
			reader.eat(Sym.COMMA);
			expr();
			reader.eat(Sym.COMMA);
			expr();
			reader.eat(Sym.COMMA);
			reader.eat(Sym.COLOR);
			reader.eat(Sym.RPAR);
		}
		else if (reader.check(Sym.FILLRECT))
		{
			reader.eat(Sym.FILLRECT);
			reader.eat(Sym.LPAR);
			expr();
			reader.eat(Sym.COMMA);
			expr();
			reader.eat(Sym.COMMA);
			expr();
			reader.eat(Sym.COMMA);
			expr();
			reader.eat(Sym.COMMA);
			reader.eat(Sym.COLOR);
			reader.eat(Sym.RPAR);
		}
		// Control Instruction
		else if (reader.check(Sym.BEGIN))
		{
			reader.eat(Sym.BEGIN);
			instruction_next();
			reader.eat(Sym.END);
		}
		else if (reader.check(Sym.IF))
		{
			reader.eat(Sym.IF);
			if_statement();
		}
		else if (reader.check(Sym.WHILE))
		{
			reader.eat(Sym.WHILE);
			expr();
			reader.eat(Sym.DO);
			instruction();
			reader.eat(Sym.DONE);
		}
		// Imp Instruction
		else if (reader.check(Sym.CONST))
		{
			reader.eat(Sym.CONST);
			reader.eat(Sym.IDENTIFIER);
			reader.eat(Sym.EQUALS);
			expr();
		}
		else if (reader.check(Sym.VAR))
		{
			reader.eat(Sym.VAR);
			reader.eat(Sym.IDENTIFIER);
			reader.eat(Sym.EQUALS);
			expr();
		}
		else if (reader.check(Sym.IDENTIFIER))
		{
			reader.eat(Sym.IDENTIFIER);
			reader.eat(Sym.EQUALS);
			expr();
		}
		else
			return (false);
		return (true);
	}

	private void if_statement() throws Exception
	{
		expr();
		reader.eat(Sym.THEN);
		instruction();
		if_follow();
	}

	private void if_follow() throws Exception
	{
		if (reader.check(Sym.ELIF))
		{
			reader.eat(Sym.ELIF);
			expr();
			reader.eat(Sym.THEN);
			instruction();
			if_follow();
		}
		else if (reader.check(Sym.ELSE))
		{
			reader.eat(Sym.ELSE);
			instruction();
		}
	}

	private void instruction_next() throws Exception
	{
		boolean ret_instruction;

		if (reader.isEmpty())
			return ;
		ret_instruction = instruction();
		if (ret_instruction == false)
			return ;
		reader.eat(Sym.SEMICOLON);
		instruction_next();
	}

	public boolean buildProg() throws Exception
	{
		instruction_next();
		return (true);
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
