#include <stdio.h>
#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;
const int N = 1e5 + 5;

char s[N];

void init(){
	int T, n;
	scanf("%d",&T);
	for(int t=1; t<=T; t++){
		scanf("%d%s",&n,s);
		int l = 2 * n - 2;
		for(int i = 0; i < l; i++){
			switch (s[i]) {
				case 'S':
				s[i] = 'E';
				break;
				default:
				s[i] = 'S';
				break;
			}
		}
		printf("Case #%d: %s\n", t, s);
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
