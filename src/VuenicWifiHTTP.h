#ifndef VuenicWifiHTTP_H
#define VuenicWifiHTTP_H
#include <Arduino.h>
#include <ArduinoJson.h>
#include <WiFiEsp.h>

class VuenicWifiHTTP
{
    public:
      VuenicWifiHTTP(String apiKey);
      void begin();
      void add(String key, String value);
      void add(String key, int value);
      void add(String key, float value);
      void add(String key, double value);
      bool wifiConnection(String wifiSSID, String wifiPassword);
      
    private:
      String _apiKey;
      String jsonString = "{}";
      char* _wifiSSID;
      char* _wifiPass;
      String ipToString(IPAddress ip);
};

#endif