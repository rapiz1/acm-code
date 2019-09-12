#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll x1, x2, y1, y2, x3, y3, h, w;
int main() {
//	freopen("input", "r", stdin);
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	if (x1 > x2) swap(x1, x2), swap(y1, y2);
	h = y2 - y3;
	w = x3 - x1;
	h = min(h, y3 - max(2*y3 - y2, y1));
	w = min(w, min(2*x3 - x1, x2) - x3);
	w = w*2 + 1;
	cout << h*w + w/2;
}
