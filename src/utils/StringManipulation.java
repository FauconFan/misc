package src.utils;

/**
 * String utils to display well some information in the Terminal
 */
public class StringManipulation
{
	public static String makeTabsProperly(String text)
	{
		boolean endWithNL;

		if (text == null)
		{
			return (null);
		}
		if (text.length() == 0)
		{
			return ("\t");
		}
		endWithNL = (text.charAt(text.length() - 1) == '\n');
		if (endWithNL)
		{
			text = text.substring(0, text.length() - 1);
		}
		text = text.replaceAll("\n", "\n\t");
		text = "\t" + text;
		if (endWithNL)
		{
			text = text + "\n";
		}
		return (text);
	}
}
