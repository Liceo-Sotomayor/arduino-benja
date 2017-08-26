#define enableA 10
#define pinA1 2
#define pinA2 3
#define enableB 9
#define pinB1 4
#define pinB2 5
#define led 13
#define Pecho 6
#define Ptrig 7
long duracion, distancia;

void setup() {
  pinMode(Pecho, INPUT);
  pinMode(Ptrig, OUTPUT);
  pinMode (enableA, OUTPUT);
  pinMode (pinA1, OUTPUT);
  pinMode (pinA2, OUTPUT);
  pinMode (enableB, OUTPUT);
  pinMode (pinB1, OUTPUT);
  pinMode (pinB2, OUTPUT);
  pinMode (led, OUTPUT);
}

void loop() {
  digitalWrite (enableA, HIGH);
  digitalWrite (enableB, HIGH);
  
  digitalWrite(Ptrig, LOW);
  delayMicroseconds(2);
  digitalWrite(Ptrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Ptrig, LOW);

  duracion = pulseIn(Pecho, HIGH);
  distancia = (duracion / 2) / 29;

  if (distancia >=  10) {
    digitalWrite (pinA1, HIGH);
    digitalWrite (pinA2, LOW);
    digitalWrite (pinB1, HIGH);
    digitalWrite (pinB2, LOW);
    digitalWrite (led, HIGH);
  } else {
    digitalWrite (pinA1, HIGH);
    digitalWrite (pinA2, LOW);
    digitalWrite (pinB1, LOW);
    digitalWrite (pinB2, HIGH);
    digitalWrite (led, LOW);
  }
  
  digitalWrite (enableA, LOW);
  digitalWrite (enableB, LOW);
}
