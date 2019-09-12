#include <iostream>
using namespace std;
int n;
int main() {
	cin >> n;
	long long x, i, y;
	for (i = 1, x = n, y = 1; x >= 10; i++, x/=10, y*=10); 
	y *= x + 1;
	cout << y - n;
}
