const double distanciaHaciaTablero = 10.0;
const int distanciaPorRecorrerRack = 30; //distancia en cm
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
}

void loop() {
    //esperar confirmacion de modelo de tablero
    String lecturaSerial = leerSerial();
    if(lecturaSerial.length() != 0){
        if(lecturaSerial.charAt(0) == '1') // listo para ajustar tablero
        {   
            String distanciaRackstr = lecturaSerial.substring(2); 
            char x[10];
            distanciaRackstr.toCharArray(x, 10);
            float distanciaRack = atof(x);        //convertir distancia a flotante
            
            Serial.print("Ajustandooo distancia: ");
            Serial.println(distanciaRack);
            ajustarRack(distanciaRack); 
            do{
                lecturaSerial = leerSerial(); //esperando confirmacion para comenzar ejecucion
            }while(lecturaSerial == "");
            Serial.println(lecturaSerial);
            if(lecturaSerial.startsWith("start")){ // listo para comenzar ejecucion
                  Serial.println("Iniciando ejecucion...");
                  runFeeder();
                  //Serial.write("z");
            }
            else{
                  Serial.println("Error: cargar receta denuevo.");
            }
        }
    }
    else {
      //Serial.print("No hay comunicacion serial");
    }
}



void ajustarRack(float distanciaNueva){
    Serial.println("Ajustando Rack...");
    float distanciaActual; //para PID
    
}

void runFeeder(){
    double distanciaRecorridaRack = 0;
    String lecturaSerial;
    while(distanciaPorRecorrerRack > distanciaRecorridaRack){
        moverRackAbajo();
        empujarTablero();
        moverConveyorACamara();
        Serial.println("Esperando respuesta de camara...");
        do{
              lecturaSerial = leerSerial();
        }while(lecturaSerial == "");
        if(lecturaSerial.startsWith("pass")){ //Pass
              moverConveyorEnfrente();
              Serial.println("Aprobado, moviendo conveyor...");
        }
        else{
              Serial.println("Denegado, regresando tablero...");
              regresarTablero();
        }
        distanciaRecorridaRack = lecturaSensor_PlataformaZ();
    }
    
}

double lecturaSensor_PlataformaZ(){
    //insertar manera de detectar distancia en cm 
    //fin
}

void moverRackAbajo(){
    Serial.println("Moviendo Rack...");
    do{
      
        //mover motorZ cierta cantidad de steps
    }while(!detectarTablero());
}

double lecturaSensor_Tablero(){
  //insertar manera de obtener distancia 
  //fin
}

bool detectarTablero(){ //regresa si ya no detecto vacio en el rack
    return (lecturaSensor_Tablero() < distanciaHaciaTablero);
}

void empujarTablero(){
    Serial.println("Empujando tablero...");
    //empujar tableros con sinfin
    //es solo eso y regresar
    //fin
}

void moverConveyorACamara(){
    Serial.println("Moviendo Conveyor...");
    //activar conveyor
    //detener cuando un sensor detecte que esta cerca de la camara
}

void moverConveyorEnfrente(){
    //esto solo es activar el conveyor
}

void regresarTablero(){
    //esto solo es mover conveyor hacia atras 
    //y empujar con el otro motor llamado 'poka yoke'
}

void reiniciarSerial(){
    while(Serial.available()>0){
        Serial.read();    
    }
    Serial.end();
    Serial.begin(9600);
}

String leerSerial(){
    String stringSerial="";
    char charSerial=' ';
    while(Serial.available()){
        delay(3);
        if(Serial.available() > 0){
            charSerial = Serial.read();
            stringSerial += charSerial;
        }
    }
    reiniciarSerial();
    return stringSerial;
}

