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
		cout << "\n" << GetNameOfEntity(pWaitress->ID()) << ": " << "Walkin' to the bar";

		pWaitress->ChangeLocation(saloon);
	}
}


void Bartend::Execute(Waitress* pWaitress)
{
	//Now the waitress is at the bar, she will work until she is bored
	//or if she isn't pretty enough to bartend
	pWaitress->DecreaseBeauty();

	pWaitress->IncreaseBoredom();

	cout << "\n" << GetNameOfEntity(pWaitress->ID()) << ": " << "I love bartending!";

	//if not enough pretty, go to the restroom
	if (!pWaitress->isPretty())
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

//------------------------------------------------------------------------methods for VisitBankAndDepositGold
