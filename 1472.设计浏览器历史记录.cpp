#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class BrowserHistory {
public:
  int cur;
  int forword_num;
  unordered_map<int, string> history;
  BrowserHistory(string homepage) : cur(0), forword_num(0) {
    history[0] = homepage;
  }

  void visit(string url) {
    history[++cur] = url;
    forword_num = cur;
  }

  string back(int steps) {
    if (cur - steps < 0) {
      cur = 0;
      return history[cur];
    } else {
      cur -= steps;
      return history[cur];
    }
  }

  string forward(int steps) {
    if (cur + steps > forword_num) {
      cur = forword_num;
      return history[cur];
    } else {
      cur += steps;
      return history[cur];
    }
  }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */