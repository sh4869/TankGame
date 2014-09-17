#include <Servo.h>

#define MAX 250
#define NOM 50

#define BaudRate (115200)

//2砲台右回転
const int Turn_A = 2;
//3砲台左回転
const int Turn_B = 3;

//4,5右モータ制御
const int Right_A = 4;
//4,5右モータ制御
const int Right_B = 5;
//6右モータ(PWM)
const int Right_PWM = 6;


//7,8発射のモーター
const int Push_A = 7;
//7,8発射のモーター
const int Push_B = 8;

//9 サーボモータ(砲身上下)
const int Up_Down = 9;
//10 NC

//11(PWM) : 左モーター
const int Left_PWM = 11;
//12, 13 左モータ制御
const int Left_A = 12;
//12, 13 左モータ制御
const int Left_B = 10;


//https://bitbucket.org/sh4869/micomtanks

//init

Servo myservo;

void setup()
{

	pinMode(0, INPUT);
	pinMode(1, OUTPUT);
	pinMode(2, OUTPUT);
	pinMode(3, OUTPUT);
	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);
	pinMode(8, OUTPUT);
	//pinMode(9, OUTPUT);
	pinMode(10, OUTPUT);
	pinMode(11, OUTPUT);
	pinMode(12, OUTPUT);
	pinMode(13, OUTPUT);

	Serial.begin(BaudRate);
	myservo.attach(Up_Down);
}

//砲台の回転に関する関数
void Turn_Right(void){
	digitalWrite(Turn_A, HIGH);
	digitalWrite(Turn_B, LOW);
}
void Turn_Left(void){
	digitalWrite(Turn_A, LOW);
	digitalWrite(Turn_B, HIGH);
}
void Turn_Stop(void){
	digitalWrite(Turn_A, LOW);
	digitalWrite(Turn_B, LOW);
}

//発射(開始、停止)
void burn(bool mode){
	if (mode)
	{

	}
	else
	{

	}
}

////砲台の上下
//void battery(char val){
//	if (val != 'x'){
//		int vali = elect(val);
//		vali = vali * 10;
//		myservo.write(vali);
//	}
//}

//発射
void Push(void){
	digitalWrite(Push_A, LOW);
	digitalWrite(Push_B, HIGH);
}
//サーボモーター(0～63を+0～180へ)
void ServoMotor(unsigned char val){
	myservo.write(((int) val) * 180 / 32);
}

//右モーター(0～63を+-0～255へ)
void RightMotor(unsigned char val){
	if (val == 32)
	{
		digitalWrite(Right_A, LOW);
		digitalWrite(Right_B, LOW);
	}
	else if (val > 32)
	{
		digitalWrite(Right_A, HIGH);
		digitalWrite(Right_B, LOW);
		analogWrite(Right_PWM, (val - 32) << 3);
	}
	else
	{
		digitalWrite(Right_A, LOW);
		digitalWrite(Right_B, HIGH);
		analogWrite(Right_PWM, (-(val - 32)) << 3);
	}
}
//左モーター(0～63を+-0～255へ)
void LeftMotor(unsigned char val){
	if (val == 32)
	{
		digitalWrite(Left_A, LOW);
		digitalWrite(Left_B, LOW);
	}
	else if (val > 32)
	{
		digitalWrite(Left_A, HIGH);
		digitalWrite(Left_B, LOW);
		analogWrite(Left_PWM, (val - 32) << 3);
	}
	else
	{
		digitalWrite(Left_A, LOW);
		digitalWrite(Left_B, HIGH);
		analogWrite(Left_PWM, (-(val - 32)) << 3);
	}
}

////右側モーターに関する関数
//void Right_go(char val){
//	int vali = elect(val);
//	Serial.println(vali);
//	if (vali == 5){
//		digitalWrite(Right_A, LOW);
//		digitalWrite(Right_B, LOW);
//	}
//	else if (vali > 5){
//		digitalWrite(Right_A, HIGH);
//		digitalWrite(Right_B, LOW);
//		analogWrite(Right_PWM, NOM + ((vali - 5) * 20));
//	}
//	else{
//		digitalWrite(Right_A, LOW);
//		digitalWrite(Right_B, HIGH);
//		vali = vali - 6;
//		analogWrite(Right_PWM, NOM + (-vali * 20));
//	}
//}
////左側のモーターに関する関数
//void Left_go(char val){
//	int vali = elect(val);
//	Serial.println(vali);
//	if (vali == 5){
//		digitalWrite(Left_A, LOW);
//		digitalWrite(Left_B, LOW);
//	}
//	else if (vali > 5){
//		digitalWrite(Left_A, HIGH);
//		digitalWrite(Left_B, LOW);
//		analogWrite(Left_PWM, NOM + ((vali - 5) * 20));
//	}
//	else{
//		digitalWrite(Left_A, LOW);
//		digitalWrite(Left_B, HIGH);
//		vali = vali - 6;
//		analogWrite(Left_PWM, NOM + (-vali * 10));
//	}
//}

inline int elect(char x){
	return x - '0';
	//switch (x){
	//case '1':return 1; break;
	//case '2':return 2; break;
	//case '3':return 3; break;
	//case '4':return 4; break;
	//case '5':return 5; break;
	//case '6':return 6; break;
	//case '7':return 7; break;
	//case '8':return 8; break;
	//case '9':return 9; break;
	//}
}


/*
0: 0--- ---+  (------ = 右モータ　　 = 6Bit = 64)(+ = パリティ = 1の数 & 1)
1: 0--- ---+  (------ = 左モータ　　 = 6Bit = 64)(+ = パリティ = 1の数 & 1)
2: 0--- ---+  (------ = サーボモータ = 6Bit = 64)(+ = パリティ = 1の数 & 1)
3: 1*** ---+  (*** 1,2,3バイト目のパリティ)(--- 砲台右、砲台左、発射)
*/

unsigned char byteNo = 0;//何バイト目か
unsigned char buff;//受信バッファ
unsigned char parity = 0;//パリティビット
bool dirty = false;//エラーあり
unsigned char Rmotor;
unsigned char Lmotor;
unsigned char servoVal;

unsigned char temp1;
unsigned char temp2;

void loop()
{
	//シリアル通信データあり
	if (Serial.available())
	{
		byteNo++;
		buff = Serial.read();

		//パリティ
		temp2 = 0;
		for (temp1 = 1; temp1 < 8; temp1++)
		{
			if ((buff >> temp1) & 0x01)
			{
				temp2++;
			}
		}
		if ((temp2 & 0x01) != (buff & 0x01))
		{
			digitalWrite(13, HIGH);
			dirty = true;
		}
		else{
			digitalWrite(13, LOW);
		}

		//最終ビット
		if (buff & 0x80)
		{
			//正常な値かのチェック
			if ((!dirty) && (byteNo == 4) && ((buff & 0x70) == parity))
			{
				//正常
				RightMotor(Rmotor);
				LeftMotor(Lmotor);
				ServoMotor(servoVal);
				//switch ((buff & 0x0C) >> 2)
				//{
				//case 1:
				//	Turn_Right();
				//	break;
				//case 2:
				//	Turn_Left();
				//	break;
				//case 0:
				//case 3:
				//default:
				//	Turn_Stop();
				//	break;
				//}
				if (0x08 & buff){
					if (0x04 & buff){
						Turn_Stop();
					}
					else{
						Turn_Right();
					}
				}else{
					if (0x04 & buff){
						Turn_Left();
					}
					else{
						Turn_Stop();
					}
				}
				burn(0x02 & buff);
			}
			if (dirty)
			{
			}
			else{
			}
			parity = 0;
			byteNo = 0;
			dirty = false;
		}else{
			if (!dirty)
			{
				switch (byteNo)
				{
				case 1:
					Rmotor = 0x3E & (buff >> 1);
					break;
				case 2:
					Lmotor = 0x3E & (buff >> 1);
					break;
				case 3:
					servoVal = 0x3E & (buff >> 1);
					break;
				default:
					dirty = true;
					break;
				}
			}
		}
	}
	else
	{
	}
}

