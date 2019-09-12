#include <iostream>
using namespace std;
int a, b;
int main() {
	cin >> a >> b;
	int i;
	for (i = 1; i <= 100; i++) {
		a*=3, b*=2;
		if (a > b) break;
	}
	cout << i;
}
