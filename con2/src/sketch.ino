int i;
void setup()
{
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
}

void loop()
{
  i=0;
  while(i < 7){
	if(analogRead(i) > 700){
	  digitalWrite(i,HIGH);
	}
	i++;
  }
}
