/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool helper(TreeNode* ll, TreeNode* rr) {
        if (!ll && !rr) return true;                   // both null → symmetric
        if (!ll || !rr) return false;                  // one null → not symmetric
        if (ll->val != rr->val) return false;          // values differ → not symmetric
        return helper(ll->left, rr->right) &&          // mirror left↔right
               helper(ll->right, rr->left);            // mirror right↔left
    }
    
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return helper(root->left, root->right);
    }
};
// class Solution {
// public:
//     bool helper(TreeNode* ll ,TreeNode* rr){
//         if(!ll && !rr) return true;
//         if((ll && !rr) || (!ll && rr)) return false;
//         if((ll->left && !rr->right) || (rr->left && !ll->right)) return false;
//         if((!ll->left && rr->right) || (!rr->left && ll->right)) return false;
//         if(ll->left && rr->right ){
//             if(ll->left->val != rr->right->val) return false;   
//         }
//         if(ll->right && rr->left ){
//             if(ll->right->val != rr->left->val) return false; 
//         }
//         return helper(ll->left,rr->right) && helper(ll->right,rr->left);
//     }
//     bool isSymmetric(TreeNode* root) {
//         if(!root->left && !root->right) return true;
//         if((root->left && !root->right) || (!root->left && root->right)) return false;
//         if(root->left->val != root->right->val) return false;
//         return helper(root->left,root->right);
//     }
// };