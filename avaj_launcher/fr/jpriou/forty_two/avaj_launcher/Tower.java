package fr.jpriou.forty_two.avaj_launcher;

import java.util.ArrayList;

import fr.jpriou.forty_two.avaj_launcher.vehicles.Aircraft;
import fr.jpriou.forty_two.avaj_launcher.vehicles.Flyable;
import fr.jpriou.forty_two.avaj_launcher.Logger;

public abstract class Tower {
    private ArrayList<Flyable> observers = new ArrayList<>();

    public void register(Flyable fl) {
        this.observers.add(fl);
        Logger.write("Tower says: " +
                    ((Aircraft)fl)._buildPrefixLogger() +
                    " registered to weather tower.");
    }

    public void unregister(Flyable fl) {
        this.observers.remove(fl);
        Logger.write("Tower says: " +
                    ((Aircraft)fl)._buildPrefixLogger() +
                    " unregistered from weather tower.");
    }

    protected void conditionsChanged() {
        int sizeActu = observers.size();
        int i = 0;
        while (i < observers.size()) {
            Flyable flyable = observers.get(i);
            flyable.updateConditions();
            if (observers.size() == sizeActu) {
                i++;
            }
            else {
                sizeActu = observers.size();
            }
        }
    }
}
