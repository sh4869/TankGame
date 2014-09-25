int i = 0;

void setup()
{
  Keyboard.begin();
}

void loop()
{
  while(i < 7){
	i++;
	Keyboard.press(i + '0');
	delay(50);
	Keyboard.releaseAll();
	delay(1000);
  }
  i = 0;
}
