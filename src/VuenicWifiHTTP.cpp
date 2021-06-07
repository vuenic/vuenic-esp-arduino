#include "VuenicWifiHTTP.h"

VuenicWifiHTTP::VuenicWifiHTTP(String apiKey) {
    _apiKey = apiKey;
}

// String Value
void VuenicWifiHTTP::add(int key, String value) {
    DynamicJsonDocument doc(256);
    deserializeJson(doc, jsonString);    
    doc[String(key)] = value;
    String newInsert;
    serializeJson(doc, newInsert);
    jsonString = newInsert;
}

// Integer Value
void VuenicWifiHTTP::add(int key, int value) {
    DynamicJsonDocument doc(256);
    deserializeJson(doc, jsonString);    
    doc[String(key)] = value;
    String newInsert;
    serializeJson(doc, newInsert);
    jsonString = newInsert;
}

// Float Value
void VuenicWifiHTTP::add(int key, float value) {
    DynamicJsonDocument doc(256);
    deserializeJson(doc, jsonString);    
    doc[String(key)] = value;
    String newInsert;
    serializeJson(doc, newInsert);
    jsonString = newInsert;
}

// Double Value
void VuenicWifiHTTP::add(int key, double value) {
    DynamicJsonDocument doc(256);
    deserializeJson(doc, jsonString);    
    doc[String(key)] = value;
    String newInsert;
    serializeJson(doc, newInsert);
    jsonString = newInsert;
}

bool VuenicWifiHTTP::wifiConnection(String wifiSSID, String wifiPassword) {
    char wifiSSIDChar[wifiSSID.length()+1];
    char wifiPasswordChar[wifiPassword.length()+1];

    wifiSSID.toCharArray(wifiSSIDChar, wifiSSID.length()+1);
    wifiPassword.toCharArray(wifiPasswordChar, wifiPassword.length()+1);

    if (WiFi.status() == WL_NO_SHIELD) {
        Serial.println("WiFi shield not present");
        while (true);
    }

    _wifiSSID = wifiSSIDChar;
    _wifiPass = wifiPasswordChar;

    WiFi.begin(_wifiSSID, _wifiPass);
    Serial.println("Connecting to " + wifiSSID + "...");

    int counter = 0;
    while(WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println(".");
        counter++;
        if(counter >= 10) {
            counter = 0;
            Serial.println("Could not connect to " + wifiSSID + "! Retrying...");
        }
    }

    Serial.println("WiFi Connected!");
    Serial.println("IP Address: " + ipToString(WiFi.localIP()));
    return true;
}

String VuenicWifiHTTP::send(){
    WiFiEspClient client; 
    HttpClient http = HttpClient(client, _server, _port);
	Serial.println("[Vuenic HTTP] Request " + jsonString);
    http.beginRequest();
    http.post(_path);
    http.sendHeader("Content-Type", "application/json");
    http.sendHeader("Content-Length", String(jsonString.length()));
    http.sendHeader("Authorization", _apiKey);
    http.beginBody();
    http.print(jsonString);
    http.endRequest();

    int statusCode = http.responseStatusCode();
    String response = http.responseBody();
    Serial.println("Status code: " + String(statusCode));
    Serial.println("Response: " + response);
    client.stop();
    return String(statusCode);
}

String VuenicWifiHTTP::ipToString(IPAddress ip){
    String s="";
    for (int i=0; i<4; i++)
        s += i  ? "." + String(ip[i]) : String(ip[i]);
    return s;
}