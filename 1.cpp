#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

int maxPathSumBST(node* root)
{

    if (root == NULL)
        return 0;

    int leftMaxPath = maxPathSumBST(root->left);
    int rightMaxPath = maxPathSumBST(root->right);


    int thisNodeMaxPath = leftMaxPath + rightMaxPath + root->data;

    return max(max(leftMaxPath, rightMaxPath), thisNodeMaxPath);
}

int main()
{

    node n1 = { 10, NULL, NULL };
    node n2 = { 5, &n1, NULL };
    node n3 = { 18, NULL, &n2 };

    cout << maxPathSumBST(&n3);

    return 0;
}