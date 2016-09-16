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

//------------------------------------------------------------------------
//
//  In this state, the waitress will go to the saloon's restroom. She makes
//  up. Then, she goes back to her previous state
//------------------------------------------------------------------------
class EnterRestroomAndMakeUp : public State<Waitress>
{
private:

	EnterRestroomAndMakeUp() {}

	EnterRestroomAndMakeUp(const EnterRestroomAndMakeUp&);
	EnterRestroomAndMakeUp& operator=(const EnterRestroomAndMakeUp&);

public:

	//this is a singleton
	static EnterRestroomAndMakeUp* Instance();

	virtual void Enter(Waitress* miner);

	virtual void Execute(Waitress* miner);

	virtual void Exit(Waitress* miner);

	virtual bool OnMessage(Waitress* agent, const Telegram& msg);

};

//------------------------------------------------------------------------
//
//  In this state, the waitress will go to the saloon's piano. She practise
//  piano to have fun and relax. She will play a random music, and then she
//  comes back to the bar. If she is sweaty, she will go to the restroom.
//------------------------------------------------------------------------
class PractisePiano : public State<Waitress>
{
private:

	PractisePiano() {}

	PractisePiano(const PractisePiano&);
	PractisePiano& operator=(const PractisePiano&);

public:

	//this is a singleton
	static PractisePiano* Instance();

	virtual void Enter(Waitress* miner);

	virtual void Execute(Waitress* miner);

	virtual void Exit(Waitress* miner);

	virtual bool OnMessage(Waitress* agent, const Telegram& msg);

};



#endif