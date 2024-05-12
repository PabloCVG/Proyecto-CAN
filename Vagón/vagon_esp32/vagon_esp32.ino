//variables pines pwm
int PinHig = 27;
int PinLow = 26;
int VELPin = 14;

//variables pines ultra
int Pinecho = 5;
int Pintrigger = 18;
int PinInterrup = 19;

// variables  PWM
const int freq = 30000;
const int canal = 0;
const int resol= 8;
int dutyCycle = 150;

//
volatile int Y=0;

//variables calculo ultra 
unsigned int tiempo, distancia; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // comunicacion con la computadora (para pruebas)

  pinMode(PinHig, OUTPUT); // poner pin como salida 
  pinMode(PinLow, OUTPUT);
  pinMode(VELPin, OUTPUT);

  pinMode(Pinecho, INPUT); // poner pin como entrada 
  pinMode(Pintrigger, OUTPUT);
  pinMode(PinInterrup, OUTPUT);


  // configuracion PWM
  ledcSetup(canal, freq, resol); // funcion pwm proveniente del IDE 
  
  // asociar pwm a un pin
  ledcAttachPin(VELPin,canal);// funcion pwm proveniente del IDE

  //asociar pin a interrupcion 1
  attachInterrupt(PinInterrup,PararEmergencia,RISING);

  digitalWrite(PinHig,HIGH);
  digitalWrite(PinLow,LOW);

   Arranque();
}


// funcion que hace que empiece a arrancar el vagon 
void Arranque(){
  while(dutyCycle <= 200) {
  ledcWrite(canal, dutyCycle);
  Serial.print("aumento del ciclo : ");
  Serial.println(dutyCycle);
  dutyCycle +=10;
  delay(50);
  }
  dutyCycle=200; //sirve 
}

//solo valido con 12 volts o una pila de 9vs y sirve para umentar la velocidad 
void Aumentar(){
  while(dutyCycle <= 255) {
  ledcWrite(canal, dutyCycle);
  Serial.print("Forward with duty cycle: ");
  Serial.println(dutyCycle);
  dutyCycle +=5;
  delay(50);
  }
  dutyCycle=255;
}

// funcion para detener el vagaon 

void Detener  (){
  dutyCycle = 0;
  ledcWrite(canal, dutyCycle);
}

//Funcion de interrupcion 
void PararEmergencia(){

  Detener();
  Serial.println("interrupcion aqui");
 
}

//funcion que permite el funcionamiento del ultrasonico 
void Ultra(){
  digitalWrite(Pintrigger,LOW);
  delayMicroseconds(2);
  digitalWrite(Pintrigger,HIGH); 
  delayMicroseconds(10);
  digitalWrite(Pintrigger,LOW);
  tiempo=pulseIn(Pinecho,HIGH);
  distancia=tiempo/58; 
  if(distancia <=4){
    digitalWrite(PinInterrup,HIGH);
    } 
   else{
    digitalWrite(PinInterrup,LOW);
    }
}

void loop() {
  // put your main code here, to run repeatedly: 
  Ultra();
}
