#include <cstdio>
#include <algorithm>
using namespace std;
const int MIN = -1e6, MAX=1e6;
int k, x;
int main() {
    scanf("%d%d", &k, &x);
    int begin = max(x - k + 1, MIN);
    int end = min(x + k - 1, MAX);
    for (int i = begin; i <= end; i++) 
       printf("%d ", i);
}
