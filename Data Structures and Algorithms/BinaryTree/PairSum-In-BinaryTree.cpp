/*
Pair sum BInary Tree

Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.
Assume binary tree contains all unique elements.
Note : In a pair, print the smaller element first. Order of different pair doesn't matter.
Input format :
Line 1 : Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Line 2 : Integer S
Output Format :
Each pair in different line (pair elements separated by space)
Constraints :
1 <= N <= 1000
Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
15
Sample Output 1:
5 10
6 9

*/
#include "CommonTemplate.h"
BinaryTreeNode<int> *takeInput()
{
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

// Using map and array

// int k = 0;
// void nodesSumToSHelper(BinaryTreeNode<int> *root, int *arr)
// {
//     if (!root)
//         return;
//     nodesSumToSHelper(root->left, arr);
//     arr[k] = root->data;
//     k = k + 1;
//     nodesSumToSHelper(root->right, arr);
// }

// void nodesSumToS(BinaryTreeNode<int> *root, int sum)
// {
//     int arr[1000000];
//     nodesSumToSHelper(root, arr);
//     unordered_map<int, int> mp;
//     for (int i = 0; i < k; i++)
//     {
//         mp[arr[i]]++;
//     }
//     for (int i = 0; i < k; i++)
//     {
//         if (mp[sum - arr[i]] > 0)
//         {
//             int l = mp[sum - arr[i]] * mp[arr[i]];
//             while (l--)
//             {
//                 cout << min(sum - arr[i], arr[i]) << " " << max(sum - arr[i], arr[i]) << endl;
//             }
//             mp[sum - arr[i]] = 0, mp[arr[i]] = 0;
//         }
//     }
// }

//Using only map No Array
unordered_map<int, int> mp;
void nodesSumToS(BinaryTreeNode<int> *root, int sum)
{
    if (!root)
        return;
    nodesSumToS(root->left, sum);
    mp[root->data]++;
    if (mp[sum - root->data])
    {
        int l = mp[root->data] * mp[sum - root->data];
        while (l--)
        {
            cout << min(sum - root->data, root->data) << " " << max(sum - root->data, root->data) << endl;
        }
        mp[sum - root->data] = 0, mp[root->data] = 0;
    }
    nodesSumToS(root->right, sum);
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    int sum;
    cin >> sum;
    nodesSumToS(root, sum);
    delete root;
}