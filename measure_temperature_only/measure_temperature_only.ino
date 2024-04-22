#include <DHT.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN A3     // Pin connected to the DHT sensor
#define DHTTYPE DHT11 // DHT 11

DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor

LiquidCrystal_I2C lcd(0x27, 16, 2); // Initialize LCD

void setup() {
  Serial.begin(9600);
  Serial.println("Temperature Sensor Test");

  dht.begin();
  lcd.init();
  lcd.backlight();
}

void loop() {
  float temperature = dht.readTemperature(); // Read temperature

  if (isnan(temperature)) { // Check if reading is valid
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  lcd.clear(); // Clear the LCD screen
  lcd.setCursor(0, 0);
  lcd.print("Temperature:");
  lcd.setCursor(0, 1);
  lcd.print(temperature);
  lcd.print(" C");

  delay(1000);
}
