
#include <ros.h>
#include <std_msgs/Time.h>
#include <std_msgs/Header.h>
#include <project_s_msgs/fromMissionServer.h>
#include <project_s_msgs/toMissionServer.h>
#include "Sixfab_CellularIoThttp.h"
#include "labCar.h"

#define DEBUG1 Serial2
labCar myCar;
char myBuff[100];
int shouldListenROS = 1;
unsigned long timestamp = 0;
int CPT = 0;
char msgState[100];
ros::NodeHandle  nh;
project_s_msgs::fromMissionServer msgFromServer;
project_s_msgs::toMissionServer msgToServer;

void messageCb( const project_s_msgs::toMissionServer& ros_msg){
  char fail[] = "MESSAGE FROM ROS LOST";
  char success[] = "TREATED";
  if (shouldListenROS == 1){
    myCar.id = ros_msg.idCar;             // get car id
    //if((ros_msg.state == labCar::LABCAR_STATUS_WAITING) && (myCar.status == labCar::LABCAR_STATUS_UNAVAILABLE)) myCar.status = ros_msg.state;         // get car state
    switch(ros_msg.state){
      case labCar::LABCAR_STATUS_WAITING:
        if(myCar.status == labCar::LABCAR_STATUS_UNAVAILABLE) myCar.status = ros_msg.state;
        break;
      case labCar::LABCAR_STATUS_ENDING:
      case labCar::LABCAR_STATUS_SLEEPING:
      case labCar::LABCAR_STATUS_UNAVAILABLE:
        myCar.status = ros_msg.state;
        break;
      default:
        break;
    }
    //if(ros_msg.state == labCar::LABCAR_STATUS_ENDING || ros_msg.state == labCar::LABCAR_STATUS_SLEEPING ||ros_msg.state == labCar::LABCAR_STATUS_UNAVAILABLE) myCar.status = ros_msg.state;         // get car state
    strcpy(myCar.lat, ros_msg.lat);  // get latitude in north deg
    strcpy(myCar.lng, ros_msg.lng);  // get longitude in west deg
    //strcpy(rosMsg, ros_msg.data);
    //DEBUG1.println(success);
    shouldListenROS = 0;
  }
  else{
    // DEBUG1.println(fail);
  }
  //char data[500];
  //sprintf(data,"idCar:%d, state:%d, mode:%d, lat:%s, lng:%s",ros_msg.idCar, ros_msg.state, ros_msg.mode, ros_msg.lat, ros_msg.lng);
  //DEBUG1.println(data);
  
}

ros::Publisher pub_fromMissionServer("fromMissionServer", &msgFromServer);
ros::Subscriber<project_s_msgs::toMissionServer> sub_toMissionServer("toMissionServer", messageCb );
 
SixfabCellularIoTAppHttp node;

const char ipAdress[] = "54.37.87.215"; // change with your ip
const char port[] = "3030"; // change with your port
const char simPin[] = "5042"; // change with your SIM PIN
const char Apn[] = "sl2sfr"; // APN for SFR Internet

const char urlGetSearch[] = "http://labcar.digital-segula.fr/get/search";
const char urlPostTsync[] = "http://labcar.digital-segula.fr/post/tsync?";
const char urlPostUpdate[] = "http://labcar.digital-segula.fr/post/update?";
const char urlPostEcho[] = "http://labcar.digital-segula.fr/post/echo?";



void reset(){
  DEBUG1.println("RESET");
  unsigned long time1 = millis();
  
  node.init(false);   
  nh.spinOnce();
  
  DEBUG1.println("START");
  
  node.getSIMstatus();
  DEBUG1.print("[1]");
  node.setSIMPin(simPin);
  DEBUG1.print("[2]");
  node.getNetworkRegistrationStatus();
  DEBUG1.print("[3]");
  node.getIMEI();
  DEBUG1.print("[4]");
  node.getFirmwareInfo();
  DEBUG1.print("[5]");
  node.getHardwareInfo();
  DEBUG1.print("[6]");
  node.setIPAddress(ipAdress);
  DEBUG1.print("[7]");
  node.setPort(port);
  DEBUG1.print("[8]");
  node.setGSMBand(GSM_900);
  DEBUG1.print("[9]");
  node.setCATM1Band(LTE_B5);
  DEBUG1.print("[10]");
  node.setNBIoTBand(LTE_B20);
  DEBUG1.print("[11]");
  node.getBandConfiguration();
  DEBUG1.print("[12]");
  node.setMode(GSM_MODE);
  DEBUG1.print("[13]");
  nh.spinOnce();

  DEBUG1.println("END 1");
  
  node.connectToOperator();
  nh.spinOnce();

  DEBUG1.println("END 2");
  
  node.getSignalQuality();
  DEBUG1.print("[14]");
  node.getQueryNetworkInfo();
  DEBUG1.print("[15]");
  node.setAPN(Apn);
  DEBUG1.print("[16]");
  node.queryActivatePDPContext();
  DEBUG1.print("[17]");
  node.queryTcpContextByID("1");
  DEBUG1.print("[18]");
  node.configureTcpContextByID("1");
  DEBUG1.print("[19]");
  node.queryPDPContext();
  DEBUG1.print("[20]");
  nh.spinOnce();

  DEBUG1.println("END 3");
  
  node.getPDPContext();
  nh.spinOnce();

  DEBUG1.println("END 4");

  node.deactivateTcpContextByID("1");
  nh.spinOnce();

  DEBUG1.println("END 5");
  
  node.activateTcpContextByID("1");
  node.testHttpConfig();
  nh.spinOnce();

  DEBUG1.println("END 6");
  
  node.configureHttpContextByParam("contextid", "1"); 
  nh.spinOnce();

  DEBUG1.println("END 7");
  
  node.configureHttpContextByParam("requestheader", "0");
  nh.spinOnce();

  DEBUG1.println("END 8");
  
  node.configureHttpContextByParam("responseheader", "0");
  nh.spinOnce();

  DEBUG1.println("END 9");
  
  node.configureHttpContextByParam("sslctxid", "1");
  nh.spinOnce();

  DEBUG1.println("END 10");
  
  node.getHttpParams();
  node.checkSslContextByID("1");
  node.closeConnection();

  unsigned long time2 = millis();
  char data[100];
  sprintf(data, "RESPONSE RESET : %u ",time2-time1);
  DEBUG1.println(data);
}

void initMessageFromServer(){
  msgFromServer.mode = msgFromServer.BYFIELDMODE;
  //sprintf(myBuff, "ConState=%d.%d ArduinoState=", connectionState, localState);
  //strcat (myBuff, (connectionState == CONNECTION_STATE_CONNECTED) ? "CONNECTED" : "DISCONNECTED");
 // msgFromServer.msg = myBuff;
  //msgFromServer.data = msgFromServer.BYFIELDMODE;
  msgFromServer.idCar = myCar.id;
  msgFromServer.stateCmd = 1;
  msgFromServer.err = false;
  msgFromServer.lat = myCar.lat;
  msgFromServer.lng = myCar.lng;

}

void setup() {
  //timestamp = millis();
  Serial.begin(57600);
  nh.getHardware()->setBaud(57600);
  DEBUG1.begin(57600);
  
  myCar.init(10);      //** myCar init.. **
  
  
  
  reset();
  nh.spinOnce();
  initMessageFromServer();

  nh.initNode();
  nh.advertise(pub_fromMissionServer);
  nh.subscribe(sub_toMissionServer);
  
  delay(100);
  DEBUG1.println("END SETUP");

  //CPT = CPT * 10;

}

void sync(){
  unsigned long time1 = millis();
  node.setHttpUrl(urlPostTsync);
  node.HttpPost(myCar.tsyncPost(myBuff));
  myCar.tsync(node.response);    // Timestamp & tSyncStatus update
  strcpy(myBuff, "lastTimestampBase=");
  myCar.ull2Str(&myBuff[strlen(myBuff)], myCar.lastTimestampBase);
  strcat(myBuff, " lastTimestampGain=");
  myCar.tsgainStr(&myBuff[strlen(myBuff)], myCar.lastTimestampGain);
  strcat(myBuff, " lastMillisBase=");
  myCar.ul2Str(&myBuff[strlen(myBuff)], myCar.lastMillisBase);
  strcat(myBuff, " millisDelta=");
  myCar.ll2Str(&myBuff[strlen(myBuff)], myCar.millisDelta); 
  strcpy(myBuff, "lastTimestamp=");
  myCar.ll2Str(&myBuff[strlen(myBuff)], myCar.lastTimestamp);
  strcat(myBuff, " TimestampPost=");
  myCar.ll2Str(&myBuff[strlen(myBuff)], myCar.tsyncPost_Timestamp);
  strcat(myBuff, " tsSrvr=");
  myCar.ll2Str(&myBuff[strlen(myBuff)], myCar.tsSrvr);
  strcat(myBuff, " tsSrvrDelta=");
  myCar.ll2Str(&myBuff[strlen(myBuff)], myCar.tsSrvrDelta);
  unsigned long time2 = millis();
  char data[100];
  sprintf(data, "RESPONSE SYNC : %u ",time2-time1);
  DEBUG1.println(data);
  
}

/*void updateData(){
  node.setHttpUrl(urlPostUpdate);
  node.HttpPost(myCar.post(myBuff));
}*/

void(* resetFunc) (void) = 0;
char mission[] = "A new mission found.";

void loop() {
  //DEBUG1.println("LOOP");
  if(shouldListenROS==1)
  {
    // increment time (timeout)
    //timestampCurrent = millis(); 
    // si current - start > ????
      //informer serveur lost connection to car
      //se remettre en attente
    nh.spinOnce();
    delay(500);
     
  }
  else
  {
    // i have a ros message to send to server
    if (myCar.bIsTimeToSync()) sync(); // Sync communication
    nh.spinOnce();
    if (myCar.status == labCar::LABCAR_STATUS_WAITING)
    { // Search mission
      node.setHttpUrl(urlGetSearch);
      node.HttpGet(myBuff);
      myCar.get(node.response);
      if(myCar.missionId != 0 && myCar.userId != 0){
        myCar.status = labCar::LABCAR_STATUS_NAVIGATING;
        strcpy(myCar.msg,mission);
        DEBUG1.println(myCar.status_txt[myCar.status]);
      }
    }

    if(myCar.status != labCar::LABCAR_STATUS_UNAVAILABLE)
    {
      node.setHttpUrl(urlPostUpdate);
      //DEBUG1.println(myBuff);
      nh.spinOnce();
      unsigned long time1 = millis();
      //DEBUG1.println("call serveur");
      node.HttpPost(myCar.post(myBuff));
      unsigned long time2 = millis();
      char data[100];
      sprintf(data, "RESPONSE SERVER : %u ",time2-time1);
      DEBUG1.println(data);
      nh.spinOnce();
      //myCar.tsync(node.response);
      
      msgFromServer.data = "";
      msgFromServer.idCar = myCar.id;
      msgFromServer.stateCmd = myCar.status;
      msgFromServer.msg = myCar.msg;
      msgFromServer.lat = myCar.lat;
      msgFromServer.lng = myCar.lng;
      msgFromServer.idUser = myCar.userId;
      msgFromServer.mission = myCar.missionId;
      msgFromServer.err = myCar.err;
      msgFromServer.errCode = myCar.code;
      msgFromServer.url = "";
      pub_fromMissionServer.publish( &msgFromServer );
      shouldListenROS = 1;
    }
    else{
      msgFromServer.mode = 0;
      msgFromServer.msg = "CONNECTED";
      msgFromServer.data = "";
      msgFromServer.idCar = myCar.id;
      msgFromServer.stateCmd = myCar.status;
      msgFromServer.lat = myCar.lat;
      msgFromServer.lng = myCar.lng;
      msgFromServer.idUser = myCar.userId;
      msgFromServer.mission = myCar.missionId;
      msgFromServer.err = myCar.err;
      msgFromServer.errCode = myCar.code;
      msgFromServer.url = "";
    }
    
    //timestampStart = millis();  
  }
  
  if(myCar.status != labCar::LABCAR_STATUS_NAVIGATING) DEBUG1.println(myCar.status_txt[myCar.status]);
  if(myCar.status == labCar::LABCAR_STATUS_NAVIGATING){
    char gpsData[100];
    sprintf(gpsData,"lat = %s | lng = %s",myCar.lat,myCar.lng);
    DEBUG1.println(gpsData);
  }
  //DEBUG1.println(freeMemory());

  CPT++;
  //DEBUG1.println(CPT);
  char cptChar[100];
  char timestampChar[100];
  sprintf(cptChar, "CPT : %d ",CPT);
  sprintf(timestampChar, "DUREE_SIMUL(S) : %u ",(millis() - timestamp)/1000);
  //DEBUG1.println(cptChar);
  DEBUG1.println(timestampChar);
  //if(((millis() - timestamp)/1000) > 100)  resetFunc();
  nh.spinOnce();
}
