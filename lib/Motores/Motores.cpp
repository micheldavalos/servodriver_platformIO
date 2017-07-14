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
      return 2;
    }
    nuevo->enableTorque();
    nuevo->jointMode(204, 820);
    nuevo->speed(speed);
    
    motores.push_back(nuevo);

    return 1;
  }

  return 0;

}

bool Motores::mover(uint8_t id, uint16_t pos)
{
  DynamixelMotor* temp = buscar_motor(id);
  if (temp != 0)
  {
    temp->goalPosition(pos);

    return true;
  }
  return false;
}

DynamixelMotor* Motores::buscar_motor(uint8_t id)
{
  size_t tam = motores.size();
  size_t i;

  for(size_t i = 0; i < tam; i++)
  {
    if (motores[i]->id() == id)
    {
      return motores[i];
    }
  }
  return 0;

}
