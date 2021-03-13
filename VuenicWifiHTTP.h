#ifndef VuenicWifiHTTP_H
#define VuenicWifiHTTP_H
#include <Arduino.h>
#include <WiFiEsp.h>

class VuenicWifiHTTP
{
    public:
      VuenicWifiHTTP(String apiKey);
      bool wifiConnection(String wifiSSID, String wifiPassword);
      
    private:
      String _apiKey;
      char* _wifiSSID;
      char* _wifiPass;
      String ipToString(IPAddress ip);
};

#endif