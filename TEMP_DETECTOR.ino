#include <DHT.h>
#include <LiquidCrystal.h>

// DHT11
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 7);

// Buzzer
int buzzer = 9;

void setup()
{
    Serial.begin(9600);

    dht.begin();
    lcd.begin(16, 2);

    pinMode(buzzer, OUTPUT);

    lcd.print("Temperature");
    lcd.setCursor(0, 1);
    lcd.print("Monitoring...");
    delay(2000);
    lcd.clear();
}

void loop()
{
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    if (isnan(temperature) || isnan(humidity))
    {
        lcd.clear();
        lcd.print("Sensor Error!");
        digitalWrite(buzzer, LOW);
        delay(2000);
        return;
    }

    // Display temperature
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temperature);
    lcd.print(" C   ");

    // Display humidity
    lcd.setCursor(0, 1);
    lcd.print("Humidity: ");
    lcd.print(humidity);
    lcd.print("%   ");

    // Temperature alert
    if (temperature >= 20)
    {
        digitalWrite(buzzer, HIGH);
    }
    else
    {
        digitalWrite(buzzer, LOW);
    }

    // Serial Monitor
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" C | Humidity: ");
    Serial.print(humidity);
    Serial.println("%");

    delay(2000);
}
