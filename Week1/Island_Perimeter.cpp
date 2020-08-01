/*
/You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

 

Example:

Input:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Output: 16

Explanation: The perimeter is the 16 yellow stripes in the image below:
*/


class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        int result = 0;
        
        for(int i =0; i < row; i++){
            for(int j = 0; j < col; j++){
                if (grid[i][j] == 1){
                    result += 4;
                
                
                if( i > 0 && grid[i-1][j] == 1){
                    result -= 2;
                }
                
                if (j > 0 && grid[i][j-1] == 1){
                    result -=  2;
                }
                
            }
                    
                    /*
                    result += (i == 0 || grid[i-1][j] == 0 ? 1 : 0);
                    result += (i == row-1 || grid[i+1][j] == 0 ? 1 : 0);
                    result += (j == 0 || grid[i][j-1] == 0 ? 1 : 0);
                    result += (j == col-1 || grid[i][j+1] == 0 ? 1 : 0);*/
                
            
        }
        }
                
        
        return result;
            
    }
};
