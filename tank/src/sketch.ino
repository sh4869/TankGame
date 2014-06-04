/* Arduinoで戦車を動かすためのプログラム
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


/*メイン関数
  (実際行う処理を書く関数。この関数はループするので終わることはない)*/

void loop(){
  //シリアルを受信している間
  while(Serial.available()){
	//シリアルの文字列をchに代入する
	ch = Serial.read();
	//chの文字によって処理を変える
	switch(ch){
	  case 's':{ //送られてきた文字がsの場合
				 //左右のモーターをどちらもストップさせる→止める
				 Right_stop();
				 Left_stop();
				 break; //これがないとそのまま下の処理に行ってしまう
			   }  
	  case 'g':{ //gの場合
				 //左右のモーターをどちらも進める→前に進める
				 Right_go();
				 Left_go();
				 break;
			   } 
	  case 'b':{ //bの場合
				 //左右どちらのモーターも後ろに進める→バックさせる
				 Right_back();
				 Left_back();
				 break;
			   }
	  case 'r':{
				 Turn_Right();
				 break;
			   }
	  case 'l':{
				 Turn_Left();
				 break;
			   }
	  case 'n':{
				 Turn_Stop();
				 break;
			   }
	}  
  }
}
