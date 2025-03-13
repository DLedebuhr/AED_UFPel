/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {

    if (p == NULL && q == NULL) {

        // Ambas estão vazias = True
        return true;

    } else if (p == NULL || q == NULL) {

        // Apenas uma das arvores esta vazia = False
        return  false;

    } else if (p -> val != q -> val) {

        // Possuem valores diferentes = False
        return false;

    }

    return isSameTree (p -> left, q -> left) && isSameTree (p -> right, q -> right);

}