#ifndef BT_NODE_H
#define BT_NODE_H

struct btNode
{
    int data;
    btNode* left;
    btNode* right;
};

void dumpToArrayInOrder(btNode* bst_root, int* dumpArray);
void dumpToArrayInOrderAux(btNode* bst_root, int* dumpArray, int& dumpIndex);
void tree_clear(btNode*& root);
int bst_size(btNode* bst_root);
void bst_insert(btNode*& root, int newInt);
bool bst_remove(btNode*& root, int remInt);
void bst_remove_max(btNode*& root, int& rootData);

#endif
