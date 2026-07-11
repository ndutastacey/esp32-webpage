#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include <secrets.h>

WebServer whatever(80);

String page(){
  return R"rawliteral(
<!docType html>
<html lang='en'>
<head>
        <title>Microcontroller Web Page</title>
        <style>
            *{
                box-sizing: border-box;
            }
            body{
                margin: 0;
                padding: 0;
                display: flex;
                flex-direction: column;
                background-color: aqua;
                height: 100vh;
                width: 100vw;
            }
            h1{
                font-size: 30px;
                font-family: 'Times New Roman', Times, serif;
                color: whitesmoke;
            }
            p{
                margin-top: 80px;
                font-family: 'Times New Roman', Times, serif;
                font-size: 25px;                
            }
            .hero{
                display: flex;
                justify-content: center;
                align-items: center;
                background-color: darkred;
                height: 20%;
            }
            .main{
                display: flex;
                flex-direction: row;
                background-color: wheat;
                height: 80%;
                justify-content: center;
                align-items: center;
            }
            .card1{
                display: flex;
                flex-direction: column;
                height: 500px;
                width: 550px;
                border: 5px solid whitesmoke;
                background-color: whitesmoke;
                align-items: center;
            }
            .space{
                height: 30px;
                width: 150px;
            }
            .card2{
                display: flex;
                flex-direction: column;
                height: 500px;
                width: 550px;
                border: 5px solid whitesmoke;
                background-color: whitesmoke;
                align-items: center;
            }
            .btn{
                background-color: black;
                color: white;
                height: 50px;
                width: 100px;
                border: 5px solid black;
            }
            .strongest{
                display: flex;
                height: 90px;
                width: 450px;
                margin-top: 40px;
                margin-left: 30px;
                margin-right: 30px;
                margin-bottom: 15px;
                background-color: darkblue;
                justify-content: center;
                align-items: center;
                border-radius: 15px;
                color: white;
            }
            .medium{
                display: flex;
                height: 90px;
                width: 450px;
                margin-top: 15px;
                margin-left: 30px;
                margin-right: 30px;
                margin-bottom: 15px;
                background-color: darkblue;
                justify-content: center;
                align-items: center;
                border-radius: 15px;
                color: white;
            }
            .weakest{
                display: flex;
                height: 90px;
                width: 450px;
                margin-top: 15px;
                margin-left: 30px;
                margin-right: 30px;
                margin-bottom: 35px;
                background-color: darkblue;
                justify-content: center;
                align-items: center;
                border-radius: 15px;
                color: white;
            }
            .form{
                display: flex;
                height: 150px;
                width: 450px;
                margin-top: 20px;
                margin-left: 30px;
                margin-right: 30px;
                margin-bottom: 30px;
                justify-content: center;
                align-items: center;
                border: 1px solid whitesmoke;
                color: white;
            }
            .form-input{
                width: 400px;
                height: 60px;
                padding: 20px;
            }
        </style>
    </head>
    <body>
        <div class="hero"><h1>ESP32 Information</h1></div>
        <div class="main">
            <div class="card1">
                <div class="strongest">STRONGEST NETWORK</div>
                <div class="medium">MEDIUM STRENGTH NETWORK</div>
                <div class="weakest">WEAKEST STRENGTH NETWORK</div>
                <button class="btn">SCAN ME</button>
            </div>
            <div class="space"></div>
            <div class="card2">
                <p>Turn your LED 'on' and 'off' here:</p>
                <div class="form">
                    <form id="form" action="/update">
                        <input class="form-input" type="text" name="status" placeholder="Type ON or OFF">
                    </form>
                </div>
                <button type="submit" form="form" class="btn">SEND</button>
            </div>
        </div>
    </body>
</html>)rawliteral";
}

void handleRoot(){
  whatever.send(200, "text/html", page());
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
     delay(1000);
     Serial.print("Connecting to WiFi ..");   
  }
  Serial.println("Connected to wifi");
  Serial.println(WiFi.localIP());
  whatever.on("/", handleRoot);
  whatever.begin();
}

void loop(){
  whatever.handleClient();
}


















