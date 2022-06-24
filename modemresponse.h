String collect = "";
uint32_t prev = 0;
void ModemResponse()
{
long now=millis();
while(now - prev < 2000)
{
prev=now;  
collect=mySerial.readString();
if ( collect.indexOf(replyfrommodem) >= 0 ) 
{  // full response obtained
break;
}
  
}
Serial.println("No response from network");
/*while( 1 ) {
delay(1);  // slow things down a  bit
//char c = (char) sim800l.read();
//collect += c;
collect=mySerial.readString();
if ( millis() - prev > 2000 ) {  // get out if no response in 2 secs
Serial.println("No response from network");
break;
}

if ( collect.indexOf(replyfrommodem) >= 0 ) {  // full response obtained
break;
}
}
*/
}