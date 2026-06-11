Projeto que controla uma mão robótica usando a câmera do computador.
O Python detecta os dedos e envia os dados para o Arduino, que move os servos.

⚙️ Como funciona
Câmera detecta a mão
Python transforma os dedos em 0 e 1
Envia via Serial USB
Arduino move os servos


📦 Instalação
Python
pip install opencv-python cvzone pyserial
▶️ Como usar
Conecte o Arduino no PC
Verifique a porta (COM3, COM4, etc)
Rode o Python:
python dedos.py
⚠️ Configuração

No arquivo Python, ajuste a porta:

arduino = serial.Serial('COM8', 9600)
🤖 Pinos dos servos (Arduino)
Dedão → D6
Indicador → D10
Meio → D3
Anelar → D5
Mindinho → D9
🧠 Lógica
1 = dedo levantado
0 = dedo fechado
📁 Arquivos
dedos.py → código Python (câmera)
arduino.ino → código Arduino (servos)
