//Maximum Subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;
        
        vector<int> vec(n);
        int dp_0 = nums[0];
        int dp_1 = 0, res = dp_0;

        for (int i = 1; i < n; i++) {
            dp_1 = max(nums[i], dp_0+nums[i]);
            dp_0 = dp_1;
            res = max(res, dp_1);
        }
        return res;


    }
};

//求最小路径和
class Solution {
public:
    vector<vector<int>> vec;
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vec1(m, vector<int>(n, -1));
        vec = vec1;
        return dp(grid,m-1,n-1);
        
    }

    int dp(vector<vector<int>>& grid,int i, int j)
    {
        if(i==0 && j==0)
            return grid[0][0];
        if(i<0 || j<0)
            return INT_MAX;
        if(vec[i][j] != -1)
            return vec[i][j];
        
        vec[i][j] = min(dp(grid,i-1,j),dp(grid,i,j-1)) + grid[i][j];

        return vec[i][j];
    }
};


int coinChange(int[] coins, int amount) {
 // 题⽬要求的最终结果是 dp(amount)
 return dp(coins, amount)
}
// 定义：要凑出⾦额 n，⾄少要 dp(coins, n) 个硬币
int dp(int[] coins, int amount) {
 // base case
    if (amount == 0) return 0;
    if (amount < 0) return -1;
    int res = Integer.MAX_VALUE;
    for (int coin : coins) {
        // 计算⼦问题的结果
        int subProblem = dp(coins, amount - coin);
        // ⼦问题⽆解则跳过
        if (subProblem == -1) continue;
        // 在⼦问题中选择最优解，然后加⼀
        res = Math.min(res, subProblem + 1);
    }
    return res == Integer.MAX_VALUE ? -1 : res;
}





int minFallingPathSum(int[][] matrix) {
    int n = matrix.length;
    int res = Integer.MAX_VALUE;
    // 备忘录⾥的值初始化为 66666
    memo = new int[n][n];
    for (int i = 0; i < n; i++) {
        Arrays.fill(memo[i], 66666);
    }
    // 终点可能在 matrix[n-1] 的任意⼀列
    for (int j = 0; j < n; j++) {
        res = Math.min(res, dp(matrix, n - 1, j));
    }
    return res;
}
// 备忘录
int[][] memo;
int dp(int[][] matrix, int i, int j) {
    // 1、索引合法性检查
    if (i < 0 || j < 0 ||
        i >= matrix.length ||
        j >= matrix[0].length) {
 
    return 99999;
    }
    // 2、base case
    if (i == 0) {
        return matrix[0][j];
    }
    // 3、查找备忘录，防⽌重复计算
    if (memo[i][j] != 66666) {
        return memo[i][j];
    }
 // 进⾏状态转移
    memo[i][j] = matrix[i][j] + min(
        dp(matrix, i - 1, j), 
        dp(matrix, i - 1, j - 1),
        dp(matrix, i - 1, j + 1)
    );
    return memo[i][j];
}
int min(int a, int b, int c) {
    return Math.min(a, Math.min(b, c));
}