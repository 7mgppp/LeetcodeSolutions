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
    bool isPalindrome(ListNode* head) {

        ListNode* end = head;
        vector<int>v;

        while(end != nullptr){
            v.push_back(end->val);
            end = end->next;
        }

        int left = 0;
        int right = v.size()-1;

        while(left < right){
            if(v[left] != v[right]){
                return false;
            }
            left++;
            right--;
            
        }

        return true;


        
    }
};