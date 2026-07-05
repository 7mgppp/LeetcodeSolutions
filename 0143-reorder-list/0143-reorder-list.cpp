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
    void reorderList(ListNode* head) {
        //n = 5; 0->5->1->4->2->3
        //Find the middle of the linked list. [done]
        //Reverse the second half. []
        //Merge the two halves alternately. []

        if(head == nullptr || head->next == nullptr){
            return;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        slow->next = nullptr;

        ListNode* prev = NULL;
        while(second!= NULL){
            ListNode* next = second->next;
            second->next = prev;
            prev = second;
            second = next;
        }

        second = prev;

        ListNode* first = head;

        while(second!= nullptr){
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;


        }
        
    }
};