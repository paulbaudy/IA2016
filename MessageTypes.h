#ifndef MESSAGE_TYPES
#define MESSAGE_TYPES

#include <string>

enum message_type
{
  Msg_HiHoneyImHome,
  Msg_StewReady,
  Msg_HiWaitress,
  Msg_HiMiner,
  Msg_GiveMeADrink,
  Msg_GiveDrinkAndAskHarvest,
  Msg_GoodHarvest,
  Msg_BadHarvest,
  Msg_AskForTips,
  Msg_LeaveMeAlone,
  Msg_TakeGold,
  Msg_WaitingForDrink,
  Msg_MaybeNextTime,
  Msg_SeeYouSoon,
  Msg_AskForGold,
  Msg_ICanExplain,
};


inline std::string MsgToStr(int msg)
{
  switch (msg)
  {
  case Msg_HiHoneyImHome:
    return "HiHoneyImHome"; 

  case Msg_StewReady: 
    return "StewReady";

  case Msg_HiWaitress:
	return "HiWaitress";

  case Msg_HiMiner:
	  return "HiMiner";

  case Msg_GiveMeADrink:
	  return "GiveMeADrink";

  case Msg_GiveDrinkAndAskHarvest:
	  return "GiveDrinkAndAskHarvest";

  case Msg_GoodHarvest:
	  return "GoodHarvest";

  case Msg_BadHarvest:
	  return "BadHarvest";
 
  case Msg_AskForTips:
	  return "AskForTips";

  case Msg_LeaveMeAlone:
	  return "LeaveMeAlone";

  case Msg_TakeGold:
	  return "TakeGold";

  case Msg_WaitingForDrink:
	  return "I've waited way too long.";

  case Msg_MaybeNextTime:
	  return "Well. Maybe next time then..";

  case Msg_SeeYouSoon:
	  return "Thanks, see you soon.";

  default:

    return "Not recognized!";
  }
}

#endif