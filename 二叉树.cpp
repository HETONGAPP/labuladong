//二叉树的最大深度
int res = 0;
int depth = 0;
int maxDepth(TreeNode* root) {
    traverse(root);
    return res;
}
void traverse(TreeNode* root) {
    if(root == nullptr)
        return;
    
    ++depth;

    traverse(root->left);
    traverse(root->right);

    if(root->left == nullptr && root->right == nullptr)
        res = max(res, depth);

    --depth;
}

int maxDepth(TreeNode* root) {

    if(root == nullptr)
        return 0;
    
    int leftMax = maxDepth(root->left);
    int rightMax = maxDepth(root->right);

    int res = max(leftMax,rightMax)+1;
    return res;
}


//二叉树前序遍历
vector<int> vec;
void preorderTraverse(TreeNode* root) {
    if(root==nullptr)
        return;
    
    vec.emplace_back(root->val);
    preorderTraverse(root->left);
    preorderTraverse(root->right);
}


//修剪 二叉搜索树
TreeNode* trimBST(TreeNode* root, int low, int high) {
    if(root==nullptr)
            return root;
        
    if(root->val < low)
    {
        return trimBST(root->right, low, high);
    }
    if(root->val > high)
    {
        return trimBST(root->left, low, high);
    }

    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
}

//求 树的最大直径
int maxDiameter = 0;
int diameterOfBinaryTree(TreeNode* root) {
 maxDepth(root);
 return maxDiameter;
}
int maxDepth(TreeNode* root) {
    if(root==nullptr)
        return 0;
    int leftMax = maxDepth(root->left);
    int rightMax = maxDepth(root->right);
    int myd = leftMax + rightMax;
    maxDiameter = max(maxDiameter, myd);

    return 1+ max(leftMax, rightMax);
}


//翻转⼆叉树
TreeNode* invertTree(TreeNode* root) {
    if(root == nullptr)
        return nullptr;
    
    TreeNode* left = invertTree(root->left);
    TreeNode* right = invertTree(root->light);

    root->left = right;
    root->right = left;

    return root;
}



//填充节点的右侧指针
Node* connect(Node* root) {
    if (root == nullptr) return nullptr;
    // 遍历「三叉树」，连接相邻节点
    traverse(root->left, root->right);
    return root;
}
// 三叉树遍历框架
void traverse(Node* node1, Node* node2) {
    if (node1 == nullptr || node2 == nullptr) {
        return;
    }
    node1->next = node2;
    traverse(node1->left, node1->right);
    traverse(node2->left, node2->right);
    traverse(node1->right, node2->left);
}


//将⼆叉树展开为链表

void flatten(TreeNode* root) {
    if(root==nullptr)
        return;

    flatten(root->left);
    flatten(root->right);

    TreeNode* left = root->left;
    TreeNode* right = root->right;

    root->left = nullptr;
    root->right = left;

    TreeNode* p = root;

    while(p->right!=nullptr)
    {
        p = p->right;
    }
    p->right = right;
}