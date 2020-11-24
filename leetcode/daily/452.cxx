/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/   https://rapiz.me
 *           code@rapiz.me
 *          Mon, 23 Nov 2020 23:01:25 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;

class Solution {
public:
	static bool compare(vector<int> a, vector<int> b) {
		if (a[1] != b[1]) {
			return a[1] < b[1];
		}
		else return a[0] > b[0];
	}
	int findMinArrowShots(vector<vector<int>>& points) {
		vector<int> sel;
		int ans = 0;
		sort(points.begin(), points.end(), compare);
		int selpos = -1;
		for (auto p : points) {
			if (sel.empty()) {
				sel.push_back(p[1]);
				selpos = 0;
				ans++;
			}
			else {
				while (selpos < sel.size() && sel[selpos] < p[0]) {
					selpos++;
				}
				if (selpos == sel.size()) {
					ans++;
					sel.push_back(p[1]);
				}
			}
		} 
		return ans;
	}
};

int main() {
	Solution sol;
	//auto poi = vector<vector<int>>{vector<int>{10,16},vector<int>{2,8},vector<int>{1,6},vector<int>{7,12}};
	auto poi = vector<vector<int>>{{1,2},{3,4},{5,6},{7,8}};
	cout << sol.findMinArrowShots(poi);
}

