#ifndef VuenicWifiHTTP_H
#define VuenicWifiHTTP_H
#include <Arduino.h>
#include <ArduinoJson.h>
#include <ArduinoHttpClient.h>
#include <WiFiEsp.h>

class VuenicWifiHTTP
{
    public:
      VuenicWifiHTTP(String apiKey);
      void begin();
      void add(int key, String value);
      void add(int key, int value);
      void add(int key, float value);
      void add(int key, double value);
      String send();
      bool wifiConnection(String wifiSSID, String wifiPassword);
      
    private:
      String _apiKey;
      String _server = "api.vuenic.com";
      String _path = "/v1/devices/";
      int _port = 8080;
      String jsonString = "{}";
      char* _wifiSSID;
      char* _wifiPass;
      String ipToString(IPAddress ip);
};

#endif