/*
Programa que se conecta con un sensor de proximidad y un led rgb,
convierte la presencia en cadenas 0 y 1 y compara una contraseña
con la cadena generada con el sensor. El led se ilumina de azul si 
la contraseña es correcta, y de rojo si no lo es.
*/

//el sensor PIR
int pirPin = 2;    

//valores para contraseña
char con[]= { '0', '0' ,'0'};
char option = 'a';
int aux = 0;

//LED
int verdePin = 11;
int azulPin = 10;
int rojoPin = 9;

/////////////////////////////
//SETUP
void setup(){
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(pirPin, LOW);
  pinMode(rojoPin, OUTPUT);
  pinMode(verdePin, OUTPUT);
  pinMode(azulPin, OUTPUT); 
}
////////////////////////////
//LOOP
void loop(){

      //tiempo de espera de inicio nuevo
      delay(900);

        //si hay presencia = 1
       if(digitalRead(pirPin) == HIGH)
       {
          Serial.print("1-"); 
          option = '1';
          delay(3000);
          aux++;
     
       }
       else
       {
          Serial.print("0-"); 
          option = '0';
          delay(3000);
          aux++;
          
       }

       con[aux-1] = option;

       //Si el contador rellena el array de contraseña
       if(aux == 3 )
       {
          //la contraseña es 110, otra opcion es guardar la
          //contraseña en otro array y comparar
          if( con[0] == '1' && con[1] == '1' && con[2] == '0')
          {
            //control en monitor 
             Serial.print("   contraseña correcta\n"); 
              analogWrite(rojoPin, LOW);
              delay(200);
              analogWrite(azulPin, 255);  
          }else{
             analogWrite(azulPin,LOW);
             delay(200);
             analogWrite(rojoPin, 255);
             
             Serial.print("   contraseña incorrecta\n");
             Serial.print("\nEL array registrado es: ");
             Serial.print(con[0]);
             Serial.print(con[1]);
             Serial.print(con[2]);
             Serial.print("\n");
          }
          
          //Para depurar
          /*
          Serial.print("posicion 0:");
          Serial.print(con[0]);
          Serial.print("posicion 1:");
          Serial.print(con[1]);
          Serial.print("posicion 2:");
          Serial.print(con[2]);
          */

          aux = 0; 
        }
         
          
       

       
   
      
}
