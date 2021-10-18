#include <bits/stdc++.h>
using namespace std;
class Solution {
    string expr;
    vector<string> ans;
    string num;
    int target;
    typedef long long ll;
    ll calc(int s, int t) {
        int add_pos = -1;
        for (add_pos = t; add_pos >= s; add_pos--) if (expr[add_pos] == '+' || expr[add_pos] == '-') {
            break;
        }
        if (add_pos >= s) {
            char op = expr[add_pos];
            ll l = calc(s, add_pos-1);
            ll r = calc(add_pos+1, t);
            if (op == '+') return l + r;
            else if (op == '-') return l - r;
            else assert(false);
        }

        int mul_pos = -1;
        for (mul_pos = t; mul_pos >= s; mul_pos--) if (expr[mul_pos] == '*') {
            break;
        }
        if (mul_pos >= s) {
            ll l = calc(s, mul_pos-1);
            ll r = calc(mul_pos+1, t);
            return l*r;
        }

        ll ret = 0;
        //cout << expr.substr(s, t-s+1) << " " << s << " " << t << endl;
        for (int i = s; i <= t; i++) {ret = ret*10 + expr[i] - '0';assert(isdigit(expr[i]));}
        return ret;
    }
    void dfs(int pos) {
        if (pos == num.size()) {
            if (calc(0, expr.size()-1) == target) {
                ans.push_back(expr);
            }
            return;
        }
        bool leading_zero = false;
        if (expr.size()) {
            int i = expr.size()-1;
            if (!isdigit(expr[i])) leading_zero = false;
            else {
                while (i >= 0 && expr[i] == '0') i--;
                if (i < 0 || !isdigit(expr[i])) leading_zero = true;
            }
        }
        //cout << expr << " " << leading_zero << endl;
				if (leading_zero) return;
        expr.push_back(num[pos]);
        if (pos != num.size()-1) {
            expr.push_back('*');
            dfs(pos+1);
            expr.pop_back();

            expr.push_back('-');
            dfs(pos+1);
            expr.pop_back();

            expr.push_back('+');
            dfs(pos+1);
            expr.pop_back();
        }
        if (!leading_zero)
            dfs(pos+1);
        expr.pop_back();
    }
public:
    vector<string> addOperators(string num, int target) {
        this->num = num;
        this->target = target;
        if (num.size()) dfs(0);
        return ans;
    }
};
int main() {
	Solution sol;
	auto ans = sol.addOperators("1000000009", 9);
	for (auto s : ans) cout <<s << endl;
}
