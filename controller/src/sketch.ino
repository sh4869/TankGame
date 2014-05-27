//ボタンのピン番号
#define Bt1 2
#define Bt2 5
#define Bt3 7

#define L1 3
#define L2 8
#define L3 6


//アナログのピン番号
#define An1 1 
#define An2 2
#define An3 3

#define L4 9
#define L5 10
#define L6 11

//ループのカウント
unsigned char Lcount = 0;

//unsigned char SendVal = 0;

//An1  An2  An3  (Bt1  Bt2  Bt3)
unsigned char Before[6] = { 255, 255, 255, 255, 255, 255 };
unsigned char temp = 0;
//int num = 0;

void setup()
{
  pinMode(Bt1, INPUT);
  pinMode(Bt2, INPUT);
  pinMode(Bt3, INPUT);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);
  pinMode(L5, OUTPUT);
  pinMode(L6, OUTPUT);
  Serial.begin(9600);


  //Before[0] = analogRead(An1) / 16;
  //Serial.write(Before[0] | 0x00);

  //Before[1] = analogRead(An2) / 16;
  //Serial.write(Before[1] | 0x40);

  //Before[2] = analogRead(An3) / 16;
  //Serial.write(Before[2] | 0x80);

  //Before[3] = (digitalRead(Bt1) << 2) | (digitalRead(Bt2) << 1) | (digitalRead(Bt3));
  //Serial.write(Before[3] | 0x80);

}


//判別	アナログ1
//00	000000

//判別	アナログ2
//01	000000

//判別	アナログ3
//10	000000

//判別	常に0	デジタル(上位から1,2,3)
//11	000			000

void loop()
{
  temp = analogRead(An1) / 16;
  if (Before[0] != temp){
	Before[0] = temp;
	analogWrite(L4, analogRead(An1)/4);
	//Serial.write(Before[0] | 0x00);
	Serial.print("0\t");
	Serial.println(Before[0]);
  }

  temp = analogRead(An2) / 16;
  if (Before[1] != temp){
	analogWrite(L5, analogRead(An2) / 4);
	Before[1] = temp;
	//Serial.write(Before[1] | 0x40);
	Serial.print("1\t");
	Serial.println(Before[1]);
  }

  temp = analogRead(An3) / 16;
  if (Before[2] != temp){
	analogWrite(L6, analogRead(An3) / 4);
	Before[2] = temp;
	//Serial.write(Before[2] | 0x80);
	Serial.print("2\t");
	Serial.println(Before[2]);
  }

  //	temp = (digitalRead(Bt1) << 2) | (digitalRead(Bt2) << 1) | (digitalRead(Bt3));


  temp = (digitalRead(Bt1));
  if (Before[3] != temp){
	Before[3] = temp;
	digitalWrite(L1, temp);
	//Serial.write(Before[3] | 0xC0);
	Serial.print("3\t");
	Serial.println(Before[3]);
  }

  temp = (digitalRead(Bt2));
  if (Before[4] != temp){
	digitalWrite(L2, temp);
	Before[4] = temp;
	//Serial.write(Before[3] | 0xC0);
	Serial.print("4\t");
	Serial.println(Before[4]);
  }

  temp = (digitalRead(Bt3));
  if (Before[5] != temp){
	digitalWrite(L3, temp);
	Before[5] = temp;
	//Serial.write(Before[3] | 0xC0);
	Serial.print("5\t");
	Serial.println(Before[5]);
  }

  //Serial.println(analogRead(An2));
  //SendVal = 0;



  //delay(10);
  //switch (Lcount)
  //{
  //case 0:
  //	num = analogRead(An1);
  //	SendVal = (num) / 16;
  //	SendVal |= 0x00;
  //	Serial.write(SendVal);
  //	break;
  //case 1:
  //	num = analogRead(An2);
  //	SendVal = (num) / 16;
  //	SendVal |= 0x40;
  //	Serial.write(SendVal);
  //	break;
  //case 2:
  //	num = analogRead(An3);
  //	SendVal = (num) / 16;
  //	SendVal |= 0x80;
  //	Serial.write(SendVal);
  //	break;
  //case 3:
  //	
  //	SendVal |= digitalRead(Bt1) << 2;
  //	SendVal |= digitalRead(Bt2) << 1;
  //	SendVal |= digitalRead(Bt3);
  //	
  //	SendVal |= 0xC0;
  //	Serial.write(SendVal);
  //	break;

  //default:
  //	break;
  //};
  //Lcount++;
  //if (Lcount == 4){
  //	Lcount = 0;
  //}
}
