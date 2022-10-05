package lab_4;
import java.util.*;
import java.util.Random;
public class q2 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the value of n");
        int n= sc.nextInt();
        int arr[]=new int[n];
        int ch; int i;
        Random rand = new Random();
        System.out.println("2--Create Random Array");
        System.out.println("1---Quit");
        System.out.println("3---Best case");
        System.out.println("4--Worst Case");
        System.out.println("5--Average Case");
        boolean b=true;
        while (b)
        {
            System.out.println("Enter the Choice");
            ch= sc.nextInt();
            switch (ch)
            {
                case 1:
                    b = false;
                    System.out.println("Quit");
                    break;
                case 2:
                    for (i = 0; i < n; i++) {
                        arr[i] = rand.nextInt(10000);
                    }
                    break;
                case 3: //best
                    //insertion_sort(arr, n);
                    int first=0;
                    int last=arr.length-1;
                    int mid_1=(first+last)/2;
                    int key = arr[mid_1];
                    long a = System.nanoTime();
                    int m=binarySearch(arr,0,last,key);
                    System.out.println("Steps Required in best case = "+m);
                    long z = System.nanoTime();
                    long best_case_time = z - a;
                    //System.out.println("Total time to complete the step in best case = " + best_case_time);
                    System.out.println(m);
                    break;
                case 4: //worst
                    //insertion_sort(arr, n);
                    int key_1=arr[arr.length-1];
                    int last_1=arr.length-1;
                    long c = System.nanoTime();
                    int o=binarySearch(arr,0,last_1,key_1);
                    System.out.println("Steps Required in worst case = "+o);
                    long d = System.nanoTime();
                    long worst_case_time = d - c;
                    //System.out.println("Total time in worst case = " + worst_case_time);
                    System.out.println(o);
                    break;
                case 5:
                    System.out.println("Enter the value to be searched for average case");
                    //insertion_sort(arr, n);
                    int key_2 = sc.nextInt();
                    int last_2=arr.length-1;
                    long e = System.nanoTime();
                    int o1=binarySearch(arr,0,last_2,key_2);
                    System.out.println("Steps Required in average case = "+o1);
                    long f = System.nanoTime();
                    long average_case_time = f - e;
                    //System.out.println("Total time in average case = " + average_case_time);
                    break;
                case 6:
                    long r=System.nanoTime();
                    binarySearch(arr,0,arr.length,23);
                    long t=System.nanoTime();
                    long g=t-r;
                    System.out.println(g);
                    break;
                case 7:
                    insertion_sort(arr,n);
                    for (int j=0;j< arr.length;j++)
                    {
                        System.out.println(arr[j]);
                    }
                    break;
            }
        }
    }
    static int binarySearch(int arr[], int first, int last, int key){
        int count=0;
        count++;
        while( first <= last ){
            count++;
            int mid = (first + last)/2;
            if ( arr[mid] < key ){
                count++;
                first = mid + 1;
            }else if ( arr[mid] == key ){
                count++;
                System.out.println("Element is found at index: " + mid);
                break;
            }else{
                count++;
                last = mid - 1;
            }
            //return count;
        }
        if ( first > last ){
            count++;
            System.out.println("Element is not found!");
        }
        return count;
    }
    static void insertion_sort(int array[], int n) {


        for (int j = 1; j < n; j++) {

            int key = array[j];
            int i = j - 1;

            while ((i > -1) && (array[i] > key)) {

                array[i + 1] = array[i];
                i--;
            }
            array[i + 1] = key;
        }
    }
}
