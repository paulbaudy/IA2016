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
	SetTextColor(BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	switch (msg.Msg)
	{
	case Msg_HiWaitress:

		cout << "\nMessage handled by " << GetNameOfEntity(pWaitress->ID())
			<< " at time: " << Clock->GetCurrentTime();

		SetTextColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

		cout << "\n" << GetNameOfEntity(pWaitress->ID())
			<< ": Oh! That's my favorite miner!";

		pWaitress->GetFSM()->ChangeState(InteractWithMiner::Instance());

		return true;

	}//end switch

	return false; //send message to global message handler
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
	SetTextColor(BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	switch (msg.Msg)
	{
	case Msg_HiWaitress:

		cout << "\nMessage handled by " << GetNameOfEntity(pWaitress->ID())
			<< " at time: " << Clock->GetCurrentTime();

		SetTextColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

		cout << "\n" << GetNameOfEntity(pWaitress->ID())
			<< ": Oh! That's my favorite miner over there!";

		pWaitress->GetFSM()->ChangeState(InteractWithMiner::Instance());

		return true;

	}//end switch

	return false; //send message to global message handler
}

//------------------------------------------------------------------------methods for InteractWithMiner
InteractWithMiner* InteractWithMiner::Instance()
{
	static InteractWithMiner instance;

	return &instance;
}


void InteractWithMiner::Enter(Waitress* pWaitress)
{
	//if the waitress is not already located at the bar, she must
	//change location to this bar
	if (pWaitress->Location() != saloon)
	{
		cout << "\n" << GetNameOfEntity(pWaitress->ID()) << ": " << "I'm coming darling!";

		pWaitress->ChangeLocation(saloon);
	}
	Dispatch->DispatchMessage(0.1,
							pWaitress->ID(),
							ent_Miner_Bob,
							Msg_HiMiner,
							NO_ADDITIONAL_INFO);

	cout << "\n" << GetNameOfEntity(pWaitress->ID()) << ": " << "Hi Miner, how are you today?";
}


void InteractWithMiner::Execute(Waitress* pWaitress)
{
	//Now the waitress is at the bar. She will talk to
	//the miner
	pWaitress->DecreaseBoredom();

	// cout << "\n" << GetNameOfEntity(pWaitress->ID()) << ": " << "Blablabla";

	//A message will be sent to end the conversation

}


void InteractWithMiner::Exit(Waitress* pWaitress)
{

}


bool InteractWithMiner::OnMessage(Waitress* pWaitress, const Telegram& msg)
{
	SetTextColor(BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	switch (msg.Msg)
	{
	case Msg_GiveMeADrink:

		cout << "\nMessage handled by " << GetNameOfEntity(pWaitress->ID())
			<< " at time: " << Clock->GetCurrentTime();

		Dispatch->DispatchMessage(0.1,
			pWaitress->ID(),
			ent_Miner_Bob,
			Msg_GiveDrinkAndAskHarvest,
			NO_ADDITIONAL_INFO);

		SetTextColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

		cout << "\n" << GetNameOfEntity(pWaitress->ID())
			<< ": There you go! Did you have a good harvest?";

		return true;

	case Msg_GoodHarvest:

		cout << "\nMessage handled by " << GetNameOfEntity(pWaitress->ID())
			<< " at time: " << Clock->GetCurrentTime();

		Dispatch->DispatchMessage(0.1,
			pWaitress->ID(),
			ent_Miner_Bob,
			Msg_AskForTips,
			NO_ADDITIONAL_INFO);

		SetTextColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

		cout << "\n" << GetNameOfEntity(pWaitress->ID())
			<< ": That's a good news! Don't you have some for your favorite waitress?";

		return true;

	case Msg_BadHarvest:
	case Msg_LeaveMeAlone:

		cout << "\nMessage handled by " << GetNameOfEntity(pWaitress->ID())
			<< " at time: " << Clock->GetCurrentTime();

		Dispatch->DispatchMessage(0.1,
			pWaitress->ID(),
			ent_Miner_Bob,
			Msg_MaybeNextTime,
			NO_ADDITIONAL_INFO);

		SetTextColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

		cout << "\n" << GetNameOfEntity(pWaitress->ID())
			<< ": That's too bad... Guess I have some work to do.";

		pWaitress->GetFSM()->RevertToPreviousState();
		return true;

	case Msg_TakeGold:

		cout << "\nMessage handled by " << GetNameOfEntity(pWaitress->ID())
			<< " at time: " << Clock->GetCurrentTime();

		Dispatch->DispatchMessage(0.1,
			pWaitress->ID(),
			ent_Miner_Bob,
			Msg_SeeYouSoon,
			NO_ADDITIONAL_INFO);

        pWaitress->AddToGoldTips(1);
		SetTextColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

		cout << "\n" << GetNameOfEntity(pWaitress->ID())
			<< ": Oh! Thank you, you're so cute! See you soon darling *kiss*";

		pWaitress->GetFSM()->RevertToPreviousState();
		return true;

	}//end switch

	return false; //send message to global message handler
} 
