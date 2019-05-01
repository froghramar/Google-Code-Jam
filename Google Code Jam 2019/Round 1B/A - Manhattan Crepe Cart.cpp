#include <stdio.h>
#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;
const int N = 1e5 + 5;

struct T {
	int pos;
	char mark;
};

bool cmp(T p, T q){
	if (p.pos != q.pos) return p.pos < q.pos;
	else return p.mark > q.mark;
}

int P, Q;

int calc(vector <T> v) {
	sort(v.begin(), v.end(), cmp);
	stack<int> ids;
	int resId = 0, resCount = 0, curCount = 0;
	for(T t: v) {
		if (t.mark == 'S') {
			curCount++;
			ids.push(t.pos);
		} else {
			curCount--;
			ids.pop();
		}
		if (curCount > resCount) {
			resId = ids.top();
			resCount = curCount;
		}
	}
	return resId;
}

vector <T> v1, v2;

void init(){
	int T;
	scanf("%d",&T);
	for(int t=1; t<=T; t++){
		v1.clear();
		v2.clear();
		scanf("%d%d",&P,&Q);
		while(P--){
			int x, y;
			char ch;
			scanf("%d %d %c\n",&x,&y,&ch);
			switch(ch) {
				case 'N':
					if (y < Q) {
						v1.push_back({y + 1, 'S'});
						v1.push_back({Q, 'E'});
					}
					v2.push_back({0, 'S'});
					v2.push_back({Q, 'E'});
					break;
				case 'S':
					if (y > 0) {
						v1.push_back({y - 1, 'E'});
						v1.push_back({0, 'S'});
					}
					v2.push_back({0, 'S'});
					v2.push_back({Q, 'E'});
					break;
				case 'E':
					if (x < Q) {
						v2.push_back({x + 1, 'S'});
						v2.push_back({Q, 'E'});
					}
					v1.push_back({0, 'S'});
					v1.push_back({Q, 'E'});
					break;
				case 'W':
					if (x > 0) {
						v2.push_back({x - 1, 'E'});
						v2.push_back({0, 'S'});
					}
					v1.push_back({0, 'S'});
					v1.push_back({Q, 'E'});
					break;
			}
		}
		int x = calc(v2), y = calc(v1);
		printf("Case #%d: %d %d\n", t, x, y);
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

