package fr.jpriou.forty_two.avaj_launcher;

import java.util.ArrayList;

import fr.jpriou.forty_two.avaj_launcher.Logger;
import fr.jpriou.forty_two.avaj_launcher.Aircraft;
import fr.jpriou.forty_two.avaj_launcher.Flyable;

public abstract class Tower
{
	private ArrayList <Flyable> observers = new ArrayList <>();

	public void register(Flyable fl)
	{
		this.observers.add(fl);
		Logger.write("Tower says: " +
					 ((Aircraft)fl)._buildPrefixLogger() +
					 " registered to weather tower.");
	}

	public void unregister(Flyable fl)
	{
		this.observers.remove(fl);
		Logger.write("Tower says: " +
					 ((Aircraft)fl)._buildPrefixLogger() +
					 " unregistered from weather tower.");
	}

	/*
	**	We have to change this part if we want to register a flyable object
	**	during execution.
	**	For now, the conditionsChanged function just adapt when a flyable object
	**	get removed from the observers Arraylist attribute.
	*/

	protected void conditionsChanged()
	{
		int sizeActu = observers.size();
		int i        = 0;

		while (i < observers.size())
		{
			Flyable flyable = observers.get(i);
			flyable.updateConditions();
			if (observers.size() == sizeActu)
			{
				i++;
			}
			else
			{
				sizeActu = observers.size();
			}
		}
	}
}
