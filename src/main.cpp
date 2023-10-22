#include <Arduino.h>
#include <BluetoothSerial.h>
#include <L298N.h>
// #include <WiFi.h>
// #include <AsyncTCP.h>
// #include <ESPAsyncWebServer.h>
// #include <AsyncElegantOTA.h>
// #include <NimBLEDevice.h>
// #include <NimBLECharacteristic.h>

// #define SERVICE_UUID "0000180d-0000-1000-8000-00805f9b34fb"
// #define CHARACTERISTIC_UUID "00002a29-0000-1000-8000-00805f9b34fb"



// NimBLEDevice  ble_device;

BluetoothSerial bt;
// NimBLEService* pService = new NimBLEService(SERVICE_UUID);
// NimBLECharacteristic* pCharacteristic = pService->createCharacteristic(CHARACTERISTIC_UUID,READ,WRITE);
// NimBLEAttValue pAttValue = pCharacteristic->getValue();



// const char* ssid = "ChinaNet-fttZ";
// const char* password = "zt4iizjr";


const unsigned int IN1_A = 12;
const unsigned int IN2_A = 13;

const unsigned int IN3_B = 14;
const unsigned int IN4_B = 27;


const unsigned int IN5_C = 26;
const unsigned int IN6_C = 25;

const unsigned int IN7_D = 33;
const unsigned int IN8_D = 32;

// int speed_slow = 100;
// int speed_fast = 250;

// AsyncWebServer server(80);



L298N motor1(IN1_A,IN2_A);
L298N motor2(IN3_B,IN4_B);
L298N motor3(IN5_C,IN6_C);
L298N motor4(IN7_D,IN8_D);





void qianjin(){  //前进
  motor1.forward(); 
  motor2.forward();
  motor3.forward();
  motor4.forward();
}

void houtui(){   //后退  
  motor1.backward(); 
  motor2.backward();
  motor3.backward();
  motor4.backward();
}

void zuopiaoyi(){  //左漂移
  motor1.backward(); 
  motor2.forward();
  motor3.forward();
  motor4.backward();
}

void youpiaoyi(){  //右漂移
  motor1.forward(); 
  motor2.backward();
  motor3.backward();
  motor4.forward();
}

void shache(){    //刹车
  motor1.stop(); 
  motor2.stop();
  motor3.stop();
  motor4.stop();
}

void youzhuan(){    //右转
  motor1.stop();
  motor2.forward();
  motor3.stop();
  motor4.forward();
}  

void zuozhuan(){     //左转
  motor1.forward();
  motor2.stop();
  motor3.forward(); 
  motor4.stop();
}

void yuandixuanzhuan(){  //原地旋转
  motor1.forward();
  motor2.backward();
  motor3.forward();
  motor4.backward();
}


void setup() {
  Serial.begin(115200);
  // WiFi.mode(WIFI_STA);
  // WiFi.begin(ssid, password);
  // server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
  //   request->send(200, "text/plain", "Hi! This is a sample response.");
  // });

  // AsyncElegantOTA.begin(&server);    // Start AsyncElegantOTA
  // server.begin();
  bt.begin("ESP32-car1");
  // ble_device.init();
  // mycharacteristic.getUUID();
  

  
  delay(1000);

}
  
  
void loop() {
  if (bt.available() > 0) {
      
    char c = bt.read();
    Serial.print(c);
    
    switch (c) {
  case 'f':
    qianjin();
    break;
  case 'b':
    houtui();
    break;
  case 'l':
    zuopiaoyi();
    break;
  case 'r':
    youpiaoyi();
    break;
  case 's':
    shache();
    break;
  case 'c':
    youzhuan();
    break;
  case 'd':
    zuozhuan();
    break;
  case 't':
    yuandixuanzhuan();
    break;
  default:
    break; 
    }
    delay(100);
  }
    
}


  


  



  
  







  
  

  

  

















  
  
  




