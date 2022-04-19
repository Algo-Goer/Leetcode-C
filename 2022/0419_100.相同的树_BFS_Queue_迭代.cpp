/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 */

// @lc code=start
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

// code2 BFS/Queue/迭代

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;
        else if (!p || !q)
            return false;
        queue<TreeNode *> q1, q2;
        q1.push(p);
        q2.push(q);
        while (!q1.empty() && !q2.empty())
        {
            TreeNode *p1 = q1.front();
            q1.pop();
            TreeNode *p2 = q2.front();
            q2.pop();
            if (p1->val != p2->val)
                return false;
            auto l1 = p1->left, r1 = p1->right, l2 = p2->left, r2 = p2->right;
            // 如果两个根结点值相同，则判断两个结点的子结点是否为空。如果只有一个结点的左孩子为空，则不相同
            if ((l1 && !l2) || (!l1 && l2))
                return false;
            if ((r1 && !r2) || (!r1 && r2))
                return false;
            if (l1)
                q1.push(l1);
            if (r1)
                q1.push(r1);
            if (l2)
                q2.push(l2);
            if (r2)
                q2.push(r2);
        }
        return true;
    }
};
// @lc code=end
