
//Declaramos los pines
const int led = 11;
const int trig = 9;
const int echo = 8;

//Declaramos algunas variables
long tiempo;
long distancia;

void setup() {
  pinMode(led,OUTPUT);
  pinMode(trig, OUTPUT); //Activación del pin trig como salida: para el pulso ultrasónico
  pinMode(echo, INPUT); //Activación del pin echo como entrada: tiempo del rebote del ultrasonido
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(5); //Par cuestión de estabilización del sensor
  digitalWrite(trig, HIGH); //Enviamos el pulso ultrasónico
  delayMicroseconds(10);
  tiempo = pulseIn(8, HIGH); //Función para medir la longitud del pulso entrante. Mide el tiempo transcurrido entre el envio del pulso ultrasónico y cuando el sensor recibe eñ rebote./
  distancia = int(0.107*tiempo); //Formula para calcular la distancia obtenida en cm
  
  if(distancia <= 20){
    digitalWrite(led,HIGH); //Si el sensor mide una distancia más pequeña o igual a 5cm, enciende el LED
  }
  else{
    digitalWrite(led,LOW); //Sinó, apaga el LED
  }
}
  

