package src.model.board;

import com.google.gson.*;

import java.lang.Cloneable;
import java.lang.reflect.Type;


/**
 * Case du labyrinthe quelconque. Taille de 1
 */
public abstract class Case implements Cloneable
{
	protected int x;
	protected int y;
	public final TypeCase type;

	public Case(int x, int y, TypeCase t)
	{
		this.x    = x;
		this.y    = y;
		this.type = t;
	}

	/**
	 * Renvoit la position en x de la case
	 * @return Position en x
	 */
	public int getX()
	{
		return (this.x);
	}

	/**
	 * Renvoit la position en y de la case
	 * @return Position en y
	 */
	public int getY()
	{
		return (this.y);
	}

	/**
	 * Renvoit le type de la case
	 * @return TypeCase type
	 */
	public TypeCase getType()
	{
		return (this.type);
	}

	/**
	 * Translate la case de (dx, dy)
	 * @param dx Deplacement en x
	 * @param dy Deplacement en y
	 */
	public void translate(int dx, int dy)
	{
		this.x = this.x + dx;
		this.y = this.y + dy;
	}

	/**
	 * Renvoit une case clone de la case courante
	 * @return Case clonée
	 */
	public abstract Case clone();

	/**
	 * Teste si les coordonnées de la case c sont similaires à la case courante
	 * @param c Case que l'on compare à la case courante
	 * @return True si les coordonnées sont les mêmes
	 */
	public boolean coordsEquals(Case c)
	{
		return (this.x == c.getX() && this.y == c.getY());
	}

	/**
	 * Teste si la case c est la même que la case courante
	 * @param c Case que l'on compare à la case courante
	 * @return True si leurs coordonnées et leurs types sont les mêmes
	 */
	public boolean equals(Case c)
	{
		return (this.type == c.type && this.coordsEquals(c));
	}

	@Override
	public String toString()
	{
		String repX = "x : " + this.x + "\n";
		String repY = "y : " + this.y + "\n";

		return (repX + repY);
	}

	/**
	 * Enumération des différents types de cases
	 */
	public enum TypeCase
	{
		START,
		END,
		TELEPORT,
		SPEED,
		TIME,
		MESSAGE,
		JUMP;
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
