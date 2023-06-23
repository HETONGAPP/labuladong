//输⼊⼀个数组 nums = [2,1,2,4,3]，你返回数组 [4,2,4,-1,-1]。

vector<int> nextGreaterElement(vector<int> nums) {
    int n = nums.size();
    vector<int> res(n);
    stack<int> s;
    for(int i = n-1; i>0 ;++i)
    {
        while(!s.isEmpty() && s.top() <= nums[i])
            s.pop();
        res[i] = s.isEmpty() ? -1 : s.top();
        s.push(nums[i]);
    }
    return res;
}


//每日温度


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& a) {
        if(a.empty()) return {};
        vector<int> res(a.size(),0);
        stack<int> s;
        for(int i=a.size()-1; i>=0; i--){
            while(!s.empty() && a[i]>=a[s.top()])
                s.pop();
            res[i] = (s.empty())?0:s.top()-i;
            s.push(i);
        }
        return res;
    }
};