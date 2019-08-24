/**
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Thu, 22 Aug 2019 20:01:28 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
typedef long long ll;
using namespace std;
const int SN = 6;
int n, t[SN], Q, vars[256];
bool locked;
struct Program;
struct Sentence;
deque<shared_ptr<Program> > q;
queue<shared_ptr<Program> > prevent;
void init() {
  memset(vars, 0, sizeof vars);
  locked = 0;
  q.clear();
  while (!prevent.empty()) prevent.pop();
}
struct Sentence {
  int type;//0=, 1print, 2lock, 3unlock, 4end
  string var;
  int value;
  int progID;
  Sentence(const string& str, int progID):progID(progID) {
    stringstream ss(str);
    string t1, t2;
    int t3;
    ss >> t1;
    if (t1 == "print") {
      type = 1;
      ss >> t2;
      var = t2;
    }
    else if (t1 == "lock") {
      type = 2;
    }
    else if (t1 == "unlock") {
      type = 3;
    }
    else if (t1 == "end") {
      type = 4;
    }
    else {
      type = 0;
      var = t1;
      ss >> t2 >> t3;
      value = t3;
      //xxx(value);
    }
  }
  void execute() {
    //printf("type%d\n", type);
    if (type == 0) {
      int id = (int)var[0];
      vars[id] = value;
    }
    else if (type == 1) {
      int id = (int)var[0];
      cout << progID <<": " << vars[id] << endl;
    }
    else if (type == 2) {
      locked = 1;
    }
    else if (type == 3) {
      locked = 0;
      if (!prevent.empty()) {
        q.push_front(prevent.front());
        prevent.pop();
      }
    }
    else if (type == 4) {
    }
  }
};
struct Program {
  vector<Sentence> lines;
  int cur, id;
  bool prevented;
  Program(int id):id(id) {
    cur = 0;
    prevented = 0; 
  }
  inline int exit(){
    if (cur == (int)lines.size()) return 0; // exit normally
    else if (prevented) return 2; // preventd
    else return 1; // paused
  }
  void execute() {
//    printf("enter prog#%d\n", id);
    prevented = 0;
    int left = Q;
    while (left>0 && cur < (int)lines.size()){
      Sentence& sen = lines[cur];
      if (sen.type == 2 && locked) {
        prevented = 1;
        //cout <<"prevented\n";
        break;
      }
      else {
        sen.execute();
        left -= t[lines[cur++].type];
      }
    }
  }
};
istream& operator>>(istream& is, Program& prog) {
  string s;
  while (getline(cin, s)) {
    prog.lines.push_back(Sentence(s, prog.id));
    if (s == "end") break;
  }
  return is;
}
int main() {
  int ks;
  cin >> ks;
  while (ks--) {
    init();
    cin >> n;
    for (int i = 0; i < 5; i++) cin >> t[i];
    cin >> Q;
    cin.ignore();
    for (int i = 1; i <= n; i++) {
      shared_ptr<Program> prog = make_shared<Program>(i);
      cin >> *prog;
      q.push_back(prog);
    }
    while (!q.empty()) {
      auto prog = q.front();
      q.pop_front();
      prog->execute();
      switch(prog->exit()) {
        case 0: break;
        case 1: q.push_back(prog); break;
        case 2: prevent.push(prog); break;
      }
    }
    if (ks) cout << endl;
  }
}
