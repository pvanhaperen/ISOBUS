#include <SPI.h>
#include <ISOBUS.h>

char spn_buffer[512];  //Data will be temporarily stored to this buffer before being written to the filechar buffer[512];  //Data will be temporarily stored to this buffer before being written to the file

ISOBUSMessage receiveMessage;

void setup()
{
  ISOBUS.begin(CAN_SPEED_250000);
  ISOBUS.setMode (CAN_MODE_NORMAL);
  Serial.begin(19200);
}

void loop()
{
  /* Receive data if available */
  if (ISOBUS.available()) {  
    receiveMessage = ISOBUS.getMessageISOBUS(WBSD_TECU_PGN, WheelBasedMachineDirection_SPN, spn_buffer);
    if (receiveMessage.status == 0) 
    {
      Serial.print(receiveMessage.status);
      Serial.print(",");
      Serial.print(receiveMessage.id);
      Serial.print(",");
      Serial.print(receiveMessage.pgn);
      Serial.print(",");
      Serial.print(receiveMessage.spn_data);
      Serial.print(",");
      Serial.println(spn_buffer);
    }
  }
}








