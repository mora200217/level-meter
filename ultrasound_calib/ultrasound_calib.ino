/**
   Calibración de sensor ultrasónico (HC-SR04)
   -
   Este script busca tomar N medidas del sensor HC-SR04 
   para poder imprimirlas en el Monitor serial, y poder ser 
   usadas en entornos de análisis de datos, tales como Matlab y/o Python 

   Autor: Andrés Morales (amoralesma@unal.edu.co)
   Materia: Sensores y Actuadores 
   Semestre: 2024-ii

*/

// Pines para el Ultrasonido.
#define TRIGGER
#define ECHO
#define N // Número de medidos 

const float Vs = 3.44;  // Velocidad del sonido (m/s)
int count = 0; 

void setup() {
  Serial.begin(9600);
  
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop() {
  delayMicroseconds(5);
  digitalWrite(TRIGGER, HIGH); 
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW); 

  float t = pulseIn(ECHO); // microsegundos 
  float d = t * Vs;  // Distancia calculada 

  showData(d); 
  
  if(++count >= N){
    Serial.println("-"); 
  while(true){}; 
  }
}


void showData(float d){
  Serial.println("-"); 
  Serial.println(d); 
    
}
