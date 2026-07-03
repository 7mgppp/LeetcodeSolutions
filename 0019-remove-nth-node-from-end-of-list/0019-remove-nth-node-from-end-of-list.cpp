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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr || head->next == nullptr){
            return nullptr;
        }

        ListNode* temp = head;
        int count = 0;

        while(temp){
            count++;
            temp = temp->next;
        }

        if(count == n){
            ListNode* delu = head;
            head = head->next;
            return head;
        }

        int fuck = count - n;

        temp = head;

        for(int i = 1; i<fuck; i++){
            temp = temp->next;
        }

        ListNode* delu = temp->next;
        temp->next = temp->next->next;
        delete delu;

        return head;


        
    }
};