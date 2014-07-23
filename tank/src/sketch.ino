/*
   Arduinoで戦車を動かすためのプログラム
author:4869 */

#include<Servo.h>

//定数宣言
#define MAX 250
#define NOM 100

//上の回線部分
const int Turn_A = 2;
const int Turn_B = 3;

//右モーター
const int Right_A = 4;
const int Right_B = 5;
const int Right_PWM = 6; //速度調整用のアナログピン

//左モーター
const int Left_PWM = 11;
const int Left_A = 12;
const int Left_B = 13;

int r,l;
//砲台の上下
Servo myservo;

//シリアル通信で使う文字の宣言
char ch = 'R';

//設定について記述
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
//砲台右回転
void Turn_Right(void){
  digitalWrite(Turn_A,HIGH);
  digitalWrite(Turn_B,LOW);
}

//砲台左回転
void Turn_Left(void){
  digitalWrite(Turn_A,LOW);
  digitalWrite(Turn_B,HIGH);
}

//砲台回転ストップ
void Turn_Stop(void){
  digitalWrite(Turn_A,LOW);
  digitalWrite(Turn_B,LOW);
}

//右側モーターに関する関数
//右のモーターを前に回転させる
void Right_go(void){
  digitalWrite(Right_A,HIGH);
  digitalWrite(Right_B,LOW);
  analogWrite(Right_PWM,MAX); 
}  

//右のモーターを後ろに回転させる
void Right_back(void){
  digitalWrite(Right_A,LOW);
  digitalWrite(Right_B,HIGH);
  analogWrite(Right_PWM,MAX);
}

//右のモーターを止める
void Right_stop(void){ 
  digitalWrite(Right_A,LOW);
  digitalWrite(Right_B,LOW);
}

//左側のモーターに関する関数
//左のモーターを前に回転させる
void Left_go(void){
  digitalWrite(Left_A,HIGH);
  digitalWrite(Left_B,LOW);
  analogWrite(Left_PWM,MAX);
}

//左のモーターを後ろに回転させる
void Left_back(void){
  digitalWrite(Left_A,LOW);
  digitalWrite(Left_B,HIGH);
  analogWrite(Left_PWM,MAX);
}

//左のモーターを止める
void Left_stop(void){
  digitalWrite(Left_A,LOW);
  digitalWrite(Left_B,LOW);
}

//砲台の上下に関する関数



void loop(){
  while(Serial.available()){
	ch = Serial.read();
	switch(ch){
	  //Car Right Moter
	  case 'R':{
				 do {

				 }while(ch != '-'); 
				 break;
			   }  
			   //Car Left Moter
	  case 'L':{ 
				 do{
				 }while(ch != '-');
				 break;
			   } 
			   //Car battery's servo moter
	  case 'H':{ 
				 do{
				 }while(ch != '-');
				 break;
			   }
			   //B1:Battery right moter B2:Battery left Moter B3:Firing
	  case 'B':{
				 ch = Serial.read();
				 if(ch == "1"){
				   Turn_Right();
				   r = 1;
				 }else{
				   r = 0;
				 }
				 ch = Serial.read();
				 if(ch == "1"){
				   Turn_Lefti();
				   l = 1;
				 }else{
				   l = 0;
				 }
				 if(r == 0 && l == 0){
				   Turn_Stop();
				 }
				 ch = Serial.read();
				 if(ch == "1"){

				 }
				 break;
			   }
	}
  }
}
