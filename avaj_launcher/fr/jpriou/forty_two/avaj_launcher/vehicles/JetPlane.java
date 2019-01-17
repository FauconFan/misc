package fr.jpriou.forty_two.avaj_launcher.vehicles;

import fr.jpriou.forty_two.avaj_launcher.weather.Coordinates;
import fr.jpriou.forty_two.avaj_launcher.WeatherTower;

class JetPlane extends Aircraft implements Flyable
{
	private WeatherTower weatherTower;

	JetPlane(String name, Coordinates coordinates)
	{
		super(name, coordinates);
	}

	public String _getType()
	{
		return (super._JETPLANE);
	}

	public void updateConditions()
	{
		String  message = "";
		boolean landing = false;

		switch (this.weatherTower.getWeather(this.coordinates))
		{
		case SUN:
			message = "Nothing in the horizon, let's go !";
			this.coordinates.increaseLatitude(10);
			landing = this.coordinates.increaseHeight(2);
			break;

		case RAIN:
			message = "It's raining... Let's slow down.";
			this.coordinates.increaseLatitude(5);
			break;

		case FOG:
			message = "We don't see anything, slowing... jetbrained :)";
			this.coordinates.increaseLatitude(1);
			break;

		case SNOW:
			message = "JetSnowed...";
			landing = this.coordinates.increaseHeight(-7);
			break;
		}
		super._logChangingWeather(message);
		if (landing)
		{
			this.weatherTower.unregister(this);
		}
	}

	public void registerTower(WeatherTower weatherTower)
	{
		this.weatherTower = weatherTower;
		this.weatherTower.register(this);
	}
}
