#include <Motores.h>
#include <SoftwareSerial.h>
#include <ArduinoJson.h>


StaticJsonBuffer<512> jsonBuffer;

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
Motores m;
void setup(void)
{
  Serial.begin(115200);
  Serial.println("Comenzando\n" );
  m.inicia();
  delay(100);



  uint8_t status = m.agregarMotor(5);
  if (status == 1)
  {
    m.mover(5, 512);
    delay(500);
    m.mover(5, 666);

  }


}

void loop(void)
{
/*  if (Serial.available())
  {
    while(Serial.available()) {
          character = Serial.read();
          Serial.println(character);
          // json_data.concat(character);
          // Serial.println(json_data);
          // if (character == '}')
          // {
          //   JsonObject& root = jsonBuffer.parse(json_data);
          //   root.printTo(Serial);
          //   json_data = "";
          // }
      }
  }
*/
  if (stringComplete) {
    // Serial.println(inputString);
    // Serial.println(inputString.length());
    JsonObject& root = jsonBuffer.parse(inputString);
    // root.printTo(Serial);

    uint8_t id = root["id"];
    uint16_t pos = root["pos"];
    Serial.println(id);
    Serial.println(pos);
    jsonBuffer.clear();
    m.mover(id, pos);
    // clear the string:
    inputString = "";
    stringComplete = false;
  }

}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '}') {
      stringComplete = true;
    }
  }
}
