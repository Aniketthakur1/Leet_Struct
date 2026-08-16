class Solution {
public:
    int mn = INT_MAX;
    
    void inorder(TreeNode* root, int size) {

        if (root->left == NULL && root->right == NULL) {
            mn = min(mn, size);
            return;
        }
        
        if (root->left) inorder(root->left, size + 1);
        if (root->right) inorder(root->right, size + 1);
    }
    
    int minDepth(TreeNode* root) {

        if (root == NULL) return 0;

        mn = INT_MAX; 
        
        inorder(root, 1);
        return mn;
    }
};
