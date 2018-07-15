package fr.jpriou.forty_two.avaj_launcher.vehicles;

import fr.jpriou.forty_two.avaj_launcher.WeatherTower;
import fr.jpriou.forty_two.avaj_launcher.weather.Coordinates;

class Baloon extends Aircraft implements Flyable {
    private WeatherTower weatherTower;

    Baloon(String name, Coordinates coordinates) {
        super(name, coordinates);
    }

    public String _getType() {
        return super._BALOON;
    }

    public void updateConditions() {
        String message = "";
        boolean landing = false;

        switch (this.weatherTower.getWeather(this.coordinates)) {
            case SUN:
                message = "Sunny Baloon !";
                this.coordinates.increaseLongitude(2);
                landing = this.coordinates.increaseHeight(4);
                break;
            case RAIN:
                message = "It's raining... Baloon down...";
                landing = this.coordinates.increaseHeight(-5);
                break;
            case FOG:
                message = "We're blind. Baloon down...";
                landing = this.coordinates.increaseHeight(-3);
                break;
            case SNOW:
                message = "Frooooooozen. Baloon doooooown....";
                landing = this.coordinates.increaseHeight(-15);
                break;
        }
        super._logChangingWeather(message);
        if (landing) {
            this.weatherTower.unregister(this);
        }
    }

    public void registerTower(WeatherTower weatherTower) {
        this.weatherTower = weatherTower;
        this.weatherTower.register(this);
    }
}
