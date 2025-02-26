#include <bits/stdc++.h>

using namespace std;

class TextEditor {
public:
  stack<char> left, right;
  TextEditor() {}

  void addText(string text) {
    for (auto &c : text)
      left.push(c);
  }

  int deleteText(int k) {
    int ans = min(k, int(left.size()));
    for (int i = 0; i < ans; i++)
      left.pop();
    return ans;
  }

  string cursorLeft(int k) {
    k = min(k, int(left.size()));
    while (k--) {
      auto c = left.top();
      left.pop();
      right.push(c);
    }
    string ans;
    for (int i = 0; i < 10 && !left.empty(); i++) {
      ans.push_back(left.top());
      left.pop();
    }
    reverse(ans.begin(), ans.end());
    for (auto &c : ans)
      left.push(c);
    return ans;
  }

  string cursorRight(int k) {
    k = min(k, int(right.size()));
    while (k--) {
      auto c = right.top();
      right.pop();
      left.push(c);
    }
    string ans;
    for (int i = 0; i < 10 && !left.empty(); i++) {
      ans.push_back(left.top());
      left.pop();
    }
    reverse(ans.begin(), ans.end());
    for (auto &c : ans)
      left.push(c);
    return ans;
  }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */