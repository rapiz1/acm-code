#include <cstdio>
#include <cstring>
#include <stack>
#include <map>
#include <string>
using std::string;
typedef std::map<string, double> Params;
struct Praser {
	char cmd[1010];
	int n, pos;
	std::stack<int> os;
	std::stack<double> ns;
	double ans;
	bool isfloat;
	Praser(char* str) {
		strcpy(cmd, str);
	}
	double eval(const Params& params) {
	//	freopen("input", "r", stdin);
		scanf("%d%s", &n, cmd);
		if (strchr(cmd, '.') != NULL) isfloat = 1;
		cmd[strlen(cmd)] = '$';
		for (int l; cmd[pos]; pos += l) {
			if (cmd[pos] == '(') os.push('('), l = 1;
			else if (cmd[pos] == ')' || cmd[pos] == '$') {
				for (;!os.empty() && os.top()!= '('; os.pop()) {
					double x = ns.top(); ns.pop();
					double y = ns.top(); ns.pop();
					if (os.top() == '+') ns.push(x + y);
					else ns.push(y - x);
				}
				if (!os.empty()) os.pop();
				l = 1;
			}
			else if (cmd[pos] == '+' || cmd[pos] == '-') {
				for (;!os.empty() && os.top()!= '('; os.pop()) {
					double x = ns.top(); ns.pop();
					double y = ns.top(); ns.pop();
					if (os.top() == '+') ns.push(x + y);
					else ns.push(y - x);
				}
				os.push(cmd[pos]);
				l = 1;
			}
			else if (isdigit(cmd[pos])){
				double x;
				sscanf(cmd + pos, "%lf%n", &x, &l);
				ns.push(x);
			}
		}
		return os.top();
	}
};
struct Function {
	Parser express;
	int n;
};
int n;
int main() {
}
