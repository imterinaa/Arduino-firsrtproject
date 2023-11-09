#include <WiFi.h>
#include <ESPAsyncWebServer.h>

const char* ssid = "Алина";
const char* password = "helloworld";

AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);

  // Подключение к Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Маршрут для обработки GET запросов на корневой URL
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", "Hello, ESP32!");
  });
  Serial.println("");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  // Запуск веб-сервера
  server.begin();
  Serial.println("Web server started");
}

void loop() {
  
}