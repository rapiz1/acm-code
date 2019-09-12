#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
const int N = 1e5 + 10;
int n, now;
std::priority_queue<int> q;
int main() {
	cin >> n;
	now = n + 1;
	for (int i = n; i >= 1; i--) {
		int x;
		cin >> x;
		q.push(x);
		while (!q.empty() && q.top() == now - 1) printf("%d ", now = q.top()),q.pop() ;
		putchar('\n');
	}
}
