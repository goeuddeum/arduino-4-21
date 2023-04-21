int DS_pin = 4;
int STCP_pin = 3;
int SHCP_pin = 2;

int digits [10][8]{
  {0,1,1,1,1,1,1,0}, // digit 0
  {0,0,1,1,0,0,0,0}, // digit 1
  {0,1,1,0,1,1,0,1}, // digit 2
  {0,1,1,1,1,0,0,1}, // digit 3
  {0,0,1,1,0,0,1,1}, // digit 4
  {0,1,0,1,1,0,1,1}, // digit 5
  {0,1,0,1,1,1,1,1}, // digit 6
  {0,1,1,1,0,0,1,0}, // digit 7
  {0,1,1,1,1,1,1,1}, // digit 8
  {0,1,1,1,1,0,1,1}  // digit 9
};

int dec_digits[10]{1,79,18,6,76,36,32,15,0,4};

void setup(){
  pinMode(DS_pin, OUTPUT);
  pinMode(STCP_pin, OUTPUT);
  pinMode(SHCP_pin, OUTPUT);
}

void DisplayDigit(int Digit)
{
    digitalWrite(STCP_pin,LOW);
    for (int i = 7; i>=0; i--)
   {
    digitalWrite(SHCP_pin,LOW);
    if (digits[Digit][i]==1) digitalWrite(DS_pin, LOW); 
    if (digits[Digit][i]==0) digitalWrite(DS_pin, HIGH);
    digitalWrite(SHCP_pin,HIGH);
   }
   digitalWrite(STCP_pin, HIGH); 
}



void loop() { 
  for (int j=0;j<10;j++){  
    for (int i=0;i<10;i++){
      digitalWrite(STCP_pin,LOW);
      shiftOut(DS_pin, SHCP_pin, LSBFIRST,dec_digits[i]);
      shiftOut(DS_pin, SHCP_pin, LSBFIRST,dec_digits[j]);
      digitalWrite(STCP_pin, HIGH);
      delay(100);
 }
}
} 
