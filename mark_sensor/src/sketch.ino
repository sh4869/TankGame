/*------------------------------------------ 
Description:
  	Control Infreared Light Sensor For Mark 
Arduino Board: 
	all
Use Pin:
	OUTPUT:
		0,1,2,3,4,5
	INPUT:
		NONE
	ANALOG:
		0,1,2,3,4,5
 ------------------------------------------*/

int pin_num;
void setup()
{
  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
}

void loop()
{
  pin_num = 0;
  while(pin_num < 6){
	if(analogRead(pin_num) > 700){
	  digitalWrite(pin_num,HIGH);
	}
	pin_num++;
  }
}
