package src.ast;

import src.prog.SemanticAnalyserException;
import src.prog.SemanticAnalyser;
import src.ast_rep.BlockASTLeaf;

import java.awt.Point;

public abstract class ASTSuperClass implements ASTInterface
{
	private final Point begin;
	private final Point end;

	public ASTSuperClass(Point begin, Point end)
	{
		this.begin = begin;
		this.end = end;
	}

	public Point begin()
	{
		return (begin);
	}

	public Point end()
	{
		return (end);
	}
}
