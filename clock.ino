#include WiFi.h
#include WiFiClientSecure.h
#define WIFI_SSID {PUT_HERE}
#define WIFI_PASSWORD {PUT_HERE}
WiFiClientSecure client;

 rtc
#include ThreeWire.h
#include RtcDS1302.h
#define PIN_DAT 23
#define PIN_CLK 18
#define PIN_RST 5
ThreeWire myWire(PIN_DAT, PIN_CLK, PIN_RST);
RtcDS1302ThreeWire Rtc(myWire);

const char FIREBASE_HOST = {PUT_HERE};

#define PIN_BUZZER 13

int alarm_hour = 0;
int alarm_minute = 0;
int alarm_second = 0;
int alarm_last_sound_day = 0;

String firebaseGET(String resource_path){

  if (!client.connect(FIREBASE_HOST, 443)) {
    Serial.println(Firebase get fail);
    return error;
  }

  client.println(GET  + resource_path + .json HTTP1.1);
  client.print(Host );
  client.println(FIREBASE_HOST);
  client.println(Connection close);
  client.println();

   skip headers
  while(client.connected()){
    String line = client.readStringUntil('n');

    if(line == r){
      break;
    }
  }

   read the pure answer
  String answer = client.readString();

  client.stop();

   remove  in answer - answer
  answer.replace(, );

  Serial.print(Firebase );
  Serial.print(ruta);
  Serial.print( );
  Serial.println(respuesta);
  
  return answer;
}

void setup(){
  Serial.begin(115200);

  Serial.println(power on);
   WiFi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while(WiFi.status() != WL_CONNECTED){
    delay(1000);
    Serial.println(connecting..);
  }
  Serial.println(nWiFi connected);
  client.setInsecure();
  
  Rtc.Begin();

   set date & time (just once time)
  RtcDateTime fechaHora(2026, 8, 29, 14, 27, 0);
  Rtc.SetDateTime(fechaHora);

  pinMode(PIN_BUZZER, OUTPUT);
  analogWrite(PIN_BUZZER, LOW);
}

void loop() {

  RtcDateTime now = Rtc.GetDateTime();
  
  String raw_hour = firebaseGET(iotalarm_hour);
  if(raw_hour != error) alarm_hour = raw_hour.toInt();
  Serial.print(Hora Firebase );
  Serial.println(alarm_hour);
  
  String raw_minute = firebaseGET(iotalarm_minute);
  if(raw_minute != error) alarm_minute = raw_minute.toInt();
  Serial.print(Minuto Firebase );
  Serial.println(alarm_minute);
  
   check if is alarm time
   compare seconds from midnight ideal (alarm) and real(now)
  long now_midnight_second = now.Hour()  3600 + now.Minute()  60 + now.Second();
  long alarm_midnight_second = alarm_hour  3600 + alarm_minute  60 + alarm_second;
  Serial.println(now_midnight_second);
  Serial.println(alarm_midnight_second);
  if(now_midnight_second = alarm_midnight_second and alarm_last_sound_day != now.Day()){
    analogWrite(PIN_BUZZER, 9);
    delay(61000);  6 seconds
    analogWrite(PIN_BUZZER, LOW);
    alarm_last_sound_day = now.Day();
  }

  Serial.printf(%04d-%02d-%02d  %02d%02d%02dn,
                now.Year(),
                now.Month(),
                now.Day(),
                now.Hour(),
                now.Minute(),
                now.Second());

  delay(60000l);  60s = 1 minute
}