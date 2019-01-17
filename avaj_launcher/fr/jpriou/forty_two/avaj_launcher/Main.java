package fr.jpriou.forty_two.avaj_launcher;

import fr.jpriou.forty_two.avaj_launcher.Logger;
import fr.jpriou.forty_two.avaj_launcher.vehicles.AircraftFactory;
import fr.jpriou.forty_two.avaj_launcher.vehicles.Flyable;
import fr.jpriou.forty_two.avaj_launcher.WeatherTower;

import java.io.IOException;
import java.lang.NumberFormatException;
import java.nio.file.Files;
import java.nio.file.InvalidPathException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;

class Main
{
	public static List <String> loadEntry(String pathString)
	{
		try {
			Path path = Paths.get(pathString);
			return (Files.readAllLines(path));
		}
		catch (InvalidPathException e) {
			System.err.println("The path given is not a path file : " + pathString);
			System.err.println(e.getMessage());
		}
		catch (IOException ioe) {
			System.err.println("Something went wrong when reading");
			System.err.println(ioe.getMessage());
		}
		catch (Exception e) {
			System.err.println(e.getMessage());
		}
		System.exit(1);
		return (null);
	}

	public static int loadNbSimulation(String firstLine)
	{
		int ret = 0;

		try {
			ret = Integer.parseInt(firstLine, 10);
		}
		catch (NumberFormatException nfe) {
			System.err.println("Wrong format number in first line");
			System.err.println(nfe.getMessage());
			System.exit(1);
		}
		if (ret < 0)
		{
			System.err.println("Number of simulations can't be negaitve...");
			System.exit(1);
		}
		return (ret);
	}

	public static Flyable[] loadFlyables(String[] contentFile)
	{
		Flyable[] flyables = new Flyable[contentFile.length - 1];
		for (int i = 1; i < contentFile.length; i++)
		{
			String[] splittedLine = contentFile[i].split(" ");
			if (splittedLine.length != 5)
			{
				System.err.println("Each line must be formatted like the following : ");
				System.err.println("[TYPE] [NAME] [LONG] [LAT] [HEIGHT]");
				System.err.println("\t-> line number " + (i + 1) + ": \"" + contentFile[i] + "\"");
				System.exit(1);
			}
			int longitude = 0;
			int latitude  = 0;
			int height    = 0;
			try {
				longitude = Integer.parseInt(splittedLine[2], 10);
				latitude  = Integer.parseInt(splittedLine[3], 10);
				height    = Integer.parseInt(splittedLine[4], 10);
			}
			catch (NumberFormatException nfe) {
				System.err.println(nfe.getMessage());
				System.err.println("\t-> line number " + (i + 1) + ": \"" + contentFile[i] + "\"");
				System.exit(1);
			}
			if (longitude < 0 || latitude < 0 || height < 0)
			{
				System.err.println("Coordinates can be negative...");
				System.err.println("\t-> line number " + (i + 1) + ": \"" + contentFile[i] + "\"");
				System.exit(1);
			}
			if (height > 100)
			{
				System.err.println("Height can't be greater than 100, taking it back to 100");
				System.err.println("\t-> line number " + (i + 1) + ": \"" + contentFile[i] + "\"");
				height = 100;
			}
			Flyable candidate = AircraftFactory.newAircraft(splittedLine[0], splittedLine[1], longitude, latitude, height);
			if (candidate == null)
			{
				System.err.println("'" + splittedLine[0] + "' is unknown...");
				System.err.println("\t-> line number " + (i + 1) + ": \"" + contentFile[i] + "\"");
				System.exit(1);
			}
			flyables[i - 1] = candidate;
		}
		return (flyables);
	}

	public static void main(String[] args)
	{
		if (args.length != 1)
		{
			System.err.println("Launch this simulation with a single argument");
			System.exit(1);
		}
		String[]     contentFile   = loadEntry(args[0]).toArray(new String[0]);
		int          nb_simulation = loadNbSimulation(contentFile[0]);
		Flyable[]    flyables      = loadFlyables(contentFile);
		WeatherTower weatherTower  = new WeatherTower();

		Logger.changeLogoutFile(args[0] + ".log");

		for (Flyable flyable : flyables)
		{
			flyable.registerTower(weatherTower);
		}

		for (int i = 0; i < nb_simulation; i++)
		{
			Logger.write("Turn number n° " + (i + 1));
			weatherTower.changeWeather();
		}

		Logger.finish();
	}
}
