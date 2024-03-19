#include <WiFi.h>
  
// debug log, set to 1 to enable
#define ENABLE_DEBUG_LOG 1

#define POWER_PIN 25

// wifi config
const char* ssid     = "SSID-NAME";
const char* password = "SSID-PSWD";
  
// ethernet config
const IPAddress local_IP(192, 168, 70, 98);
const IPAddress gateway(192, 168, 70, 99);
const IPAddress subnet(255, 255, 255, 0);
const IPAddress primaryDNS(8, 8, 8, 8);
const IPAddress secondaryDNS(8, 8, 4, 4);
  
// rs-server config
const int serverPort = 1234;
  
// rs port config
const int baudrate = 115200;
const int rs_config = SERIAL_8N1;
  
// reading buffor config
#define BUFFER_SIZE 1024
  
// global objects
WiFiServer server;
byte buff[BUFFER_SIZE];
  
void debug_log(char* str) {
#if ENABLE_DEBUG_LOG == 1
   Serial.println(str);
#endif
}
  
void setup() {

    // POWER_PIN : This pin controls the power supply of the SIM7600
  pinMode(POWER_PIN, OUTPUT);
  digitalWrite(POWER_PIN, HIGH);

// init rs port
   Serial.begin(baudrate, rs_config);
   Serial1.begin(115200, SERIAL_8N1, 27, 26 /*, false, 20000UL, SERIAL_SIZE_RX*/);
  
// init wifi connection
if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)) {
       debug_log("Failed to configure network settings");
}
   WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
       debug_log("connecting to WiFi network");
       delay(500);
}
  
   debug_log("connected to WiFi");
   debug_log("IP adddr: ");
   debug_log((String)WiFi.localIP());
   delay(1000);
  
//start server
   server = WiFiServer(serverPort);
   server.begin();
   delay(1000);
   debug_log("server started");
}
  
void loop() {
// wait for client
   WiFiClient client = server.available();
if (!client)
return;
  
   debug_log("client found");
while (client.connected()) {
int size = 0;
  
// read data from wifi client and send to serial1
while ((size = client.available())) {
           size = (size >= BUFFER_SIZE ? BUFFER_SIZE : size);
           client.read(buff, size);
           Serial1.write(buff, size);
           Serial1.flush();
}
  
// read data from serial1 and send to wifi client
while ((size = Serial1.available())) {
           size = (size >= BUFFER_SIZE ? BUFFER_SIZE : size);
           Serial1.readBytes(buff, size);
           client.write(buff, size);
           client.flush();
}
}
   debug_log("client disconnected");
   client.stop();
}
