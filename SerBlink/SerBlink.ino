// serblink
// (w) 2013 Neo
// Program that listens on the Serial
int led = 13;
boolean heartbeat = true;

void setup() {                
    //setup serial
    Serial.begin(9600);
    
    // init the digital pin as an output.
    pinMode(led, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
    if(heartbeat){
        digitalWrite(7,HIGH);
        delay(250);
        digitalWrite(7,LOW);
        delay(250);
    }
    
    if(Serial.available()) {
        heartbeat = false;
        char ser = Serial.read();
        switch(ser) {
            case 'q':
                digitalWrite(led, HIGH);
                Serial.println("[+] LED 13 ON");
                break;
            case 'a':
                digitalWrite(led, LOW);
                Serial.println("[-] LED 13 OFF");
                break;
            case 'w':
              Serial.println("[*] LED 13 BLINKING 100 times");
              for (int x = 0; x <= 100; x++) {
                  digitalWrite(led,HIGH);
                  delay(30);
                  digitalWrite(led,LOW);
                  delay(30);
              }
        }
    }
}
