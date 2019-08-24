#include <cstdio>
#include <algorithm>
int a, b, c;
using namespace std;
int main() {
    scanf("%d%d", &a, &b);
    c = a+b;
    c = max(c, a-b);
    c = max(c, a*b);
    printf("%d", c);
}
