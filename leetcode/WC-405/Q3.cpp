// 3212. Count Submatrices With Equal Frequency of X and Y
// https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y/

// intution standard problem of 2D prefix sum
// prefix interation :- prefix[i][j] = matrix[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1]
// 1 2 -->  1   1+2
// 3 4      1+3 (4+1+3+1+2)wrong (4+1+2+3)correct  {1 repeats itself so as to take the diagonal element only once we substract the sum by prefix[i-1][j-1]}

class Solution {
public:
    vector<vector<int>> solve(vector<vector<char>> &grid,char ch){
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> pre(n+7,vector<int>(m+7,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                pre[i][j]=(grid[i][j]==ch);
                pre[i][j]=pre[i][j]+((i>0)?pre[i-1][j]:0)+((j>0)?pre[i][j-1]:0)-((i>0 && j>0)?pre[i-1][j-1]:0);
            
            }
        }
        return pre;
    }
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        
        vector<vector<int>> preX=solve(grid,'X');
        vector<vector<int>> preY=solve(grid,'Y');
        
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            ans+=(preX[i][j]==preY[i][j] && preX[i][j]>0);
        }
        return ans;
    }
};

/*
grid = [
    ['X', 'Y', 'X'],
    ['Y', 'X', 'Y'],
    ['X', 'Y', 'X']
]

Initial prefix sum arrays (preX and preY):

preX:
[
    [0, 0, 0],
    [0, 0, 0],
    [0, 0, 0]
]

preY:
[
    [0, 0, 0],
    [0, 0, 0],
    [0, 0, 0]
]

1. Construct preX:
   preX[0][0] = (grid[0][0] == 'X') = 1
   preX[0][1] = (grid[0][1] == 'X') + preX[0][0] = 0 + 1 = 1
   preX[0][2] = (grid[0][2] == 'X') + preX[0][1] = 1 + 1 = 2

   preX:
   [
       [1, 1, 2],
       [0, 0, 0],
       [0, 0, 0]
   ]

   preX[1][0] = (grid[1][0] == 'X') + preX[0][0] = 0 + 1 = 1
   preX[1][1] = (grid[1][1] == 'X') + preX[0][1] + preX[1][0] - preX[0][0] = 1 + 1 + 1 - 1 = 2
   preX[1][2] = (grid[1][2] == 'X') + preX[0][2] + preX[1][1] - preX[0][1] = 0 + 2 + 2 - 1 = 3

   preX:
   [
       [1, 1, 2],
       [1, 2, 3],
       [0, 0, 0]
   ]

   preX[2][0] = (grid[2][0] == 'X') + preX[1][0] = 1 + 1 = 2
   preX[2][1] = (grid[2][1] == 'X') + preX[1][1] + preX[2][0] - preX[1][0] = 0 + 2 + 2 - 1 = 3
   preX[2][2] = (grid[2][2] == 'X') + preX[1][2] + preX[2][1] - preX[1][1] = 1 + 3 + 3 - 2 = 5

   preX:
   [
       [1, 1, 2],
       [1, 2, 3],
       [2, 3, 5]
   ]

2. Construct preY:
   preY[0][0] = (grid[0][0] == 'Y') = 0
   preY[0][1] = (grid[0][1] == 'Y') + preY[0][0] = 1 + 0 = 1
   preY[0][2] = (grid[0][2] == 'Y') + preY[0][1] = 0 + 1 = 1

   preY:
   [
       [0, 1, 1],
       [0, 0, 0],
       [0, 0, 0]
   ]

   preY[1][0] = (grid[1][0] == 'Y') + preY[0][0] = 1 + 0 = 1
   preY[1][1] = (grid[1][1] == 'Y') + preY[0][1] + preY[1][0] - preY[0][0] = 0 + 1 + 1 - 0 = 2
   preY[1][2] = (grid[1][2] == 'Y') + preY[0][2] + preY[1][1] - preY[0][1] = 1 + 1 + 2 - 1 = 3

   preY:
   [
       [0, 1, 1],
       [1, 2, 3],
       [0, 0, 0]
   ]

   preY[2][0] = (grid[2][0] == 'Y') + preY[1][0] = 0 + 1 = 1
   preY[2][1] = (grid[2][1] == 'Y') + preY[1][1] + preY[2][0] - preY[1][0] = 1 + 2 + 1 - 1 = 3
   preY[2][2] = (grid[2][2] == 'Y') + preY[1][2] + preY[2][1] - preY[1][1] = 0 + 3 + 3 - 2 = 4

   preY:
   [
       [0, 1, 1],
       [1, 2, 3],
       [1, 3, 4]
   ]

3. Count submatrices where preX[i][j] == preY[i][j] and preX[i][j] > 0:
   - (0, 1) -> preX[0][1] == preY[0][1] == 1
   - (1, 1) -> preX[1][1] == preY[1][1] == 2
   - (2, 1) -> preX[2][1] == preY[2][1] == 3

   Total submatrices: 3
*/
