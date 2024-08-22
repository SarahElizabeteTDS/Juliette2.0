int ENA = 3;
int ENB = 6; //define velocidade aqui
int IN1 = 2;
int IN2 = 4;
int IN3 = 7;
int IN4 = 5;

int sensorD = A1;
int sensorM = A2;
int sensorE = A3;

int velocidade = 200;  // Velocidade do motor (0 a 255)

void setup() {
  Serial.begin(9600);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(sensorD, INPUT);
  pinMode(sensorM, INPUT);
  pinMode(sensorE, INPUT);
}

void loop() {
  int valorSensorE = analogRead(sensorE);
  int valorSensorM = analogRead(sensorM);
  int valorSensorD = analogRead(sensorD);

  Serial.print("Sensor E: ");
  Serial.print(valorSensorE);
  Serial.print(" Sensor M: ");
  Serial.print(valorSensorM);
  Serial.print(" Sensor D: ");
  Serial.println(valorSensorD);

  if (is_black(valorSensorM)) { // se o sensor do meio estiver no preto
    if (!is_black(valorSensorE)) { // se o sensor esquerdo estiver no branco
      praEsquerda();
    } else if (!is_black(valorSensorD)) { // se o sensor direito estiver no branco
      praDireita();
    }
  } else {
    if (!is_black(valorSensorM) && !is_black(valorSensorE) && !is_black(valorSensorD)) {
      praFrente();
    } else if (!is_black(valorSensorM) && is_black(valorSensorE) && is_black(valorSensorD)) {
      praFrente();
    } else if (!is_black(valorSensorM) && !is_black(valorSensorE) && is_black(valorSensorD)) {
      praEsquerda();
    } else if (!is_black(valorSensorM) && is_black(valorSensorE) && !is_black(valorSensorD)) {
      praDireita();
    }
  }
}

bool is_black(int valorSensor) {
  return valorSensor > 900;
}

void praFrente() {

  // Aciona os motores
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);

  digitalWrite(IN1, LOW);   // A
  digitalWrite(IN2, HIGH);  // A 
  digitalWrite(IN3, LOW);   // B
  digitalWrite(IN4, HIGH);  // B
}


void praEsquerda() {
  analogWrite(ENA, 170);
  analogWrite(ENB, 100);
  // Aciona os motores no sentido inverso
  digitalWrite(IN1, LOW);   // A
  digitalWrite(IN2, HIGH);  // A
  digitalWrite(IN3, HIGH);  // B
  digitalWrite(IN4, LOW);   // B
}

void praDireita() {
   analogWrite(ENA, 100);
  analogWrite(ENB, 170 );
  // Aciona os motores no sentido inverso
  digitalWrite(IN1, HIGH);  // A
  digitalWrite(IN2, LOW);   // A
  digitalWrite(IN3, LOW);   // B
  digitalWrite(IN4, HIGH);  // B
}
