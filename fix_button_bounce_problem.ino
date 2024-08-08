#define BUTTON_PIN 2

byte buttonState = LOW;

unsigned long lastTimeButtonChanged = millis();
unsigned long bounceDelay = 50;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  unsigned long currTime = millis();

  if(currTime - lastTimeButtonChanged > bounceDelay){
    byte newButtonState = digitalRead(BUTTON_PIN);
    if(newButtonState != buttonState){
      buttonState = newButtonState;
      lastTimeButtonChanged = currTime;
      Serial.print(millis());
      Serial.print(" -> ");
      if(buttonState == HIGH){
        Serial.println("Button pressed!");
      } else{
        Serial.println("Button released!");

      }
    }
  
  }

}
