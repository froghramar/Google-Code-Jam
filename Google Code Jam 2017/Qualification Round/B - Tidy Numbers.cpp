#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
const int N = 20;

char s[N];
int l, L;

void mini(int x){
	while(x and s[x] == '0'){
		s[x] = '9';
		x--;
	}
	s[x]--;
}

void maxi(int x){
	while(x <= L){
		s[x] = '9';
		x++;
	}
}

void init(){
	int T;
	scanf("%d",&T);
	for(int t=1; t<=T; t++){
		scanf("%s",s + 1);
		l = L = strlen(s + 1);
		while(l){
			if(s[l] < s[l - 1]){
				mini(l - 1);
				maxi(l);
			}
			l--;
		}
		printf("Case #%d: %s\n",t,s + 1 + (s[1] == '0'));
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