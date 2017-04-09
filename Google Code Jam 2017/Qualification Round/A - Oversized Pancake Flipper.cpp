#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
const int N = 1005;

char s[N];
int S, k, res;

void init(){
	int T;
	scanf("%d",&T);
	for(int t=1; t<=T; t++){
		list <int> ls;
		scanf("%s%d",s,&k);
		S = strlen(s);
		bool impossible = false;
		res = 0;
		for(int i = 0; i < S; i++){
			while(!ls.empty() and ls.front() < i){
				ls.pop_front();
			}
			if(((s[i] == '-') + (int)ls.size()) % 2 == 0) continue;
			res++;
			ls.push_back(i + k - 1);
		}
		if(ls.empty() or ls.back() < S) printf("Case #%d: %d\n",t,res);
		else printf("Case #%d: IMPOSSIBLE\n",t);
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