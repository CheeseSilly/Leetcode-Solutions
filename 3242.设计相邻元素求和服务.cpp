#include <cstddef>
#include<iostream>
#include<vector>
class NeighborSum {
public:
    std::vector<std::vector<int>> grid;
    //初始化对象
    NeighborSum(std::vector<std::vector<int>>& grid) {
    this->grid = grid;
    }
    
    int adjacentSum(int value) {
        int sum = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == value){
                    if(i > 0){
                        sum += grid[i-1][j];
                    }
                    if(i < grid.size()-1){
                        sum += grid[i+1][j];
                    }
                    if(j > 0){
                        sum += grid[i][j-1];
                    }
                    if(j < grid[i].size()-1){
                        sum += grid[i][j+1];
                    }
                }
            }
        }
        return sum;
    }
    
    int diagonalSum(int value) {
        int sum=0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == value){
                    if(i > 0&&j>0){
                        sum += grid[i-1][j-1];
                    }
                    if(i < grid.size()-1&&j>0){
                        sum += grid[i+1][j-1];
                    }
                    if(i>0&&j<grid[i].size()-1){
                        sum += grid[i-1][j+1];
                    }
                    if(i<grid.size()&&j < grid[i].size()-1){
                        sum += grid[i+1][j+1];
                    }
                }
            }
        }
        return sum;
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */

int main(){
    std::vector<std::vector<int>> grid = {{0,1,2},{3,4,5},{6,7,8}};
    NeighborSum* obj = new NeighborSum(grid);
    std::cout<<obj->adjacentSum(1)<<std::endl;
    std::cout<<obj->adjacentSum(4)<<std::endl;
    std::cout<<obj->diagonalSum(4)<<std::endl;
    std::cout<<obj->diagonalSum(8)<<std::endl;
}