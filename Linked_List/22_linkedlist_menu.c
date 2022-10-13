#include <stdio.h>
#include <stdlib.h>

struct mynode
{
    int data;
    struct mynode *next;
};

struct mynode *head = NULL;

void insAtFirst();
void insAtEnd();
void insAtPosition();
void delAtFirst();
void delAtEnd();
void delAtPosition();
void display();
void search();

int main()
{
    int choice = 0;
    do
    {
        printf("  Main menu\n1. Insert at first\n2. Insert at end\n3. Insert at position\n4. Delete at first\n5. Delete at end\n6. Delete at position\n7. Display\n8. Search\n9. Exit\nEnter your choice\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            insAtFirst();
            break;
        case 2:
            insAtEnd();
            break;
        case 3:
            insAtPosition();
            break;
        case 4:
            delAtFirst();
            break;
        case 5:
            delAtEnd();
            break;
        case 6:
            delAtPosition();
            break;
        case 7:
            display();
            break;
        case 8:
            search();
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 9);

    return 0;
}

void insAtFirst()
{
    struct mynode *ptr;
    int ele;
    ptr = (struct mynode *)malloc(sizeof(struct mynode));
    if (ptr == NULL)
    {
        printf("Dynamic allocation is not done\n");
    }
    else
    {
        printf("Enter the element which you want to insert at first\n");
        scanf("%d", &ele);
        ptr->data = ele;
        ptr->next = head;
        head = ptr;
    }
}

void insAtEnd()
{
    struct mynode *ptr, *temp;
    int ele;
    ptr = (struct mynode *)malloc(sizeof(struct mynode));
    if (ptr == NULL)
    {
        printf("Dynamic allocation is not done\n");
    }
    else
    {
        printf("Enter the element which you want t insert at end\n");
        scanf("%d", &ele);
        ptr->data = ele;
        if (head == NULL)
        {
            ptr->next = NULL;
            head = ptr;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = NULL;
        }
    }
}

void insAtPosition()
{
    struct mynode *ptr, *temp;
    int ele, pos;
    ptr = (struct mynode *)malloc(sizeof(struct mynode));
    temp = head;
    if (ptr == NULL)
    {
        printf("Dynamic allocation is not done\n");
    }
    else
    {
        printf("Enter the position at which you want to insert the element\n");
        scanf("%d", &pos);
        if (head == NULL)
        {
            if (pos == 1)
            {
                insAtFirst();
            }
            else
            {
                printf("Can't insert\n");
            }
        }
        else if (pos == 1)
        {
            insAtFirst();
        }
        else
        {
            printf("Enter the element which you want to insert at position %d\n", pos);
            scanf("%d", &ele);
            ptr->data = ele;
            int i;
            for (i = 1; i < pos - 1; i++)
            {
                temp = temp->next;
                if (temp == NULL)
                {
                    printf("Can't insert\n");
                    return;
                }
            }
            ptr->next = temp->next;
            temp->next = ptr;
        }
    }
}

void delAtFirst()
{
    struct mynode *ptr;
    int ele;
    if (head == NULL)
    {
        printf("Linked list is empty\n");
    }
    else
    {
        ptr = head;
        head = ptr->next;
        ele = ptr->data;
        printf("The deleted element is %d\n",ele);
        free(ptr);
    }
}

void delAtEnd()
{
    struct mynode *ptr, *temp;
    int ele;
    if (head == NULL)
    {
        printf("Linked list is empty\n");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = NULL;
        ele = ptr->data;
        printf("The deleted element is %d\n",ele);
        free(ptr);
    }
}

void delAtPosition()
{
    struct mynode *ptr, *temp;
    int pos, i , ele;
    printf("Enter the position at which you want to delete the element\n");
    scanf("%d", &pos);
    if (head == NULL)
    {
        printf("Can't delete because linked list is empty\n");
    }
    else if (pos == 1)
    {
        delAtFirst();
    }
    else
    {
        ptr = head;
        for (i = 1; i < pos; i++)
        {
            temp = ptr;
            ptr = ptr->next;
            if (ptr == NULL)
            {
                printf("Can't delete\n");
                return;
            }
        }
        temp->next = ptr->next;
        ele = ptr->data;
        printf("The deleted element is %d\n",ele);
        free(ptr);
    }
}

void display()
{
    struct mynode *ptr;
    int count = 0;
    ptr = head;
    if (ptr == NULL)
    {
        printf("Linked list is empty\n");
    }
    else
    {
        printf("Printing the linked list..\n");
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
            count++;
        }
        printf("\nThe number of nodes - %d\n",count);
        int a[count] , i=0;
        ptr = head;
        while (ptr!=NULL)
        {
            a[i] = ptr->data;
            ptr = ptr->next;
            i++;
        }
        printf("Printing linked list in reverse order\n");
        for (int j = count-1; j >= 0; j--)
        {
            printf("%d ",a[j]);
        }
        printf("\n");
        
    }
}

void search()
{
    struct mynode *ptr;
    int i, ele, pos, found = 0;
    ptr = head;
    if (ptr == NULL)
    {
        printf("Linked list is empty\n");
    }
    else
    {
        printf("Enter the element which you want search\n");
        scanf("%d", &ele);
        i = 1;
        while (ptr != NULL)
        {
            if (ptr->data == ele)
            {
                found++;
                break;
            }
            ptr = ptr->next;
            i = i + 1;
        }
        if (found == 1)
        {
            printf("The element %d is found at position %d\n", ele, i);
        }
        else
        {
            printf("The element %d is not found\n", ele);
        }
    }
}