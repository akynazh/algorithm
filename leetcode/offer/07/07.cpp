#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        this->preorder = preorder;
        for (int i = 0; i < (int)inorder.size(); i++) dic[inorder[i]] = i;
		return solve(0, 0, (int)inorder.size() - 1); // 前序根，中序左子树，中序右子树
    }

   private:
    unordered_map<int, int> dic; // 中序序列，确定左右子树范围
    vector<int> preorder; // 前序序列，确定根节点，用于建树
	TreeNode* solve(int root, int left, int right) {
		if (left > right) return nullptr;
		int idx = dic[preorder[root]];
		TreeNode* tree = new TreeNode(preorder[root]);
		tree->left = solve(root + 1, left, idx - 1); 
		tree->right = solve(root + 1 + ((idx - 1 - left + 1) - 1) + 1, idx + 1, right);
						//  左子树根 + 左子树个数 - 1 == 左子树序列最后一个数 
		return tree;
	}
};
int main() {
    Solution solution;
    vector<int> v1{};
    vector<int> v2{};
    solution.buildTree(v1, v2);
    return 0;
}