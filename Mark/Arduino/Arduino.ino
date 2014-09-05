void setup(){
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  Serial.begin(9600);
}

void loop(){
  if(digitalRead(2) == 1){
	Serial.println("1");
  }
  if(digitalRead(3) == 1){
	Serial.println("2");
  }
  if(digitalRead(4) == 1){
	Serial.println("3");
  }
  if(digitalRead(5) == 1){
	Serial.println("4");
  }
  if(digitalRead(6) == 1){
	Serial.println("5");
  }
  if(digitalRead(7) == 1){
	Serial.println("6");
  }
  if(digitalRead(8) == 1){
	Serial.println("7");
  }
  if(digitalRead(9) == 1){
	Serial.println("8");
  }
  if(digitalRead(10) == 1){
	Serial.println("9");
  }
}
