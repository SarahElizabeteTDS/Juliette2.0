int ENA = 3;
int ENB = 6; //define velocidade aqui
int IN1 = 2;
int IN2 = 4;
int IN3 = 7;
int IN4 = 5;

int sensorD = 12;
int sensorM = 11;
int sensorE = 10;

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
      praDireita();
    } else if (!is_black(valorSensorM) && is_black(valorSensorE) && is_black(valorSensorD)) {
      praFrente();
    } else if (!is_black(valorSensorM) && !is_black(valorSensorE) && is_black(valorSensorD)) {
      praDireita();
    } else if (!is_black(valorSensorM) && is_black(valorSensorE) && !is_black(valorSensorD)) {
      praEsquerda();
    }
  }
}

bool is_black(int valorSensor) {
  return valorSensor == 0;
}

void praFrente() {

  // Aciona os motores
  analogWrite(ENA, 255); //esquerda
  analogWrite(ENB, 255); // direita

  digitalWrite(IN1, LOW);   // A E
  digitalWrite(IN2, HIGH);  // A E
  digitalWrite(IN3, LOW);   // B D
  digitalWrite(IN4, HIGH);  // B D
}


void praEsquerda() {
  analogWrite(ENA, 255);
  analogWrite(ENB, 240);
  // Aciona os motores no sentido inverso
  digitalWrite(IN1, LOW);   // A E
  digitalWrite(IN2, HIGH);  // A E
  digitalWrite(IN3, HIGH);  // B D
  digitalWrite(IN4, LOW);   // B D
}

void praDireita() {
   analogWrite(ENA, 255);
  analogWrite(ENB, 240);
  // Aciona os motores no sentido inverso
  digitalWrite(IN1, HIGH);  // A E
  digitalWrite(IN2, LOW);   // A E
  digitalWrite(IN3, LOW);   // B D
  digitalWrite(IN4, HIGH);  // B D
}

//ter a opcao de colocar a velocidade como var da function --> fazer por ultimo
