/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* merge(ListNode *h1, ListNode *h2) {
        ListNode* head = NULL;
        if (h1 == NULL) return h2;
        if (h2 == NULL) return h1;
        if (h1->val < h2->val) {
            head = h1;
            h1 = h1->next;
        }
        else {
            head=h2;
            h2 = h2->next;
        }
        ListNode* ptr = head;
        while(h1!=NULL && h2!=NULL) {
            if (h1->val < h2->val) {
                ptr->next = h1;
                h1 = h1->next;
            }
            else {
                ptr = h2->next;
                h2 = h2->next;
            }
            ptr = ptr->next;
        }
        if (h1 != NULL) ptr->next = h1;
        else ptr->next = h2;
        return head;
    }
    ListNode* mergesort(ListNode*head) {
        if (head==NULL || head->next==NULL) return head;
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        ListNode* pre = NULL;
        while (ptr2!=NULL && ptr2->next!=NULL) {
            pre = ptr1;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next->next;
        }
        pre->next = NULL; //´ò¿ªÁ´
        ListNode* h1 = mergesort(head);
        ListNode* h2 = mergesort(ptr1);
        return merge(h1, h2);
    }

public:
    ListNode *sortList(ListNode *head) {
        return mergesort(head);
    }
};
