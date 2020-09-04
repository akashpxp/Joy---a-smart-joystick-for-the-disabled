#include <DHT.h>;

//Constants
#define DHTPIN 2     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino
int flag=0;


//Variables
int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value

#define trigPin1 6
#define echoPin1 7
#define trigPin2 8
#define echoPin2 9
int c,d,e=0,stand=0;
void setup()
{
  
Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  
dht.begin();


}

int firstsensor()
{ // This function is for first sensor.
  int duration1, distance1;
  digitalWrite (trigPin1, HIGH);
  delayMicroseconds (10);
  digitalWrite (trigPin1, LOW);
  duration1 = pulseIn (echoPin1, HIGH);
  distance1 = (duration1/2) / 29.1;

      Serial.print("1st Sensor: ");
      Serial.print(distance1);  
      Serial.print("cm    ");
      return(distance1);
}
int secondsensor()
{ // This function is for second sensor.
    int duration2, distance2;
    digitalWrite (trigPin2, HIGH);
    delayMicroseconds (10);
    digitalWrite (trigPin2, LOW);
    duration2 = pulseIn (echoPin2, HIGH);
    distance2 = (duration2/2) / 29.1;
  
      Serial.print("2nd Sensor: "); 
      Serial.print(distance2);  
      Serial.print("cm    ");
      return(distance2);
}
void loop() 
{
  delay(2000);
Serial.println("\n");
int a=firstsensor();
int b=secondsensor();
Serial.println(a);
Serial.println(b);


  hum = dht.readHumidity();
  temp= dht.readTemperature();
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print(" %, Temp: ");
  Serial.print(temp);
  Serial.println(" Celsius");

if ( flag==0 )
{
  stand=hum;
  flag++;
}

if (a<20)
{
  //move left
  c=1;
  Serial.println("move left");
}

if (b<20)
{
  //move right
  d=1;
  Serial.println("move right");
}


if ( hum>(stand+200))
{
  //rotate
   Serial.println("Rotate");
}

}
