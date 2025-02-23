#include <bits/stdc++.h>

using namespace std;

class OrderedStream {
public:
  vector<string> stream;
  int ptr;

  OrderedStream(int n) : ptr(0), stream(n) {}

  vector<string> insert(int idKey, string value) {
    vector<string> ans;
    stream[idKey - 1] = value;
    while (stream[ptr] != "") {
      ans.push_back(stream[ptr++]);
      if (ptr == stream.size()) {
        break;
      }
    }
    return ans;
  }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
