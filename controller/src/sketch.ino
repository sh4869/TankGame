/* 戦車 コントローラー
   ---デジタルピン---
2:砲台右 Bt1 Btc1
5:砲台左 Bt2 Btc2
7:発射   Bt3 Btc3
---アナログ---


---メモ---
 */

//ボタンのピン番号
#define Bt1 2
#define Bt2 5
#define Bt3 7

//アナログのピン番号
#define RAn 1 
#define LAn 2
#define HAn 3

//Button 1:砲台右 2:砲台左 3:発射
int bt1 = 1,bt2 = 1,bt3 = 1;
String Btc1 = "";
String Btc2 = "";
String Btc3 = "";

//可変抵抗 R:右モーター L:左モーター H:砲台上下
int Ra = 0,La = 0,Ha = 0;
String rach = "";
String lach = "";
String hach = "";


void setup()
{
  pinMode(Bt1, INPUT);
  pinMode(Bt2, INPUT);
  pinMode(Bt3, INPUT);
  Serial.begin(9600);
}

void loop()
{
  if(Ra != analogRead(RAn)){
	Ra = analogRead(RAn);
	rach = String(Ra,DEC);
  }else{
	rach = "x";
  }

  if(La != analogRead(LAn)){
	La = analogRead(LAn);
	lach = String(La,DEC);
  }else{
	lach = "x";
  }

  if(Ha != analogRead(HAn)){
	Ha = analogRead(HAn);
	hach = String(Ha,DEC);
  }else{
	hach = "x";
  }

  bt1 = digitalRead(Bt1);
  if(bt1 == 0){
	Btc1 = "0";
  }else if(bt1 == 1){
	Btc1 = "1";
  }

  bt2 = digitalRead(Bt2);
  if(bt2 == 0){
	Btc2 = "0";
  }else if(bt2 == 1){
	Btc2 = "1";
  }

  bt3 = digitalRead(Bt3);
  if(bt3 == 0){
	Btc3 = "0";
  }else if(bt3 == 1){
	Btc3 = "1";
  }

  Serial.print("R:");
  Serial.print(rach);
  Serial.print(" L:");
  Serial.print(lach);
  Serial.print(" H:");
  Serial.print(hach);
  Serial.print(" B1:");
  Serial.print(Btc1);
  Serial.print(" B2:");
  Serial.print(Btc2);
  Serial.print(" B3:");
  Serial.println(Btc3);
  delay(1000);
}
