
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

//---------------------------------------------------------------
//Our HTML webpage contents in program memory
const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
        <style>
        .buttonOn {
          background-color: #4CAF50;
          border: none;
          color: white;
          padding: 15px 32px;
          text-align: center;
          text-decoration: none;
          display: inline-block;
          font-size: 16px;
          margin: 5px px;
          cursor: pointer;
          border-radius: 20px;
        }
        .buttonOff {
          background-color: rgba(255, 0, 0, 0.74);
          border: none;
          color: white;
          padding: 15px 32px;
          text-align: center;
          text-decoration: none;
          display: inline-block;
          font-size: 16px;
          margin: 4px 2px;
          cursor: pointer;
          border-radius: 20px;
        }
        </style>
</head>
<body>
    <center>
        <hr>
        <h1 style="color: rgb(255, 153, 0);">Home Automation</h1>
        <hr>
        <a href="ledOn0" class="buttonOn">Room 1 Light ON</a>
        <a href="ledOff0", class="buttonOff">Room 1 Light OFF</a><br>
        <hr>
        <a href="ledOn1" , class="buttonOn" >Room 2 Light ON</a>
        <a href="ledOff1", class="buttonOff">Room 2 Light OFF</a><br>
        <hr>
        <a href="ledOn2", class="buttonOn" >Kitchen Light ON</a>
        <a href="ledOff2", class="buttonOff">Kitchen Light OFF</a><br>
        <hr>
        <a href="ledOn3" , class="buttonOn" >Lounge Light ON</a>
        <a href="ledOff3", class="buttonOff">Lounge Light OFF</a><br>
         <hr>
        <a href="ledOn4" , class="buttonOn" >Socket ON</a>
        <a href="ledOff4", class="buttonOff">Socket OFF</a><br>
        <hr>
        <a href=""></a>
        </center>  
</body>
</html>
)=====";
//---------------------------------------------------------------
//On board LED Connected to GPIO2
const int LED0 = 4;
const int LED1 = 12;
const int LED2 = 14;
const int LED3 = 16;
const int LED4 = 5;
//const int LED5 = 12;


//SSID and Password of your WiFi router
const char* ssid = "HomeAutomation";
const char* password = "12345678";

//Declare a global object variable from the ESP8266WebServer class.
ESP8266WebServer server(80); //Server on port 80

//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void handleRoot() {
 Serial.println("You called root page");
 String s = MAIN_page; //Read HTML contents
 server.send(200, "text/html", s); //Send web page
}

void handleLEDon0() { 
 Serial.println("LED on page");
 digitalWrite(LED0,HIGH); //LED is connected in reverse
 server.send(200, "text/html", "Room 1 Light ON"); //Send ADC value only to client ajax request
}

void handleLEDoff0() { 
 Serial.println("LED off page");
 digitalWrite(LED0,LOW); //LED off
 server.send(200, "text/html", "Room 1 Light OFF"); //Send ADC value only to client ajax request
}


void handleLEDon1() { 
 Serial.println("LED on page");
 digitalWrite(LED1,HIGH); //LED is connected in reverse
 server.send(200, "text/html", "Room 2 Light ON"); //Send ADC value only to client ajax request
}

void handleLEDoff1() { 
 Serial.println("LED off page");
 digitalWrite(LED1,LOW); //LED off
 server.send(200, "text/html", "Room 2 Light OFF"); //Send ADC value only to client ajax request
}


void handleLEDon2() { 
 Serial.println("LED on page");
 digitalWrite(LED2,HIGH); //LED is connected in reverse
 server.send(200, "text/html", "Kitchen Light ON"); //Send ADC value only to client ajax request
}

void handleLEDoff2() { 
 Serial.println("LED off page");
 digitalWrite(LED2,LOW); //LED off
 server.send(200, "text/html", "Kitchen Light OFF"); //Send ADC value only to client ajax request
}


void handleLEDon3() { 
 Serial.println("LED on page");
 digitalWrite(LED3,LOW); //LED is connected in reverse
 server.send(200, "text/html", "Lounge Light ON"); //Send ADC value only to client ajax request
}

void handleLEDoff3() { 
 Serial.println("LED off page");
 digitalWrite(LED3,HIGH); //LED off
 server.send(200, "text/html", "Lounge Light OFF"); //Send ADC value only to client ajax request
}


void handleLEDon4() { 
 Serial.println("LED on page");
 digitalWrite(LED4,LOW); //LED is connected in reverse
 server.send(200, "text/html", "Socket ON"); //Send ADC value only to client ajax request
}

void handleLEDoff4() { 
 Serial.println("LED off page");
 digitalWrite(LED4,HIGH); //LED off
 server.send(200, "text/html", "Socket OFF"); //Send ADC value only to client ajax request
}

//==============================================================
//                  SETUP
//==============================================================
void setup(void){
  Serial.begin(115200);
  
  //Connect to your WiFi router
  WiFi.softAP(ssid,password);



  //Onboard LED port Direction output
  pinMode(LED0,OUTPUT); 
  digitalWrite(LED0,LOW);
  pinMode(LED1,OUTPUT); 
  digitalWrite(LED1,LOW);
  pinMode(LED2,OUTPUT); 
  digitalWrite(LED2,LOW);
  pinMode(LED3,OUTPUT); 
  digitalWrite(LED3,HIGH);
  pinMode(LED4,OUTPUT); 
  digitalWrite(LED4,HIGH);
   WiFi.softAP(ssid,password);
  Serial.println("Initializing_Wifi_accesspoint");
  Serial.println("over");
  
  Serial.print("SoftAP IP: ");
  Serial.println(WiFi.softAPIP());
 
  server.on("/", handleRoot);      //Which routine to handle at root location. This is display page
  server.on("/ledOn0", handleLEDon0); //as Per  <a href="ledOn">, Subroutine to be called
  server.on("/ledOff0", handleLEDoff0);

   server.on("/ledOn1", handleLEDon1); //as Per  <a href="ledOn">, Subroutine to be called
  server.on("/ledOff1", handleLEDoff1);

    server.on("/ledOn2", handleLEDon2); //as Per  <a href="ledOn">, Subroutine to be called
  server.on("/ledOff2", handleLEDoff2);

    server.on("/ledOn3", handleLEDon3); //as Per  <a href="ledOn">, Subroutine to be called
  server.on("/ledOff3", handleLEDoff3);

    server.on("/ledOn4", handleLEDon4); //as Per  <a href="ledOn">, Subroutine to be called
  server.on("/ledOff4", handleLEDoff4);

  server.begin();                  //Start server
  Serial.println("HTTP server started");
}
//==============================================================
//                     LOOP
//==============================================================
void loop(void){
  server.handleClient();          //Handle client requests
}
