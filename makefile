# Definicje zmiennych
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
SOURCES = frames_gpsdata.cpp pugixml.cpp
EXECUTABLE = frames_gpsdata

# Domyślna reguła, która zostanie wykonana po wpisaniu 'make'
all: $(EXECUTABLE)

# Reguła, jak zbudować plik wykonywalny
$(EXECUTABLE): $(SOURCES)
	# WAŻNE: Poniższa linia MUSI zaczynać się od znaku TAB, a nie spacji!
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(EXECUTABLE)

# Reguła do czyszczenia skompilowanych plików
clean:
	# WAŻNE: Poniższa linia również MUSI zaczynać się od znaku TAB!
	rm -f $(EXECUTABLE)