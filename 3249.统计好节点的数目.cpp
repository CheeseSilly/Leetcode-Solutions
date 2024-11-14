#include<iostream>
#include<vector>

class Solution {
public:
    int countGoodNodes(std::vector<std::vector<int>>& edges) {
        int n = edges.size() + 1;
        std::vector<std::vector<int>> g(n);
        for (auto& e : edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        int ans=0;
        //dfs  
        auto dfs = [&](auto&& dfs, int x, int fa) -> int {
        int size=1,sz0=0;
        bool ok=true;
        for(int y:g[x]){
            //不能递归父节点，这是无向树
            if(y==fa){
                continue;
            }
            int sz=dfs(dfs,y,x);
            if(sz0==0){
                sz0=sz;//记录第一个子节点的值
            }
            else if(sz0!=sz){
                ok=false;
            }
            size+=sz;
        }
        ans+=ok;
        return size;
        };
        dfs(dfs,0,-1);
        return ans; 
    }
};