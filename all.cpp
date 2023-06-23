//在排序数组中查找元素的第⼀个和最后⼀个位置 二分查找
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return vector<int> {left_bound(nums,target),right_bound(nums,target)};
    }

    int left_bound(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size()-1;
        while(left<=right)
        {
            int mid = left + (right -left)/2;
            if(nums[mid]==target)
                right = mid-1;
            else if(nums[mid]<target)
                left = mid +1;
            else
                right = mid -1;
        }
        if(left>=nums.size() || nums[left]!=target)
            return -1;
        return left;
    }
    int right_bound(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size()-1;
        while(left<=right)
        {
            int mid = left + (right -left)/2;
            if(nums[mid]==target)
                left = mid+1;
            else if(nums[mid]<target)
                left = mid +1;
            else
                right = mid -1;
        }
        if(right<0 || nums[right]!=target)
            return -1;

        return right;
    }
};


//二分搜索
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                left = mid+1;
            else
                right = mid -1;
        }
        return -1;
    }
};


//搜索插入位置 就是求左边界
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return left_bound(nums, target);
    }
    int left_bound(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while(left <= right)
        {
            int mid = left + (right -left)/2;
            if(nums[mid]==target)
                right = mid -1;
            else if(nums[mid]<target)
                left = mid+1;
            else
                right = mid -1;
        }
        return left;
    }

};


//旋转矩阵
class Solution {
public:
    void swap(int& a, int& b){
        int t = a;
        a = b;
        b = t;
    }
    void rotate(vector<vector<int>>& m) {
        if(m.empty()) return;
        int n = m.size();
        //transpose matrix转置矩阵
        for(int i=0; i<n; i++)
            for(int j=0; j<=i; j++){
                swap(m[i][j],m[j][i]);
            }
        //reverse row翻转行
        for(int i=0; i<n; i++)
            for(int j=0; j<n/2; j++)
                swap(m[i][j],m[i][n-j-1]);
        return;
    }
};