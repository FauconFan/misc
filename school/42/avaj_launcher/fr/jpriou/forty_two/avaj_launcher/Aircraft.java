package fr.jpriou.forty_two.avaj_launcher;

import fr.jpriou.forty_two.avaj_launcher.Logger;
import fr.jpriou.forty_two.avaj_launcher.Coordinates;

public abstract class Aircraft
{
	protected long id;
	protected String name;
	protected Coordinates coordinates;

	private static long idCounter = 0;

	public static final String _BALOON     = "Baloon";
	public static final String _HELICOPTER = "Helicopter";
	public static final String _JETPLANE   = "JetPlane";

	public abstract String _getType();

	protected Aircraft(String name, Coordinates coordinates)
	{
		this.id          = nextId();
		this.name        = name;
		this.coordinates = coordinates;
	}

	private long nextId()
	{
		Aircraft.idCounter++;
		return (Aircraft.idCounter - 1);
	}

	public String _buildPrefixLogger()
	{
		return (this._getType() + "#" + this.name + "(" + this.id + ")");
	}

	public void _logChangingWeather(String msg)
	{
		String line = "";

		line += this._buildPrefixLogger();
		line += ": " + msg;
		Logger.write(line);
	}
}
