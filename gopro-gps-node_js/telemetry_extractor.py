from gopro2gpx import extract

input_file = "/home/radek/Desktop/SUAS_2025/C++_Projects/SUAS_2025/GX010064.MP4"
output_file = "./output.gpx"

# extract spodziewa się ścieżki do pliku wideo, nie bajtów z pliku binarnego
gpx_data = extract(input_file)

with open(output_file, "w") as f:
    f.write(gpx_data)

print(f"Zapisano dane GPS do {output_file}")
