#include "btNode.h"
#include <iomanip>

void dumpToArrayInOrder(btNode* bst_root, int* dumpArray)
{
    if (bst_root == 0) return;
    int dumpIndex = 0;
    dumpToArrayInOrderAux(bst_root, dumpArray, dumpIndex);
}

void dumpToArrayInOrderAux(btNode* bst_root, int* dumpArray, int& dumpIndex)
{
    if (bst_root == 0) return;
    dumpToArrayInOrderAux(bst_root->left, dumpArray, dumpIndex);
    dumpArray[dumpIndex++] = bst_root->data;
    dumpToArrayInOrderAux(bst_root->right, dumpArray, dumpIndex);
}

void tree_clear(btNode*& root)
{
    if (root == 0) return;
    tree_clear(root->left);
    tree_clear(root->right);
    delete root;
    root = 0;
}

int bst_size(btNode* bst_root)
{
    if (bst_root == 0) return 0;
    return 1 + bst_size(bst_root->left) + bst_size(bst_root->right);
}

void bst_insert(btNode*& root, int newInt)
{
    if(root == NULL){  // if tree is empty, start new tree
        btNode* new_node = new btNode;
        new_node->data = newInt;
        new_node->left = NULL;
        new_node->right = NULL;
        root = new_node;
        return;
    }
    btNode *cursor = root;
    while(cursor != NULL){  // while cursor isn't a leaf
        if(newInt > cursor->data){ // if newInt is greater than cursor
            if(cursor->right != NULL){
                cursor = cursor->right;
                continue;
            }
            if(cursor->right == NULL){
                btNode* new_node = new btNode;
                new_node->data = newInt;
                new_node->left = NULL;
                new_node->right = NULL;
                cursor->right = new_node;
                return;
            }
        }
        // else if newInt is less/equal to cursor
        if(cursor->left != NULL){
            cursor = cursor->left;
            continue;
        }
        if(cursor->left == NULL){
            btNode* new_node = new btNode;
            new_node->data = newInt;
            new_node->left = NULL;
            new_node->right = NULL;
            cursor->left = new_node;
            return;
        }
    }
}

bool bst_remove(btNode*& root, int remInt){
    
    if(root == NULL) return false;  // return false if empty
    
    // target less than root
    if(remInt < root->data) return bst_remove(root->left, remInt);
    
    // target greater than root
    if(remInt > root->data) return bst_remove(root->right, remInt);
    
    // target equal to root
    if(remInt == root->data){
        if(root->left == NULL){ // if root has no left child
            btNode* oldroot_ptr = root;
            root = root->right;
            delete oldroot_ptr;
            return true;
        }
        // else root has a left child
        bst_remove_max(root->left, root->data);
        return true;
    }
    return false;
}

void bst_remove_max(btNode*& root, int& rootData){
    if(root->right != NULL) return bst_remove_max(root->right, rootData);
    
    rootData = root->data;
    if(root->left == NULL){ // if root has no left child
        root = NULL;
        return;
    }
    // else root has a left child
    root = root->left;
    return;
}
