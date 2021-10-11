class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        vector<int> quick_s[2];
        int k = nums.size()/2;
        int n = nums.size();
        int comb = (1<<k)-1;//comb是每一个k元素的子集，从0…01…1开始
        int sum = 0, ans = 0;
        for (auto x : nums) sum += x, ans += abs(x);
        for (int i = 0; i < 2; i++) {
            int offset = i*15;
            for (int s = 0; s < (1<<15); s++) {
                quick_s[i].push_back(0);
                for (int j = 0; j < 15 && j + offset < nums.size(); j++) if((s>>j)&1) quick_s[i][s] += nums[j + offset];
            }
        }
        //printf("%d %d\n", quick_s[0][3], quick_s[])
        while(comb<1<<n)
        {
            int part = 0;
            //for (int i = 0; i < n; i++) if ((comb>>i)&1) part += nums[i];
            //for (int idx = 0, s = comb; s; idx++, s >>= 1) part += (s&1)*nums[idx];
            part = quick_s[1][comb>>15] + quick_s[0][comb&((1<<15)-1)];
            ans = min(ans, abs(sum - part - part));
            int x=comb&-comb,y=comb+x;
            comb=((comb&~y)/x>>1)|y;
        }
        return ans;
    }
};
