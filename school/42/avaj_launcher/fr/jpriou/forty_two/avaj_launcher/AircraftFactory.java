package fr.jpriou.forty_two.avaj_launcher;

import fr.jpriou.forty_two.avaj_launcher.Aircraft;
import fr.jpriou.forty_two.avaj_launcher.Flyable;
import fr.jpriou.forty_two.avaj_launcher.Coordinates;

import java.lang.Exception;

public class AircraftFactory
{
	public static Flyable newAircraft(
							String type,
							String name,
							int longitude,
							int latitude,
							int height)
	{
		Coordinates coo = new Coordinates(longitude, latitude, height);

		switch (type)
		{
		case Aircraft._HELICOPTER:
			return (new Helicopter(name, coo));

		case Aircraft._JETPLANE:
			return (new JetPlane(name, coo));

		case Aircraft._BALOON:
			return (new Baloon(name, coo));

		default:
			return (null);
		}
	}
}
