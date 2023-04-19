import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.URL;
import org.json.JSONArray;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) {
        try {
            //Test działania lokalnego REST API
            String temp_url = "http://localhost/IS_LAB6_REST/cities/read";
            URL url = new URL(temp_url);
            System.out.println("Wysyłanie zapytania...");

            InputStream is = url.openStream();

            System.out.println("Pobieranie odpowiedzi...");

            String source = new BufferedReader(new InputStreamReader(is)).lines().collect(Collectors.joining("\n"));
            System.out.println("Przetwarzanie danych...");
            JSONObject json = new JSONObject(source);
            JSONArray recieveddata = (JSONArray)json.get("cities");
            List<City> cities = new ArrayList<City>();
            for (int i=0; i < recieveddata.length(); i++) {
                cities.add(new City(recieveddata.getJSONObject(i).get("Name").toString(), recieveddata.getJSONObject(i).get("CountryCode").toString(),
                        recieveddata.getJSONObject(i).get("District").toString(), recieveddata.getJSONObject(i).get("Population").toString()));
            }
            show(cities);
        } catch (Exception e) {
            System.err.println("Wystąpił nieoczekiwany błąd!!! ");
            e.printStackTrace(System.err);
        }
    }

    public static void show(List<City> cities) {
        for (City city : cities) {
            System.out.println("City name: " + city.getName() +
                    " Country Code: " + city.getCountryCode() +
                    " District: " + city.getDistrict() +
                    " Population: " + city.getPopulation());
        }
    }
}