#!/bin/bash

# Wyjście przy błędzie
set -e

# Plik wejściowy
INPUT_FILE="/home/radek/Desktop/SUAS_2025/C++_Projects/SUAS_2025/GX010020.MP4"
# Plik wyjściowy
echo "make dla Image_Stitching rozpoczęte..."
cd Image_Stitching 
make
cd ..
echo "make dla Image_Stitching zakończone"

echo "Podział na klatki rozpoczęty..."
#./Image_Stitching/frames_extractor "$INPUT_FILE" 30
echo "Podział na klatki zakończony"

echo "Wyciaganie danych GPS"
exiftool -p /usr/share/doc/libimage-exiftool-perl/fmt_files/gpx.fmt -ee -w gpx "$INPUT_FILE"

# Uruchomienie Makefile
echo "Uruchamianie make..."
make
echo "Zakończono make."

echo "Uruchamianie frames_gpsdata.cpp"
./frames_gpsdata
echo "Zakończono frames_gpsdata.cpp."
