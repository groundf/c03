/*************************************************
  Teplotní čidlo LM335 s Arduino
  arduinonavody.eu
*************************************************/
#include <LiquidCrystal.h>


// Temperature
float temperature_K = 0.0;
float temperature_C = 0.0;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

/**
 * Represents the analog temperature sensor LM335.
 */
// class LM335 {

// private:
//     float m_calc;
//     int   m_pin_number;

// public:
//     LM335(float calc, int pin_number);

//     float measure_V();

//     float measure_K();

//     float measure_C();

//     float measure_F();
// };


////////////////////////////////////////////////////////////////////////////////
void setup() {
  lcd.begin(16, 2);
  lcd.setCursor (0, 0);
  lcd.print("");
  delay(2000);
  Serial.begin(9600); // nastavení bps
}

////////////////////////////////////////////////////////////////////////////////
void loop() {
  temperature_K = (analogRead(0)) * 0.0046875 * 100  ; //přečtení teploty v Kelvinech

  Serial.print(analogRead(0));
               
  temperature_C = temperature_K - 273.15; //konvertování z Kelvinů na Celsia

  lcd.setCursor (0, 0);
   //zobrazení údajů na Serial Monitoru
  lcd.print("TK ");
  lcd.print(temperature_K);
  
  delay(1000); //počkání 1 sekundu
  
  lcd.setCursor (0, 0);
  for (int i = 0; i < 16; ++i)
  {
    lcd.write(' ');
  }
  lcd.setCursor (0, 1);
  for (int j = 0; j < 16; ++j)
  {
    lcd.write(' ');
  }

  lcd.setCursor (0, 0);
  lcd.print("TC");
  lcd.print(temperature_C);

  delay(1000); //počkání 1 sekundu
}
