#include <Servo.h>

// OBJETOS
Servo servo_1;
Servo servo_2;
Servo servo_base;
Servo garra;

// PINOS
const int ANALOG_1_EIXO_X = A0;
const int ANALOG_1_EIXO_Y = A1;
const int ANALOG_2_EIXO_X = A2;
const int PIN_BOTAO = 2;
const int PIN_BOTAO_RESET = 4;

// VARIÁVEIS SERVOS BRAÇOS E BASE
const int PASSO_SERVO = 3;
int val_servo_1 = 0;
int val_servo_2 = 50;
int val_servo_base = 90;
int servo_base_ref = 0;

// VARIÁVEIS SERVO GARRA
bool garra_acionada = false;

// DELAYs
unsigned long delay1 = 0;
unsigned long delay2 = 0;

void setup() {
  pinMode(PIN_BOTAO, INPUT_PULLUP);
  pinMode(PIN_BOTAO_RESET, INPUT_PULLUP);

  servo_1.attach(9);
  servo_2.attach(11);
  servo_base.attach(10);
  garra.attach(5);

  Serial.begin(9600);
  Serial.println("START");
}

void loop() {

  // DELAY DE 10 MS
  if ((millis() - delay1) > 10) {

    // MOVIMENTO DO BRAÇO 1
    int analogicoX = analogRead(ANALOG_1_EIXO_X);
    switch (analogicoX) {
      case 0:
        val_servo_1 += PASSO_SERVO;
        if (val_servo_1 > 80) {
          val_servo_1 = 80;
        }

        Serial.print("BRACO 1: ");
        Serial.println(val_servo_1);
        break;
      case 1023:
        val_servo_1 -= PASSO_SERVO;
        if (val_servo_1 < 0) {
          val_servo_1 = 0;
        }

        // MOVIMENTA O BRAÇO 2 JUNTO PARA NÃO TRAVAR - FIM DE CURSO
        if (val_servo_1 <= 50) {
          val_servo_2 -= PASSO_SERVO;
          if (val_servo_2 < 50) {
            val_servo_2 = 50;
          }
        }

        Serial.print("BRACO 1: ");
        Serial.println(val_servo_1);
        break;
    }

    // MOVIMENTO DO BRAÇO 2
    int analogicoX_2 = analogRead(ANALOG_1_EIXO_Y);
    switch (analogicoX_2) {
      case 0:
        val_servo_2 += PASSO_SERVO;
        if (val_servo_2 > 140) {
          val_servo_2 = 140;
        }

        // MOVIMENTA O BRAÇO 1 JUNTO PARA NÃO TRAVAR - FIM DE CURSO
        if (val_servo_2 >= 80) {
          val_servo_1 += PASSO_SERVO;
          if (val_servo_1 > 80) {
            val_servo_1 = 80;
          }
        }

        Serial.print("BRACO 2: ");
        Serial.println(val_servo_2);
        break;
      case 1023:
        val_servo_2 -= PASSO_SERVO;
        if (val_servo_2 < 50) {
          val_servo_2 = 50;
        }

        Serial.print("BRACO 2: ");
        Serial.println(val_servo_2);
        break;
    }

    // MOVIMENTO DA BASE
    int analogicoY = analogRead(ANALOG_2_EIXO_X);
    switch (analogicoY) {
      case 0:
        servo_base_ref -= PASSO_SERVO;
        if (servo_base_ref < 0) {
          servo_base_ref = 0;
        }

        Serial.print("BASE: ");
        Serial.println(servo_base_ref);

        if (servo_base_ref > 0) {
          val_servo_base = 0;  // Move para esquerda
        }
        break;
      case 1023:
        servo_base_ref += PASSO_SERVO;
        if (servo_base_ref > 45) {
          servo_base_ref = 45;
        }

        Serial.print("BASE: ");
        Serial.println(servo_base_ref);

        if (servo_base_ref < 45) {
          val_servo_base = 180;  // Move para direita
        }
        break;
    }

    delay1 = millis();
  }

  // DELAY DE 100 MS
  if ((millis() - delay2) > 100) {

    // CONTROLE DA GARRA
    if (digitalRead(PIN_BOTAO) == LOW) {

      if (!garra_acionada) {
        Serial.println("GARRA ABERTA");
        garra.write(180);
        garra_acionada = true;
        delay(100);
      } else {
        Serial.println("GARRA FECHADA");
        garra.write(110);
        garra_acionada = false;
        delay(100);
      }
    }

    // RESET BASE
    if (digitalRead(PIN_BOTAO_RESET) == LOW) {
      Serial.println("RESET PRESSIONADO");

      servo_base_ref = 0;
    }

    delay2 = millis();
  }

  servo_1.write(val_servo_1);
  servo_2.write(val_servo_2);

  // NECESSÁRIO PARA O CONTROLE DO SERVO MG996
  if (val_servo_base != 90) {
    servo_base.write(val_servo_base);  // Move
    delay(100);
    val_servo_base = 90;
    servo_base.write(val_servo_base);  // Para
  }
}