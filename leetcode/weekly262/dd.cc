#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        vector<int> quick_s[2], sorted_s[2][16];
        int k = nums.size()/2;
        int n = nums.size();
        int comb = (1<<k)-1;//comb是每一个k元素的子集，从0…01…1开始
        int sum = 0, ans = 0;
        for (auto x : nums) sum += x, ans += abs(x);
        for (int i = 0; i < 2; i++) {
            int offset = i*15;
            quick_s[i].reserve(1<<15);
            for (int s = 0; s < (1<<15); s++) {
                quick_s[i].push_back(0);
                int c1 = 0;
                for (int j = 0; j < 15 && j + offset < nums.size(); j++) if((s>>j)&1) c1++, quick_s[i][s] += nums[j + offset];
                sorted_s[i][c1].push_back(quick_s[i][s]);
            }
            for (int j = 0; j <= 15; j++)
                sort(sorted_s[i][j].begin(), sorted_s[i][j].end());
        }
        for (int i = 0; i <= k; i++) {
            for (auto e : sorted_s[0][i]) {
                int wanted = sum/2 - e;
                auto& v = sorted_s[1][k-i];
                if (v.empty()) continue;
                
                int now_s;
                
                auto it = lower_bound(v.begin(), v.end(), wanted);
                if (it != v.end()) {
                    now_s = e + *it;
										ans = min(ans, abs(sum - 2*now_s));
									if (it != v.begin() && --it != v.end()) {
											now_s = e + *it;
											ans = min(ans, abs(sum - 2*now_s));
									}
                }
                
                
                it = upper_bound(v.begin(), v.end(), wanted);
                if (it != v.end()) {
                    now_s = e + *it;
										ans = min(ans, abs(sum - 2*now_s));
                }
                
            }
        }
        return ans;
    }
};
int main() {
	Solution sol;
	auto arg = vector<int>{3,9,7,3};
	cout << sol.minimumDifference(arg);
}
