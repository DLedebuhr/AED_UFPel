/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode * Cabeca = (struct ListNode*) malloc (sizeof(struct ListNode));
    struct ListNode * Corre = Cabeca;

    int Carry = 0;

    while (l1 != NULL || l2 != NULL || Carry) {

        int Somatorio = Carry;

        if (l1 != NULL) {

            Somatorio += l1 -> val;
            l1 = l1 -> next;

        }

        if (l2 != NULL) {

            Somatorio += l2 -> val;
            l2 = l2 -> next;
            
        }

        Carry = Somatorio / 10;

        Corre -> next = (struct ListNode *) malloc (sizeof(struct ListNode));

        Corre = Corre -> next;

        Corre -> val = Somatorio % 10;

        Corre -> next = NULL;

    }

    struct ListNode * Resultado = Cabeca -> next;

    free(Cabeca);

    return Resultado;

}