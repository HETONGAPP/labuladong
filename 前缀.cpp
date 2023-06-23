//前缀主要处理 一个不变数组的 一段区间的和

class NumArray {

    vector<int> preSum;
    public:
    NumArray(int[] nums) 
    {
        preSum.resize(nums.size()+1,0);
        for(int i = 1; i<preSum.size(); ++i)
            preSum[i] = preSum[i-1] + nums[i-1];
    }

    int sumRange(int left, int right) 
    {
        return preSum[right+1] - preSum[left];
    }
}



//扩展 二维矩阵
class NumMatrix {
 // 定义：preSum[i][j] 记录 matrix 中⼦矩阵 [0, 0, i-1, j-1] 的元素和
    private int[][] preSum;
 
    public NumMatrix(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        if (m == 0 || n == 0) return;

        preSum = new int[m + 1][n + 1];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                preSum[i][j] = preSum[i-1][j] + preSum[i][j-1] + matrix[i
                - 1][j - 1] - preSum[i-1][j-1];
            }
        }
    }
    public int sumRegion(int x1, int y1, int x2, int y2) {
    return preSum[x2+1][y2+1] - preSum[x1][y2+1] - preSum[x2+1][y1] +
    preSum[x1][y1];
    }
}




///差分数组的主要适⽤场景是频繁对原始数组的某个区间的元素进⾏增减
class Difference
{
    vector<int> diff;
    Difference(int[] nums) 
    {
       diff.resize(nums.size(),0);
       diff[0]=nums[0];
       for(int i = 1; i<nums.size(); ++i)
       {
            diff[i] = nums[i] - nums[i-1];
       } 
    }
    void increment(int i, int j, int val) 
    {
        diff[i] += val;
        if(j + 1 < diff.size())
            diff[j+1] -=val;
    }
    vector<int> result() 
    {
        vector<int> res(diff.size());
        res[0] = diff[0];
        for (int i = 1; i < diff.size(); i++) {
            res[i] = res[i - 1] + diff[i];
        }
        return res;
    }
}
