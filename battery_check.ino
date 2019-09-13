#include <M5StickC.h>

void setup() {
  M5.begin();
  M5.Lcd.setRotation(3);
  M5.Lcd.setTextFont(2);
  M5.Lcd.setTextSize(1);
  M5.Lcd.fillScreen(BLACK);
}

void loop() {
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.printf(" battery voltage: %.2fV\r\n", M5.Axp.GetVbatData() * 1.1 / 1000);  // 1setp 1.1mV
  M5.Lcd.printf(" charge current : %3dmA\r\n", M5.Axp.GetIchargeData() / 2);  // 1setp 0.5mA
  M5.Lcd.printf(" output current : %3dmA\r\n", M5.Axp.GetIdischargeData() / 2);  // 1step 0.5mA
  M5.Lcd.printf(" USB voltage : %.2fV\r\n", M5.Axp.GetVusbinData() * 1.7 / 1000);  // 1setp 1.7mV
  M5.Lcd.printf(" USB current : %6.2fmA\r\n", M5.Axp.GetIusbinData() * 0.375);  // 1step 0.375mA

  delay(300);
}
