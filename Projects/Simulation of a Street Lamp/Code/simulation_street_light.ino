
// SIMULATION OF A STREET LAMP 

const int pinLED = 7;
const int pinLDR = A0;
int amountOfLight = 0;

void setup() {
  
  // We should observe the results
  Serial.begin(9600);
  pinMode(pinLDR, INPUT);
  pinMode(pinLED, OUTPUT);

}

void loop() {
  
  amountOfLight = analogRead(pinLDR);
  Serial.println(amountOfLight);

  if(amountOfLight > 500){
    // I used a voltage divider circuit 
    // HIGH VOLTAGES = HIGH RESULTS = BRIGHT
    digitalWrite(pinLED, LOW);
  }
  else{
    // LOW VOLTAGES = LOW RESULTS = DARKNESS
    digitalWrite(pinLED, HIGH);
  }


  delay(50);

}
