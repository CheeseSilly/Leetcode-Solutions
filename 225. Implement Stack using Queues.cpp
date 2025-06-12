#include <queue>
#include <vector>

class MyStack {
public:
  MyStack() {}

  // example: <-1-2-3-4<-
  void push(int x) { qe_in.push(x); }
  // in: <-1-2-3-4<-
  // out: <-4-3-2-1<-
  int pop() {
    int pop_num = 0;
    while (qe_in.size() != 1) {
      qe_out.push(qe_in.front());
      qe_in.pop();
    }
    pop_num = qe_in.front();
    qe_in.pop();

    // copy qe_out->qe_in
    qe_in = qe_out;

    while (!qe_out.empty()) {
      qe_out.pop();
    }
    return pop_num;
  }

  int top() { return qe_in.back(); }

  bool empty() { return qe_in.empty() && qe_out.empty(); }

private:
  std::queue<int> qe_in;
  std::queue<int> qe_out;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */