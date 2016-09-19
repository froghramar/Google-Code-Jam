#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
const int N = 1000005;

int deci, base1, base2, p[150];
char num[35], alien1[100], alien2[100];

int alienToDecimal(){
	base1 = strlen(alien1);
	for(int i = 0; i < base1; i++){
		p[alien1[i]] = i;
	}
	int n = 0;
	for(int i = 0; num[i] ; i++){
		n = n * base1 + p[num[i]];
	}
	return n;
}

void decimalToAlien(){
	int k = 0;
	base2 = strlen(alien2);
	int val = deci;
	while(val){
		num[k++] = val % base2;
		val /= base2;
	}
	reverse(num,num+k);
	for(int i = 0; i < k; i++){
		num[i] = alien2[num[i]];
	}
	num[k] = 0;
}

void init(){
	int T;
	scanf("%d",&T);
	for(int t=1; t<=T; t++){
		scanf("%s%s%s",num,alien1,alien2);
		deci = alienToDecimal();
		decimalToAlien();
		printf("Case #%d: %s\n",t, num);
	}
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	init();
	return 0;
}