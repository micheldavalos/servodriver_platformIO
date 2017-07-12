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
    // void mover(uint8_t id, int pos);

private:
    // DynamixelMotor arreglo_motores[NUM_MOTORS];
    vector<DynamixelMotor*> motores;

};

#endif // MOTORES_H
