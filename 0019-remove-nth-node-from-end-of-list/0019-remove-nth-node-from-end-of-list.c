/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    
    struct ListNode * A = head;
    
    int i = 0;

    while (A != NULL) {
        
        A = A -> next;

        i++;

    }

    if (i == n) {

        struct ListNode * novaCabeca = head -> next;

        free (head);

        return novaCabeca;

    }

    int j = 0;
  
    A = head;

    while (j < i - n - 1) {
        
        A = A -> next;

        j++;

    }

    struct ListNode* B = A -> next;

    A -> next = A -> next -> next;

    free (B);

    return head;

}