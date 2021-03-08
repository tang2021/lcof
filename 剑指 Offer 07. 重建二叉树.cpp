// 剑指 Offer 07. 重建二叉树
// 输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
// 例如，给
// 前序遍历 preorder = [3,9,20,15,7]
// 中序遍历 inorder = [9,3,15,20,7]
// 返回如下的二叉树：
//     3
//    / \
//   9  20
//     /  \
//    15   7
// 限制：
// 0 <= 节点个数 <= 5000
#include<vector>
#include<map>
using namespace std;
typedef struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int v):val(v),left(NULL),right(NULL){}
};


TreeNode* rebuild(vector<int> &pre,vector<int> &inv,int r,int start,int end){
    if(start>end)return NULL;
    int n=pre.size();
    TreeNode* root=new TreeNode(pre[r]);
    int i=start;
    while(i<n&&pre[r]!=inv[i])i++;
    root->left=rebuild(pre,inv,r+1,start,i-1);
    root->right=rebuild(pre,inv,r+1+i-start,i+1,end);
}
TreeNode* rebuildTree(vector<int>preorder,vector<int>inorder){
    int n = preorder.size();
    return rebuild(preorder,inorder,0,0,n-1);
}
map<int,int>m;
TreeNode* rebuildTree1(vector<int>preorder,vector<int>inorder){
    int n=preorder.size();
    for(int i=0;i<n;i++)
    m[inorder[i]]=i;
    return rebuild1(preorder,inorder,0,0,n-1);
}
TreeNode* rebuild1(vector<int>&pre,vector<int>&inv,int r,int start,int end){
    if(start>end)return NULL;
    TreeNode* root=new TreeNode(pre[r]);
    int i=m[pre[r]];
    root->left=rebuild1(pre,inv,r+1,start,i-1);
    root->right=rebuild1(pre,inv,r+1+i,i+1,end);
}
