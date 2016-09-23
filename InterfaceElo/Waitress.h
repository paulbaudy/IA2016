#ifndef WAITRESS_H
#define WAITRESS_H
//------------------------------------------------------------------------
//
//  Name:   Waitress.h
//
//  Desc:   A class defining a waitress.
//
//  Author: Paul BAUDY and Elodie COCQ
//  (paul.baudy1@uqac.ca and elodie.cocq1@uqac.ca)
//
//------------------------------------------------------------------------
#include <string>
#include <cassert>
#include <iostream>

#include "BaseGameEntity.h"
#include "Locations.h"
#include "misc/ConsoleUtils.h"
#include "WaitressOwnedStates.h"
#include "fsm/StateMachine.h"

#include "misc/Utils.h"

template <class entity_type> class State; //pre-fixed with "template <class entity_type> " for vs8 compatibility

struct Telegram;

//bellow this value a waitress looks bad
const int SweatLevel = 4; //TODO voir si on change valeur
//above this value a waitress is bored
const int BoredomLevel = 5;


class Waitress : public BaseGameEntity
{
private:

	//an instance of the state machine class
	StateMachine<Waitress>*  m_pStateMachine;

	//how many nuggets the waitress has in her pockets
	int                   m_iGoldTips;

	//the higher the value, the sweatier the waitress
	int                   m_iSweat;

	//the higher the value, the more bored the waitress
	int                   m_iBoredom;

public:

    Waitress(int id, QMap<location_type, QLabel*> locations, QLabel* img = nullptr) :
		m_iGoldTips(0),
		m_iSweat(0),
		m_iBoredom(0),
        BaseGameEntity(id, saloon, locations, img)

	{
		//set up state machine
		m_pStateMachine = new StateMachine<Waitress>(this);

		m_pStateMachine->SetCurrentState(Bartend::Instance());

	}

	~Waitress() { delete m_pStateMachine; }

	//this must be implemented
	void Update();

	//so must this
	virtual bool  HandleMessage(const Telegram& msg);


	StateMachine<Waitress>* GetFSM()const { return m_pStateMachine; }



	//-------------------------------------------------------------accessors


	int           GoldTips()const { return m_iGoldTips; }
    void          SetGoldTips(int val) { val<0 ? m_iGoldTips = 0 : m_iGoldTips = val; }
	void          AddToGoldTips(int val);

	bool		  isSweaty()const;
	void		  DecreaseSweat() { m_iSweat -= 1; } //TODO voir si on change de valeur
	void		  IncreaseSweat() { m_iSweat += 1; }
    void		  SetSweat(int val) {val<0 ? m_iSweat=0 : m_iSweat = val; }
    int           GetSweat() { return m_iSweat; }

	bool          isBored()const;
	void          DecreaseBoredom() { m_iBoredom -= 1; }
	void          IncreaseBoredom() { m_iBoredom += 1; }
    void		  SetBoredom(int val) { val<0 ? m_iBoredom = 0 : m_iBoredom = val; }
    int           GetBoredom() { return m_iBoredom; }

};


#endif

