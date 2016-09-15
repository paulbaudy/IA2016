#ifndef WAITRESS_OWNED_STATES_H
#define WAITRESS_OWNED_STATES_H
//------------------------------------------------------------------------
//
//  Name:   WaitressOwnedStates.h
//
//  Desc:   All the states that can be assigned to the Waitress class.
//          Note that a global state has not been implemented.
//
//  Author: Paul BAUDY and Elodie COCQ
//  (paul.baudy1@uqac.ca and elodie.cocq1@uqac.ca)
//
//------------------------------------------------------------------------
#include "fsm/State.h"


class Waitress;
struct Telegram;




//------------------------------------------------------------------------
//
//  In this state, the waitress will go to the bar. She bartends until
//  she is bored or not pretty enough. If she becomes bored, she will
//  change state to PractisePiano. If she feels not pretty enough to
//  bartend, she will change state to EnterRestroomAndMakeUp
//------------------------------------------------------------------------
class Bartend : public State<Waitress>
{
private:

	Bartend() {}

	Bartend(const Bartend&);
	Bartend& operator=(const Bartend&);

public:

	//this is a singleton
	static Bartend* Instance();

	virtual void Enter(Waitress* miner);

	virtual void Execute(Waitress* miner);

	virtual void Exit(Waitress* miner);

	virtual bool OnMessage(Waitress* agent, const Telegram& msg);

};





#endif