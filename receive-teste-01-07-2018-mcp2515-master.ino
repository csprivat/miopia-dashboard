/* MIOPIA DASHBOARD
 * Teste inicial biblioteca mcp2515-master
 * 01-07-2018
 */

#include <SPI.h>
#include <mcp2515.h>

struct can_frame canMsg;
MCP2515 mcp2515(10);


void setup() {
  Serial.begin(115200);
  SPI.begin();
  
  mcp2515.reset();
  mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ); //oscilador definido para 08MHz
  /*
   CAN_5KBPS,
    CAN_10KBPS,
    CAN_20KBPS,
    CAN_31K25BPS,
    CAN_33KBPS,
    CAN_40KBPS,
    CAN_50KBPS,
    CAN_80KBPS,
    CAN_83K3BPS,
    CAN_95KBPS,
    CAN_100KBPS,
    CAN_125KBPS,
    CAN_200KBPS,
    CAN_250KBPS,
    CAN_500KBPS,
    CAN_1000KBPS
   */
  mcp2515.setNormalMode();
  
  Serial.println("MIOPIA DashBoard");
  Serial.println("------- CAN Read ----------");
  Serial.println("ID      DLC       DATA");
}

void loop() {
  
  if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) {
      
    Serial.print(canMsg.can_id, HEX); // print ID
    Serial.print(" "); 
    Serial.print(canMsg.can_dlc, HEX); // print DLC
    Serial.print(" ");
    
    for (int i = 0; i<canMsg.can_dlc; i++)  {  // print the data
        
      Serial.print(canMsg.data[i],HEX);
      Serial.print(" ");

    }

    Serial.println();      
  }

/*
"PID00-21", // 0x00   PIDs supported

"CoolantT", // 0x05   Engine coolant temperature
"Fuel Prs", // 0x0A   Fuel pressure
"  MAP  ",  // 0x0B   Intake manifold absolute pressure
"  RPM  ",  // 0x0C   Engine RPM
"Throttle", // 0x11   Throttle position
 
 */


}
