//题「全排列」就是给你输⼊⼀个数组 nums，让你返回这些数字的全排列。

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