#include "motores.h"

Motores::Motores():interface(Serial1), speed(512)
{
  interface.begin(baudrate);
  delay(100);
}

uint8_t Motores::agregarMotor(uint8_t id)
{
  DynamixelMotor *nuevo = new DynamixelMotor(interface, id);

  if (nuevo != 0)
  {
    uint8_t status = nuevo->init();
    if(status!=DYN_STATUS_OK)
    {
      return false;
    }
    nuevo->enableTorque();
    nuevo->jointMode(204, 820);
    nuevo->speed(speed);

    motores.push_back(nuevo);

    return true;
  }

  return false;

}

void Motores::mover(uint8_t id, uint16_t pos)
{
  motores[0]->goalPosition(pos);
}
