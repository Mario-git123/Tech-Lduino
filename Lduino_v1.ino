#define LIGHT_PIN 12
#define ON  1
#define OFF 0
int high_threshold = 600;//! high threshold
int low_threshold = 300;//! low threshold
int ledstate = 0; //! heart beat on built in led


void setLight(bool on)
{
  digitalWrite(LIGHT_PIN, on);
}

void toggleLed()
{
   digitalWrite(LED_BUILTIN, ledstate);    // toggle the LED off
   ledstate =! ledstate;
}

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LIGHT_PIN, OUTPUT);
  Serial.print("start!\r\n");
}

void loop() 
{
   int sensorVal = analogRead(A0);//! read sensor raw data
   float percent = (sensorVal * 100.0) / 1023.0 ; //! data to percent [0% 100%]
   char tmp [128];
   sprintf(tmp,"sensor raw value: %d",sensorVal);
   Serial.println(tmp);//! print on console raw data
   Serial.print("light percentage:");
   Serial.print(percent,3);
   Serial.println("%");//! print on console percent data
   delay(20);
   toggleLed();
   if(sensorVal < low_threshold )
    setLight(ON);
   else if(sensorVal > high_threshold)
    setLight(OFF);
}
