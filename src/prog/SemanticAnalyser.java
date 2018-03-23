package src.prog;

import java.util.HashMap;
import java.util.ArrayList;

import src.ast.AST;

public class SemanticAnalyser
{
	private HashMap <Integer, ArrayList<AccessDataTmp>> registre_verify;
	private int current_depth;

	public SemanticAnalyser()
	{
		this.registre_verify = new HashMap<>();
		this.current_depth = 0;

		this.registre_verify.put(0, new ArrayList<>());
	}

	public void checkAST(AST ast) throws SemanticAnalyserException
	{
		ast.checkSemantic(this);
	}

	public void incremente()
	{
		this.current_depth++;
		this.registre_verify.put(this.current_depth, new ArrayList<>());
	}

	public void decremente()
	{
		this.registre_verify.remove(this.current_depth);
		this.current_depth--;
	}

	private boolean is_present_in_registre(String identifier, boolean need_to_modify) throws SemanticAnalyserException
	{
		for (int i = 0; i <= this.current_depth; i++)
		{
			ArrayList <AccessDataTmp> registre_i;

			registre_i = this.registre_verify.get(i);
			for (AccessDataTmp adt : registre_i)
			{
				if (adt.getIdentifier().equals(identifier))
				{
					if (need_to_modify == true && adt.is_cst() == true)
						throw new SemanticAnalyserException("Modifying constant " + identifier);
					return (true);
				}
			}
		}
		return (false);
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

	public void verify_if_present_in_registre(String identifier, boolean need_to_modify) throws SemanticAnalyserException
	{
		if (is_present_in_registre(identifier, need_to_modify) == false)
		{
			throw new SemanticAnalyserException("Identifier " + identifier + " doesn't exist");
		}
	}

	public void verify_if_not_present_in_registre(String identifier) throws SemanticAnalyserException
	{
		if (is_present_in_registre(identifier, false))
		{
			throw new SemanticAnalyserException("Identifier " + identifier + " does exist");
		}
	}

	public void add_in_registre(String identifier, boolean is_cst) throws SemanticAnalyserException
	{
		if (is_present_in_registre(identifier, false))
		{
			throw new SemanticAnalyserException("Identifier " + identifier + " is already used");
		}
		this.registre_verify.get(this.current_depth).add(new AccessDataTmp(is_cst, identifier));
		describe();
	}

	private static class AccessDataTmp
	{
		private final boolean is_cst;
		private final String identifier;

		public AccessDataTmp(boolean is_cst, String identifier)
		{
			this.is_cst = is_cst;
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