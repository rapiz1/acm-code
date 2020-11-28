/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/   https://rapiz.me
 *           code@rapiz.me
 *          Fri, 27 Nov 2020 22:38:13 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
				vector<int> all;	
				for (auto a : nums1) all.push_back(a);
				for (auto a : nums2) all.push_back(a);
				sort(all.begin(), all.end());
				return all[all.size()/2];
    }
};
int main() {
	vector<int> a;
	vector<int> b;
	int n, m;
	cin >> n;
	while (n--) {
		int x; cin >> x;
		a.push_back(x);
	}
	cin >> m;
	while (m--) {
		int x; cin >> x;
		b.push_back(x);
	}
	Solution sol;
	cout << sol.findMedianSortedArrays(a, b);
}

