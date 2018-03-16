package src.model;

import java.util.ArrayList;

public class Directions
{
	public enum Dir { north, east, west, south, left, right, up, down };

	private ArrayList <Dir> actualsDirs = new ArrayList <Dir>();

	public ArrayList <Dir> getArrayList()
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
