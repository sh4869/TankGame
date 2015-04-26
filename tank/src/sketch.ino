/*--------------------------------------
Description:
	Arduino Tank Program 
Arduino Board:
	all
Use Pin:
	OUTPUT:
		1~15
	INPUT:
		0	
  -------------------------------------*/

#include <Servo.h>

#define MAX 250
#define NOM 50

#define BaudRate (115200)

#define debug false

//発射状況
bool launchMode = false;

bool launchButtonReleased = true;
//発射開始時刻
unsigned long launchStart = 0;
//発射完了時刻
unsigned long launchEnd = 0;
//一時保存用
unsigned long launchTempTime;


//発射開始～発射終了までの時間
const unsigned long start2endT = 1000000ul;
//発射終了～次の発射までの時間
const unsigned long end2startT = 2000000ul;
//LEDオンの幅
const unsigned long ledOnT = 12;
//LEDオフの幅
const unsigned long ledOffT = 12;
//LEDのオンオフにかかる時間の合計
const unsigned long ledSumT = ledOnT + ledOffT;




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

//10 左モータ制御
const int Left_B = 12;
//11(PWM) : 左モーター
const int Left_PWM = 11;
//12 左モータ制御
const int Left_A = 13;

//14(アナログ0番)
const int launch_LED = 14;
const int launch_LED2 = 15;

//https://bitbucket.org/sh4869/micomtanks

//init

Servo myservo;

void setup()
{

	pinMode(0, INPUT);
	pinMode(1, OUTPUT);
	pinMode(2, OUTPUT);
	//	delay(1000);
	pinMode(3, OUTPUT);
	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);
	pinMode(8, OUTPUT);
	//pinMode(9, OUTPUT);
	//pinMode(10, OUTPUT);
	pinMode(11, OUTPUT);
	pinMode(12, OUTPUT);
	pinMode(13, OUTPUT);

	pinMode(launch_LED, OUTPUT);
	pinMode(launch_LED2, OUTPUT);

	Serial.begin(BaudRate);
	myservo.attach(Up_Down);

	//while (true)
	//{
	//	RightMotor(63);
	//	delay(1000);
	//	RightMotor(32);
	//	delay(1000);
	//	RightMotor(0);
	//	delay(1000);
	//	RightMotor(32);
	//	delay(1000);
	//	LeftMotor(63);
	//	delay(1000);
	//	LeftMotor(32);
	//	delay(1000);
	//	LeftMotor(0);
	//	delay(1000);
	//	LeftMotor(32);
	//	delay(1000);
	//}
	//Serial.print("Start\r\n");
	//while (true)
	//{
	//	myservo.write(180);
	//	delay(1000);
	//	myservo.write(0);
	//	delay(1000);
	//}
#if 0
	while (true)
	{
		digitalWrite(launch_LED, HIGH);
		delayMicroseconds(13);
		digitalWrite(launch_LED, LOW);
		delayMicroseconds(13);
	}
#endif
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
#if 0
void launch(bool mode){
	if (mode)
	{
		if (launchMode)
		{
			//発射中(長押し)
			//開始からの時間で判定
			launchEnd = micros();
			launchTempTime = launchEnd - launchStart;
			if (start2endT > launchTempTime)
			{
				//現在OnにするかOffにするか判定(launchTempTime=開始してからの時間)
				if ((launchTempTime % ledSumT) <= ledOnT)
				{
					digitalWrite(launch_LED, HIGH);
					//digitalWrite(launch_LED2, LOW);
				}
				else{
					digitalWrite(launch_LED, LOW);
					//digitalWrite(launch_LED2, HIGH);
				}
				launchButtonReleased = false;
			}
			else
			{
				//停止
				digitalWrite(launch_LED, LOW);
				//digitalWrite(launch_LED2, HIGH);
				digitalWrite(launch_LED2, LOW);
				launchMode = false;
				launchButtonReleased = false;
			}
		}
		else
		{
			//発射終了後長押しもしくは開始
			//ボタンをオフにしないと次を打てない
			if (launchButtonReleased)
			{
				//発射開始
				//終了からの時間経過で判定
				launchStart = micros();
				launchTempTime = launchStart - launchEnd;
				if (end2startT < launchTempTime)
				{
					digitalWrite(launch_LED, HIGH);
					digitalWrite(launch_LED2, HIGH);
					//digitalWrite(launch_LED2, LOW);
					launchMode = true;
				}
				launchButtonReleased = false;
			}
		}
	}
	else
	{
		launchButtonReleased = true;
		if (launchMode)
		{
			//離していても時間が経ってないなら判定を行う
			//開始からの時間で判定
			launchEnd = micros();
			launchTempTime = launchEnd - launchStart;
			if (start2endT > launchTempTime)
			{
				//現在OnにするかOffにするか判定(launchTempTime=開始してからの時間)
				if ((launchTempTime % ledSumT) <= ledOnT)
				{
					digitalWrite(launch_LED, HIGH);
					//digitalWrite(launch_LED2, LOW);
				}
				else{
					digitalWrite(launch_LED, LOW);
					//digitalWrite(launch_LED2, HIGH);
				}
			}
			else
			{
				//停止
				digitalWrite(launch_LED, LOW);
				digitalWrite(launch_LED2, LOW);
				//digitalWrite(launch_LED2, HIGH);
				launchMode = false;
			}
		}
	}
}
#else
void launch(bool mode){
	if (mode)
	{
		//終了からの時間経過で判定
		launchStart = micros();
		launchTempTime = launchStart - launchEnd;
		if (end2startT < launchTempTime)
		{
			launchEnd = launchStart + start2endT;
			digitalWrite(launch_LED2, HIGH);
			LeftMotor(32);
			RightMotor(32);
			Turn_Stop();
			launchEnd = micros();
			launchTempTime = launchEnd - launchStart;
			while (start2endT > launchTempTime)
			{
				delayMicroseconds(ledOffT);
				digitalWrite(launch_LED, HIGH);
				delayMicroseconds(ledOnT);
				digitalWrite(launch_LED, LOW);
				launchEnd = micros();
				launchTempTime = launchEnd - launchStart;
			}
			digitalWrite(launch_LED2, LOW);
			Serial.flush();
		}
	}

}
#endif

//サーボモーター(0～63を+0～180へ)
void ServoMotor(unsigned char val){
	Serial.write('A' + (val >> 2));
	myservo.write(((int) val));
}

//右モーター(0～63を+-0～255へ)
void RightMotor(unsigned char val){
	if ((val == 32) || (val == 31))
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
		analogWrite(Right_PWM, (-(val - 31)) << 3);
	}
}
//左モーター(0～63を+-0～255へ)
void LeftMotor(unsigned char val){
	if ((val == 32) || (val == 31))
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
		analogWrite(Left_PWM, (-(val - 31)) << 3);
	}
}

inline int elect(char x){
	return x - '0';
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
		for (int i = 7; i > 0; i--)
		{
			if (1 & (buff >> i))break;
#if debug
			else Serial.write('0');
#endif
		}
#if debug
		Serial.print((int) buff, BIN);
		Serial.print('-');
#endif
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
			dirty = true;
#if debug
			Serial.print('_');
#endif
		}
		else{
#if debug
			Serial.print('!');
#endif
		}

		//最終ビット
		if (buff & 0x80)
		{
			//正常な値かのチェック
			if ((!dirty) && (byteNo == 4) && ((buff & 0x70) == parity))
			{
				//正常
#if debug
				Serial.print("R=");
				Serial.print((int) Rmotor);
				Serial.print(" L=");
				Serial.print((int) Lmotor);
				Serial.print(" D=");
				Serial.print(((int) servoVal) * 180 / 64);

				Serial.print("         \r");
#endif
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
				launch(0x02 & buff);
			}
#if debug
			if (dirty)
			{
				//digitalWrite(13, HIGH);
				Serial.print('f');
			}
			else{
				//digitalWrite(13, LOW);
				Serial.print('t');
			}
#endif
			parity = 0;
			byteNo = 0;
			dirty = false;
		}else{
			if (!dirty)
			{
				switch (byteNo)
				{
				case 1:
					Rmotor = (0x7E & buff) >> 1;
#if debug
					Serial.print('1');
#endif
					parity = (buff & 0x01) << 6;
					break;
				case 2:
					Lmotor = (0x7E & buff) >> 1;
#if debug
					Serial.print('2');
#endif
					parity |= (buff & 0x01) << 5;
					break;
				case 3:
					servoVal = (0x7E & buff) >> 1;
#if debug
					Serial.print('3');
#endif
					parity |= (buff & 0x01) << 4;
					break;
				default:
					dirty = true;
#if debug
					Serial.print('e');
#endif
					break;
				}
			}
		}
	}
	else
	{
	}

}

