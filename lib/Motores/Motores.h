#ifndef MOTORES_H
#define MOTORES_H

#include "Arduino.h"
#include "DynamixelMotor.h"
#include <StandardCplusplus.h>
#include <vector>

using namespace std;



class Motores
{
public:
    Motores();
    uint8_t agregarMotor(uint8_t id);
    void mover(uint8_t id, uint16_t pos);

private:
    // DynamixelMotor arreglo_motores[NUM_MOTORS];
    vector<DynamixelMotor*> motores;
    const long unsigned int baudrate = 1000000;
    int16_t speed;
    HardwareDynamixelInterface interface;

};

#endif // MOTORES_H
