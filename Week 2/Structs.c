#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Represents an item in the cart
typedef struct item_t
{
    char item_name[100];
    int item_cost;
} item;

int are_strings_equal(char *str1, char *str2)
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            return 0;
        }
        i++;
    }
    return str1[i] == '\0' && str2[i] == '\0';
}

int main()
{
    int n;
    scanf("%d", &n);
    item *cart[100];
    for (int i = 0; i < n; i++)
    {
        cart[i] = (item *)malloc(sizeof(item));
        if (cart[i] == NULL)
        {
            printf("Memory allocation failed.\n");
            return 1;
        }
        scanf(" %[^,],%d", cart[i]->item_name, &cart[i]->item_cost);
    }

    printf("item list\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s,%d\n", cart[i]->item_name, cart[i]->item_cost);
    }
    int total_cost = 0;
    for (int i = 0; i < n; i++)
    {
        total_cost += cart[i]->item_cost;
    }
    printf("Total cost %d\n", total_cost);

    printf("item quantities\n");
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        if (cart[i]->item_cost == -1)
        {
            continue;
        }
        for (int j = i + 1; j < n; j++)
        {
            if (are_strings_equal(cart[i]->item_name, cart[j]->item_name))
            {
                count++;
                cart[j]->item_cost = -1;
            }
        }
        printf("%s - %d\n", cart[i]->item_name, count);
    }
    // this is another way of checking count
    // int counted[100] = {0}; // Array to track counted items
    // for (int i = 0; i < n; i++)
    // {
    // if (counted[i])
    // {
    // continue; // Skip already counted items
    // }
    // int count = 1;
    // for (int j = i + 1; j < n; j++)
    // {
    // if (are_strings_equal(cart[i]->item_name, cart[j]->item_name))
    // {
    // count++;
    // counted[j] = 1; // Mark this item as counted
    // }
    // }
    // printf("%s - %d\n", cart[i]->item_name, count);
    // }

    for (int i = 0; i < n; i++)
    {
        if (cart[i] != NULL)
        {
            free(cart[i]);
        }
    }
    return 0;
}