/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*4 1 9 5
delete node(1)
    node->val =1 = node ->next->val =9
    1->next =9 = 5
    4 1 5
    
*/
class Solution {
public:
    void deleteNode(ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;         
    }
};
