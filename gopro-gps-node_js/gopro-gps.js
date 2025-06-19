const fs = require("fs");
const telemetry = require("gopro-telemetry");

const mp4Buffer = fs.readFileSync("/home/radek/Desktop/SUAS_2025/C++_Projects/SUAS_2025/GX010064.MP4");
console.log("MP4 size:", mp4Buffer.length);
// Pobieranie danych GPS z pliku MP4

telemetry(mp4Buffer, { stream: ["GPS5"] }).then((result) => {
  // Dane są w result["1"].streams.GPS5.samples
  const gpsSamples = result["1"].streams.GPS5.samples;

  const simplified = gpsSamples.map((s) => {
    return {
      timestamp: s.cts / 1000, // sekundy
      lat: s.value[0],
      lon: s.value[1],
      alt: s.value[2]
    };
  });

  fs.writeFileSync("gps_data.json", JSON.stringify(simplified, null, 2));
});
