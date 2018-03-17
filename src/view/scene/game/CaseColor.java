package src.view.scene.game;

import java.util.EnumMap;
import javafx.scene.paint.Color;

import src.model.board.Case;

class CaseColor extends EnumMap <Case.TypeCase, Color>
{
	private static final long serialVersionUID = 354054054055L;

	public CaseColor()
	{
		super(Case.TypeCase.class);
		put(Case.TypeCase.START, Color.BLACK);
		put(Case.TypeCase.END, Color.GREEN);
		put(Case.TypeCase.TELEPORT, Color.PURPLE);
		put(Case.TypeCase.SPEED, Color.RED);
		put(Case.TypeCase.TIME, Color.YELLOW);
	}
}
