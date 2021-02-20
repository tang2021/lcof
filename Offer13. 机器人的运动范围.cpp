// 剑指 Offer 13. 机器人的运动范围
// 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
// 示例 1：
// 输入：m = 2, n = 3, k = 1
// 输出：3
// 示例 2：
// 输入：m = 3, n = 1, k = 0
// 输出：1
// 提示：
// 1 <= n,m <= 100
// 0 <= k <= 20
#include<vector>
using namespace std;

bool check(int row,int col,int k){
int sum=0;
while(row>0||col>0){
    sum+=row%10+col%10;
    row/=10;
    col/=10;
}
return sum<=k;
}
int M,N;
int movingCount(int m, int n, int k) {
    M=m;
    N=n;
    vector<int>visited(N*M,0);
    return dfs(k,0,0,visited);
}
int dfs(int k,int i,int j,vector<int>&visited){
    if(i<0||i>=M||j<0||j>=N||visited[i*N+j]==1||!check(i,j,k))return 0;
    
    visited[i*N+j]=1;
    return dfs(k,i+1,j,visited) + dfs(k,i,j+1,visited) + 1;
}