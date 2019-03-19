#define echopin 9     //assign echopin to port 9
#define trigpin 10    //assign trigger pin to port 10


long sw, distance; //variables to store data in

void setup() {
 Serial.begin (9600);
 pinMode (trigpin, OUTPUT);     //emitts sound waves
 pinMode (echopin, INPUT );     //records reflected sound waves in form of echo
 pinMode (13,OUTPUT);           //sends signal to power relay from port 12
}

void loop (){
 {

 // Distance sensor code
 // In arduino "LOW" means ON and "HIGH" means OFF
 digitalWrite(trigpin,LOW);     // turns off trigpin
 delayMicroseconds(100); 

 digitalWrite(trigpin,HIGH);    // turns on trigpin
 delayMicroseconds(100);

 sw = pulseIn (echopin,HIGH);   //stores echo data in sw
 distance= (sw/2)/29.1;         //converts sound waves frequency to distance in cm
 delay (50);                    //stop recording for 50 millisecond
 Serial.print(distance);        //prints distance in Serial Monitor
 Serial.println(" cm");         //prints distance in cm in Serial Monitor
 
 }

if (distance < 4 ){
 digitalWrite (13,HIGH);        //turns on relay(motor) when distance is > 4 cm
 delay(0);
}
else if (distance >=4) {

 digitalWrite (13,LOW);         //turns off relay(motor) when distance is <= 4 cm
 delay(0);

}
}
