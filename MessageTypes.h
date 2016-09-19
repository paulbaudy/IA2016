#ifndef MESSAGE_TYPES
#define MESSAGE_TYPES

#include <string>

enum message_type
{
  Msg_HiHoneyImHome,
  Msg_StewReady,
  Msg_HiWaitress,
  Msg_HoneyImHere,
  Msg_WaitingForDrink,
  Msg_MaybeNextTime,
  Msg_SeeYouSoon,
  Msg_AskForGold,
  Msg_ICanExplain,
  Msg_HiMiner,
};


inline std::string MsgToStr(int msg)
{
  switch (msg)
  {
  case Msg_HiHoneyImHome:
    
    return "HiHoneyImHome"; 

  case Msg_StewReady:
    
    return "StewReady";

  case Msg_HoneyImHere:
	  return "Hello honey, I'm here!";

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