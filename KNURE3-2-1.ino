#include "DHT.h"
#define DHTPIN 6 // пин подключения контакта DATA
#define DHTTYPE DHT22 // DHT 22
#include <LiquidCrystal.h>
// инициализация с указанием контактов подключения
LiquidCrystal lcd(  12, 11, 5, 4, 3, 2);
DHT dht(DHTPIN, DHTTYPE);
void setup()
{
lcd.begin(20,2); // режим работы
dht.begin();
}
void loop()
{
// получение с датчика данных влажности и температуры
float h = dht.readHumidity();
float t = dht.readTemperature();
if (isnan(t) || isnan(h)) // ошибка получения данных
{
lcd.clear();lcd.setCursor(0,0);
lcd.print("Failed to read");
}
else // вывести данные на ЖКИ
{
lcd.clear();

lcd.setCursor(0,0);
lcd.print("TO:"); lcd.print(t);

lcd.setCursor(8,0);
lcd.print("TI:"); lcd.print(t);


lcd.setCursor(3,1);
lcd.print("HUM:");lcd.print(h); lcd.println("%   ");
}

delay(2000); // пауза перед следующим измерением
}
