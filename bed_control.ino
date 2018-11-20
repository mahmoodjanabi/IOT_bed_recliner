/*------------------------------------------------------------------------------------------
This Project uses an existing bed with a moving base that is connected to a wired remote.
the push buttons on the remote are removed and replaced with 2 relays, then the relays
are connected to an ESP8266 MCU.
------------------------------------------------------------------------------------------*/

/* Comment this out to disable prints and save space */
//#define BLYNK_PRINT Serial
#define up_relay 5
#define down_relay 4
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = ""; //Blynk project auth code
char ssid[] = "";                           // My WIFI network name
char pass[] = "";                      // My WIFI network password

/* This function reads the input from virtual input in the Blynk app and writes it to a variable here*/
BLYNK_WRITE(V1)
{
  int up = param.asInt(); // assigning incoming value from pin V1 to a variable
  //Serial.print("UP= ");
  //Serial.print(up);
  //Serial.print("\n");

  if (up==1)
  {
    digitalWrite(up_relay, HIGH);
    //Serial.print("Urelay= High\n");
  }
  else
  {
  digitalWrite(up_relay, LOW);
  //Serial.print("Urelay= Low\n");
  }
}
BLYNK_WRITE(V2)
{
  int down = param.asInt(); // assigning incoming value from pin V1 to a variable
  //Serial.print("DOWN= ");
  //Serial.print(down);
  //Serial.print("\n");

    if (down==1)
  {
    digitalWrite(down_relay, HIGH);
    //Serial.print("Drelay= High\n");
  }
  else
  {
  digitalWrite(down_relay, LOW);
  //Serial.print("Drelay= Low\n");
  }
}
void setup()
{
  //Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);

  pinMode(up_relay, OUTPUT);
  pinMode(down_relay, OUTPUT);
}

void loop()
{
  Blynk.run();
}
