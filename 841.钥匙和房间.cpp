#include <iostream>
#include <vector>

class Solution {
public:
  bool canVisitAllRooms(std::vector<std::vector<int>> &rooms) {
    int n = rooms.size();
    std::vector<bool> keys(n, false);
    keys[0] = true;
    bool res = false;
    int count = 1;
    dfs(rooms, 0, count, res, keys);
    // for(auto key:keys){
    //    if(key==false)
    //        return false;
    // }
    // cout<<count;
    return res;
  }

private:
  void dfs(std::vector<std::vector<int>> &rooms, int n, int &count, bool &res,
           std::vector<bool> &keys) {
    if (count == rooms.size()) {
      res = true;
    }
    for (int i = 0; i < rooms[n].size(); i++) {
      if (!keys[rooms[n][i]]) {
        keys[rooms[n][i]] = true;
        count++;
        dfs(rooms, rooms[n][i], count, res, keys);
      }
    }
  }
};
