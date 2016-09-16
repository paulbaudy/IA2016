#include "WaitressOwnedStates.h"
#include "fsm/State.h"
#include "Waitress.h"
#include "Locations.h"
#include "messaging/Telegram.h"
#include "MessageDispatcher.h"
#include "MessageTypes.h"
#include "Time/CrudeTimer.h"
#include "EntityNames.h"

#include <iostream>
using std::cout;


#ifdef TEXTOUTPUT
#include <fstream>
extern std::ofstream os;
#define cout os
#endif


//------------------------------------------------------------------------methods for Bartend
Bartend* Bartend::Instance()
{
	static Bartend instance;

	return &instance;
}


void Bartend::Enter(Waitress* pWaitress)
{
	//if the waitress is not already located at the bar, she must
	//change location to the saloon
	if (pWaitress->Location() != saloon)
	{
		cout << "\n" << GetNameOfEntity(pWaitress->ID()) << ": " << "I'm walking to the bar";

		pWaitress->ChangeLocation(saloon);
	}
}


void Bartend::Execute(Waitress* pWaitress)
{
	//Now the waitress is at the bar, she will work until she is bored
	//or if she isn't pretty enough to bartend
	pWaitress->IncreaseSweat();

	pWaitress->IncreaseBoredom();

	cout << "\n" << GetNameOfEntity(pWaitress->ID()) << ": " << "I love bartending!";

	//if not enough pretty, go to the restroom
	if (pWaitress->isSweaty())
	{
		pWaitress->GetFSM()->ChangeState(EnterRestroomAndMakeUp::Instance());
	}

	if (pWaitress->isBored())
	{
		pWaitress->GetFSM()->ChangeState(PractisePiano::Instance());
	}
}


void Bartend::Exit(Waitress* pWaitress)
{
	cout << "\n" << GetNameOfEntity(pWaitress->ID()) << ": "
		<< "I'm leaving the bar darlings!";
}


bool Bartend::OnMessage(Waitress* pWaitress, const Telegram& msg)
{
	//send msg to global message handler
	return false;
}

//------------------------------------------------------------------------methods for EnterRestroomAndMakeUp
EnterRestroomAndMakeUp* EnterRestroomAndMakeUp::Instance()
{
	static EnterRestroomAndMakeUp instance;

	return &instance;
}


void EnterRestroomAndMakeUp::Enter(Waitress* pWaitress)
{
	//if the waitress is not already located at the saloon's restroom, she must
	//change location to this restroom
	if (pWaitress->Location() != saloonRestroom)
	{
		cout << "\n" << GetNameOfEntity(pWaitress->ID()) << ": " << "Let's go to the restroom";

		pWaitress->ChangeLocation(saloonRestroom);
	}
}


void EnterRestroomAndMakeUp::Execute(Waitress* pWaitress)
{
	//Now the waitress is at the restroom. She will clean 
	//her face and do her make up
	pWaitress->SetSweat(0);

	pWaitress->IncreaseBoredom();

	cout << "\n" << GetNameOfEntity(pWaitress->ID()) << ": " << "I'll be the prettiest girl!";

	pWaitress->GetFSM()->RevertToPreviousState();
}


void EnterRestroomAndMakeUp::Exit(Waitress* pWaitress)
{
	cout << "\n" << GetNameOfEntity(pWaitress->ID()) << ": "
		<< "Bye peace and quiet place!";
}


bool EnterRestroomAndMakeUp::OnMessage(Waitress* pWaitress, const Telegram& msg)
{
	//send msg to global message handler
	return false;
}

//------------------------------------------------------------------------methods for PractisePiano
PractisePiano* PractisePiano::Instance()
{
	static PractisePiano instance;

	return &instance;
}


void PractisePiano::Enter(Waitress* pWaitress)
{
	//if the waitress is not already located at the piano, she must
	//change location to the piano
	if (pWaitress->Location() != saloonPiano)
	{
		cout << "\n" << GetNameOfEntity(pWaitress->ID()) << ": " << "I'm walking to the piano!";

		pWaitress->ChangeLocation(saloonPiano);
	}
}


void PractisePiano::Execute(Waitress* pWaitress)
{
	//Now the waitress is at the piano, she will play
	//randomly a music
	pWaitress->IncreaseSweat();
	pWaitress->DecreaseBoredom();

	cout << "\n" << GetNameOfEntity(pWaitress->ID()) << ": " << "What a groove!";

	//if not enough pretty, go to the restroom
	if (pWaitress->isSweaty())
	{
		pWaitress->GetFSM()->ChangeState(EnterRestroomAndMakeUp::Instance());
	}else if (!pWaitress->isBored() && RandFloat() < 0.4)
	{
		pWaitress->GetFSM()->ChangeState(Bartend::Instance());
	}
}


void PractisePiano::Exit(Waitress* pWaitress)
{
	cout << "\n" << GetNameOfEntity(pWaitress->ID()) << ": "
		<< "The artist is leaving the scene!";
}


bool PractisePiano::OnMessage(Waitress* pWaitress, const Telegram& msg)
{
	//send msg to global message handler
	return false;
}
