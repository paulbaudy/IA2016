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
        std::stringstream ss;
        ss << "\n" << GetNameOfEntity(pWaitress->ID()) << ": " << "I'm walking to the bar";
        cout << ss.str();

		pWaitress->ChangeLocation(saloon);
	}
}


void Bartend::Execute(Waitress* pWaitress)
{
	//Now the waitress is at the bar, she will work until she is bored
	//or if she isn't pretty enough to bartend
	pWaitress->IncreaseSweat();

	pWaitress->IncreaseBoredom();

    std::stringstream ss;
    ss << "\n" << GetNameOfEntity(pWaitress->ID()) << ": " << "I love bartending!";
    cout << ss.str();

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
    std::stringstream ss;
    ss << "\n" << GetNameOfEntity(pWaitress->ID()) << ": "
        << "I'm leaving the bottles darlings!";
    cout << ss.str();
}


bool Bartend::OnMessage(Waitress* pWaitress, const Telegram& msg)
{
	SetTextColor(BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    std::stringstream ss;
    std::stringstream ss2;

	switch (msg.Msg)
	{
	case Msg_HiWaitress:

        ss << "\nMessage handled by " << GetNameOfEntity(pWaitress->ID())
			<< " at time: " << Clock->GetCurrentTime();
        cout << ss.str();

		SetTextColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);


        ss2 << "\n" << GetNameOfEntity(pWaitress->ID())
			<< ": Oh! That's my favorite miner!";
        cout << ss2.str();

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
        std::stringstream ss;
        ss << "\n" << GetNameOfEntity(pWaitress->ID()) << ": " << "Let's go to the restroom";
        cout << ss.str();

		pWaitress->ChangeLocation(saloonRestroom);
	}
}


void EnterRestroomAndMakeUp::Execute(Waitress* pWaitress)
{
	//Now the waitress is at the restroom. She will clean 
	//her face and do her make up
	pWaitress->SetSweat(0);

	pWaitress->IncreaseBoredom();

    std::stringstream ss;
    ss << "\n" << GetNameOfEntity(pWaitress->ID()) << ": " << "I'll be the prettiest girl!";
    cout << ss.str();

	pWaitress->GetFSM()->RevertToPreviousState();
}


void EnterRestroomAndMakeUp::Exit(Waitress* pWaitress)
{
    std::stringstream ss;
    ss << "\n" << GetNameOfEntity(pWaitress->ID()) << ": "
		<< "Bye peace and quiet place!";
    cout << ss.str();
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
        std::stringstream ss;
        ss << "\n" << GetNameOfEntity(pWaitress->ID()) << ": " << "I'm walking to the piano!";
        cout << ss.str();

		pWaitress->ChangeLocation(saloonPiano);
	}
}


void PractisePiano::Execute(Waitress* pWaitress)
{
	//Now the waitress is at the piano, she will play
	//randomly a music
	pWaitress->IncreaseSweat();
	pWaitress->DecreaseBoredom();

    std::stringstream ss;
    ss << "\n" << GetNameOfEntity(pWaitress->ID()) << ": " << "What a groove!";
    cout << ss.str();

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
    std::stringstream ss;
    ss << "\n" << GetNameOfEntity(pWaitress->ID()) << ": "
		<< "The artist is leaving the scene!";
    cout << ss.str();
}


bool PractisePiano::OnMessage(Waitress* pWaitress, const Telegram& msg)
{
	SetTextColor(BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    std::stringstream ss;
    std::stringstream ss2;

	switch (msg.Msg)
	{
	case Msg_HiWaitress:

        ss << "\nMessage handled by " << GetNameOfEntity(pWaitress->ID())
			<< " at time: " << Clock->GetCurrentTime();
        cout << ss.str();

		SetTextColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

        ss2 << "\n" << GetNameOfEntity(pWaitress->ID())
			<< ": Oh! That's my favorite miner over there!";
        cout << ss2.str();

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
    std::stringstream ss;
    std::stringstream ss2;

	if (pWaitress->Location() != saloon)
	{
        ss << "\n" << GetNameOfEntity(pWaitress->ID()) << ": " << "I'm coming darling!";
        cout << ss.str();
		pWaitress->ChangeLocation(saloon);
	}
    Dispatch->DispatchMessage(0.001,
							pWaitress->ID(),
							ent_Miner_Bob,
							Msg_HiMiner,
							NO_ADDITIONAL_INFO);

    ss2 << "\n" << GetNameOfEntity(pWaitress->ID()) << ": " << "Hi Miner, how are you today?";
    cout << ss2.str();
}


void InteractWithMiner::Execute(Waitress* pWaitress)
{
	//Now the waitress is at the bar. She will talk to
	//the miner
	pWaitress->DecreaseBoredom();

	//A message will be sent to end the conversation

}


void InteractWithMiner::Exit(Waitress* pWaitress)
{

}


bool InteractWithMiner::OnMessage(Waitress* pWaitress, const Telegram& msg)
{
	SetTextColor(BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    std::stringstream ss;
    std::stringstream ss2;

	switch (msg.Msg)
	{
    //Bob left before she can come
    case Msg_AlreadyLeft:

        SetTextColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        ss << "\n" << GetNameOfEntity(pWaitress->ID())
            << ": That's too sad... He will come back soon!";
        cout << ss.str();
        pWaitress->GetFSM()->RevertToPreviousState();
        return true;

    //Bob asks her some drink
	case Msg_GiveMeADrink:

        ss << "\nMessage handled by " << GetNameOfEntity(pWaitress->ID())
			<< " at time: " << Clock->GetCurrentTime();
        cout << ss.str();

        Dispatch->DispatchMessage(0.01,
			pWaitress->ID(),
			ent_Miner_Bob,
			Msg_GiveDrinkAndAskHarvest,
			NO_ADDITIONAL_INFO);

		SetTextColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

        ss2 << "\n" << GetNameOfEntity(pWaitress->ID())
			<< ": There you go! Did you have a good harvest?";
        cout << ss2.str();

		return true;

    //Bob explains he had a good harvest
	case Msg_GoodHarvest:

        ss << "\nMessage handled by " << GetNameOfEntity(pWaitress->ID())
			<< " at time: " << Clock->GetCurrentTime();
        cout << ss.str();

        Dispatch->DispatchMessage(0.01,
			pWaitress->ID(),
			ent_Miner_Bob,
			Msg_AskForTips,
			NO_ADDITIONAL_INFO);

		SetTextColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

        ss2 << "\n" << GetNameOfEntity(pWaitress->ID())
			<< ": That's a good news! Don't you have some for your favorite waitress?";
        cout << ss2.str();

		return true;

    //Bob doesn't have any nugget to give, or just doesn't want to
	case Msg_BadHarvest:
	case Msg_LeaveMeAlone:


        ss << "\nMessage handled by " << GetNameOfEntity(pWaitress->ID())
			<< " at time: " << Clock->GetCurrentTime();
        cout << ss.str();

        Dispatch->DispatchMessage(0.01,
			pWaitress->ID(),
			ent_Miner_Bob,
			Msg_MaybeNextTime,
			NO_ADDITIONAL_INFO);

		SetTextColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

        ss2 << "\n" << GetNameOfEntity(pWaitress->ID())
			<< ": That's too bad... Guess I have some work to do.";
        cout << ss2.str();

		pWaitress->GetFSM()->RevertToPreviousState();
		return true;

    //Bob gives a nugget to Jessica
	case Msg_TakeGold:

        ss << "\nMessage handled by " << GetNameOfEntity(pWaitress->ID())
			<< " at time: " << Clock->GetCurrentTime();
        cout << ss.str();

        Dispatch->DispatchMessage(0.01,
			pWaitress->ID(),
			ent_Miner_Bob,
			Msg_SeeYouSoon,
			NO_ADDITIONAL_INFO);

        pWaitress->AddToGoldTips(1);
		SetTextColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

        ss2 << "\n" << GetNameOfEntity(pWaitress->ID())
			<< ": Oh! Thank you, you're so cute! See you soon darling *kiss*";
        cout << ss2.str();

		pWaitress->GetFSM()->RevertToPreviousState();
		return true;

	}//end switch

	return false; //send message to global message handler
} 
