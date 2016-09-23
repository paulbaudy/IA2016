#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "Locations.h"
#include "fsm/State.h"
#include "Miner.h"
#include "MinerOwnedStates.h"
#include "MinersWife.h"
#include "MinersWifeOwnedStates.h"
#include "Waitress.h"
#include "WaitressOwnedStates.h"

typedef struct {
    State<Miner> *bob_state;
    State<MinersWife> *elsa_state;
    State<Waitress> *jess_state;

    int nbIteration;
    bool stepbystep;

}configuration;

#endif // CONFIGURATION_H
