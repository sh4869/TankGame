/*
   Arduinoで戦車を動かすためのプログラム
author:4869 */

#include<Servo.h>
#include<stdlib.h>
//定数宣言
#define MAX 250
#define NOM 50

//発射
const int Push_A = 7;
const int Push_B = 8;

//上の回線部分
const int Turn_A = 2;
const int Turn_B = 3;

//右モーター
const int Right_A = 4;
const int Right_B = 5;
const int Right_PWM = 6; 

//左モーター
const int Left_PWM = 11;
const int Left_A = 12;
const int Left_B = 13;

int r,l;

//砲台の上下
Servo myservo;

//シリアル通信で使う文字の宣言
char ch = 'R';

void setup(){
  //シリアルポートの設定
  Serial.begin(9600);
  //デジタルピンの設定
  pinMode(Turn_A,OUTPUT);
  pinMode(Turn_B,OUTPUT);
  pinMode(Right_A,OUTPUT); 
  pinMode(Right_B,OUTPUT);
  pinMode(Left_A,OUTPUT); 
  pinMode(Left_B,OUTPUT);
  myservo.attach(9);
}

/*   独自関数を記述します  */

//砲台の回転に関する関数
void Turn_Right(void){
  digitalWrite(Turn_A,HIGH);
  digitalWrite(Turn_B,LOW);
}
void Turn_Left(void){
  digitalWrite(Turn_A,LOW);
  digitalWrite(Turn_B,HIGH);
}
void Turn_Stop(){
  digitalWrite(Turn_A,LOW);
  digitalWrite(Turn_B,LOW);
}

//砲台の上下
void battery(char val){
  if(val != 'x'){
	int vali = elect(val);
	vali = vali * 10;
	myservo.write(vali);
  }
}

//発射
void Push(void){
  digitalWrite(Push_A,LOW);
  digitalWrite(Push_B,HIGH);
}

//右側モーターに関する関数
void Right_go(char val){
  int vali = elect(val);
  Serial.println(vali);
  if(vali == 5){
	digitalWrite(Right_A,LOW);
	digitalWrite(Right_B,LOW);
  }else if(vali > 5){
	digitalWrite(Right_A,HIGH);
	digitalWrite(Right_B,LOW);
	analogWrite(Right_PWM,NOM + ((vali - 5) * 20)); 
  }else{  
	digitalWrite(Right_A,LOW);
	digitalWrite(Right_B,HIGH);
	vali = vali - 6;
	analogWrite(Right_PWM,NOM+ (-vali * 20));
  }
}
//左側のモーターに関する関数
void Left_go(char val){
  int vali = elect(val);
  Serial.println(vali);
  if(vali == 5){
	digitalWrite(Left_A,LOW);
	digitalWrite(Left_B,LOW);
  }else if(vali > 5){
	digitalWrite(Left_A,HIGH);
	digitalWrite(Left_B,LOW);
	analogWrite(Left_PWM,NOM + ((vali - 5) * 20));
  }else{
	digitalWrite(Left_A,LOW);
	digitalWrite(Left_B,HIGH);
	vali = vali - 6;
	analogWrite(Left_PWM,NOM + (-vali  * 10));
  }
}

int elect(char x){
  switch(x){
	case '1':return 1;break;
	case '2':return 2;break;
	case '3':return 3;break;
	case '4':return 4;break;
	case '5':return 5;break;
	case '6':return 6;break;
	case '7':return 7;break;
	case '8':return 8;break;
	case '9':return 9;break;
  }
}

void loop(){
  while(Serial.available()){
	ch = Serial.read();
	switch(ch){
	  //Car Right Moter
	  case 'R':{
				 delay(10);
				 ch = Serial.read();
				 Serial.println(ch);
				 Right_go(ch);
				 break;
			   }  
			   //Car Left Moter
	  case 'L':{ 
				 delay(10);
				 ch = Serial.read();
				 Left_go(ch);
				 break;
			   } 
			   //Car battery's servo moter

	  case 'H':{ 
				 ch = Serial.read();
				 battery(ch);
				 break;
			   }

			   //B1:Battery right moter B2:Battery left Moter B3:Firing
	  case 'B':{
				 ch = Serial.read();
				 if(ch == '1'){
				   Turn_Right();
				   r = 1;
				 }else{
				   r = 0;
				 }
				 ch = Serial.read();
				 if(ch == '1'){
				   Turn_Left();
				   l = 1;
				 }else{
				   l = 0;
				 }
				 if(r == 0 && l == 0){
				   Turn_Stop();
				 }
				 ch = Serial.read();
				 if(ch == '1'){
				   Push(); 
				 }
				 break;
			   }
	}
  }
}
