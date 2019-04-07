#include <stdio.h>
#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;
const int N = 1050;

int n, b, f, ans[N], k;
char req[10][N], res[10][N];

void solve(int row, int left, int right, int resLeft, int resRight, int cnt) {
	if (left > right) return;
	if (cnt == (right - left + 1)) {
		for(int i = left; i <= right; i++){
			ans[k++] = i;
		}
		return;
	}
	if (row == f) return;
	int leftZero = 0;
	for(int i = resLeft; i <= resRight; i++){
		if (res[row][i] == '0') leftZero++;
	}
	int mid = (left + right) / 2;
	int countLeft = mid - left + 1 - leftZero;
	int countRight = cnt - countLeft;
	solve(row + 1, left, mid, resLeft, resLeft + leftZero - 1, countLeft);
	solve(row + 1, mid + 1, right, resLeft + leftZero, resRight, countRight);
}

void generateRequest(int row, int left, int right){
	if (left > right) return;
	if (row == f) return;
	int mid = (left + right) / 2;
	for(int i = left; i <= mid; i++){
		req[row][i] = '0';
	}
	for(int i = mid + 1; i <= right; i++){
		req[row][i] = '1';
	}
	generateRequest(row + 1, left, mid);
	generateRequest(row + 1, mid + 1, right);
}

void init(){
	int T, verdict;
	scanf("%d",&T);
	for(int t=1; t<=T; t++){
		scanf("%d%d%d",&n,&b,&f);
		generateRequest(0, 0, n - 1);
		for(int i = 0; i < f; i++){
			req[i][n] = 0;
			printf("%s\n", req[i]);
			fflush(stdout);
			scanf("%s",res[i]);
		}
		k = 0;
		solve(0, 0, n - 1, 0, n - b - 1, b);
		for(int i = 0; i < b - 1; i++){
			printf("%d ", ans[i]);
		}
		printf("%d\n", ans[b - 1]);
		fflush(stdout);
		scanf("%d",&verdict);
		if (verdict == -1) {
			exit(0);
		}
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
