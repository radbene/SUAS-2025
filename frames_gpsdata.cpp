#include <iostream>
#include <fstream>
#include <string>
#include "pugixml.hpp" // Dołączamy nagłówek biblioteki PugiXML

int main() {
    // Nazwy plików wejściowego i wyjściowego
    const char* gpxFileName = "/home/radek/Desktop/SUAS_2025/C++_Projects/SUAS_2025/GX010064.gpx";
    const char* outputFileName = "parsed_data.txt";

    // 1. Wczytanie dokumentu XML
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(gpxFileName);

    // Sprawdzenie, czy plik został poprawnie wczytany i sparsowany
    if (!result) {
        std::cerr << "Blad podczas wczytywania pliku " << gpxFileName << "!" << std::endl;
        std::cerr << "Opis bledu: " << result.description() << std::endl;
        return 1; // Zakończ program z kodem błędu
    }
    
    // 2. Otworzenie pliku do zapisu wyników
    std::ofstream outFile(outputFileName);
    if (!outFile.is_open()) {
        std::cerr << "Nie mozna otworzyc pliku do zapisu: " << outputFileName << std::endl;
        return 1;
    }

    // 3. Przetwarzanie danych
    int frameCounter = 30; // Inicjalizujemy licznik klatek
    
    // Nawigujemy po strukturze GPX: gpx -> trk -> trkseg
    pugi::xml_node trackSegment = doc.child("gpx").child("trk").child("trkseg");

    // Iterujemy po wszystkich punktach trasy (<trkpt>) wewnątrz segmentu
    for (pugi::xml_node trackPoint : trackSegment.children("trkpt")) {
        // Ekstrakcja atrybutów 'lat' i 'lon'
        std::string lat = trackPoint.attribute("lat").as_string("Brak danych");
        std::string lon = trackPoint.attribute("lon").as_string("Brak danych");
        
        // Ekstrakcja wartości z tagów potomnych ('ele' i 'time')
        // uzywamy .child_value(), ktory zwraca pusty string, jesli tag nie istnieje
        std::string ele = trackPoint.child_value("ele");
        std::string time = trackPoint.child_value("time");

        // Zabezpieczenie na wypadek braku danych (jak w pierwszym punkcie w Twoim pliku)
        if (ele.empty()) {
            ele = "Brak danych";
        }
        if (time.empty()) {
            time = "Brak danych";
        }

        // 4. Zapis sformatowanych danych do pliku
        outFile << "frame" << frameCounter << ":\n";
        outFile << "  lat: " << lat << "\n";
        outFile << "  lon: " << lon << "\n";
        outFile << "  ele: " << ele << " m\n";
        outFile << "  time: " << time << "\n\n";

        // Inkrementacja licznika klatek o 30
        frameCounter += 30;
    }

    // 5. Zamknięcie pliku i informacja dla użytkownika
    outFile.close();
    std::cout << "Przetwarzanie zakonczone." << std::endl;
    std::cout << "Dane zostaly zapisane do pliku: " << outputFileName << std::endl;

    return 0; // Zakończ program pomyślnie
}