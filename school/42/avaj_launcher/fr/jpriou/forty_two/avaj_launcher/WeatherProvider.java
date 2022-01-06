package fr.jpriou.forty_two.avaj_launcher;

import java.util.Random;

/*
**	WeatherProvider is a singleton class.
**
**	usecase: WeatherProvider.getWeatherProvider().getCurrentWeather(coo);
*/

public class WeatherProvider
{
	private static WeatherProvider weatherProvider = new WeatherProvider();

	public static WeatherProvider getWeatherProvider()
	{
		return (WeatherProvider.weatherProvider);
	}

	private WeatherProvider() {}

	public Weather getCurrentWeather(Coordinates coo)
	{
		int		cand;
		Random	rand;

		rand = new Random();
		cand = coo.getLongitude() + coo.getLatitude() + coo.getHeight();
		cand += rand.nextInt();
		cand %= 4;

		if (cand == 0)
			return (Weather.RAIN);
		else if (cand == 1)
			return (Weather.FOG);
		else if (cand == 2)
			return (Weather.SUN);
		return (Weather.SNOW);
	}
}
