
int triggerPin = 5;    // Trigger pin
int echoPin = 18;    // Echo pin
int triggerPin2 = 16;    // Trigger pin
int echoPin2 = 17;    // Echo pin
long trvanie, trvanie2;
long vzdialenost, vzdialenost2;
int aktualny_stav = 0;
int minuly_stav = 0;
int aktualny_stav2 = 0;
int minuly_stav2 = 0;
int i = 0;

void setup() {
  
  Serial.begin(9600); //inicializácia komunikácie s PC  
  pinMode(triggerPin, OUTPUT); //definovanie pinu ako výstup
  pinMode(echoPin, INPUT);  //definovanie pinu ako vstup
  pinMode(triggerPin2, OUTPUT); //definovanie pinu2 ako výstup
  pinMode(echoPin2, INPUT);  //definovanie pinu2 ako vstup

}

void loop() {
  // na veľmi krátky čas 10 mikrosekúnd spustíme ultrazvuk
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(5);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  trvanie = pulseIn(echoPin, HIGH);  //funkcia pulseIn() nám počká kým na pine echoPin bude signál a vráti nám hodnotu v mikrosekundách

    digitalWrite(triggerPin2, LOW);
  delayMicroseconds(5);
  digitalWrite(triggerPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin2, LOW);

  trvanie2 = pulseIn(echoPin2, HIGH);

  // konverzia času na vzdialenosť
  vzdialenost = trvanie * 0.0343 / 2;
  vzdialenost2 = trvanie2 * 0.0343 / 2;



  // OBJEKT vstupuje
   if (vzdialenost <= 10) {
     aktualny_stav = 1;
  }
   else {
     aktualny_stav = 0;
  }
  delay(100);
   if (aktualny_stav != minuly_stav) {
     while (aktualny_stav == 1) {
       long trvanie2, vzdialenost2;
      digitalWrite(triggerPin2, LOW);
      delayMicroseconds(5);
      digitalWrite(triggerPin2, HIGH);
      delayMicroseconds(10);
      digitalWrite(triggerPin2, LOW);

      trvanie2 = pulseIn(echoPin2, HIGH);
      vzdialenost2 = trvanie2 * 0.0343 / 2;
      if (vzdialenost2 <= 10) {
        aktualny_stav2 = 1;
      }
      else {
        aktualny_stav2 = 0;
      }
    delay(100);
    if (aktualny_stav2 != minuly_stav2) {
      if (aktualny_stav2 == 1) {
        i = i+1;
        Serial.print(i); 
        Serial.print("navstevnikov"); 
        Serial.println(); 
        delay(1000);
        }
        else {
          Serial.print(i); 
          Serial.print("navstevnikov"); 
          Serial.println(); 
          }
          return;
      }
    }
  }
  // OBJEKT odchadza
  if (vzdialenost2 <= 10) {
    aktualny_stav2 = 1;
    }
  else {
    aktualny_stav2 = 0;
    }
  delay(100);
  if (aktualny_stav2 != minuly_stav2) {
    while (aktualny_stav2 == 1) {
      long trvanie, vzdialenost;
      digitalWrite(triggerPin, LOW);
      delayMicroseconds(5);
      digitalWrite(triggerPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(triggerPin, LOW);

      trvanie = pulseIn(echoPin, HIGH);
      vzdialenost = trvanie * 0.0343 / 2;
      if (vzdialenost <= 10) {
        aktualny_stav = 1;
        }
      else {
        aktualny_stav = 0;
        }
      delay(100);
      if (aktualny_stav != minuly_stav) {
      if (aktualny_stav == 1) {
        i = i-1;
        Serial.print(i); 
        Serial.print("navstevnikov"); 
        Serial.println(); 
        delay(1000);
        }
        else {
          Serial.print(i); 
          Serial.print("navstevnikov"); 
          Serial.println(); 
          }
          return;
      }
    }
  }
  delay(100);
}