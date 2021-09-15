#include<iostream>
#include<stack>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int i = 0, j = 0, L = preorder.size();
    TreeNode* root = new TreeNode(preorder[0]);
    stack<TreeNode*> nodes;
    nodes.push(root);
    TreeNode* curr = root;
    TreeNode* next;
    TreeNode* top;
    while (i < L - 1)
    {
        next = new TreeNode(preorder[i + 1]);
        if (preorder[i] != inorder[j])
        {
            curr->left = next;
            curr = next;
            nodes.push(curr);
            i++;
        }
        else
        {
            while (curr->val == inorder[j])
            {
                nodes.pop();
                j++;
                if (!nodes.empty())
                {
                    top = nodes.top();
                    if (top->val == inorder[j])
                    {
                        curr = nodes.top();
                    }
                }
            }
            curr->right = next;
            curr = next;
            nodes.push(curr);
            i++;
        }
    }
    return root;
}

int main()
{
    return 0;
}