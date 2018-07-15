package fr.jpriou.forty_two.avaj_launcher;

import java.util.ArrayList;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public final class Logger {
    private static String pathLog = "./log.txt";
    private static ArrayList<String> contentLog = new ArrayList<>();

    public static void changeLogoutFile(String p) {
        Logger.pathLog = p;
    }

    public static void write(String line) {
        Logger.contentLog.add(line);
    }

    public static void finish() {
        File file = new File(Logger.pathLog);
        FileWriter fr = null;
        String data = "";
        for (String line : contentLog) {
            data += line + "\n";
        }
        try {
            fr = new FileWriter(file);
            fr.write(data);
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                fr.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
