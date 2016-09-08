#ifndef NAMES_H
#define NAMES_H

#include <string>

enum 
{
  ent_Miner_Bob,
  ent_Elsa,
  //Add by Elo -- TODO remove
  ent_Miner_John
};

inline std::string GetNameOfEntity(int n)
{
  switch(n)
  {
  case ent_Miner_Bob:

    return "Miner Bob";

  case ent_Elsa:
    
    return "Elsa"; 

  //Add by Elo -- TODO remove
  case ent_Miner_John:

	  return "Miner John";

  default:

    return "UNKNOWN!";
  }
}

#endif