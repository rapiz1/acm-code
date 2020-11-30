/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/   https://rapiz.me
 *           code@rapiz.me
 *          Sun, 29 Nov 2020 14:22:06 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end(), greater<int>());
        for (int i = 0; i + 2 < A.size(); i++) {
            if (A[i] < A[i+1] + A[i+2])
                return A[i] + A[i+1] + A[i+2];
        }
        return 0;
    }
};
int main() {
	vector<int> v = {1, 2, 1};
	Solution sol;
	cout << sol.largestPerimeter(v);
}

