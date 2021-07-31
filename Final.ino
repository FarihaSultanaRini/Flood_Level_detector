 #include<LiquidCrystal.h>
 #include<SoftwareSerial.h>
 
 SoftwareSerial waterSeriall(9,10);
 LiquidCrystal lcd(12,11,6,5,4,3);
 //these pins are used for LCD DISPLAY
 const int trigPin = 13;
 const int echoPin = 8;
const int led = 2;
 

 int buzzer=7;
 //pin no 7 is declared for the buzzer
 
 void setup()
 {
   waterSeriall.begin(9600);
   Serial.begin(9600);
   
   
   
   pinMode(buzzer,OUTPUT);
   pinMode(led,OUTPUT);
   //for output of the buzzer
   
   lcd.begin(20,4);
   //starting  the LCD20*4
   
   lcd.setCursor(1,0);
   //selecting the coloum =1 and row=0
   lcd.print("flood Detector");
   //printing  given message in the LCD
   lcd.setCursor(4,1);
   //selecting the coloum=4 and row=1
   lcd.print("Group 8");
   //printing  given message in the LCD
   lcd.setCursor(0,2);
    //selecting the coloum=0 and row=2
   
   lcd.print("WATER LEVEL: ");
    //printing  given message in the LCD
   lcd.setCursor(0,3);
   //selecting the coloum=4 and row=1
   
   lcd.print("VOLTAGE: ");
    //printing  given message in the LCD
   
   
 }
 void SendMessage(){
  waterSeriall.println("AT+CMGF=1");
  delay(1000);
  waterSeriall.println("AT+CMGS=\"01812320837\"\r");
  delay(100);
  waterSeriall.println("FLOOD IS COMING!!!");
  waterSeriall.println((char)26);
  delay(1000);
}

  
 void loop()
 {
long duration, distance;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) * 0.034;
Serial.println(distance);
delay(1);
if(distance<30){
lcd.setCursor(14,2);
lcd.print("HIGH ");
digitalWrite(buzzer,HIGH);
digitalWrite(led,HIGH);
lcd.setCursor(9,3);            //when the distance  is less than30 lcd will display "HIGH" and the buzzer will be on
delay(1000);
SendMessage();
delay(5000);
   }
  /** else if(distance<25)
   {
     lcd.setCursor(14,2);
     lcd.print("MEDIUM ");
     digitalWrite(buzzer,HIGH);
     lcd.setCursor(9,3);          ///when the sensor value is above 340 lcd will display "Medium" and the buzzer will be on
     
     delay(1000);
   }
   else
   {
     lcd.setCursor(14,2);
     lcd.print("LOW ");
     digitalWrite(buzzer,LOW);
     lcd.setCursor(9,3);    ///when the sensor value is above 19 lcd will display "LOW" and the buzzer will be off
     
     delay(1000);
   }
   
   **/  
    
  }

     
     
     
     
 
   
   
   
   
   
   
   
