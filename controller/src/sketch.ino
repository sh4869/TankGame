/*
---デジタルピン---
2:砲台右 Bt1 Btc1
5:砲台左 Bt2 Btc2
7:発射 Bt3 Btc3

---アナログ---
1:右モーターに関するコントローラー
2:左モーターに関するコントローラー
3:砲台上下のサーボに関するコントローラー

*/
//ボタンのピン番号
const int Bt1 = 2;
const int Bt2 = 5;
const int Bt3 = 7;

//アナログのピン番号
const int RAn = 1;
const int LAn = 2;
const int HAn = 3;

//送信毎のインターバル(ミリ秒)
#define interval (10)

//出力
#define debug false

#define BaudRate (115200)


void setup()
{
  pinMode(Bt1, INPUT);
  pinMode(Bt2, INPUT);
  pinMode(Bt3, INPUT);
  Serial.begin(BaudRate);
}

//1になっているビット数を数える
inline unsigned char bitCount(unsigned char bits){
  unsigned char res = 0;
  for (unsigned char i = 0; i < 8; i++)
  {
    if ((bits >> i) & 1)
    {
      res++;
    }
  }
  return res;
}


/*
0: 0--- ---+  (------ = 右モータ　　 = 6Bit = 64)(+ = パリティ = 1の数 & 1)
1: 0--- ---+  (------ = 左モータ　　 = 6Bit = 64)(+ = パリティ = 1の数 & 1)
2: 0--- ---+  (------ = サーボモータ = 6Bit = 64)(+ = パリティ = 1の数 & 1)
3: 1*** ---+  (*** 1,2,3バイト目のパリティ)(--- 砲台右、砲台左、発射)
*/

unsigned char buff;
unsigned char parity;
void loop()
{
  //1Byte目
  //1023 >> 4 = 63
  buff = (analogRead(RAn) >> 4) << 1;
  buff |= (bitCount(buff) & 1);
  parity = (buff & 1) << 6;
#if debug
  Serial.print("\nB1 = ");
  for (int i = 7; i > 0; i--)
  {
    if (1 & (buff >> i))break;
    else Serial.write('0');
  }
  Serial.print(buff, BIN);
#else
  Serial.write(buff);
#endif // debug

#if interval
  delay(interval);
#endif


  //2Byte目
  //1023 >> 4 = 63
  buff = (analogRead(LAn) >> 4) << 1;
  buff |= (bitCount(buff) & 1);
  parity |= (buff & 1) << 5;
#if debug
  Serial.print(" , B2 = ");
  for (int i = 7; i > 0; i--)
  {
    if (1 & (buff >> i))break;
    else Serial.write('0');
  }
  Serial.print(buff, BIN);
#else
  Serial.write(buff);
#endif // debug

#if interval
  delay(interval);
#endif

  //3Byte目
  //1023 >> 4 = 63
  buff = (analogRead(HAn) >> 4) << 1;
  buff |= (bitCount(buff) & 1);
  parity |= (buff & 1) << 4;
#if debug
  Serial.print(" , B3 = ");
  for (int i = 7; i > 0; i--)
  {
    if (1 & (buff >> i))break;
    else Serial.write('0');
  }
  Serial.print(buff, BIN);
#else
  Serial.write(buff);
#endif // debug
#if interval
  delay(interval);
#endif

  //4Byte目
  buff = 0x80 | (digitalRead(Bt1) << 3) | (digitalRead(Bt2) << 2) | (digitalRead(Bt3) << 1) | parity;
  buff |= (bitCount(buff) & 1);
#if debug
  Serial.print(" , B4 = ");
  for (int i = 7; i > 0; i--)
  {
    if (1 & (buff >> i))break;
    else Serial.write('0');
  }
  Serial.print(buff, BIN);
#else
  Serial.write(buff);
#endif // debug

}

