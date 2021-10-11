class Solution {
    vector<int> nums;
    int ans;
    int total;
    int n;
    void dfs(int p, int now_s, int cnt) {
        if (nums.size() - p + cnt < n) return;
        if (p >= nums.size()) return;
        int diff = total - now_s*2;
        if (cnt == n) {
            ans = min(ans, abs(diff));
            return;
        }
        if (nums.size() - p + cnt == n) {
            dfs(p+1, now_s + nums[p], cnt+1);
            return;
        }
        dfs(p+1, now_s + nums[p], cnt+1);
        dfs(p+1, now_s, cnt);
    }
public:
    int minimumDifference(vector<int>& nums) {
        this->nums = nums;
        n = nums.size()/2;
        sort(nums.begin(), nums.end());
        for (auto x : nums) total += x, ans += abs(x);
        dfs(0, 0, 0);
        return ans;
    }
};
