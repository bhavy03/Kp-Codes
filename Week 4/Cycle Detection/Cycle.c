#include <stdio.h>
#include <stdbool.h>
struct Node
{
    int data;
    struct Node *next;
};
bool has_cycle(struct Node *head)
{
    struct Node *slow = head;
    struct Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

// this is to detect the starting point of loop
struct Node *detectCycle(struct Node *head)
{
    struct Node *slow = head;
    struct Node *fast = head;
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {

            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }

    return NULL;
}
