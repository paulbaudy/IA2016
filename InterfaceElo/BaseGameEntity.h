#ifndef ENTITY_H
#define ENTITY_H
//------------------------------------------------------------------------
//
//  Name:   BaseGameEntity.h
//
//  Desc:   Base class for a game object
//
//  Author: Mat Buckland 2002 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------
#include <string>

#include "Locations.h"
#include "messaging/Telegram.h"
#include <QLabel>
#include <QMap>
#include <QObject>


class BaseGameEntity: public QObject
{

Q_OBJECT

private:

  //every entity must have a unique identifying number
  int          m_ID;

  //this is the next valid ID. Each time a BaseGameEntity is instantiated
  //this value is updated
  static int  m_iNextValidID;

  //this must be called within the constructor to make sure the ID is set
  //correctly. It verifies that the value passed to the method is greater
  //or equal to the next valid ID, before setting the ID and incrementing
  //the next valid ID
  void SetID(int val);

  location_type   m_Location;
  QLabel *img;
  QMap<location_type, QLabel*> locations;

public:

  BaseGameEntity(int id, location_type location, QMap<location_type, QLabel*> locations, QLabel *img = nullptr)
  {
    SetID(id);
    m_Location = location;
    img!=nullptr?this->img = img:this->img=nullptr;
    this->locations = locations;

  }

  virtual ~BaseGameEntity(){}

  //all entities must implement an update function
  virtual void  Update()=0;

  //all entities can communicate using messages. They are sent
  //using the MessageDispatcher singleton class
  virtual bool  HandleMessage(const Telegram& msg)=0;

  int           ID()const{return m_ID;}  

  location_type Location()const{return m_Location;}
  void          ChangeLocation(location_type loc){
      m_Location=loc;
      emit newLocation(loc, this->img);



  }
signals:
    void newLocation(location_type loc, QLabel *img);
    void emitText(QString text);

};



#endif


