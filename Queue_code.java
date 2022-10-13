import java.util.*;
class MyQueue{
    static int front=0;
    static int rear=0;
    static int capacity=0;
    static int count=0;
    static int arr[];

    MyQueue(int size){
        arr=new int[size];
        capacity=size;
        front=0;
        rear=-1;
        count=0;
    }

    static void enqueue(int data){
        if(rear>capacity){
            System.out.println("Queue full......");
            return;
        }
        else if(rear==-1){
            rear=0;
            arr[rear]=data;
        }
        else{
            rear+=1;
            arr[rear]=data;
        }
        count+=1;
    }
    static int dequeue(){
        int temp=0;
        if(count==0){
            System.out.println("Queue is Empty");
            System.exit(0);
        }
        else{
            temp=arr[front];
            front+=1;
            count-=1;
        }
        return temp;
    }
    static int peek(){
        if(size()==0){
            return 0;
        }
        return arr[front];
    }
    static int size(){
        return count;
    }
    static boolean isEmpty(){
        return (size()==0);
    }
    static boolean isFull(){
        return (rear>capacity);
    }
}


public class Queue {
    static int sliding_window(int arr[], int k){
        int max=Integer.MIN_VALUE;int sum=0;
        Deque<Integer> dq=new LinkedList();
        List<Integer> ll=new ArrayList<>();
        for(int i=0;i<k;i++){
            while(dq.isEmpty() && arr[dq.peekLast()]<=arr[i]){
                dq.removeLast();
            }
            dq.addLast(i);
        }
        ll.add(arr[dq.peekFirst()]);
        for(int i=k;i<arr.length;i++){
            dq.removeFirst();
            
        }

        return max;
    }
    static int noOfSubs(int arr[]){
        int cursum=0,count=0;
        Map<Integer, Integer> s=new HashMap<>();
        for(int i=0;i<arr.length;i++){
            cursum+=arr[i];
            if(s.containsKey(cursum)){
                count+=s.get(cursum);
                s.put(cursum, s.get(cursum)+1);
            }else{
                s.put(cursum, 1);
            }
            
            
        }
        return count;
    }
    public static void main(String[] args) {
        MyQueue m=new MyQueue(10);
        m.enqueue(10);
        m.enqueue(45);
        Random rand=new Random();
        int yourluck=rand.nextInt(7);
        int[] ar={15, -2, 2 ,-8, 1, 7, 10, 23};
        System.out.println(noOfSubs(ar));
        //System.out.println(sliding_window(ar, 3));
    }
}
