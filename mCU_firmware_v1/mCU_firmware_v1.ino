const int LogicVDD_pin = 10;
const int Cam2Lens_pin = 11;
const int Clock_pin = 13;

//fstops = {0:'0',0x8:'1',0xB:'1.1',0xC:'1.2',0xD:'1.2',0x10:'1.4',0x13:'1.6',
//          0x14:'1.8',0x15:'1.8',0x18:'2',0x1B:'2.2',0x1C:'2.5',0x1D:'2.5',0x20:'2.8',
//          23:'3.2',0x24:'3.2',0x25:'3.5',0x28:'4',0x2B:'4.5',0x2C:'4.5',0x2D:'5',
//          0x30:'5.6',0x33:'6.3',0x34:'6.7',0x35:'7.1',0x38:'8',0x3B:'9',0x3C:'9.5',
//          0x3D:'10',0x40:'11',0x43:'13',0x44:'13',0x45:'14',0x48:'16',0x4B:'18',
//          0x4C:'19',0x4D:'20',0x4E:'20',0x4F:'20',0x50:'22',0x53:'25',0x54:'27',
//          0x55:'29',0x58:'32',0x5A:'32',0x5B:'36',0x5C:'38',0x5D:'40',0x60:'45', 
//          0x63:'51',0x64:'54',0x65:'57',0x68:'64',0x6B:'72',0x6C:'76',0x6D:'80',0x70:'91'}

void setup()
{
  pinMode(LogicVDD_pin, OUTPUT);
  digitalWrite(LogicVDD_pin, HIGH);
  
  pinMode(Cam2Lens_pin, OUTPUT);

  pinMode(Clock_pin, OUTPUT);
  digitalWrite(Clock_pin, HIGH);


  send_signal(0x4F);
  delay(1000);
  send_signal(0x50);
  delay(200);  
  send_signal(0x60);
  delay(200);
  send_signal(0xA0);
  delay(1000);

    send_signal(0x07);
    delay(200);
    send_signal(0x13);
    delay(200);
    send_signal(0x48);
    delay(200);
    send_signal(0xA0);
    delay(250);
  
}

void send_signal(byte signal)
{
  unsigned int i;
  for (i = 0; i < 16; i++)
  {
    digitalWrite(Clock_pin, i & 1);
    if(i % 2 == 0)
    {
//     digitalWrite(Cam2Lens_pin, (signal >> (i/2)) & 1);
     digitalWrite(Cam2Lens_pin, (signal >> (i/2)) & 1);

    }
  }
}

void loop()
{
}

