package src.model;

import java.util.HashSet;

public class Directions
{
	public enum Dir { north, east, west, south, goUp, goDown, left, right, up, down };

	private HashSet <Dir> actualsDirs = new HashSet <Dir>();

	public HashSet <Dir> getHashSet()
	{
		return (actualsDirs);
	}

	public void add(Dir d)
	{
		actualsDirs.add(d);
	}

	public void remove(Dir d)
	{
		actualsDirs.remove(d);
	}
}
