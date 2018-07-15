package fr.jpriou.forty_two.avaj_launcher;

import fr.jpriou.forty_two.avaj_launcher.weather.Coordinates;
import fr.jpriou.forty_two.avaj_launcher.Tower;
import fr.jpriou.forty_two.avaj_launcher.Weather;

public class WeatherTower extends Tower {
    public Weather getWeather(Coordinates coo) {
        int cand = coo.getLongitude() + coo.getLatitude() + coo.getHeight();
        cand %= 4;

        if (cand == 0) {
            return Weather.RAIN;
        }
        else if (cand == 1) {
            return Weather.FOG;
        }
        else if (cand == 2) {
            return Weather.SUN;
        }
        else {
            return Weather.SNOW;
        }
    }

    void changeWeather() {
        super.conditionsChanged();
    }
}
