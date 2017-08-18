const int LogicVDD_pin = 10;
const int Cam2Lens_pin = 11;
const int Clock_pin = 13;
void setup()
{
  pinMode(LogicVDD_pin, OUTPUT);
  digitalWrite(LogicVDD_pin, HIGH);
  
  pinMode(Cam2Lens_pin, OUTPUT);

  pinMode(Clock_pin, OUTPUT);
  digitalWrite(Clock_pin, HIGH);


   send_signal(0xA0);
   delay(1000);
//
//   send_signal(0x31);
//   delay(200);
//   send_signal(0x08);
//   delay(1000);
   send_signal(0x70);
  delay(250);
   send_signal(0x31);
  delay(250);
   send_signal(0x40);
  delay(250);
   send_signal(0x00);


  
}

void send_signal(byte signal)
{
  unsigned int i;
  for (i = 0; i < 16; i++)
  {
    digitalWrite(Clock_pin, i & 1);
    if(i % 2 == 0)
    {
     digitalWrite(Cam2Lens_pin, (signal >> (i/2)) & 1);
    }
  }
}

void loop()
{
}

