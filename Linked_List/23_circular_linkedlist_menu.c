#include<stdio.h>
#include<stdlib.h>

struct cnode
{
    int data;
    struct cnode*next;
};

struct cnode*head = NULL;

void display();
void insAtFirst();
void insAtEnd();
void insAtPosition();
void delAtFirst();
void delAtEnd();
void delAtPosition();

int main()
{
    int choice = 0;
    do
    {
        printf("   Main menu\n1. Insert at first\n2. Insert at end\n3. Insert at position\n4. Delete at first\n5. Delete at end\n6. Delete at position\n7. display\n8. exit\n\n  Enter your choice : ");
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
            exit(0);
            break;
        default:
            printf("Invalid input\n");
            break;
        }
    } while (choice != 8);
    
    // insAtEnd();
    // insAtFirst();
    // insAtPosition();
    // display();
    // delAtFirst();
    // insAtPosition();
    // insAtFirst();
    // insAtFirst();
    // insAtFirst();
    // insAtFirst();
    // display();
    // delAtEnd();
    // display();
    // delAtPosition();
    // display();
    // delAtPosition();
    // display();
    // delAtPosition();
    // display();

    // insAtFirst();
    // insAtEnd();
    // display();
    return 0;
}

void display()
{
    struct cnode*ptr;
    if (head == NULL)
    {
        printf("Linked list is empty\n");
    }
    else
    {
        ptr = head->next;
        do
        {
            printf("%d ",ptr->data);
            ptr = ptr->next;
        } while (ptr != head->next);
    }
    printf("\n");
}

void insAtFirst()
{
    struct cnode*ptr;
    int ele;
    ptr = (struct cnode*)malloc(sizeof(struct cnode));
    if (ptr == NULL)
    {
        printf("Dynamic allocation is not done\n");
    }
    else
    {
        printf("Enter the element which you want to insert at first\n");
        scanf("%d",&ele);
        if (head == NULL)
        {
            ptr->data = ele;
            ptr->next = ptr;
            head = ptr;
        }
        else
        {
            ptr->data = ele;
            ptr->next = head->next;
            head->next = ptr;
        }
    }
}

void insAtEnd()
{
    struct cnode*ptr;
    int ele;
    ptr = (struct cnode*)malloc(sizeof(struct cnode));
    if (ptr == NULL)
    {
        printf("Dynamic allocation is not done\n");
    }
    else
    {
        printf("Enter the element which you want to insert at end\n");
        scanf("%d",&ele);
        if (head == NULL)
        {
            ptr->data = ele;
            ptr->next = ptr;
            head = ptr;
        }
        else
        {
            ptr->data = ele;
            ptr->next = head->next;
            head->next = ptr;
            head = ptr; 
        }
    }
}

void insAtPosition()
{
    struct cnode*ptr , *temp;
    int pos , ele;
    ptr = (struct cnode*)malloc(sizeof(struct cnode));
    if (ptr == NULL)
    {
        printf("Dynamic allocation is not done\n");
    }
    else
    {
        printf("Enter the position at which you want to insert the element\n");
        scanf("%d",&pos);
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
            printf("Enter the element which you want to insert at position %d\n",pos);
            scanf("%d",&ele);
            ptr->data = ele;
            temp = head->next;
            for (int i = 1; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            if (temp == head)
            {
                ptr->next = head->next;
                head->next = ptr;
                head = ptr;
            }
            else
            {
                ptr->next = temp->next;
                temp->next = ptr;    
            }
        }   
    }
}

void delAtFirst()
{
    struct cnode*ptr;
    int ele;
    if (head == NULL)
    {
        printf("Linked list is empty\n");
    }
    else
    {
        if (head->next == head )
        {
            ptr = head;
            ele = ptr->data;
            printf("The deleted element is %d\n",ele);
            free(ptr);
            head = NULL;
        }
        else
        {
            ptr = head->next;
            head->next = ptr->next;
            ele = ptr->data;
            printf("The deleted element is %d\n",ele);
            free(ptr);
        }
    }
}

void delAtEnd()
{
    struct cnode*ptr , *temp;
    int ele;
    if (head == NULL)
    {
        printf("Can't delete because linked list is empty\n");
    }
    else
    {
        if (head->next == head)
        {
            ptr = head;
            ele = ptr->data;
            printf("The deleted element is %d\n",ele);
            free(ptr);
            head = NULL; 
        }
        else
        {
            temp = head;
            ptr = temp->next;
            while (ptr->next != temp)
            {
                ptr = ptr->next;
            }
            ptr->next = temp->next;
            ele = temp->data;
            printf("The deleted element is %d\n",ele);
            free(temp);
            head = ptr;
        }
    }
}

void delAtPosition()
{
    struct cnode*ptr , *pptr , *temp;
    int pos , ele;
    if (head == NULL)
    {
        printf("Can't delete becuse linked list is empty\n");
    }
    else
    {
        printf("Enter the position at which you want to delete the element\n");
        scanf("%d",&pos);
        if (pos == 1)
        {
            delAtFirst();
        }
        else
        {
            ptr = head->next;
            for (int i = 1; i < pos; i++)
            {
                pptr = ptr;
                ptr = ptr->next;
            }
            if (ptr == head)
            {
                temp = head;
                pptr->next = temp->next;
                ele = temp->data;
                printf("The deleted element is %d\n",ele);
                free(temp);
                head = pptr;
            }
            else
            {
                pptr->next = ptr->next;
                ele = ptr->data;
                printf("The deleted element is %d\n",ele);
                free(ptr);
            }
        }
    }
}