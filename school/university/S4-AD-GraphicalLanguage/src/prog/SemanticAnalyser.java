package src.prog;

import java.util.HashMap;
import java.util.ArrayList;

import src.ast.AST;

public class SemanticAnalyser
{
	private HashMap <Integer, ArrayList <AccessDataTmp> > registre_verify;
	private int current_depth;

	public SemanticAnalyser()
	{
		this.registre_verify = new HashMap <>();
		this.current_depth   = 0;

		this.registre_verify.put(0, new ArrayList <>());
	}

	public void checkAST(AST ast) throws SemanticAnalyserException
	{
		ast.checkSemantic(this);
	}

	public void incremente()
	{
		this.current_depth++;
		this.registre_verify.put(this.current_depth, new ArrayList <>());
	}

	public void decremente()
	{
		this.registre_verify.remove(this.current_depth);
		this.current_depth--;
	}

	public void can_access_var_in_registre(String identifier) throws SemanticAnalyserException
	{
		for (int i = this.current_depth; i >= 0; i--)
		{
			ArrayList <AccessDataTmp> registre_i;

			registre_i = this.registre_verify.get(i);
			for (AccessDataTmp adt : registre_i)
			{
				if (adt.getIdentifier().equals(identifier))
				{
					return;
				}
			}
		}
		throw new SemanticAnalyserException("variable " + identifier + " doesn't exist");
	}

	public void can_modify_var_in_registre(String identifier) throws SemanticAnalyserException
	{
		for (int i = this.current_depth; i >= 0; i--)
		{
			ArrayList <AccessDataTmp> registre_i;

			registre_i = this.registre_verify.get(i);
			for (AccessDataTmp adt : registre_i)
			{
				if (adt.getIdentifier().equals(identifier))
				{
					if (adt.is_cst())
					{
						throw new SemanticAnalyserException("cannot modify the constant " + identifier);
					}
					return;
				}
			}
		}
		throw new SemanticAnalyserException("variable " + identifier + " doesn't exist");
	}

	public void add_in_registre(String identifier, boolean is_cst) throws SemanticAnalyserException
	{
		ArrayList <AccessDataTmp> registre_last;

		registre_last = this.registre_verify.get(this.current_depth);
		for (AccessDataTmp adt : registre_last)
		{
			if (adt.getIdentifier().equals(identifier))
			{
				throw new SemanticAnalyserException("variable " + identifier + " already exists");
			}
		}
		this.registre_verify.get(this.current_depth).add(new AccessDataTmp(is_cst, identifier));
		// describe();
	}

	public void describe()
	{
		for (int i = 0; i <= this.current_depth; i++)
		{
			ArrayList <AccessDataTmp> list_i;

			list_i = this.registre_verify.get(i);
			System.out.print("[");
			for (AccessDataTmp adt : list_i)
			{
				System.out.print(adt + " ");
			}
			System.out.println("]");
		}
	}

	private static class AccessDataTmp
	{
		private final boolean is_cst;
		private final String identifier;

		public AccessDataTmp(boolean is_cst, String identifier)
		{
			this.is_cst     = is_cst;
			this.identifier = identifier;
		}

		public boolean is_cst()
		{
			return (this.is_cst);
		}

		public String getIdentifier()
		{
			return (this.identifier);
		}

		public String toString()
		{
			return (this.identifier + " " + (is_cst ? 'C' : 'N'));
		}
	}
}
