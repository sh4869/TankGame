#MicomTankS
---------

##What is it?

2014 TEIENSAI Micom club Tank game project

##What include

* controller
* tank

---------

##戦車概要

###戦車本体 

Arduino 
PINの説明

* 2,3           :砲台の左右回転
* 4,5,6(PWM)    :右モーター
* 7,8           :発射のモーター
* 9,10          :サーボモーター
* 11(PWM),12,13 :左モーター

###コントローラ

Arduino
PINの説明

---デジタルピン---

* 2:砲台右 Bt1 Btc1
* 5:砲台左 Bt2 Btc2
* 7:発射   Bt3 Btc3

---アナログ---
   
* 1:右モーターに関するコントローラー
* 2:左モーターに関するコントローラー
* 3:砲台上下のサーボに関するコントローラー

送信する文字列の形

R(rm)-L(lm)-H(hm)-B(b1)(b2)(b3)
