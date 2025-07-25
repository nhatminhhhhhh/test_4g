#define TINY_GSM_MODEM_SIM7600 // Khai báo loại modem #define
TINY_GSM_RX_BUFFER 1024 // Tăng buffer nếu cần
  
  #include <WiFi.h> 
  #include <TinyGsmClient.h>
  #include <HardwareSerial.h>
  #define MODEM_RX 15 // RX của ESP32 (nối với TX SIM) 
  #define MODEM_TX 13 // TX của ESP32 (nối với RX SIM) 
  #define MODEM_PWRKEY 4 // PWRKEY nối từ ESP32 điều khiển SIM (nếu có) 
  #define MODEM_RST -1 // Không dùng chân reset 
  HardwareSerial SerialAT(2); 
TinyGsm modem(SerialAT); 
const char apn[] = "m3-world"; const char user[] = "mms"; const char pass[] = "mms"; // Wi-Fi hotspot
const char ssid[] = "Stream4G"; const char password[] = "12345678"; 
void setup() {
Serial.begin(115200);
delay(3000); 
Serial.println("=== Bắt đầu khởi động SIM A7680C ==="); // Bật UART 2 cho ESP32 
SerialAT.begin(115200, SERIAL_8N1, MODEM_RX, MODEM_TX); // Khởi động modem nếu cần điều khiển PWRKEY
pinMode(MODEM_PWRKEY, OUTPUT);
digitalWrite(MODEM_PWRKEY, LOW); 
delay(1000);
digitalWrite(MODEM_PWRKEY, HIGH);
delay(2000); 
Serial.println("Khởi tạo modem..."); 
modem.restart(); // Gửi lệnh AT+CFUN=1, AT+CRESET...
String modemInfo = modem.getModemInfo(); 
Serial.print("Modem info: "); 
Serial.println(modemInfo); // Đợi SIM sẵn sàng
if (!modem.waitForNetwork()) { 
  Serial.println("Không tìm thấy mạng!");
  while (true); 
} 
Serial.println("Đã kết nối mạng di động"); // GPRS connect
Serial.print("Kết nối GPRS với APN: "); 
Serial.println(apn); 
if (!modem.gprsConnect(apn, user, pass)) { 
  Serial.println("GPRS kết nối thất bại!"); 
  while (true); 
} 
  delay(5000); 
  Serial.println("GPRS kết nối thành công");
  delay(3000);
  Serial.println(" ok, IP: " + modem.getLocalIP()); 
  delay(3000); WiFi.softAP(ssid, password); 
  IPAddress IP = WiFi.softAPIP(); 
  Serial.print("Wi-Fi AP IP: "); 
  Serial.println(IP); 
} 
void loop() { 
  // Giữ kết nối, kiểm tra số lượng thiết bị truy cập
  Serial.print("Stations: ");
  Serial.println(WiFi.softAPgetStationNum());
  delay(10000);
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
