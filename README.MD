# Template WiFi Manager ESP8266

Fungsi dari program ini adalah untuk memudahkan pengaturan/perubahan parameter WiFi (SSID dan Password) tanpa harus memprogram ulang(Hard coding).

## Parameter Costum

- Jika anda menghendaki perubahan pada nama AP dan Password AP silahkan ganti pada syntax berikut

```cpp
res = wm.autoConnect("ESP8266-AP", "12345678"); // Menjadikan mode AP dengan SSID "ESP8266-AP" dan password "12345678"
```

- Perubahan waktu Timeout bisa anda sesuaikan dengan mengganti nilai pada syntax berikut dengan satuan menit

```cpp
unsigned long Timeout = 1;       // timeout connect to WiFi (menit)
unsigned long PortalTimeout = 2; // timeout portal config (menit)
```

- Uncomment syntax berikut untuk testing mode, ini berfungsi untuk menghapus parameter WiFi yang sudah tersimpan sebelumnya

```cpp
// wm.resetSettings();  // uncomment for testing
```

### Editor

- Arduino IDE 2.2.1

### Board

- Board ESP8266 3.1.2 by ESP8266 Community
  https://arduino.esp8266.com/stable/package_esp8266com_index.json

### Library

- Include Board

  - Ticker at version 1.0
  - ESP8266WiFi at version 1.0
  - ESP8266WebServer at version 1.0
  - DNSServer at version 1.1.1

- Manual Install
  - [WiFiManager](https://github.com/tzapu/WiFiManager) at version 2.0.16-rc.2 by tzapu

### Additional Feature

- [x] Auto reconnect wifi
- [x] Portal config untuk merubah parameter WiFi (SSID & Password)
- [x] Led blink indicator (1 sec) Connecting to WiFi (0.3 sec) AP mode
      for config parameter
- [x] Led indikator on jika berhasil terhubung ke WiFi
- [x] Timeout 1 menit untuk menghubungkan ke WiFi yang tersimpan (STA Mode)
- [x] Timeout 2 menit portal untuk config (AP Mode)

---
