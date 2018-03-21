package src;

import java.io.*;

class Parser
{
	protected LookAhead1 reader;

	public Parser(LookAhead1 r) throws IOException
	{
		reader = r;
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
