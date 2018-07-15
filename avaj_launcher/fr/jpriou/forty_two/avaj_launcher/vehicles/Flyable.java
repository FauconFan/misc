package fr.jpriou.forty_two.avaj_launcher.vehicles;

import fr.jpriou.forty_two.avaj_launcher.WeatherTower;

public interface Flyable {
    void updateConditions();
    void registerTower(WeatherTower wt);
}
