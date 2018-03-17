package src.view.scene.game;

import java.util.EnumMap;
import java.util.Map;
import javafx.scene.paint.Color;

import src.model.board.Case;

class CaseColor extends EnumMap <Case.TypeCase, ColorWithName>
{
	private static final long serialVersionUID = 354054054055L;

	public CaseColor()
	{
		super(Case.TypeCase.class);
		put(Case.TypeCase.START, new ColorWithName(Color.BLACK, "BLACK"));
		put(Case.TypeCase.END, new ColorWithName(Color.GREEN, "GREEN"));
		put(Case.TypeCase.TELEPORT, new ColorWithName(Color.PURPLE, "PURPLE"));
		put(Case.TypeCase.SPEED, new ColorWithName(Color.RED, "RED"));
		put(Case.TypeCase.TIME, new ColorWithName(Color.YELLOW, "YELLOW"));
	}

	public String prettify()
	{
		String res = "";

		for (Map.Entry <Case.TypeCase, ColorWithName> entry: entrySet())
		{
			res += entry.getKey().toString() + " cells are in " + entry.getValue().name + "\n";
		}
		return (res);
	}
}
