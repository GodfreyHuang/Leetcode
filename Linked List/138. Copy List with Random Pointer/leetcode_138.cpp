/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> data; //old to new
        Node *ans = nullptr;
        Node **toA = &ans;
        Node *n = head;

        //透過hashmap來建立舊與新節點的關聯
        while(n)
        {
            data[n] = new Node(n->val); //建立一個全新的節點 且暫不連接next, random。該表同時可以對應節點數值    
            n = n->next;
        }

        n = head;
        while(n)
        {
            data[n]->next = data[n->next]; //獲得舊點對應的新點 將舊點連結的next節點直接讓新點做連接 可以避免新點連到舊點
            data[n]->random = data[n->random];
            n = n->next;
        }

        return data[head];
    }
};