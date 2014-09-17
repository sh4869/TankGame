#ifndef TOKUTEN_H
#define TOKUTEN_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int keta(int num){
  int keta=0;
  while(1){
	if(num==0) break;
	num=num/10;
	keta++;
  }
  return keta;
}

int jou(int num){
  int k=1,i;
  for(i=0;i<num;i++){
	k=k*10;
  }
  return k;
}

int kaijou(int kai){
  int k;
  if(kai==0){
	k=1;
  }else{
	k = kaijou(kai-1)*kai;
  }
  return k;
}

int SixRandPos(int nyu){
  using namespace std;
  int num = 6;
  int tensu[num+1],amari[num + 1], wari[num+1];
  int i,j,l,n,s,result=0;

  amari[0]=nyu;

  for(i=0;i<num;i++){
	tensu[i]=1;
  }

  for(i=0;i<num-1;i++){
	j=0;n=0;
	wari[i] = amari[i] / kaijou(num-i-1);

	while(j<num){
	  for(s=0;s<i;s++){
		for(l=0;l<i;l++){
		  if(tensu[l]==tensu[i]) tensu[i]++;
		}
	  }
	  if(n<wari[i]) tensu[i]++;
	  n++;
	  j++;
	}
	amari[i+1] = amari[i] % kaijou(num-i-1);
  }

  int las=1;
  for(i=0;i<num-1;i++){
	for(j=0;j<num-1;j++){
	  if(las==tensu[j]) las++;
	}
  }
  tensu[num-1] = las;

  for(i=0;i<num;i++)  result+=tensu[i]*jou(num-1-i);

  return result;
}

#endif

