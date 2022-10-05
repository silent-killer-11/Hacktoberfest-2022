package linked_list;

import java.util.*;
class node
{
    int data;
    node next;
}
class ll
{
    node head;
    node tail;
    int size;
    public void add_last(int item)
    {
        node nn=new node();
        nn.data=item;
        nn.next=null;
        if(size==0)
        {
            head=nn;
            tail=nn;
        }
        else
        {
            tail.next=nn;
            tail=nn;
        }
        size++;
    }
    void add_first(int item)
    {
        node nn=new node();
        nn.data=item;
        nn.next=null;
        if(size==0)
        {
            head=nn;
            tail=nn;
        }
        else
        {
            nn.next=head;
            head=nn;
        }
        size++;
    }
    void add_at(int item,int index)
    {
        node nn=new node();
        nn.data=item;
        nn.next=null;
        if(size==0)
        {
            add_first(item);
        }
        else if (index==size)
        {
            add_last(item);
        }
        else if (index<0 || index>size)
        {
            System.out.println("Invalid arguments");
        }
        else
        {
            node temp = this.head;
            for(int i=0;i<index-1;i++)
            {
                temp=temp.next;
            }
            nn.next=temp.next;
            temp.next=nn;
        }
    }
    void remove_first()
    {
        if(size==0)
        {
            System.out.println("Linked list is empty");
        }
        else if(size==1)
        {
           head=tail=null; size=0;
        }
        else
        {
            head=head.next;
            size--;
        }
    }
    void remove_at(int index)
    {
        node temp=this.head;
        if(size==0)
        {
            System.out.println("List is Empty");
        }
        else if(index==size)
        {
            remove_last();
        }
        else
        {
            for(int i=0;i<index-1;i++)
            {
                temp=temp.next;
            }
            temp.next=temp.next.next;
            size--;
        }

    }
    void remove_last()
    {
        if(size==0)
        {
            System.out.println("List is empty");
        }
        else if(size==1)
        {
            head=tail=null;
        }
        else
        {
            node temp=this.head;
            for(int i=0;i<size-1;i++)
            {
                temp=temp.next;
            }
            tail=temp;
            temp.next=null;
        }
    }
    void get_first()
    {
        if(size==0)
        {
            System.out.println("List is empty");
        }
        else
        {
            System.out.println("First element = "+head.data);
        }
    }

    void get_last()
    {
        if(size==0)
        {
            System.out.println("List is empty");
        }
        else
        {
            System.out.println("Last data of the list = "+tail.data);
        }
    }
    void get_at(int index)
    {
        if(size==0)
        {
            System.out.println("List is empty");
        }
        else
        {
            node temp=this.head;
            for(int i=0;i<index;i++)
            {
                temp=temp.next;
            }
            System.out.println("Value at specified index = "+temp.data);
        }
    }
    void get_kth_last(int index)
    {
        node slow=this.head;
        node fast=this.head;
        for(int i=1;i<index;i++)
        {
            fast=fast.next;
        }
        while(fast.next!=null)
        {
            fast=fast.next;
            slow=slow.next;
        }
        System.out.println("Element from last index = "+slow.data);
    }
    void reverse()
    {
        node curr=this.head;
        node prev=null;
        while(curr!=null)
        {
            node next=curr.next;
            curr.next=prev;
            prev=curr;
            curr=next;
        }
        node temp= this.head;
        head=this.tail;
        tail=temp;
    }
    void display()
    {
        System.out.println( );
        node nn=this.head;
        while(nn!=null)
        {
            if(size==0)
            {
                System.out.println("Empty Linked List");
            }
            else
            {
                System.out.print(nn.data+"  ");
                nn=nn.next;
            }
        }
        System.out.println( );
    }
}
public class q1 {
    public static void main(String[] args) {
        ll ob=new ll();
        ob.add_last(10);
        ob.add_last(20);
        ob.add_last(30);
        ob.add_last(40);
        ob.display();
        ob.remove_first();
        ob.display();
        ob.get_first();
        ob.get_last();
        ob.get_at(1);
        ob.add_first(5);
        ob.display();
        ob.add_at(50,1);
        ob.display();
        ob.remove_last();
        ob.display();
        ob.reverse();
        ob.display();
        ob.remove_at(2);
        ob.display();
        ob.get_kth_last(2);
    }
}
