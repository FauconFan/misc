package fr.jpriou.forty_two.avaj_launcher;

import fr.jpriou.forty_two.avaj_launcher.WeatherTower;

public interface Flyable
{
	public void updateConditions();
	public void registerTower(WeatherTower wt);
}
