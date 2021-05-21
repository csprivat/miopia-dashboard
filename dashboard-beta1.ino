
/*
  MIOPIA DASHBOARD
  Copyright 2017, Cristian Privat (privat.tecnologia@gmail.com)
 
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 
    Função shiftlhight baseada no código de Cassio Urquisa: https://www.youtube.com/watch?v=Uxf_4gSZqTA
   
 Versão Beta1: 21/04/2017: Leitura do sinal RPM
 
 */

 /* 
  *  OBJETOS DO LAYOUT
  *  Page 0
  *  Objeto           ID          Nome
  *  Barra RPM        1           rpm_bar 
  *  Exibe RPM        2           tRPM      
  *  Exibe Marcha     3           tGEAR
  *  Label SPPED      4           t1
  *  Exibe SPEED      5           tSPEED
  *  Label RPM        7           t0
  *  Relógio          8           tCLOCK
  */


// Carrega biblioteca do Nextion
#include "Nextion.h"
#include "NexText.h"



/* Define os objetos da interface
 *  object [page id, component id, component name ""]
 */
NexProgressBar rpm_bar = NexProgressBar(0, 1, "rpm_bar");
NexText tRPM = NexText(0, 2, "tRPM");
NexText tGEAR = NexText(0, 3, "tGEAR");
//NexText t1 = NexText(0, 4, "t1");
NexText tSPEED = NexText(0, 5, "tSPEED");
//NexText t0 = NexText(0, 7, "t0");
NexText tCLOCK = NexText(0, 8, "tCLOCK");



// Declaração das variáveis
int exiberpm;
int exibespeed = 0;
char bufferrpm[32] = {0};
char buffer2[16] = {0};
int rpmbar = 0;
//char buffer_hour[10] = {0};
//char buffer_minute[10] = {0};
int rpmin = 12;  //sinal RPM
//int ledGreen1 = 5;
//int ledGreen2 = 11;
//int ledYellow1 = 6;
//int ledYellow2 = 9;
//int ledRed = 3;
//int ledBlue = 10; // Desabilita os leds azuis 
//int ledAll = 8;
unsigned long duration;
unsigned long rpm;


void setup() {
  //Inicia Nextion
  nexInit();
  
  //Inicia porta serial
  Serial.begin(9600);

  //Define estado das portas
  pinMode(rpmin, INPUT);
  pinMode(8, OUTPUT);

}

void loop(void) {
   
  // Conversao dos valores de inteiro para string
   memset(bufferrpm, 0, sizeof(bufferrpm));
   //itoa(exiberpm, buffer, 10);
   ltoa(rpm, bufferrpm, 10);
   tRPM.setText(bufferrpm);
  

  //Serial.print("RPM: ");
  //Serial.println(rpm);
   duration = pulseIn(rpmin, HIGH);
   
  //if (rpm > 5800) Serial.println("SHIFT! "); valor original
  //if (rpm > 6200) Serial.println("SHIFT! "); // novo valor
  
  //Cálculo RPM (Pode variar de acordo com o modelo do veículo)
  //rpm = 30000000 / duration;
    rpm = 15000000 / duration;
 
       
  //Apaga todos os leds
  // digitalWrite(ledAll, HIGH); // HIGH para Catodo comum; LOW para Anodo comum

  //Alerta - Acende todos os leds em azul quando RPM atinge Corte do motor
  //if (rpm > 5800 && rpm < 7200){  // Valor original
    //if (rpm > 6200 && rpm < 6500){ // Novo valor
    //digitalWrite(ledAll, /*HIGH*/LOW); // HIGH para Catodo comum; LOW para Anodo comum
    //delay(35);
    //digitalWrite(ledAll, /*LOW*/HIGH); // LOW para Catodo comum; HIGH para Anodo comum
    //delay(15); 
    
  //}
/*
  //Acionamento sequencial dos leds de acordo com faixas de rotação
  if (rpm > 4300) analogWrite(ledGreen1, 0);
  if (rpm < 4250 || rpm > 6200) analogWrite(ledGreen1, 255); //Use "0" para Catodo comum
  
  if (rpm > 4650) analogWrite(ledGreen2, 0);
  if (rpm < 4600 || rpm > 6200) analogWrite(ledGreen2, 255); //Use "0" para Catodo comum
  
  if (rpm > 4950) analogWrite(ledYellow1, 0);
  if (rpm < 4900 || rpm > 6200) analogWrite(ledYellow1, 255); //Use "0" para Catodo comum
  
  if (rpm > 5250) analogWrite(ledYellow2, 0);
  if (rpm < 5200 || rpm > 6200) analogWrite(ledYellow2, 255); //Use "0" para Catodo comum
  
  if (rpm > 5550) analogWrite(ledRed, 0);
  if (rpm < 5500 || rpm > 6200) analogWrite(ledRed, 255); //Use "0" para Catodo comum
  
  //Descomente abaixo para habilitar os três leds azuis
  //if (rpm > 5750) analogWrite(ledBlue, 17);
  //if (rpm < 5700 || rpm > 6200) analogWrite(ledBlue, 127);
  
  delay(15);

  */
}
