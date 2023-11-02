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
        // this problem is really easy to solve by iterate twice but the key point for this question is using two pointers
        if (head->next == nullptr) {
            return nullptr;
        }
        ListNode* fast;
        ListNode* slow;
        fast = head;
        int count = n;
        // count guranteed by the question to be smaller than size
        while (count > 0) {
            fast = fast->next;
            count--;
        }
        // here is a problem that is slow move at the same speed, we cant delete the node since it has passed
        // but if we want slow to move one step slower, we need to consider the situation that fast is already at NULL
        if (fast == nullptr) {
            return head->next;
        }
        // then fast should go one step further
        fast = fast->next;
        slow = head;
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};

//a smarter solution by chatGPT (or others) to use a dummy node to avoid the above special case
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Use a dummy node to simplify head removal
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast n steps ahead
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move fast to the end while keeping slow n steps behind
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove the nth node
        slow->next = slow->next->next;

        // Get the new head after potential head removal
        head = dummy->next;

        delete dummy;  // Free the dummy node

        return head;
    }
};