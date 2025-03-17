void readAddress(byte adrByte2, byte adrByte1) {
  Serial.print("Adr " + String(adrByte1) + ": ");
  PORTL = adrByte1;
  PORTA = adrByte2;
  PORTB = 0b00100000;
  for (int pin = 30; pin < 38; pin++) {
    Serial.print(digitalRead(pin));
  }
  PORTB = 0b00110000;
  Serial.println();
}

void writeData(byte adrByte2, byte adrByte1, byte data) {
  DDRC = 0b11111111; // Data
  DDRA = 0b11111111; // Address 2
  DDRL = 0b11111111; // Address 1
  DDRB = 0b11110000; // Red, Green, WE#, OE#

  PORTA = 0b00000000;
  PORTC = 0b00000000;
  PORTL = 0b00000000;
  PORTB = 0b00110000;
  
  PORTL = 0b01010101;
  PORTA = 0b01010101;
  PORTC = 0b10101010;
  PORTB = 0b00110000;
  PORTB = 0b00010000;
  PORTB = 0b00010000;
  PORTB = 0b00110000;

  PORTL = 0b10101010;
  PORTA = 0b00101010;
  PORTC = 0b01010101;
  PORTB = 0b00110000;
  PORTB = 0b00010000;
  PORTB = 0b00010000;
  PORTB = 0b00110000;

  PORTL = 0b01010101;
  PORTA = 0b01010101;
  PORTC = 0b10100000;
  PORTB = 0b00110000;
  PORTB = 0b00010000;
  PORTB = 0b00010000;
  PORTB = 0b00110000;

  PORTL = adrByte1;
  PORTA = adrByte2;
  PORTC = data;
  PORTB = 0b00110000;
  PORTB = 0b00010000;
  PORTB = 0b00010000;
  PORTB = 0b00110000;
  PORTB = 0b00110000;
  PORTB = 0b00010000;
  PORTB = 0b00010000;

  PORTL = 0b00000000;
  PORTA = 0b00000000;
  PORTC = 0b00000000;
  DDRC = B00000000;
  PORTB = 0b00100000;
}

void clearChip() {
  PORTL = 0x55;
  PORTA = 0x55;
  PORTC = 0xaa;
  PORTB = 0b00110000;
  PORTB = 0b00010000;
  PORTB = 0b00010000;
  PORTB = 0b00110000;

  PORTL = 0xaa;
  PORTA = 0x2a;
  PORTC = 0x55;
  PORTB = 0b00110000;
  PORTB = 0b00010000;
  PORTB = 0b00010000;
  PORTB = 0b00110000;

  PORTL = 0x55;
  PORTA = 0x55;
  PORTC = 0x80;
  PORTB = 0b00110000;
  PORTB = 0b00010000;
  PORTB = 0b00010000;
  PORTB = 0b00110000;

  PORTL = 0x55;
  PORTA = 0x55;
  PORTC = 0xaa;
  PORTB = 0b00110000;
  PORTB = 0b00010000;
  PORTB = 0b00010000;
  PORTB = 0b00110000;

  PORTL = 0xaa;
  PORTA = 0x2a;
  PORTC = 0x55;
  PORTB = 0b00110000;
  PORTB = 0b00010000;
  PORTB = 0b00010000;
  PORTB = 0b00110000;

  PORTL = 0x55;
  PORTA = 0x55;
  PORTC = 0x10;
  PORTB = 0b00110000;
  PORTB = 0b00010000;
  PORTB = 0b00010000;
  PORTB = 0b00110000;
  Serial.println("cleared");
}

byte binToDecOut[] = {
  0b10001000, // 0
  0b11101110, // 1
  0b01001001, // 2
  0b01001100, // 3
  0b00101110, // 4
  0b00011100, // 5
  0b00011000, // 6
  0b11001110, // 7
  0b00001000, // 8
  0b00001100, // 9
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  DDRC = 0b11111111; // Data
  DDRA = 0b11111111; // Address 2
  DDRL = 0b11111111; // Address 1
  DDRB = 0b11110000; // Red, Green, WE#, OE#

  PORTA = 0b00000000;
  PORTC = 0b00000000;
  PORTL = 0b00000000;
  PORTB = 0b00110000;
  clearChip();
  delay(100);
  int hi = 0;

  for (hi; hi < 10; hi++) {
    writeData(0b00000000, hi, binToDecOut[hi]);
    delay(50);
    readAddress(0,hi);
    delay(50);
    Serial.println(String(binToDecOut[hi], BIN));
  }
//for (int a=0; a < 10; a++) {
//  readAddress(0,a);
//}


  PORTA = 0b00000000;
  PORTC = 0b00000000;
  PORTL = 0b00000000;
  PORTB = 0b00100000;
}

void loop() {
  // put your main code here, to run repeatedly:

}




//  int value = 1;
//  clearChip();
//  delay(100);
//  writeData(0b00000000, value, binToDecOut[value]);
//  readAddress(0, value);
//  delay(100);
//  writeData(0b00000000, 2, binToDecOut[2]);
//  readAddress(0, 2);
