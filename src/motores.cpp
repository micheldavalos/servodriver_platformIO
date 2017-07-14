#include <Motores.h>
#include <SoftwareSerial.h>
#include <ArduinoJson.h>

String json_data = "";
      // "{\"sensor\":\"gps\",\"time\":1351824120,\"data\":[48.756080,2.302038]}";
char character;
StaticJsonBuffer<512> jsonBuffer;

void setup(void)
{
  Serial.begin(57600);
  Serial.println("Comenzando\n" );
  Motores m;
  uint8_t status = m.agregarMotor(5);

  // if (status == 1)
  // {
  //   m.mover(5, 512);
  //   delay(500);
  //   m.mover(5, 666);
  //
  // }


}

void loop(void)
{
  if (Serial.available())
  {
    while(Serial.available()) {
          character = Serial.read();
          json_data.concat(character);
          // Serial.println(json_data);
          if (character == '}')
          {
            JsonObject& root = jsonBuffer.parse(json_data);
            root.printTo(Serial);
            json_data = "";
          }
      }
  }

}
