class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size()/2;
        int total = 0, ans = 0;
        for (auto x : nums) total += x, ans += abs(x);
        vector<int> rec[2][30];
        for (int i = 0; i < 2; i++) {
            int offset = i*n;
            for (int s = 0; s < (1<<n); s++) {
                int c1 = __builtin_popcount(s);
                int sum = 0;
                for (int idx = 0, x = s; x; x >>= 1, idx++) if (x&1) sum += nums[idx + offset];
                rec[i][c1].push_back(sum);
            }
        }
        for (int i = 0; i <= n; i++) {
            auto &v = rec[1][n - i];    
            sort(v.begin(), v.end());
            for (auto s : rec[0][i]) {
                int wanted = total/2 - s;
                auto it = lower_bound(v.begin(), v.end(), wanted);
                if (it != v.end()) {
                    ans = min(ans, abs(total - 2*(*it  + s)));
                }
                it = upper_bound(v.begin(), v.end(), wanted);
                if (it != v.end()) {
                    ans = min(ans, abs(total - 2*(*it + s)));
                }
                it = upper_bound(v.begin(), v.end(), wanted, greater<int>{});
                if (it != v.end()) {
                    ans = min(ans, abs(total - 2*(*it  + s)));
                }
            }
        }
        return ans;
    }
};