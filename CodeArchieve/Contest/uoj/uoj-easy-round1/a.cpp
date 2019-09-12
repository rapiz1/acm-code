#include <iostream>
#include <cmath>
using namespace std;
long long g, l;
int main() {
	int t; cin >> t;
	while (t--) {
		cin >> g >> l;
		cout << (long long)(sqrt((long double)g*l) + 0.5)*2 << " " << g + l;
		cout << endl;
	}
}
