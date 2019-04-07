#include <stdio.h>
#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;
const int N = 105;

char s[N], sA[N], sB[N];

void solve(int t){
	int l = strlen(s);
	int A = 0, B = 0;
	for(int i = 0; i < l; i++) {
		switch(s[i]) {
			case '4':
				sA[A++] = '3';
				sB[B++] = '1';
				break;
			default:
				sA[A++] = s[i];
				if (B) {
					sB[B++] = '0';
				}
				break;
		}
	}
	if (!B) {
		sB[B++] = '0';
	}
	sA[A] = 0;
	sB[B] = 0;
	printf("Case #%d: %s %s\n", t, sA, sB);
}

void init(){
	int T, n;
	scanf("%d",&T);
	for(int t=1; t<=T; t++){
		scanf("%s",s);
		solve(t);
	}
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
		#ifdef __linux__
			signal(SIGALRM, [](int signum){
				fprintf(stderr, "[Force exit......]\n");
				exit(0);
			});
			alarm(5);
		#endif
	#endif
	init();
	return 0;
}
