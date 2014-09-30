
void setup()
{
  pinMode(13,INPUT);
  Serial.begin(9600);
}

void loop()
{
  if(digitalRead(13) == LOW){
	Serial.println("OK");
  }
}
