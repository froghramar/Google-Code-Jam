/******************************************************************************
*  ▄██████████▄  ▀█████████▄   ▀██████████▄    ▄████████████▄   ▄██████████▄  *
* ▀▀███    ███▀    ███    ███    ███     ▀██▄  ▀███▀    ▀███▀   █▀    ▄███▀   *
*   ███            ███           ███      ██    ███      ███         ▄███▀    *
*  ▄███▄▄▄██▀    ▄███▄▄▄██▀      ███      ██▀   ███      ███        ▄███▀     *
* ▀▀███▀▀▀██▄   ▀▀███▀▀▀██▄     ▄███▄▄▄▄▄██▀    ███      ███       ▄███▀      *
*   ███            ███         ▀▀███▀▀▀▀▀██▄    ███      ███      ▄███▀       *
*   ███            ███    ███    ███     ███   ▄███▄    ▄███▄    ▄███▀    ▄█  *
* ▄▄████▀        ▄█████████▀    ▄███     ███▄  ▀████████████▀   ▀██████████▀  *
*                                                                             *
*                        *Don't limit your challenges, challenge your limits. *
******************************************************************************/

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
const int N = 10005;

vector <pair<int, int> > pos;
vector <int> dir;
map<pair<int, int>, int> mp;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
char path1[N], path2[N];

void init(){
	int T;
	scanf("%d",&T);
	for(int t = 1; t <= T; ++t){
		printf("Case #%d:\n",t);
		scanf("%s%s",path1,path2);
		int len1 = strlen(path1), len2 = strlen(path2);
		int d = 0, px = 0, py = 0;
		pos.clear();
		dir.clear();
		for(int i = 0; i < len1; i++){
			if(path1[i] == 'W'){
				pos.push_back(make_pair(px, py));
				dir.push_back(d);
				px += dx[d], py += dy[d];
			}
			else if(path1[i] == 'L'){
				d = (d + 1) % 4;
			}
			else if(path1[i] == 'R'){
				d = (d + 3) % 4;
			}
		}
		int ex = px, ey = py;
		d = (d + 2) % 4;
		for(int i = 0; i < len2; i++){
			if(path2[i] == 'W'){
				pos.push_back(make_pair(px, py));
				dir.push_back(d);
				px += dx[d], py += dy[d];
			}
			else if(path2[i] == 'L'){
				d = (d + 1) % 4;
			}
			else if(path2[i] == 'R'){
				d = (d + 3) % 4;
			}
		}
		mp.clear();
		int ymax = INT_MIN, xmin = INT_MAX, xmax = INT_MIN;
		for(int i = 0; i < pos.size(); i++){
			if((pos[i].first != 0 || pos[i].second != 0) && (pos[i].first != ex || pos[i].second != ey)){
				if(!mp.count(pos[i])) mp[pos[i]] = 0;
				int xx = pos[i].first;
				int yy = pos[i].second;
				int dd = dir[i];
				int bit;
				if(dd == 0) bit = 1;
				if(dd == 1) bit = 3;
				if(dd == 2) bit = 0;
				if(dd == 3) bit = 2;
				mp[pos[i]] |= 1 << bit;
				if(xmin > xx) xmin = xx;
				if(xmax < xx) xmax = xx;
				if(ymax < yy) ymax = yy;
			}
		}
		for(int j = 1; j <= ymax; ++j){
			for(int i = xmin; i <= xmax; i++){
				int val = mp[make_pair(i, j)];
				if(val < 10) printf("%d",val);
				else putchar(val - 10 + 'a');
			}
			putchar('\n');
		}
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
