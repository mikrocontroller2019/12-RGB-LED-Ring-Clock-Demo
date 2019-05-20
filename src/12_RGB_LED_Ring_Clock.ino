#include <WiFi.h>
#include <time.h>
#include <Adafruit_NeoPixel.h>

int hour;
int minute;
int second;
int displayCount;
int hourHand;
int minuteHand;
int secondHand;
int ledIndex;
int red;
int green;
int blue;

const char* ssid = "...";
const char* password = "...";
Adafruit_NeoPixel myLedRing;
bool touchDetected[10];

void connect() {
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
  };
}

bool wasTouchDetected(int pinIdx) {
  bool td = touchDetected[pinIdx];
  touchDetected[pinIdx] = false;
  return td;
}

void gotTouchT0() {
  touchDetected[0] = true;
}

struct tm* getTime(){
  time_t now = time(nullptr);
  return localtime(&now);
}



void setup() {
  touchAttachInterrupt(T0, gotTouchT0, 40);

  connect();
  configTime(3600, 3600, "pool.ntp.org");
  myLedRing = Adafruit_NeoPixel(12, 12, NEO_GRB + NEO_KHZ800);
  myLedRing.begin();
  myLedRing.show();
  hour = 0;
  minute = 0;
  second = 0;
  displayCount = 15;

}

void loop() {
  if (wasTouchDetected(0)) {
    displayCount = 30;
  }
  while (displayCount > 0) {
    hour = getTime()->tm_hour;
    minute = getTime()->tm_min;
    second = getTime()->tm_sec;
    hourHand = hour % 12;
    minuteHand = minute / 5;
    secondHand = second / 5;
    for (ledIndex = 0; ledIndex <= 11; ledIndex++) {
      red = 0 + (ledIndex == hourHand ? 128 - 32 * (minute / 15) : 0);
      green = 0 + (ledIndex == minuteHand ? 128 - 32 * (minute % 5) : 0);
      blue = 0 + (ledIndex == secondHand ? 128 - 32 * (second % 5) : 0);
      if (ledIndex == (hourHand + 1) % 12) {
        red = 32 * (minute / 15);
      }
      if (ledIndex == (minuteHand + 1) % 12) {
        green = 32 * (minute % 5);
      }
      if (ledIndex == (secondHand + 1) % 12) {
        blue = 32 * (second % 5);
      }
      myLedRing.setPixelColor(ledIndex, myLedRing.Color(red, green, blue));
    }
    myLedRing.show();
    delay(1000);
    displayCount += -1;
    if (displayCount == 0) {
      for (ledIndex = 0; ledIndex <= 11; ledIndex++) {
        myLedRing.setPixelColor(ledIndex, myLedRing.Color(0, 0, 0));
      }
      myLedRing.show();
      delay(10);
    }
  }

}