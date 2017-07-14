#include <Motores.h>
#include <SoftwareSerial.h>


void setup(void)
{
  Serial.begin(57600);
  Serial.println("Comenzando\n" );
  Motores m;
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
}
