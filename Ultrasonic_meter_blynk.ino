#include <Blynk.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

const int trigPin = 13;
const int echoPin = 12;
// defines variables
long duration;
int distance;
char auth[] = "O3zKYZjQ8yXrRGxRhaIq80Nqj2-77J-r";//blynk app sync token
//network credentials
char ssid[] = "Home"; 
char pass[] = "1234567890";

BLYNK_READ(V0) //Blynk app has something on V5
{digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
  Blynk.virtualWrite(V0, distance); //sending to Blynk via virtual port no. 0
}

void setup() {
Serial.begin(115200);
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT);
  delay(10);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  int wifi_ctr = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
  Blynk.begin("O3zKYZjQ8yXrRGxRhaIq80Nqj2-77J-r", ssid, pass);
}

void loop() {
  Blynk.run();
  }
