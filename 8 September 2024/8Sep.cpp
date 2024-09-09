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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length = 0;
        ListNode* current = head;
        while (current != nullptr) {
            length++;
            current = current->next;
        }
        
        int partSize = length / k;
        int remainder = length % k;
        
        vector<ListNode*> result(k, nullptr);
        current = head;
        
        for (int i = 0; i < k && current != nullptr; i++) {
            result[i] = current;
            int currentPartSize = partSize + (i < remainder ? 1 : 0);
            
            for (int j = 1; j < currentPartSize; j++) {
                current = current->next;
            }
            
            ListNode* nextPart = current->next;
            current->next = nullptr;
            current = nextPart;
        }
        
        return result;
    }
};