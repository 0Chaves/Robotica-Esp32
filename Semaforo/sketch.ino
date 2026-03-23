/* Semaforo
  * Reproduz a troca de cores constantemente
  * Se o botão for apertado enquanto o led vermelho está acesso, irá piscar e pular direto para o verde
*/

int buttonPin = 2;
int greenPin = 19;
int yellowPin = 18;
int redPin = 21;
int buttonState = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  digitalWrite(redPin, HIGH);
  delay(500);
}

void loop() {
  semaforo();
  for(int i = 0; i<=200; i++){
    buttonState = digitalRead(buttonPin);
    if(abrir_pedestres(buttonState)) break;
    delay(10);
  }
  // Por que se verificar o greenPin não funciona?
  if(buttonState == HIGH){
    Serial.println("Caiu no IF");
    delay(5000);
    digitalWrite(greenPin, LOW);
  }
}

void semaforo(){
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, HIGH);
  delay(1000);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, HIGH);
  delay(2000);
  digitalWrite(greenPin, LOW);
  delay(5);
  digitalWrite(redPin, HIGH);
}

int abrir_pedestres(int buttonState){
  if(buttonState == HIGH){
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
    piscar(redPin);
    digitalWrite(greenPin, HIGH);
    return 1;
  }
  return 0;
}

void piscar(int led){
  for(int i = 0; i<5; i++){
    digitalWrite(led, LOW);
    delay(300);
    digitalWrite(led, HIGH);
    delay(300);
  }
  digitalWrite(led, LOW);
}
