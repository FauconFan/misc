package fr.jpriou.forty_two.avaj_launcher;

public class Coordinates
{
	private int longitude;
	private int latitude;
	private int height;

	Coordinates(int longitude, int latitude, int height)
	{
		this.longitude = longitude;
		this.latitude  = latitude;
		this.height    = height;
	}

	public int getLongitude() { return (this.longitude); }
	public int getLatitude() { return (this.latitude); }
	public int getHeight() { return (this.height); }

	public void increaseLongitude(int delta)
	{
		this.longitude += delta;
		if (this.longitude < 0)
		{
			this.longitude = 0;
		}
	}

	public void increaseLatitude(int delta)
	{
		this.latitude += delta;
		if (this.latitude < 0)
		{
			this.latitude = 0;
		}
	}

	public boolean increaseHeight(int delta)
	{
		this.height += delta;
		if (this.height > 100)
		{
			this.height = 100;
		}
		else if (this.height < 0)
		{
			this.height = 0;
			return (true);
		}
		return (false);
	}
}
