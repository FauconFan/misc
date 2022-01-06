package fr.jpriou.forty_two.avaj_launcher;

import fr.jpriou.forty_two.avaj_launcher.Tower;
import fr.jpriou.forty_two.avaj_launcher.Coordinates;
import fr.jpriou.forty_two.avaj_launcher.Weather;
import fr.jpriou.forty_two.avaj_launcher.WeatherProvider;

public class WeatherTower extends Tower
{
	public Weather getWeather(Coordinates coo)
	{
		return (WeatherProvider.getWeatherProvider().getCurrentWeather(coo));
	}

	void changeWeather()
	{
		super.conditionsChanged();
	}
}
