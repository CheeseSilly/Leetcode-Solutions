#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Allocator {
public:
  vector<int> memory;
  unordered_map<int, int> idTable;
  Allocator(int n) : memory(n, 0) {}

  int allocate(int size, int mID) {
    int flag = 0;
    int s = size;
    int first = memory.size() + 1;

    for (int i = 0; i < memory.size(); i++) {

      if (memory[i] == 0) {
        first = min(first, i);
        s--;
      }
      if (memory[i] == 1) {
        first = memory.size() + 1;
        s = size;
      }
      if (s == 0) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      first = -1;
      return first;
    }
    for (int i = first; i < first + size; i++) {
      memory[i] = 1;
      idTable[i] = mID;
    }
    return first;
  }

  int freeMemory(int mID) {
    int num = 0;
    for (auto i : idTable) {
      if (i.second == mID) {
        memory[i.first] = 0;
        idTable[i.first] = 0;
        num++;
      }
    }
    return num;
  }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */
