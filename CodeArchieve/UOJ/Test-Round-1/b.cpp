#include <cstdio>
#include <algorithm>
#include <queue>
struct Task {
	int t, s, p;
	bool operator<(const Task& rhs)const {
		return p < rhs.p;
	}
};
int main() {
}
