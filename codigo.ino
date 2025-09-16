// #include <WiFi.h>
// #include <HTTPClient.h>
// #include <PulseSensorPlayground.h> 



// ===== CONFIG WiFi =====
// const char* ssid = "Wokwi-GUEST";
// const char* password = "";

// // ===== CONFIG Webhook =====
// const char* serverUrl = "https://webhook.site/b585a37d-3116-4442-9188-bebe3305781a"; 

// const int pulsePin = 34; 

// void setup() {
// Serial.begin(115200);
// WiFi.begin(ssid, password);

// Serial.print("Conectando ao WiFi...");
// while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
// }
// Serial.println("\nWiFi conectado!");
// }

// void loop() {
// int sensorValue = analogRead(pulsePin);  
//   int bpm = map(sensorValue, 0, 4095, 60, 120); // Simulação de BPM

// if (WiFi.status() == WL_CONNECTED) {
//     HTTPClient http;
//     http.begin(serverUrl);
//     http.addHeader("Content-Type", "application/json");

//     String jsonData = "{\"bpm\": " + String(bpm) + "}";
//     int httpResponseCode = http.POST(jsonData);

//     if (httpResponseCode > 0) {
//     Serial.println("Dados enviados: " + jsonData);
//     Serial.println("Resposta: " + String(httpResponseCode));
//     } else {
//     Serial.println("Erro ao enviar: " + String(httpResponseCode));
//     }

//     http.end();
// }

//   delay(10000); // envia a cada 10s
// }
// Fim do código