/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        return func(head, nullptr);
    }

    TreeNode* func(ListNode* head, ListNode* tail)
    {
        if(head == tail) //已經分到最細
            return nullptr;
        
        //需要先找到最中間的點
        ListNode *mid = head, *find = head;
        while(find != tail && find->next != tail) //快指針到底即停止
        {
            mid = mid->next;
            find = find->next->next;
        }

        TreeNode *node = new TreeNode(mid->val); //建立BS樹
        node->left = func(head, mid); //Divide and conquer
        node->right = func(mid->next, tail);
        return node;
    }
};