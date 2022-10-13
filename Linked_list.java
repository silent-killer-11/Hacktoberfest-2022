class MyLinkedList{
    static Node head=null;
    static void insert(int data){
       Node current=new Node(data);
        if(head==null){
            head=current;
            head.next=null;
        }
        else{
            Node temp=head;
            while(temp.next!=null){
                temp=temp.next;
            }
            temp.next=current;
        }
    }

    static void printList(){
        Node temp=head;
        while(temp!=null){
            System.out.println(temp.data);
            temp=temp.next;
        }
    }
}
class Linked_List {
    public static void main(String[] args) {
        MyLinkedList m=new MyLinkedList();
        m.insert(20);
        m.insert(28);
        m.insert(56);
        m.printList();
    }
}
class Node{
    int data;
    Node next;
    public Node(int data){
        this.data = data;
        next=null;
    }
}
  
