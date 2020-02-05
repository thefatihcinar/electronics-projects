
int theDuration = 0; // how many micro-seconds waves in the air

int theDistance = 0;  // in cm

const int pinEcho = 8;  // yankı bacağı
const int pinTrigger = 7; // ateşleme bacağı




void setup() {
  
  pinMode(pinTrigger,OUTPUT);
  // ateşleme bacağına sinyal vereceğimiz için, OUTPUT
  pinMode(pinEcho, INPUT);
  // yankı bacağına sinyal vereceğimiz için INPUT

  Serial.begin(9600);

}


void loop() {

  digitalWrite(pinTrigger, LOW); // önce ateşlemeye LOW sinyal gönder ki HIGH'ın farkına varabilsin
  delayMicroseconds(5);
  digitalWrite(pinTrigger, HIGH); // 5 mikrosaniye sonra HIGH gönder
  delayMicroseconds(10);  // 10 mikro saniyelik VURUŞ(PULSE) sinyali alsın
  digitalWrite(pinTrigger, LOW);  // sonra söndür

  // dalga gönderilince, DUYAÇ(SENSÖR) ECHO'yu otomatik HIGH yapacak
  theDuration = pulseIn(pinEcho, HIGH); // biz de ne kadar süre boyunca HIGH oldugunu dinleyeceğiz
  
  theDistance = (theDuration / 2 ) * 0.03435;  // cm cinsinden
  // sürenin yarısı önemli * sesin havadaki hıı cm/ mikro-saniye
  
  Serial.print("Distance: ");
  Serial.print(theDistance);
  Serial.println(" cm");
 
  delay(500);  // bir miktar gecikme olmalı
  
}
