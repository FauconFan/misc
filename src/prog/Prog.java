package src.prog;

import java.util.HashMap;
import java.awt.Graphics2D;
import src.ast.AST;
import src.prog.SemanticAnalyser;

public class Prog
{
	private AST ast;
	private Graphics2D g2d;
	private HashMap <Integer, HashMap <String, AccessData> > registre;
	private int current_depth;

	public Prog(AST ast, Graphics2D g2d)
	{
		this.ast           = ast;
		this.g2d           = g2d;
		this.registre      = new HashMap <>();
		this.current_depth = 0;

		this.registre.put(0, new HashMap <>());
	}

	public void exec()
	{
		ast.exec(this);
	}

	public Graphics2D getGraphics()
	{
		return (this.g2d);
	}

	public void incremente()
	{
		this.current_depth++;
		this.registre.put(this.current_depth, new HashMap <>());
	}

	public void decremente()
	{
		this.registre.remove(this.current_depth);
		this.current_depth--;
	}

	public int getData(String identifier)
	{
		for (int i = this.current_depth; i >= 0; i--)
		{
			AccessData ad = this.registre.get(i).get(identifier);
			if (ad == null)
			{
				continue;
			}
			return (ad.getValue());
		}
		throw new RuntimeException("variable " + identifier + " does not exist");
	}

	public void setData(String identifier, int value)
	{
		for (int i = this.current_depth; i >= 0; i--)
		{
			AccessData ad = this.registre.get(i).get(identifier);
			if (ad == null)
			{
				continue;
			}
			if (!ad.setValue(value))
				throw new RuntimeException("cannot change value of the constant " + identifier);
			return;
		}
		throw new RuntimeException("variable " + identifier + " does not exist");
	}

	// addData doesn't check if the variable already exist
	// we have checked it before in semantic analyser
	// shall we ?
	public void addData(String identifier, int value, boolean is_cst)
	{
		HashMap <String, AccessData> current_registre;

		current_registre = this.registre.get(this.current_depth);
		current_registre.put(identifier, new AccessData(is_cst, value));
	}

	public static class AccessData
	{
		private final boolean is_cst;
		private int value;

		public AccessData(boolean is_cst, int value)
		{
			this.is_cst = is_cst;
			this.value  = value;
		}

		public int getValue()
		{
			return (this.value);
		}

		public boolean isSettable()
		{
			return (this.is_cst == false);
		}

		public boolean setValue(int value)
		{
			if (!is_cst)
				this.value = value;
			return !is_cst;
		}
	}
}
