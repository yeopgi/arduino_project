#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,20,4);     // 접근주소: 0x3F or 0x27

String item_1 = "item1";
String item_2 = "item2";
String item_3 = "item3";
int item_1_quantity = 0;
//int item_2_quantity = 0;
//int item_3_quantity = 0;
int item_1_price = 10000;
int item_2_price = 5500;
int item_3_price = 7500;
double total_price = 0;
//--------------------------------------------------
int button1 = A0;
int buttonValue1;

int button2 = A1;
int buttonValue2;
int value2;
//--------------------------------------------------
#include <hid.h>
#include <hiduniversal.h>
#include <avr/pgmspace.h>
#include <Usb.h>
#include <usbhub.h>
#include <avr/pgmspace.h>
#include <hidboot.h>
USB     Usb;
USBHub     Hub(&Usb);
HIDUniversal  Hid(&Usb);
HIDBoot<HID_PROTOCOL_KEYBOARD>  Keyboard(&Usb);
int i = 0;
char barcode[14] = {0};
class KbdRptParser : public KeyboardReportParser {
    void PrintKey(uint8_t mod, uint8_t key);
  protected:
    virtual void OnKeyDown	(uint8_t mod, uint8_t key);
    virtual void OnKeyPressed(uint8_t key);
};
void KbdRptParser::OnKeyDown(uint8_t mod, uint8_t key) {
  uint8_t c = OemToAscii(mod, key);
  if (c)
    OnKeyPressed(c);
}
void KbdRptParser::OnKeyPressed(uint8_t key) {
  barcode[i] = key;
  if (i == 13) {
    i = 0;
    if (barcode[0] == '8' && barcode[1] == '8' && barcode[2] == '0'
        && barcode[3] == '0' && barcode[4] == '0' && barcode[5] == '0'
        && barcode[6] == '0' && barcode[7] == '0' && barcode[8] == '0'
        && barcode[9] == '0' && barcode[10] == '1' && barcode[11] == '1'
        && barcode[12] == '4') {
      Serial.println("");
      Serial.println(item_1);

      if (buttonValue1 == 1) {

        if (item_1_quantity >= 1) {
          item_1_quantity = item_1_quantity - 1;

          total_price = total_price - item_1_price;
          lcd.setCursor(1, 1);
          lcd.print("                    ");
          lcd.setCursor(1, 1);
          lcd.print(item_1);
          lcd.print(" Cancel");

          lcd.setCursor(1, 2);
          lcd.print("                    ");

          lcd.setCursor(1, 3);
          lcd.print("                    ");
          lcd.setCursor(1, 3);
          lcd.print("Total: ");
          lcd.print(total_price, 0);
        }
      }
  else {    
 
        item_1_quantity++;
        total_price = total_price + item_1_price;
        lcd.setCursor(1, 1);
        lcd.print("                    ");
        lcd.setCursor(1, 1);
        lcd.print(item_1);
        lcd.print(": " + (String)item_1_price);

        lcd.setCursor(1, 2);
        lcd.print("                    ");
        lcd.setCursor(1, 2);
        lcd.print("Quantity : ");
        lcd.print((String)item_1_quantity);

        lcd.setCursor(1, 3);
        lcd.print("                    ");
        lcd.setCursor(1, 3);
        lcd.print("Total: ");
        lcd.print(total_price, 0);
        }
  
         
        }else if (barcode[0] == '8' && barcode[1] == '8' && barcode[2] == '0'
               && barcode[3] == '0' && barcode[4] == '0' && barcode[5] == '0'
               && barcode[6] == '0' && barcode[7] == '0' && barcode[8] == '0'
               && barcode[9] == '0' && barcode[10] == '2' && barcode[11] == '2'
               && barcode[12] == '0') {
      Serial.println("");
      Serial.println(item_2);

      if (buttonValue1 == 1) {

        if (item_1_quantity >= 1) {
          item_1_quantity=item_1_quantity-1;

          total_price = total_price - item_2_price;
          lcd.setCursor(1, 1);
          lcd.print("                    ");
          lcd.setCursor(1, 1);
          lcd.print(item_2);
          lcd.print(" Cancel");

          lcd.setCursor(1, 2);
          lcd.print("                    ");

          lcd.setCursor(1, 3);
          lcd.print("                    ");
          lcd.setCursor(1, 3);
          lcd.print("Total: ");
          lcd.print(total_price, 0);
        }

      } 
               else {

        item_1_quantity++;
        total_price = total_price + item_2_price;
        lcd.setCursor(1, 1);
        lcd.print("                    ");
        lcd.setCursor(1, 1);
        lcd.print(item_2);
        lcd.print(": " + (String)item_2_price);

        lcd.setCursor(1, 2);
        lcd.print("                    ");
        lcd.setCursor(1, 2);
        lcd.print("Quantity : ");
        lcd.print((String)item_1_quantity);

        lcd.setCursor(1, 3);
        lcd.print("                    ");
        lcd.setCursor(1, 3);
        lcd.print("Total: ");
        lcd.print(total_price, 0);
               }
      }

      else if (barcode[0] == '8' && barcode[1] == '8' && barcode[2] == '0'
                && barcode[3] == '0' && barcode[4] == '0' && barcode[5] == '0'
                && barcode[6] == '0' && barcode[7] == '0' && barcode[8] == '0'
                && barcode[9] == '0' && barcode[10] == '3' && barcode[11] == '3'
                && barcode[12] == '6') {
      Serial.println("");
      Serial.println(item_3);

      if (buttonValue1 == 1) {

        if (item_1_quantity >= 1) {
          item_1_quantity=item_1_quantity-1;

          total_price = total_price - item_3_price;
          lcd.setCursor(1, 1);
          lcd.print("                    ");
          lcd.setCursor(1, 1);
          lcd.print(item_3);
          lcd.print(" Cancel");

          lcd.setCursor(1, 2);
          lcd.print("                    ");

          lcd.setCursor(1, 3);
          lcd.print("                    ");
          lcd.setCursor(1, 3);
          lcd.print("Total: ");
          lcd.print(total_price, 0);
        }

      } else {

        item_1_quantity++;
        total_price = total_price + item_3_price;
        //lcd.setCursor(1, 1);
        //lcd.print("                    ");
        lcd.setCursor(1, 1);
        lcd.print(item_3);
        lcd.print(": " + (String)item_3_price);

        lcd.setCursor(1, 2);
        lcd.print("                    ");
        lcd.setCursor(1, 2);
        lcd.print("Quantity : ");
        lcd.print((String)item_1_quantity);

        lcd.setCursor(1, 3);
        lcd.print("                    ");
        lcd.setCursor(1, 3);
        lcd.print("Total: ");
        lcd.print(total_price, 0);

      }


                }else {
      Serial.println("");
      Serial.println("error");
    }
  }else {
    i++;
    //Serial.print( (char)key );
  } 
};
    
KbdRptParser Prs;
//--------------------------------------------------
//--------------------------------------------------
//--------------------------------------------------
//--------------------------------------------------
//--------------------------------------------------
void setup() {
  Serial.begin( 9600 );
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  lcd.init();
  lcd.backlight();
  //--------------------------------------------------
  Serial.println("Start");
  if (Usb.Init() == -1) {
    Serial.println("OSC did not start.");
  }
  delay( 200 );
  Hid.SetReportParser(0, (HIDReportParser*)&Prs);
  delay( 200 );
}
//--------------------------------------------------
//--------------------------------------------------
//--------------------------------------------------
//--------------------------------------------------
//--------------------------------------------------
void loop() {
  Usb.Task();
  buttonValue1 = digitalRead(button1);
  buttonValue2 = digitalRead(button2);

  Serial.print("button1 : ");
  Serial.print(buttonValue1);
  //Serial.print("   button2 : ");
  //Serial.println(buttonValue2);

  
     if (/*value2 == 0 && */buttonValue2 == 1) {
    //value2 = 1;
    Serial.println("button2 hit");

    lcd.setCursor(1, 0);
    lcd.print("                    ");
    lcd.setCursor(1, 1);
    lcd.print("                    ");
    lcd.setCursor(1, 2);
    lcd.print("                    ");
    lcd.setCursor(1, 3);
    lcd.print("                    ");


    lcd.setCursor(1, 1);
    lcd.print("Thank you.");
    lcd.setCursor(1, 2);
    lcd.print("Come Back Again.");

    delay(3000);

    total_price = 0;

    item_1_quantity = 0;
    //item_2_quantity = 0;
    //item_3_quantity = 0;

    lcd.setCursor(1, 0);
    lcd.print("                    ");
    lcd.setCursor(1, 1);
    lcd.print("                    ");
    lcd.setCursor(1, 2);
    lcd.print("                    ");
    lcd.setCursor(1, 3);
    lcd.print("                    ");

    value2 = 0;

  }
}
