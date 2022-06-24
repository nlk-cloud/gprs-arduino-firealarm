
void AdminAccess()
{
Serial.print("count is");
Serial.println(count);
index = entiremsg.indexOf('\n');
index2 = entiremsg.indexOf('\n', index+1); // look for second newline character from the next position of the first newline character
//Serial.print("index is");
//Serial.println(index);
//Serial.print("index2 is");
//Serial.println(index2);
//presms = entiremsg.substring(0, index);
smstxt = entiremsg.substring((index2 + 1), (index2 + 4));//.toInt();
smstxt.toUpperCase();
Serial.print("Sub_str is");
Serial.println(smstxt);
numtoincldel= entiremsg.substring((index2 + 5), (index2 + 18));
Serial.print("numtoinclor del is set to ");
Serial.println(numtoincldel);
 if (smstxt=="ADD")
 {
    if (count==arraysize)
    { msg= "Array is full. Del first";
        //Serial.print("msg is set to ");
        //Serial.println(msg);
        //Serial.print("sender is set to ");
        //Serial.println(sendto);
      SendMessage();}
      else 

      if (count<arraysize)
      {
        i=0;
        while( (recipientNumber[i] != "\0") && (i< arraysize) )  // count only holds the n. of valid phone no.s in the array.
        // But we have to scan the entire array. Hence i<arraysize and not i<count
        {
          i=i+1;
        }
        recipientNumber[i] = numtoincldel;
        count=count+1;
        
        delay(5000);
        msg="included";
        SendMessage();
        delay(10000); 
        msg="added to the list";
        sendto=numtoincldel;
        Serial.print("about to send msg to ");
        SendMessage();
        delay(1000);
        
            
      }
 }
 if (smstxt=="DEL")
{
for(i=0; i<arraysize; i++) //count only holds the n. of valid phone no.s in the array.
        // But we have to scan the entire array to check for the no. to be deleted. Hence i<arraysize and not i<count
{
if (recipientNumber[i] == numtoincldel)  
{
recipientNumber[i] = "\0"; 
count=count-1;
msg="deleted";
sendto=admin;
SendMessage();
}
else continue;

}  

}
Serial.print("count is  ");
Serial.println(count);
for(int i=0; i<arraysize; i++) //count only holds the n. of valid phone no.s in the array.
        // But we have to scan the entire array. Hence i<arraysize and not i<count
        {
            //Serial.print("msg is set to ");
        Serial.println(recipientNumber[i]);
 
        }
 
}