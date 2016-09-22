#include "MinerOwnedStates.h"
#include "fsm/State.h"
#include "Miner.h"
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


//------------------------------------------------------------------------methods for EnterMineAndDigForNugget
EnterMineAndDigForNugget* EnterMineAndDigForNugget::Instance()
{
  static EnterMineAndDigForNugget instance;

  return &instance;
}


void EnterMineAndDigForNugget::Enter(Miner* pMiner)
{
  //if the miner is not already located at the goldmine, he must
  //change location to the gold mine
  if (pMiner->Location() != goldmine)
  {
    cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Walkin' to the goldmine";

    pMiner->ChangeLocation(goldmine);
  }
}


void EnterMineAndDigForNugget::Execute(Miner* pMiner)
{  
  //Now the miner is at the goldmine he digs for gold until he
  //is carrying in excess of MaxNuggets. If he gets thirsty during
  //his digging he packs up work for a while and changes state to
  //gp to the saloon for a whiskey.
  pMiner->AddToGoldCarried(1);

  pMiner->IncreaseFatigue();

  cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Pickin' up a nugget";

  //if enough gold mined, go and put it in the bank
  if (pMiner->PocketsFull())
  {
    pMiner->GetFSM()->ChangeState(VisitBankAndDepositGold::Instance());
  }

  if (pMiner->Thirsty())
  {
    pMiner->GetFSM()->ChangeState(QuenchThirst::Instance());
  }
}


void EnterMineAndDigForNugget::Exit(Miner* pMiner)
{
  cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " 
       << "Ah'm leavin' the goldmine with mah pockets full o' sweet gold";
}


bool EnterMineAndDigForNugget::OnMessage(Miner* pMiner, const Telegram& msg)
{
  //send msg to global message handler
  return false;
}

//------------------------------------------------------------------------methods for VisitBankAndDepositGold

VisitBankAndDepositGold* VisitBankAndDepositGold::Instance()
{
  static VisitBankAndDepositGold instance;

  return &instance;
}

void VisitBankAndDepositGold::Enter(Miner* pMiner)
{  
  //on entry the miner makes sure he is located at the bank
  if (pMiner->Location() != bank)
  {
    cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Goin' to the bank. Yes siree";

    pMiner->ChangeLocation(bank);
  }
}


void VisitBankAndDepositGold::Execute(Miner* pMiner)
{
  //deposit the gold
  pMiner->AddToWealth(pMiner->GoldCarried());
    
  pMiner->SetGoldCarried(0);

  cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " 
       << "Depositing gold. Total savings now: "<< pMiner->Wealth();

  //wealthy enough to have a well earned rest?
  if (pMiner->Wealth() >= ComfortLevel)
  {
    cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " 
         << "WooHoo! Rich enough for now. Back home to mah li'lle lady";
      
    pMiner->GetFSM()->ChangeState(GoHomeAndSleepTilRested::Instance());      
  }

  //otherwise get more gold
  else 
  {
    pMiner->GetFSM()->ChangeState(EnterMineAndDigForNugget::Instance());
  }
}


void VisitBankAndDepositGold::Exit(Miner* pMiner)
{
  cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Leavin' the bank";
}


bool VisitBankAndDepositGold::OnMessage(Miner* pMiner, const Telegram& msg)
{
  //send msg to global message handler
  return false;
}
//------------------------------------------------------------------------methods for GoHomeAndSleepTilRested

GoHomeAndSleepTilRested* GoHomeAndSleepTilRested::Instance()
{
  static GoHomeAndSleepTilRested instance;

  return &instance;
}

void GoHomeAndSleepTilRested::Enter(Miner* pMiner)
{
  if (pMiner->Location() != shack)
  {
    cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Walkin' home";

    pMiner->ChangeLocation(shack); 

    if(pMiner->Kissed()){
        //let the wife know that's not what it looks like
        Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY, //time delay
                                  pMiner->ID(),        //ID of sender
                                  ent_Elsa,            //ID of recipient
                                  Msg_NotWhatLooksLike,   //the message
                                  NO_ADDITIONAL_INFO);

        SetTextColor(FOREGROUND_RED|FOREGROUND_INTENSITY);

        cout << "\n" << GetNameOfEntity(pMiner->ID())
             << ": Honey, it's net' whot it looks lik'! A' prumis' you!";
        pMiner->cleanLipstick();
    }else{
        //let the wife know I'm home
        Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY, //time delay
                                  pMiner->ID(),        //ID of sender
                                  ent_Elsa,            //ID of recipient
                                  Msg_HiHoneyImHome,   //the message
                                  NO_ADDITIONAL_INFO);
    }
  }
}

void GoHomeAndSleepTilRested::Execute(Miner* pMiner)
{ 
  //if miner is not fatigued start to dig for nuggets again.
  if (!pMiner->Fatigued())
  {
     cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " 
          << "All mah fatigue has drained away. Time to find more gold!";

     pMiner->GetFSM()->ChangeState(EnterMineAndDigForNugget::Instance());
  }

  else 
  {
    //sleep
    pMiner->DecreaseFatigue();

    cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "ZZZZ... ";
  } 
}

void GoHomeAndSleepTilRested::Exit(Miner* pMiner)
{ 
}


bool GoHomeAndSleepTilRested::OnMessage(Miner* pMiner, const Telegram& msg)
{
   SetTextColor(BACKGROUND_RED|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);

   switch(msg.Msg)
   {
   case Msg_StewReady:

     cout << "\nMessage handled by " << GetNameOfEntity(pMiner->ID()) 
     << " at time: " << Clock->GetCurrentTime();

     SetTextColor(FOREGROUND_RED|FOREGROUND_INTENSITY);

     cout << "\n" << GetNameOfEntity(pMiner->ID()) 
          << ": Okay Hun, ahm a comin'!";

     pMiner->GetFSM()->ChangeState(EatStew::Instance());
      
     return true;

   }//end switch

   return false; //send message to global message handler
}

//------------------------------------------------------------------------QuenchThirst

QuenchThirst* QuenchThirst::Instance()
{
  static QuenchThirst instance;

  return &instance;
}

void QuenchThirst::Enter(Miner* pMiner)
{
  if (pMiner->Location() != saloon)
  {    
    pMiner->ChangeLocation(saloon);

    cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Boy, ah sure is thusty! Walking to the saloon";

	//let the waitress know I'm here
	Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY, //time delay
		pMiner->ID(),        //ID of sender
		ent_Jessica,            //ID of recipient
		Msg_HiWaitress,   //the message
		NO_ADDITIONAL_INFO); 

	Dispatch->DispatchMessage(1.5, //time delay
		pMiner->ID(),        //ID of sender
		pMiner->ID(),            //ID of recipient
		Msg_WaitingForDrink,   //the message
		NO_ADDITIONAL_INFO);
  }
}

void QuenchThirst::Execute(Miner* pMiner)
{
	// pMiner->BuyAndDrinkAWhiskey();

	// cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "That's mighty fine sippin' liquer";
	
	// pMiner->GetFSM()->ChangeState(EnterMineAndDigForNugget::Instance());

	//let the waitress know I'm here
	Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY, //time delay
		pMiner->ID(),        //ID of sender
		ent_Jessica,            //ID of recipient
		Msg_HiWaitress,   //the message
		NO_ADDITIONAL_INFO);

	cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Still waiting for Jess...";

}


void QuenchThirst::Exit(Miner* pMiner)
{ 
	if (!pMiner->Thirsty()) {
		cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Leaving the saloon, feelin' good";
	}
}


bool QuenchThirst::OnMessage(Miner* pMiner, const Telegram& msg)
{
	SetTextColor(BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	switch (msg.Msg)
	{
	case Msg_HiMiner:

		cout << "\nMessage handled by " << GetNameOfEntity(pMiner->ID())
			<< " at time: " << Clock->GetCurrentTime();

		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);


		pMiner->GetFSM()->ChangeState(InteractWithWaitress::Instance());

		return true;

	case Msg_WaitingForDrink:
		cout << "\nMessage handled by " << GetNameOfEntity(pMiner->ID())
			<< " at time: " << Clock->GetCurrentTime();

		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);

		pMiner->BuyAndDrinkAWhiskey();

		cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "That's mighty fine sippin' liquer"; 

		pMiner->GetFSM()->ChangeState(EnterMineAndDigForNugget::Instance());
	}//end switch

	return false; //send message to global message handler
}

//------------------------------------------------------------------------InteractWithWaitress

InteractWithWaitress* InteractWithWaitress::Instance() {
	static InteractWithWaitress instance;

	return &instance;
}

void InteractWithWaitress::Enter(Miner* pMiner) {
	//if the miner is not already located at the saloon, he must
	//change location to the gold mine
	if (pMiner->Location() != saloon) {

		pMiner->ChangeLocation(saloon);
	}

	Dispatch->DispatchMessage(0.1, //time delay
		pMiner->ID(),        //ID of sender
		ent_Jessica,            //ID of recipient
		Msg_GiveMeADrink,   //the message
		NO_ADDITIONAL_INFO);

	cout << "\n" << GetNameOfEntity(pMiner->ID())
		<< ": Oh, fine! Can I have my sippin' liquer?";
}

void InteractWithWaitress::Execute(Miner* pMiner) {

	// cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Bla bla!";

}

void InteractWithWaitress::Exit(Miner* pMiner) {

}

bool InteractWithWaitress::OnMessage(Miner* pMiner, const Telegram& msg) {
	SetTextColor(BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	message_type msgt;

	switch (msg.Msg)
	{
	case Msg_GiveDrinkAndAskHarvest:
		cout << "\nMessage handled by " << GetNameOfEntity(pMiner->ID())
			<< " at time: " << Clock->GetCurrentTime();

		

		pMiner->BuyAndDrinkAWhiskey();

        (pMiner->GoldCarried() >= 2) ? msgt = Msg_GoodHarvest : msgt = Msg_BadHarvest;

		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);

		Dispatch->DispatchMessage(0.1, //time delay
		pMiner->ID(),        //ID of sender
		ent_Jessica,            //ID of recipient
		msgt,   //the message
		NO_ADDITIONAL_INFO);

		msgt ==Msg_GoodHarvest?
			cout << "\n" << GetNameOfEntity(pMiner->ID())
			<< ": Oh yeah, a real gold mine! My pockets are almost full'!": 
			cout << "\n" << GetNameOfEntity(pMiner->ID())
			<< ": Not really. This is just not my day.";

		return true;

	case Msg_AskForTips:
		cout << "\nMessage handled by " << GetNameOfEntity(pMiner->ID())
			<< " at time: " << Clock->GetCurrentTime();

        (RandFloat() < 0.5) ? msgt = Msg_LeaveMeAlone : msgt = Msg_TakeGold;

		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);

		Dispatch->DispatchMessage(0.1, //time delay
			pMiner->ID(),        //ID of sender
			ent_Jessica,            //ID of recipient
			msgt,   //the message
			NO_ADDITIONAL_INFO);

		msgt == Msg_LeaveMeAlone ?
			cout << "\n" << GetNameOfEntity(pMiner->ID())
			<< ":  Leave me alone. I'm tired..." :
			cout << "\n" << GetNameOfEntity(pMiner->ID())
			<< ": What a good idea! Take this nugget!";

		return true;

	case Msg_MaybeNextTime:

		cout << "\nMessage handled by " << GetNameOfEntity(pMiner->ID())
			<< " at time: " << Clock->GetCurrentTime();

		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);

		cout << "\n" << GetNameOfEntity(pMiner->ID())
            << ": Okay Hun, see ya'! Let's finish my drink!";

        //Drink his last sip
        pMiner->SetThirst(0);

		pMiner->GetFSM()->ChangeState(EnterMineAndDigForNugget::Instance());

		return true;
		
	case Msg_SeeYouSoon:
		cout << "\nMessage handled by " << GetNameOfEntity(pMiner->ID())
			<< " at time: " << Clock->GetCurrentTime();

		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);

		pMiner->getKissed();

		cout << "\n" << GetNameOfEntity(pMiner->ID())
            << ": Okay, see ya'! Let's finish my drink!";

        //Drink his last sip
        pMiner->SetThirst(0);
		
		pMiner->GetFSM()->ChangeState(VisitBankAndDepositGold::Instance());

		return true;

	}//end switch

	return false; //send message to global message handler
}


//------------------------------------------------------------------------EatStew

EatStew* EatStew::Instance()
{
  static EatStew instance;

  return &instance;
}


void EatStew::Enter(Miner* pMiner)
{
  cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Smells Reaaal goood Elsa!";
}

void EatStew::Execute(Miner* pMiner)
{

  cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Tastes real good too!";

  pMiner->GetFSM()->RevertToPreviousState();
}

void EatStew::Exit(Miner* pMiner)
{ 
  cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Thankya li'lle lady. Ah better get back to whatever ah wuz doin'";
}


bool EatStew::OnMessage(Miner* pMiner, const Telegram& msg)
{
  //send msg to global message handler
  return false;
}


