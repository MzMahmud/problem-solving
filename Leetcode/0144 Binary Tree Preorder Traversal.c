/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct ArrayList {
    int *data;
    int size;
    int capacity;
} ArrayList;

ArrayList construct(int initialCapacity) {
    ArrayList arrayList;
    arrayList.data = (int *) malloc(initialCapacity * sizeof(int));
    arrayList.size = 0;
    arrayList.capacity = initialCapacity;
    return arrayList;
}

void reallocate(ArrayList *arrayList, int newCapacity) {
    if (arrayList->capacity > newCapacity) {
        return;
    }
    arrayList->data = (int *) realloc(arrayList->data, newCapacity * sizeof(int));
    arrayList->capacity = newCapacity;
}

void add(ArrayList *arrayList, int value) {
    if(arrayList->size == arrayList->capacity) {
        int newCapacity = arrayList->capacity +  (arrayList->capacity >> 1); // 1.5 * arrayList->capacity
        reallocate(arrayList, newCapacity);
    }
    arrayList->data[arrayList->size++] = value;
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    ArrayList arrayList = construct(4);
    getPreorderTraversal(root, &arrayList);
    *returnSize = arrayList.size;
    return arrayList.data;
}

void getPreorderTraversal(struct TreeNode* root, ArrayList *arrayList){
    if(root == NULL) {
        return;
    }
    add(arrayList, root->val);
    getPreorderTraversal(root->left, arrayList);
    getPreorderTraversal(root->right, arrayList);
}


