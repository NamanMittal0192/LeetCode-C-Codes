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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* sorted = nullptr;

        while (head != nullptr) {
            ListNode* temp = head->next;
            sorted = insert(sorted, head);
            head = temp;
        }

        return sorted;
    }

    ListNode* insert(ListNode* sorted, ListNode* node) {
        if (!sorted || node->val <= sorted->val) {
            node->next = sorted;
            return node;
        }

        ListNode* current = sorted;
        while (current->next && current->next->val < node->val) {
            current = current->next;
        }

        node->next = current->next;
        current->next = node;

        return sorted;
    }
};
