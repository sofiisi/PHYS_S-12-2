#include <Adafruit_NeoPixel.h>

#define PIN        14 
#define NUMPIXELS 300 
#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

uint32_t red = strip.Color(255, 0, 0);
uint32_t orange = strip.Color(255, 127, 0);
uint32_t yellow = strip.Color(167, 167, 0);
uint32_t green = strip.Color(0, 255, 0);
uint32_t blue = strip.Color(0, 0, 255);
uint32_t violet = strip.Color(143, 10, 255);
uint32_t pink = strip.Color(255, 8, 167);
long R;
long G;
long B;

#include <FirebaseESP32.h>
#include <FirebaseESP32HTTPClient.h>
#include <FirebaseJson.h>

#include <WiFi.h>

#define FIREBASE_HOST "https://final-project-ac183.firebaseio.com/"  // the project name address from firebase id
#define FIREBASE_AUTH "kGvypuyyOaPN4LcutL0waWqd4NfL4XQEgvVVpKsj"                          // the secret key generated from firebase
#define WIFI_SSID "HUAWEI-A40A"                                // input your home or public wifi name
#define WIFI_PASSWORD "95964506"  

//#define WIFI_SSID "VTR-ap-7160305"                                // input your home or public wifi name
//#define WIFI_PASSWORD "zAbxhdbvp3c6"  

String fireStringr = "";     
String fireStringo = "";                                      
String fireStringy = ""; 
String fireStringg = ""; 
String fireStringb = ""; 
String fireStringv = ""; 
String fireStringp = ""; 
String fireStringc = "";
String fireStringrand = "";

//Define FirebaseESP32 data object
FirebaseData firebaseData;
WiFiServer server(80);

void setup() {
  strip.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50); // Set BRIGHTNESS low to reduce draw (max = 255)
 
  Serial.begin(9600);
  delay(1000);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                          // try to connect with wifi

  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());                                // print local IP address
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);                  // connect to firebase
  Firebase.reconnectWiFi(true);
  Firebase.set(firebaseData, "Red", "OFF"); 
  Firebase.set(firebaseData, "Orange", "OFF");   
  Firebase.set(firebaseData, "Yellow", "OFF");     
  Firebase.set(firebaseData, "Green", "OFF");   
  Firebase.set(firebaseData, "Blue", "OFF");
  Firebase.set(firebaseData, "Violet", "OFF");
  Firebase.set(firebaseData, "Pink", "OFF");
  Firebase.set(firebaseData, "Clap", "OFF");
  Firebase.set(firebaseData, "Random", "OFF");
}

void loop() {
 strip.clear();

readfb();

  redp();
  orangep();
  yellowp();
  greenp();
  bluep();
  violetp();
  pinkp();
  clapp();
  randomp();
 
}

void redp() {
   if (fireStringr == "ON") {
 strip.fill(red, 0, 300);
 strip.show(); 
 delay(100);  
 } 
  }

void orangep() {
  if (fireStringo == "ON") {
 strip.fill(orange, 0, 300);
 strip.show(); 
 delay(10);  
 } 
  }

void yellowp() {
  if (fireStringy == "ON") {
 strip.fill(yellow, 0, 300);
 strip.show(); 
 delay(100);  
 } 
  }

void greenp() { 
  if (fireStringg == "ON") {
 strip.fill(green, 0, 300);
 strip.show(); 
 delay(100);  
 } 
  }

void bluep() {
   if (fireStringb == "ON") {
 strip.fill(blue, 0, 300);
 strip.show(); 
 delay(100);  
 } 
  }

void violetp() {
  if (fireStringv == "ON") {
 strip.fill(violet, 0, 300);
 strip.show(); 
 delay(100);  
 } 
  }

void pinkp() {
  if (fireStringp == "ON") {
 strip.fill(pink, 0, 300);
 strip.show(); 
 delay(100);  
 } 
 }

void clapp() {
  if (fireStringc == "ON") {
  strip.show();
  }
  }

void randomp() {
  if (fireStringrand == "ON") {
  R = random(256);
  G = random(256);
  B = random(256);
  uint32_t randomc = strip.Color(R, G, B);
  strip.fill(randomc, 0, 300);
  strip.show();
  }
  }
  
void readfb() {
   Firebase.get(firebaseData, "/Red");                     
  fireStringr = firebaseData.stringData();

   Firebase.get(firebaseData, "/Orange");                     
  fireStringo = firebaseData.stringData();

  Firebase.get(firebaseData, "/Yellow");                     
  fireStringy = firebaseData.stringData();

  Firebase.get(firebaseData, "/Green");                     
  fireStringg = firebaseData.stringData();

   Firebase.get(firebaseData, "/Blue");                     
  fireStringb = firebaseData.stringData();

  Firebase.get(firebaseData, "/Violet");                     
  fireStringv = firebaseData.stringData();

  Firebase.get(firebaseData, "/Pink");                     
  fireStringp = firebaseData.stringData();

  Firebase.get(firebaseData, "/Clap");                     
  fireStringc = firebaseData.stringData();

  Firebase.get(firebaseData, "/Random");                     
  fireStringrand = firebaseData.stringData();
 
  }
