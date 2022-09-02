#include <iostream>
#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include "Button2.h"
#include <string.h>



//WiFiClientSecure net;

WiFiClient wifiClient;
PubSubClient client(wifiClient);

Button2 activeButton01,activeButton02,activeButton03,activeButton04,activeButton05,activeButton06,activeButton07,disableButton01,disableButton02,disableButton03,disableButton04,disableButton05,disableButton06,disableButton07;
//depois separar os nomes para buttonEnable1,buttonDisable1.....


#define AWS_IOT_PUBLISH_TOPIC "EmergencyCall_Leitos"

#define leitoEnable01 34
#define leitoEnable02 35
#define leitoEnable03 32
#define leitoEnable04 27
#define leitoEnable05 14
#define leitoEnable06 21
#define leitoEnable07 19




#define leitoDisable01 33 
#define leitoDisable02 25
#define leitoDisable03 26
#define leitoDisable04 13
#define leitoDisable05 23
#define leitoDisable06 22
#define leitoDisable07 18




int idLeito01 = 1;
int idLeito02 = 2;
int idLeito03 = 3;
int idLeito04 = 4;
int idLeito05 = 5;
int idLeito06 = 6;
int idLeito07 = 7;



int postoRef = 1;



class Leitos
{

  private:

  static void sendMessage(int idLeito , int statusButton, int postoRef )
  {
    StaticJsonDocument<512> doc;
    doc["id"] = idLeito;
    doc["status"] = statusButton;
    doc["posto_ref"] = postoRef;
    char jsonBuffer[700];
    serializeJson(doc, jsonBuffer);
    client.publish(AWS_IOT_PUBLISH_TOPIC, jsonBuffer);
    Serial.println(jsonBuffer);
  }


  static void handleIdDisable(Button2 t,int id){
    int statebutton = 0;
    int id3=0;
    t.setID(id);
    id3=t.getID();
    sendMessage(id3,statebutton,postoRef);
  }

  static void handleIdActive(Button2 t,int id){
    int statebutton = 1;
    int id2=0;
    t.setID(id);
    id2=t.getID();
    sendMessage(id2,statebutton,postoRef);
  }

  static void activeCall(Button2& btn){
    if(btn == activeButton01){
    
      handleIdActive(activeButton01,idLeito01);
    }else if(btn == activeButton02){
    
      handleIdActive(activeButton02,idLeito02);

    }else if(btn == activeButton03){

      handleIdActive(activeButton03,idLeito03);

    }else if(btn == activeButton04){

      handleIdActive(activeButton04,idLeito04);

    }else if(btn == activeButton05){

       handleIdActive(activeButton05,idLeito05);

    }else if(btn == activeButton06){

       handleIdActive(activeButton06,idLeito06);

     }else if(btn == activeButton07){

       handleIdActive(activeButton07,idLeito07);

     }
    
  }



  static void disableCall(Button2& btn){
    if(btn == disableButton01){
    
      handleIdDisable(disableButton01,idLeito01);
    }else if(btn == disableButton02){
    
      handleIdDisable(disableButton02,idLeito02);

    }else if(btn == disableButton03){
    
      handleIdDisable(disableButton03,idLeito03);

    }else if(btn == disableButton04){
    
      handleIdDisable(disableButton04,idLeito04);

    }else if(btn == disableButton05){
    
       handleIdDisable(disableButton05,idLeito05);

    }else if(btn == disableButton06){
    
       handleIdDisable(disableButton06,idLeito06);

     }else if(btn == disableButton07){
    
       handleIdDisable(disableButton07,idLeito07);

    }
    
  }

  static void setupPressHandleActive(){
    activeButton01.setPressedHandler(Leitos::activeCall);
    activeButton02.setPressedHandler(Leitos::activeCall);
    activeButton03.setPressedHandler(Leitos::activeCall);
    activeButton04.setPressedHandler(Leitos::activeCall);
    activeButton05.setPressedHandler(Leitos::activeCall);
    activeButton06.setPressedHandler(Leitos::activeCall);
    activeButton07.setPressedHandler(Leitos::activeCall);


  }

  static void setupPressHandleDisable(){
    disableButton01.setPressedHandler(Leitos::disableCall);
    disableButton02.setPressedHandler(Leitos::disableCall);
    disableButton03.setPressedHandler(Leitos::disableCall);
    disableButton04.setPressedHandler(Leitos::disableCall);
    disableButton05.setPressedHandler(Leitos::disableCall);
    disableButton06.setPressedHandler(Leitos::disableCall);
    disableButton07.setPressedHandler(Leitos::disableCall);


  }

  static void setupBeginEnable(){
    activeButton01.begin(leitoEnable01,INPUT_PULLUP,false, false);
    activeButton02.begin(leitoEnable02,INPUT_PULLUP,false, false);
    activeButton03.begin(leitoEnable03,INPUT_PULLUP,false, false);
    activeButton04.begin(leitoEnable04,INPUT_PULLUP,false, false);
    activeButton05.begin(leitoEnable05,INPUT_PULLUP,false, false);
    activeButton06.begin(leitoEnable06,INPUT_PULLUP,false, false);
    activeButton07.begin(leitoEnable07,INPUT_PULLUP,false, false);


  }

  static void setupBeginDisable(){
    disableButton01.begin(leitoDisable01,INPUT_PULLUP,false, false);
    disableButton02.begin(leitoDisable02,INPUT_PULLUP,false, false);
    disableButton03.begin(leitoDisable03,INPUT_PULLUP,false, false);
    disableButton04.begin(leitoDisable04,INPUT_PULLUP,false, false);
    disableButton05.begin(leitoDisable05,INPUT_PULLUP,false, false);
    disableButton06.begin(leitoDisable06,INPUT_PULLUP,false, false);
    disableButton07.begin(leitoDisable07,INPUT_PULLUP,false, false);


  }

  static void loopButtonEnable(){
    activeButton01.loop();
    activeButton02.loop();
    activeButton03.loop();
    activeButton04.loop();
    activeButton05.loop();
    activeButton06.loop();
    activeButton07.loop();


  }

  static void loopButtonDisable(){
    disableButton01.loop();
    disableButton02.loop();
    disableButton03.loop();
    disableButton04.loop();
    disableButton05.loop();
    disableButton06.loop();
    disableButton07.loop();


  }




  public:

  static void setupPressHandle(){
  Leitos::setupPressHandleActive();
  Leitos::setupPressHandleDisable();

  }

  static void setupBegin(){
    Leitos::setupBeginEnable();
    Leitos::setupBeginDisable();
  }

  static void loopButtons(){
  Leitos::loopButtonEnable();
  Leitos::loopButtonDisable();
  }



};
