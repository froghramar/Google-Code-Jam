#include <stdio.h>
#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;
const int N = 260;
const int L = 505;

char s[N][L], res[L], seq[] = {'R', 'P', 'S'};
int n, len[N];
bool alive[N];

void init(){
	int T;
	scanf("%d",&T);
	for(int t=1; t<=T; t++){
		bool hasRes = false;
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			scanf("%s", s[i]);
			len[i] = strlen(s[i]);
			alive[i] = true;
		}
		for(int j = 0; j < 500; j++) {
			set <char> st;
			for(int i = 0; i < n; i++) {
				if (alive[i]) {
					st.insert(s[i][j % len[i]]);
				}
			}
			if (st.size() == 1) {
				for(int i = 0; i < 3; i++) {
					if (seq[i] == *st.begin()) {
						res[j] = seq[(i + 1) % 3];
					}
				}
				res[j + 1] = 0;
				hasRes = true;
				break;
			} else if (st.size() == 3) {
				break;
			} else {
				char charToEliminate;
				for(int i = 0; i < 3; i++) {
					if ((seq[i] == *st.begin()) && (seq[(i + 1) % 3]) == *st.rbegin()) {
						res[j] = *st.rbegin();
						charToEliminate = *st.begin();
					} else if ((seq[i] == *st.rbegin()) && (seq[(i + 1) % 3]) == *st.begin()) {
						res[j] = *st.begin();
						charToEliminate = *st.rbegin();
					}
				}
				for(int i = 0; i < n; i++) {
					if (alive[i] && (s[i][j % len[i]] == charToEliminate)) {
						alive[i] = false;
					}
				}
			}
		}
		printf("Case #%d: %s\n", t, hasRes ? res : "IMPOSSIBLE");
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

