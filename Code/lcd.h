#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setupLCD();
void ControlLCD();

void setupLCD(){
    lcd.begin();
    lcd.backlight();
}

void ControlLCD(){
    //Muetra temperatura 1
    lcd.setCursor(0,0);
    lcd.print("T1= ");
    if (T1 < 10){
        lcd.print(' ');
        lcd.print(T1);    
    }
    else{
        lcd.print(T1);
    }
    lcd.print(248);
    if (T1I == 1){
        lcd.print('!');
    }
    else{
        lcd.print(' ');
    }
    
    
    //Muetra temperatura 2
    lcd.setCursor(10,0);
    lcd.print("T2= ");
    if (T2 < 10){
        lcd.print(' ');
        lcd.print(T2);    
    }
    else{
        lcd.print(T2);
    }
    lcd.print(248);
    if (T2I == 1){
        lcd.print('!');
    }
    else{
        lcd.print(' ');
    }
    
    
    //Muetra humedad 1
    lcd.setCursor(0,1);
    lcd.print("H1= ");
    if (H1 < 10){
        lcd.print(' ');
        lcd.print(H1);    
    }
    else{
        lcd.print(H1);
    }
    lcd.print('%');
    if (H1I == 1){
        lcd.print('!');
    }
    else{
        lcd.print(' ');
    }
    
    
    //Muetra humedad 2
    lcd.setCursor(10,1);
    lcd.print("H2= ");
    if (H2 < 10){
        lcd.print(' ');
        lcd.print(H2);    
    }
    else{
        lcd.print(H2);
    }
    lcd.print('%');
    if (H2I == 1){
        lcd.print('!');
    }
    else{
        lcd.print(' ');
    }
    
    
    //Muestra agua del suelo 1
    lcd.setCursor(0,2);
    lcd.print("Agua 1 ");
    if (A1I == 1){
        lcd.print("SI");    
    }
    else{
        lcd.print("NO");
    }
    
    
    //Muestra agua del suelo 2
    lcd.setCursor(10,2);
    lcd.print("Agua 2 ");
    if (A2I == 1){
        lcd.print("SI");    
    }
    else{
        lcd.print("NO");
    }
}
