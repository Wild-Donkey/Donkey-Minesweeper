#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
unsigned n, m, Mine(0), Cnt(0), Tot, Sum[105][105];
char a[105][105], Ans[105][105], Tmp[105][105];
inline void Print () {
	printf("Case: %u\n", ++Cnt);
	for (unsigned i(1); i <= n; ++i) {
		for (unsigned j(1); j <= m; ++j) Sum[i][j] += Ans[i][j], putchar(Ans[i][j] ? '@' : ' ');
		putchar(0x0A);
	}
}
inline void Check(){
	for (unsigned i(1); i <= n; ++i) for (unsigned j(1); j <= m; ++j) Tmp[i][j] = 0;
	for (unsigned i(1); i <= n; ++i) for (unsigned j(1); j <= m; ++j) if(Ans[i][j])
		++Tmp[i - 1][j - 1], ++Tmp[i - 1][j], ++Tmp[i - 1][j + 1], ++Tmp[i][j - 1], ++Tmp[i][j + 1], ++Tmp[i + 1][j - 1], ++Tmp[i + 1][j], ++Tmp[i + 1][j + 1];
	for (unsigned i(1); i <= n; ++i) for (unsigned j(1); j <= m; ++j) if(a[i][j] < 10) if(a[i][j] ^ Tmp[i][j]) return;
	Print();
}
inline void DFS(char x, char y) {
	if(y > m) y = 1, ++x;
	if(x > n) {
		if(Tot == Mine) Check();
		return;
	}
	if(a[x][y] == '?') {
		if(Mine < Tot) Ans[x][y] = 1, ++Mine, DFS(x, y + 1), --Mine, Ans[x][y] = 0;
		DFS(x, y + 1);
	} else DFS(x, y + 1);
	return;
}
int main() {
	n = RD(), m = RD(), Tot = RD();
	for (unsigned char i(1); i <= n; ++i) {
		scanf("%s", a[i] + 1);
		for (unsigned char j(1); j <= m; ++j) {
			if((a[i][j] >= '0') && (a[i][j] < '9')) a[i][j] -= '0';
			if(a[i][j] == '@') Ans[i][j] = 1;
		}
	}
	DFS(1, 1);
	for(unsigned char i(1); i<=n; ++i) {
		for(unsigned char j(1); j<=m; ++j) printf("%.6lf ", (double)Sum[i][j] / Cnt);
		putchar(0x0A);
	}
	return 0;
}
/*
4 6 5
2?????
@?3???
3?????
@3@@@@
*/
