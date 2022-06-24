/*THIS TUTORIAL USED GSM SIM900A MINI V3.9.2
 
  Connect 5VT to D9 and 5VR to D10
  Feed GSM SIM900A with Arduino's 5V

  Code by IDAYU SABRI - MYBOTIC
*/

#include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 10);
String msg="tst";
String entiremsg; // entire sms msg
String smstxt; // txt part of the sms received
String sender; // the person who has sent the sms to gprs
String sendto; // the person to whom sms has to be sent
String numtoincldel; // the phone no. to be included or deleted
String replyfrommodem;

int reply;
//String presms;
char msgr;
char call;
//char x;
int position = 0;
int position2 = 0;
int index_str; //used to store the position from where the sender's phone no. starts
int index; // used to store the position where the carriage return or enter key is character is there. THe SMS text is expected to start after the enter character
int index2; // used to find the position of second newline character
//const char* recipientNumber[5] = { "+919611839500", "+919663325288", "+919886022284", "+919611126362", "+919611839500" };
//String recipientNumber[] = { "+919611839500", "+919663325288", "+919886022284", "+919611126362" };
String recipientNumber[] = { "\0", "\0", "\0", "\0","\0" };
String admin = "+919886022284";
//int count=sizeof (recipientNumber) / sizeof (recipientNumber[0]); //holds the count of phone numbers in the receipient array
int count=0;// the no. of valid phone numbers in the receipient array. changes dynamically
int arraysize =5; // Is fixed. Value to be inputted based on the customer requirement
int i;

//#include "modemresponse.h"
#include "sendmsg.h"
#include "adminaccess.h"


void setup()
{
  mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  Serial.println("GSM SIM900A BEGIN");
  Serial.println("Enter character for control option:");
  Serial.println("a : admin to set the no.s");
  Serial.println("h : to disconnect a call");
  Serial.println("i : to receive a call");
  Serial.println("s : to send message");
  Serial.println("c : to make a call");  
  Serial.println("e : to redial");
  Serial.println("m : to receive sms");
  Serial.println();
  delay(100);
}

void loop()
{  
  if (Serial.available()>0)
   switch(Serial.read())
  {
    case 'a':
      AdminAccess();
    case 's':
      //SendMessage(admin, "tst");
      msg="check";
      sendto="+919611839500";
      SendMessage();
      break;
    case 'm':
      ReceiveMessage();
      break;
    case 'c':
      MakeCall();
      break;
    case 'h':
      HangupCall();
      break;
    case 'e':
      RedialCall();
      break;
    case 'i':
      ReceiveCall();
      break;
  }
  index_str=0;
  index=0;
 if (mySerial.available()>0)

{ //Serial.write(mySerial.read());
 entiremsg=mySerial.readString();
 delay(1000);
 Serial.print("Received");
 Serial.println(entiremsg);
 delay(100);
 position = entiremsg.indexOf("+CMT");
 if(position != -1)
 {
   position2 = entiremsg.indexOf('+', position+1); 
   Serial.print("position is ");
   Serial.println(position2);
   sender = entiremsg.substring((position2), (position2+13));
 //index_str=msg.indexOf("+919611839500");
 //index_str=entiremsg.indexOf(admin); // checking if the sms has come from admin. Looks for admin no. in the recvd msg and returns the position of the string. else returns -1 
   Serial.print("sender is ");
   Serial.println(sender);
   sendto=sender;
if (sender == admin)
{
AdminAccess();  
}
else
if (sender != admin)
{
  msg="sorry. only admin pls.";
  SendMessage();
}
 }
 

 
}


}


void ReceiveMessage()
{
  mySerial.println("AT+CNMI=2,2,0,0,0"); // AT Command to recieve a live SMS
  delay(1000);
 mySerial.println("AT+CMGR=1");  
  if (mySerial.available()>0)
  {
    msgr=mySerial.read();
    Serial.print(msgr);
  }
}

void MakeCall()
{
  mySerial.println("ATD+919611839500;"); // ATDxxxxxxxxxx; -- watch out here for semicolon at the end!!
  Serial.println("Calling  "); // print response over serial port
  delay(1000);
}


void HangupCall()
{
  mySerial.println("ATH");
  Serial.println("Hangup Call");
  delay(1000);
}

void ReceiveCall()
{
  mySerial.println("ATA");
  delay(1000);
  {
    call=mySerial.read();
    Serial.print(call);
  }
}

void RedialCall()
{
  mySerial.println("ATDL");
  Serial.println("Redialing");
  delay(1000);
}



/*
#include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 10); // RX, TX
void setup() {

  // put your setup code here, to run once:
  Serial.begin(9600);
  mySerial.begin(9600);
  Serial.println();
  delay(1000);
}
void loop() {
  if (mySerial.available()) {
    Serial.write(mySerial.read());
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
}
*/
