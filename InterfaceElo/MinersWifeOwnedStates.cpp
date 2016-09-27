#include "MinersWifeOwnedStates.h"
#include "MinerOwnedStates.h"
#include "MinersWife.h"
#include "Locations.h"
#include "Time/CrudeTimer.h"
#include "MessageDispatcher.h"
#include "MessageTypes.h"
#include "EntityNames.h"

#include <iostream>
using std::cout;

#ifdef TEXTOUTPUT
#include <fstream>
extern std::ofstream os;
#define cout os
#endif

//-----------------------------------------------------------------------Global state

WifesGlobalState* WifesGlobalState::Instance()
{
  static WifesGlobalState instance;

  return &instance;
}


void WifesGlobalState::Execute(MinersWife* wife)
{
  //1 in 10 chance of needing the bathroom (provided she is not already
  //in the bathroom)
  if ( (RandFloat() < 0.1) && 
       !wife->GetFSM()->isInState(*VisitBathroom::Instance()) )
  {
    wife->GetFSM()->ChangeState(VisitBathroom::Instance());
  }
}

bool WifesGlobalState::OnMessage(MinersWife* wife, const Telegram& msg)
{
  SetTextColor(BACKGROUND_RED|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
  std::stringstream ss;
  std::stringstream ss2;

  switch(msg.Msg)
  {
  case Msg_NotWhatLooksLike: {

      ss << "\nMessage handled by " << GetNameOfEntity(wife->ID()) << " at time: "
		  << Clock->GetCurrentTime();
      cout << ss.str();

	  SetTextColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);


      ss2 << "\n" << GetNameOfEntity(wife->ID()) <<
           ": Really... I'm not sure! Go away, I don't what to see you for the moment!";
      cout << ss2.str();

	  return true;
  }

	 
  case Msg_HiHoneyImHome:
   {

       ss << "\nMessage handled by " << GetNameOfEntity(wife->ID()) << " at time: "
       << Clock->GetCurrentTime();
       cout << ss.str();

     SetTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY);


     ss2 << "\n" << GetNameOfEntity(wife->ID()) <<
          ": Hi honey. Let me make you some of mah fine country stew";
     cout << ss2.str();

     wife->GetFSM()->ChangeState(CookStew::Instance());
   }

   return true;

  }//end switch

  return false;
}

//-------------------------------------------------------------------------DoHouseWork

DoHouseWork* DoHouseWork::Instance()
{
  static DoHouseWork instance;

  return &instance;
}


void DoHouseWork::Enter(MinersWife* wife)
{
  std::stringstream ss;
  ss << "\n" << GetNameOfEntity(wife->ID()) << ": Time to do some more housework!";
  cout << ss.str();
}


void DoHouseWork::Execute(MinersWife* wife)
{
    std::stringstream ss;
  switch(RandInt(0,2))
  {
  case 0:

    ss << "\n" << GetNameOfEntity(wife->ID()) << ": Moppin' the floor";

    break;

  case 1:

    ss << "\n" << GetNameOfEntity(wife->ID()) << ": Washin' the dishes";

    break;

  case 2:

    ss << "\n" << GetNameOfEntity(wife->ID()) << ": Makin' the bed";

    break;
  }
  cout << ss.str();
}

void DoHouseWork::Exit(MinersWife* wife)
{
}

bool DoHouseWork::OnMessage(MinersWife* wife, const Telegram& msg)
{
  return false;
}

//------------------------------------------------------------------------VisitBathroom

VisitBathroom* VisitBathroom::Instance()
{
  static VisitBathroom instance;

  return &instance;
}


void VisitBathroom::Enter(MinersWife* wife)
{  
  std::stringstream ss;
  ss << "\n" << GetNameOfEntity(wife->ID()) << ": Walkin' to the can. Need to powda mah pretty li'lle nose";
  cout << ss.str();
}


void VisitBathroom::Execute(MinersWife* wife)
{
  std::stringstream ss;
  ss << "\n" << GetNameOfEntity(wife->ID()) << ": Ahhhhhh! Sweet relief!";
  cout << ss.str();

  wife->GetFSM()->RevertToPreviousState();
}

void VisitBathroom::Exit(MinersWife* wife)
{
  std::stringstream ss;
  ss << "\n" << GetNameOfEntity(wife->ID()) << ": Leavin' the Jon";
  cout << ss.str();
}


bool VisitBathroom::OnMessage(MinersWife* wife, const Telegram& msg)
{
  return false;
}


//------------------------------------------------------------------------CookStew

CookStew* CookStew::Instance()
{
  static CookStew instance;

  return &instance;
}


void CookStew::Enter(MinersWife* wife)
{
  //if not already cooking put the stew in the oven
  if (!wife->Cooking())
  {
    std::stringstream ss;
    ss << "\n" << GetNameOfEntity(wife->ID()) << ": Putting the stew in the oven";
    cout << ss.str();
  
    //send a delayed message myself so that I know when to take the stew
    //out of the oven
    Dispatch->DispatchMessage(1.5,                  //time delay
                              wife->ID(),           //sender ID
                              wife->ID(),           //receiver ID
                              Msg_StewReady,        //msg
                              NO_ADDITIONAL_INFO); 

    wife->SetCooking(true);
  }
}


void CookStew::Execute(MinersWife* wife)
{
  std::stringstream ss;
  ss << "\n" << GetNameOfEntity(wife->ID()) << ": Fussin' over food";
  cout << ss.str();
}

void CookStew::Exit(MinersWife* wife)
{
  SetTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY);
  std::stringstream ss;
  ss << "\n" << GetNameOfEntity(wife->ID()) << ": Puttin' the stew on the table";
  cout << ss.str();
}


bool CookStew::OnMessage(MinersWife* wife, const Telegram& msg)
{
  SetTextColor(BACKGROUND_RED|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
  std::stringstream ss;
  std::stringstream ss2;

  switch(msg.Msg)
  {
    case Msg_StewReady:
    {

      ss << "\nMessage received by " << GetNameOfEntity(wife->ID()) <<
           " at time: " << Clock->GetCurrentTime();
      cout << ss.str();

      SetTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY);

      ss2 << "\n" << GetNameOfEntity(wife->ID()) << ": StewReady! Lets eat";
      cout << ss2.str();

      //let hubby know the stew is ready
      Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY,
                                wife->ID(),
                                ent_Miner_Bob,
                                Msg_StewReady,
                                NO_ADDITIONAL_INFO);

      wife->SetCooking(false);

      wife->GetFSM()->ChangeState(DoHouseWork::Instance());               
    }

    return true;

  }//end switch

  return false;
}
