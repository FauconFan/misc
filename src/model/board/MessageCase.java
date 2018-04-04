package src.model.board;

import javafx.scene.text.Text;

/**
 * Case du labyrinthe contenant un message 3D
 */
public class MessageCase extends Case
{
	private String msg;

	public MessageCase(int x, int y, String s)
	{
		super(x, y, TypeCase.MESSAGE);
		this.msg = s;
	}

	public MessageCase clone()
	{
		return (new MessageCase(this.x, this.y, this.msg));
	}

	public String getMsg()
	{
		return (this.msg);
	}

	public String toString()
	{
		return ("MessageCase\n" + super.toString() + "Text: " + this.msg);
	}
}
