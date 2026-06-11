#include <Servo.h>

Servo dedao;
Servo indicador;
Servo meio;
Servo anelar;
Servo mindinho;

String data = "";
bool dataComplete = false;

int aberto = 10;
int fechado = 170;

void setup() {
  Serial.begin(9600);

  dedao.attach(6);
  indicador.attach(10);
  meio.attach(3);
  anelar.attach(5);
  mindinho.attach(9);

  abrirMao();
}

void loop() {
  if (dataComplete) {

    int dedos[5];
    int index = 0;

    for (int i = 0; i < 5; i++) {
      dedos[i] = data.substring(index, index + 1).toInt();
      index += 2;
    }

    // 👍 dedão OK (não mexe)
    dedao.write(dedos[0] ? fechado : aberto);

    // 🔁 demais INVERTIDOS (corrigido aqui)
    indicador.write(dedos[1] ? aberto : fechado);
    meio.write(dedos[2] ? aberto : fechado);
    anelar.write(dedos[3] ? aberto : fechado);
    mindinho.write(dedos[4] ? aberto : fechado);

    data = "";
    dataComplete = false;
  }
}

void serialEvent() {
  while (Serial.available()) {
    char c = (char)Serial.read();

    if (c == '\n') {
      dataComplete = true;
    } else {
      data += c;
    }
  }
}

void abrirMao() {
  dedao.write(aberto);
  indicador.write(aberto);
  meio.write(aberto);
  anelar.write(aberto);
  mindinho.write(aberto);
}