/**The MIT License (MIT)

Copyright (c) 2016 by Count023 -> https://github.com/count023

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <JsonListener.h>
#include "WundergroundAstronomy.h"

/**
 * Wunderground Settings
 */
const String  WUNDERGRROUND_API_KEY = "808ba87ed77c4501";
const String  WUNDERGR_UND_STATE_OR_COUNTRY = "CH";
const String  WUNDERGR_UND_CITY = "ZURICH";
const String  WUNDERGRROUND_LANGUAGE = "EN";
const boolean USE_PM = false;

// initiate the WundergoundClient
WundergroundAstronomy wunderground(USE_PM);


/**
 * WiFi Settings
 */
const char* ESP_HOST_NAME = "esp-" + ESP.getFlashChipId();
const char* WIFI_SSID     = "yourssid";
const char* WIFI_PASSWORD = "yourpassw0rd";

// initiate the WifiClient
WiFiClient wifiClient;



/**
 * Helping funtions
 */
void connectWifi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to ");
  Serial.println(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected!");
  Serial.println(WiFi.localIP());
  Serial.println();
}


/**
 * SETUP
 */
void setup() {

  Serial.begin(115200);
  delay(500);
  connectWifi();

  Serial.println();
  Serial.println("\n\nNext Loop-Step: " + String(millis()) + ":");

  wunderground.updateAstronomy(WUNDERGRROUND_API_KEY, WUNDERGRROUND_LANGUAGE, WUNDERGR_UND_STATE_OR_COUNTRY, WUNDERGR_UND_CITY);

  Serial.println("wundergroundMoonPctIlum: " + wunderground.getMoonPctIlum());
  Serial.println("wundergroundMoonAge: " + wunderground.getMoonAge());
  Serial.println("wundergroundMoonPhase: " + wunderground.getMoonPhase());
  Serial.println("wundergroundSunriseTime: " + wunderground.getSunriseTime());
  Serial.println("wundergroundSunsetTime: " + wunderground.getSunsetTime());
  Serial.println("wundergroundMoonriseTime: " + wunderground.getMoonriseTime());
  Serial.println("wundergroundMoonsetTime: " + wunderground.getMoonsetTime());


  Serial.println();
  Serial.println("---------------------------------------------------/\n");

}


/**
 * LOOP
 */
void loop() {

}
