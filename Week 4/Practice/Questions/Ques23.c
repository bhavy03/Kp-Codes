#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};
struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *dummyHead = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *current = dummyHead;

    while (l1 != NULL && l2 != NULL)
    {
        if (l1->val < l2->val)
        {
            current->next = l1;
            l1 = l1->next;
        }
        else
        {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }

    if (l1 != NULL)
        current->next = l1;
    if (l2 != NULL)
        current->next = l2;

    struct ListNode *result = dummyHead->next;
    free(dummyHead);
    return result;
}

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize)
{
    if (listsSize == 0)
        return NULL;

    struct ListNode *result = lists[0];
    for (int i = 1; i < listsSize; i++)
    {
        result = mergeTwoLists(result, lists[i]);
    }
    return result;
}
