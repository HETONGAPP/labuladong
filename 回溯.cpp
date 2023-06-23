



//题「全排列」就是给你输⼊⼀个数组 nums，让你返回这些数字的全排列。
[
 [1,2,3],[1,3,2],
 [2,1,3],[2,3,1],
 [3,1,2],[3,2,1]
]

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> track;
        vector<bool> used(nums.size());
        traceBack(nums,track,used);
        return res;

    }

    void traceBack(vector<int>& nums,vector<int>& track, vector<bool>& used)
    {
        if(nums.size() == track.size())
        {
            res.push_back(track);
            return;
        }
        for(int i = 0; i < nums.size(); ++i)
        {
            if(used[i])
                continue;
            
            track.push_back(nums[i]);
            used[i] = true;

            traceBack(nums, track, used);
            track.pop_back();
            used[i] = false;

        }
    }
};


/// path sum tree
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)return false;
        if(sum==root->val&&!root->left&&!root->right)return true;
        sum-=root->val;
        if(true==hasPathSum(root->left,sum))return true;
        else{
            if(true==hasPathSum(root->right,sum))return true;
        }
        return false;
    }
};

/// path sum tree 2
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        if (!root) return result;
        vector<int> path;
        path.push_back(root->val);
        dfs(root, root->val, sum ,path, result);
        return result;
    }
    void dfs(TreeNode *root, int s, int sum, vector<int> &p, vector<vector<int>> &r) {
        if (!root) return;
        if (!root->left && !root->right) {
            if (s == sum) r.push_back(p);
            return;
        }
        
        if (root->left) {
            p.push_back(root->left->val);
            dfs(root->left, s+root->left->val, sum, p, r);
            p.pop_back();
        }
           
        if (root->right) {
            p.push_back(root->right->val);
            dfs(root->right, s+root->right->val, sum, p, r);
            p.pop_back();
        }   
    }
};



//nums = [1,2,3] Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
class Solution {
public:
    vector<vector<int>> res;
    vector<int> vec;
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size() == 0)
            return {};

        backTrack(nums, 0, vec);
        return res;
    }

    void backTrack(vector<int>&nums, int start, vector<int> vec)
    {
        res.push_back(vec);

        for(int i = start; i<nums.size(); ++i)
        {
            vec.emplace_back(nums[i]);
            backTrack(nums, i+1, vec);
            vec.pop_back();
        }
    }
};


//给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。 [ [1,2],[1,3],[2,3] ]
class Solution {
public:

    vector<vector<int>> res;
    vector<int> track;
    vector<vector<int>> combine(int n, int k) {
        if(n<=0 || k<=0)
            return res;
        backTrack(n, 1,track, k);
        return res;
    }

    void backTrack(int n, int start, vector<int>track, int k)
    {
        if(track.size() == k)
        {
            res.push_back(track);
            return;
        }

        for(int i = start; i<=n;++i)
        {
            track.emplace_back(i);
            backTrack(n, i+1, track, k);
            track.pop_back();
        }
    }
};


//Input: candidates = [2,3,6,7], target = 7 Output: [[2,2,3],[7]]

class Solution {
public:

    vector<vector<int>> res;

    vector<int> track;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        if(candidates.size()==0)
            return {};
        backTrack(candidates, 0, target, 0);
        return res;
    }

    void backTrack(vector<int>& candidates, int start, int target, int sum)
    {
        if(sum == target)
            res.push_back(track);
        
        if(sum>target)
            return;
        
        for(int i = start; i < candidates.size(); ++i)
        {
            track.push_back(candidates[i]);
            sum += candidates[i];
            backTrack(candidates, i, target, sum);
            track.pop_back();
            sum -= candidates[i];
        }
    }
};




///[ [],[1],[2],[1,2],[2,2],[1,2,2] ]
class Solution {
public:
    vector<vector<int>> res;
    vector<int> track;


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if(nums.size() == 0)
            return res;
        sort(nums.begin(), nums.end());
        backTrack(nums, 0, track);
        return res;
    }

    void backTrack(vector<int>& nums, int start, vector<int>& track)
    {
        res.push_back(track);

        for(int i = start; i< nums.size(); ++i)
        {
            if(i>start &&nums[i]==nums[i-1])
                continue;

            track.emplace_back(nums[i]);
            backTrack(nums, i+1, track);
            track.pop_back();
        }
    }
};

///[ [1,2,2],[2,1,2],[2,2,1] ]

List<List<Integer>> res = new LinkedList<>();
LinkedList<Integer> track = new LinkedList<>();
boolean[] used;
public List<List<Integer>> permuteUnique(int[] nums) {
    // 先排序，让相同的元素靠在⼀起
    Arrays.sort(nums);
    used = new boolean[nums.length];
    backtrack(nums);
    return res;
}
void backtrack(int[] nums) {
    if (track.size() == nums.length) {
        res.add(new LinkedList(track));
        return;
    }
    for (int i = 0; i < nums.length; i++) {
        if (used[i]) {
            continue;
        }
 // 新添加的剪枝逻辑，固定相同的元素在排列中的相对位置
        if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
            continue;
        }
        track.add(nums[i]);
        used[i] = true;
        backtrack(nums);
        track.removeLast();
        used[i] = false;
    }
}












