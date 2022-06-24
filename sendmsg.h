void SendMessage()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  //replyfrommodem="OK";
  //ModemResponse();
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  //mySerial.println("AT+CMGS=\"+919611839500\"\r"); // Replace x with mobile number
  mySerial.println("AT+CMGS=\""+sendto+"\"\r");  
  //replyfrommodem="OK";
  //ModemResponse();
  delay(1000);
  //mySerial.println("sim900a sms");// The SMS text you want to send
  mySerial.println(msg);
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
  
}
/*
//String smsto;
//String msg;
void SendMessage(String smsto, String msg)
{
//for (int i=0;i<5;i++)
  // {
     mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
     delay(100);  // Delay of 1000 milli seconds or 1 second
     //mySerial.println("AT+CMGS=\"+919611839500\"\r"); // this was working in the original gprs code
    // mySerial.println("AT+CMGS=\""+recipientNumber[i]+"\"\r");
     mySerial.println("AT+CMGS=\""+smsto+"\"\r");
     delay(100);
  
     //mySerial.println("FIRE ALERT SMS TST");// The SMS text you want to send
     mySerial.println(msg);
     delay(100);
     mySerial.println((char)26);// ASCII code of CTRL+Z
     delay(100);
    Serial.println("SMS sent");     
   //}  
   //}
  
  
}
*/