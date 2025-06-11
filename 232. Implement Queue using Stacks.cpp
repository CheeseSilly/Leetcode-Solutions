#include <stack>
class MyQueue {
public:
  MyQueue() {}

  void push(int x) { st_in.push(x); }

  int pop() {
    if (st_in.empty()) {
      auto tmp = st_out.top();
      st_out.pop();
      return tmp;
    }
    if (st_out.empty()) {
      while (!st_in.empty()) {
        auto tmp = st_in.top();
        st_out.push(tmp);
        st_in.pop();
      }
    }
    auto tmp = st_out.top();
    st_out.pop();
    return tmp;
  }

  int peek() {
    if (st_in.empty()) {
      auto tmp = st_out.top();
      return tmp;
    }
    if (st_out.empty()) {
      while (!st_in.empty()) {
        auto tmp = st_in.top();
        st_out.push(tmp);
        st_in.pop();
      }
    }
    auto tmp = st_out.top();
    return tmp;
  }

  bool empty() { return st_in.empty() && st_out.empty(); }

private:
  std::stack<int> st_in;
  std::stack<int> st_out;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */