package fr.jpriou.forty_two.avaj_launcher.vehicles;

import fr.jpriou.forty_two.avaj_launcher.weather.Coordinates;
import fr.jpriou.forty_two.avaj_launcher.WeatherTower;

class Helicopter extends Aircraft implements Flyable
{
	private WeatherTower weatherTower;

	Helicopter(String name, Coordinates coordinates)
	{
		super(name, coordinates);
	}

	public String _getType()
	{
		return (super._HELICOPTER);
	}

	public void updateConditions()
	{
		String  message = "";
		boolean landing = false;

		switch (this.weatherTower.getWeather(this.coordinates))
		{
		case SUN:
			message = "Skywalking today !!";
			this.coordinates.increaseLongitude(10);
			landing = this.coordinates.increaseHeight(2);
			break;

		case RAIN:
			message = "It's raining... Let's go !";
			this.coordinates.increaseLongitude(5);
			break;

		case FOG:
			message = "We don't see anything, still SKYWALKING !";
			this.coordinates.increaseLongitude(1);
			break;

		case SNOW:
			message = "Ah, we are going down deep !!";
			landing = this.coordinates.increaseHeight(-10);
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
