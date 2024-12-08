# Projeto Arduino: Controle de Braço Robótico com Joystick

Este projeto utiliza um Arduino Uno para controlar um braço robótico composto por servos MG995, MG996 e SG90, manipulados por um módulo joystick e botões para acionar e resetar a garra.

---

## ⚙️ Componentes Utilizados

### Hardware
- **Arduino Uno**
- **Servos:**
  - MG995 (x2)
  - MG996 (x1)
  - SG90 (x1)
- **Módulo Joystick**
  - Conexões: Eixos X e Y (analógicos), botões (digitais).
- **Botões:**
  - Botão de controle da garra.
  - Botão de reset para a base.
- Jumpers e cabos de conexão.

### Software
- **Linguagem:** C++ (usando a IDE Arduino).
- **Biblioteca:**
  - [Servo.h](https://www.arduino.cc/reference/en/libraries/servo/): Controle de servomotores.

---

## 🚀 Funcionalidades

- **Controle dos braços robóticos:**
  - Movimentação dos servos que compõem o braço com precisão.
  - Sincronização de movimentos para evitar travamentos nos fins de curso.
  
- **Movimentação da base:**
  - Rotação controlada por joystick, com limites de movimento configurados.

- **Controle da garra:**
  - Botão para abrir e fechar a garra.

- **Reset da base:**
  - Retorna a base para a posição inicial ao pressionar o botão de reset.

---

## 🔌 Esquemático de Conexões

### Conexões dos Servos
| Servo            | Pino Arduino |
|-------------------|--------------|
| MG995            | 9            |
| MG995 (braço)    | 11           |
| MG996 (base)     | 10           |
| SG90 (garra)     | 5            |

### Conexões do Joystick
| Joystick | Pino Arduino |
|----------|--------------|
| Eixo X1  | A0           |
| Eixo Y1  | A1           |
| Eixo X2  | A2           |
| Botão    | 2            |

### Conexões dos Botões
| Botão         | Pino Arduino |
|---------------|--------------|
| Garra         | 2            |
| Reset Base    | 4            |

---

## 🛠️ Como Usar

### Passo 1: Configurar o Hardware
1. Conecte os servos MG995, MG996 e SG90 conforme descrito na tabela de conexões.
2. Conecte o módulo joystick aos pinos analógicos do Arduino.
3. Conecte os botões nos pinos digitais com resistores pull-up internos.

### Passo 2: Configurar o Software
1. Abra o código na IDE Arduino.
2. Certifique-se de que a biblioteca **Servo.h** está instalada.
3. Faça upload do código para o Arduino Uno.

### Passo 3: Operar o Braço Robótico
- Utilize o joystick para controlar os movimentos dos servos.
- Pressione o botão de controle para abrir/fechar a garra.
- Use o botão de reset para reposicionar a base.

---

## 📂 Organização do Código

O código está estruturado em um único arquivo `.ino`. Para projetos maiores, considere dividir o código em módulos para melhor organização.

---

## 📋 Observações

- **Alimentação:** Certifique-se de usar uma fonte externa para os servos MG995 e MG996, pois eles consomem mais corrente do que o Arduino pode fornecer.
- **Calibração:** Ajuste os limites de movimento no código, se necessário, para evitar danos físicos ao braço robótico.

---

## 📚 Datasheets
Os datasheets dos componentes usados neste projeto estão na pasta [docs/datasheets/](docs/datasheets/).
