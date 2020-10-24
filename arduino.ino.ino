#include <LiquidCrystal.h>

int Contrast=145;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  
int incomingByte = 0;
String data;
String a;
String b;
String c;
String d;
void setup(){
  analogWrite(6,Contrast);
  lcd.begin(16, 2);
  Serial.begin(9600);
  
} 

void loop(){ 
 if (Serial.available()) {
    while (Serial.available() > 0) { 
       data = Serial.readString(); // read the incoming data as string
    int a1 = data.indexOf("a");
    int b1 = data.indexOf("b");
    int c1 = data.indexOf("c");
    int d1 = data.indexOf("d");
    int e1 = data.indexOf("e");
    a = data.substring(a1 + 1, b1);
    b = data.substring(b1 + 1, c1);
    c = data.substring(c1 + 1, d1);
    d = data.substring(d1 + 1, e1);
      lcd.setCursor(0, 0);
      lcd.print("CPU:" + a);
      lcd.setCursor(0, 1);
      lcd.print("RAM:" + b);
    }
  }
 
}
