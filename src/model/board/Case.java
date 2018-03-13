package src.model.board;

import com.google.gson.*;

import java.lang.Cloneable;
import java.lang.reflect.Type;

import src.model.board.LineWall;

/**
 * Case du labyrinthe quelconque.
 */
public abstract class Case implements Cloneable
{
	protected int x;
	protected int y;

	private static float tailleCase = 1;

	public Case(int x, int y)
	{
		this.x = x;
		this.y = y;
	}

	public int getX()
	{
		return (this.x);
	}

	public int getY()
	{
		return (this.y);
	}

	public static float getTailleCase()
	{
		return (tailleCase);
	}

	public void translate(int dx, int dy)
	{
		this.x = this.x + dx;
		this.y = this.y + dy;
	}

	public abstract Case clone();
	public abstract TypeCase getTypeCase();

	public boolean coordsEquals(Case c)
	{
		return (this.x == c.getX() && this.y == c.getY());
	}

	public boolean equals(Case c)
	{
		return (this.getTypeCase() == c.getTypeCase() && this.coordsEquals(c));
	}

	@Override
	public String toString()
	{
		String repX = "x : " + this.x + "\n";
		String repY = "y : " + this.y + "\n";

		return (repX + repY);
	}

	public enum TypeCase
	{
		START,
		END,
		TELEPORT,
		SPEED,
		MECHANISM;
	}

	public static class CaseAdapter implements JsonSerializer <Case>, JsonDeserializer <Case>
	{
		@Override
		public JsonElement serialize(Case cs, Type tp, JsonSerializationContext context)
		{
			JsonObject result = new JsonObject();

			result.add("type", new JsonPrimitive(cs.getClass().getSimpleName()));
			result.add("properties", context.serialize(cs, cs.getClass()));

			return (result);
		}

		@Override
		public Case deserialize(JsonElement json, Type tp, JsonDeserializationContext context)
		{
			JsonObject  object = json.getAsJsonObject();
			String      type   = object.get("type").getAsString();
			JsonElement jele   = object.get("properties");

			try
			{
				return (context.deserialize(jele, Class.forName("src.model.board." + type)));
			}
			catch (Exception e)
			{
				throw new RuntimeException();
			}
		}
	}
}
