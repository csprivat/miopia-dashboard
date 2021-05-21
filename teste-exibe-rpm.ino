// Carrega biblioteca do Nextion
#include "Nextion.h"
#include "NexText.h"


/* Define os objetos da interface
 *  object [page id, component id, component name ""]
 */
 NexText tRPM = NexText(0, 2, "tRPM");


// Declaracao das variaveis
int exiberpm = 6300;
char buffer[1000] = {0};

void setup(void) {
  //Inicia Nextion
  nexInit();
  
  
  //Inicia porta serial
  Serial.begin(9600);
 }

void loop(void) {


// Conversao dos valores de inteiro para string
   memset(buffer, 0, sizeof(buffer));
   itoa(exiberpm, buffer, 10);
  
  tRPM.setText(buffer);
}

