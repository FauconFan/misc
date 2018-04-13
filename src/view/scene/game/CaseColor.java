package src.view.scene.game;

import java.util.EnumMap;
import java.util.Map;
import javafx.scene.paint.Color;

import src.model.board.Case;

import src.utils.Tuple;

/**
 * Static class for storing the correspondance Case/Color
 */
public final class CaseColor
{
	private static final long serialVersionUID = 354054054055L;

	private static final EnumMap <Case.TypeCase, Tuple <Color, String> > colorCases;

	static
	{
		colorCases = new EnumMap <>(Case.TypeCase.class);
		colorCases.put(Case.TypeCase.START, new Tuple <>(Color.DARKGRAY, "DARKGRAY"));
		colorCases.put(Case.TypeCase.END, new Tuple <>(Color.GREEN, "GREEN"));
		colorCases.put(Case.TypeCase.TELEPORT, new Tuple <>(Color.PURPLE, "PURPLE"));
		colorCases.put(Case.TypeCase.SPEED, new Tuple <>(Color.RED, "RED"));
		colorCases.put(Case.TypeCase.TIME, new Tuple <>(Color.YELLOW, "YELLOW"));
		colorCases.put(Case.TypeCase.MESSAGE, new Tuple <>(Color.TRANSPARENT, "NONE"));
		colorCases.put(Case.TypeCase.JUMP, new Tuple <>(Color.BLUE, "BLUE"));
	}

	public static String prettify()
	{
		String res = "";

		for (Map.Entry <Case.TypeCase, Tuple <Color, String> > entry: colorCases.entrySet())
		{
			res += entry.getKey().toString() + " cells are in " + entry.getValue().getSecond() + "\n";
		}
		return (res);
	}

	public static Color getColor(Case.TypeCase ct)
	{
		return (colorCases.get(ct).getFirst());
	}
}
