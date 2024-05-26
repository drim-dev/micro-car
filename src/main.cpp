// #include <Arduino.h>

// #include <SoftwareSerial.h>
 
// SoftwareSerial bluetooth(2, 3);

// #define pinX    A2
// #define pinY    A1
// #define swPin    4

// void setup() {
//   Serial.begin(9600);
//   bluetooth.begin(9600);

//   pinMode(pinX, INPUT);
//   pinMode(pinY, INPUT);

//   pinMode(2, INPUT);
//   pinMode(3, OUTPUT);
  
//   pinMode(swPin, INPUT);
//   digitalWrite(swPin, HIGH);
//   pinMode(LED_BUILTIN, OUTPUT);
// }

// void loop() {
//   int x = analogRead(pinX);

//   x = map(x, 0, 1023, 511, 0);

//   bluetooth.println(x);

//   if (x < 253) {
//     // uint8_t direction = 1;
//     // uint8_t power = 255 - x;
//     // bluetooth.write(direction);
//     // bluetooth.write(power);
//     digitalWrite(LED_BUILTIN, HIGH);
//   }
//   else if (x > 253) {
//     // uint8_t direction = 2;
//     // uint8_t power = x - 256;
//     // bluetooth.write(direction);
//     // bluetooth.write(power);
//     digitalWrite(LED_BUILTIN, LOW);
//   }
//   else {
//     // uint8_t direction = 0;
//     // uint8_t power = 0;
//     // bluetooth.write(direction);
//     // bluetooth.write(power);
//   }
// }

// ===========================================
#include <Arduino.h>

#include <SoftwareSerial.h>
 
SoftwareSerial bluetooth(2, 3);

#define AIN1 5
#define AIN2 6
#define BIN1 9
#define BIN2 10

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);

  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
}

int x = 253;
 
void loop() {
  if (bluetooth.available() > 0) {
    x = bluetooth.readStringUntil('\n').toInt();
  }

  Serial.println(x);

  if (x < 253) {
    int power = 255 - x;

    analogWrite(AIN1, power);
    digitalWrite(AIN2,LOW);
    analogWrite(BIN1, power);
    digitalWrite(BIN2,LOW);
  }
  else if (x > 253) {
    int power = x - 256;

    analogWrite(AIN1, LOW);
    analogWrite(AIN2, power);
    analogWrite(BIN1, LOW);
    analogWrite(BIN2, power);
  }
  else {
    analogWrite(AIN1, LOW);
    analogWrite(AIN2, LOW);
    analogWrite(BIN1, LOW);
    analogWrite(BIN2, LOW);
  }
}

// ===========================================
// #include <Arduino.h>

// #include <SoftwareSerial.h>

// SoftwareSerial mySerial(2, 3); // указываем пины rx и tx соответственно

// void setup()  {
//   pinMode(2, INPUT);
//   pinMode(3, OUTPUT);
//   Serial.begin(9600);
//   mySerial.begin(38400);
//   Serial.println("start prg");
// }

// void loop() {
//   if (mySerial.available()) {
//     char c = mySerial.read(); // читаем из software-порта
//     Serial.print(c); // пишем в hardware-порт
//   }
//   if (Serial.available()) {
//     char c = Serial.read(); // читаем из hardware-порта
//     mySerial.write(c); // пишем в software-порт
//   }
// }
