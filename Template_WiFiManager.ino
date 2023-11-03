/*******************************************************************
//                             XXXXXX                             //
*******************************************************************/

#include <Ticker.h>
#include <WiFiManager.h>

WiFiManager wm; // object untuk WiFi WiFi Manager
Ticker tick;    // Object untuk buzzer danger

const int led = 2;

unsigned long Timeout = 1;       // timeout connect to WiFi (menit)
unsigned long PortalTimeout = 2; // timeout portal config (menit)

//-----------------------------------------------------------------------
void blink()
{
  int state = digitalRead(led);
  digitalWrite(led, !state);
}

//-----------------------------------------------------------------------
void configModeCallback(WiFiManager *myWiFiManager)
{
  Serial.println("Entering config mode");
  Serial.println(WiFi.softAPIP());
  Serial.println(myWiFiManager->getConfigPortalSSID());
  tick.attach(0.3, blink);
}

//-----------------------------------------------------------------------
void connectWifi()
{
  wm.setAPCallback(configModeCallback);
  wm.setClass("invert");
  wm.setScanDispPerc(true);
  // wm.resetSettings();  // uncomment for testing

  bool res;
  wm.setConnectTimeout(60 * Timeout);             // mencoba menghubungkan ke jaringan yang sudah tersimpan selama 2 menit, jika tidak menjadi mode AP
  wm.setConfigPortalTimeout(60 * PortalTimeout);  // menutup configportal setelah 2 menit
  res = wm.autoConnect("ESP8266-AP", "12345678"); // Menjadikan mode AP dengan SSID "ESP8266-AP" dan password "12345678"

  if (res)
  {
    Serial.println("Berhasil Terhubung"); // jika berhasil
    tick.detach();
  }
  else
  {
    Serial.println("Gagal Terhubung"); // jika gagal
    delay(3000);
    ESP.restart(); // restart ESP
  }

  Serial.println("Setup ready!");
}

//-----------------------------------------------------------------------
void cekWiFi()
{
  if (WiFi.status() == WL_CONNECTED)
  {
    digitalWrite(led, LOW);
  }
  else
  {
    digitalWrite(led, HIGH);
  }
}

//-----------------------------------------------------------------------
void setup()
{
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  tick.attach(1, blink);
  connectWifi(); // Fungsi menghubungkan kejaringan
  // Set auto reconnect jika sewaktu terputus ke jaringan
  WiFi.setAutoReconnect(true);
  WiFi.persistent(true);
}

//-----------------------------------------------------------------------
void loop()
{
  //------------------------------------------------
  cekWiFi();
  //------------------------------------------------
}