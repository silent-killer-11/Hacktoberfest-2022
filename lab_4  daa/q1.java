package lab_4;

import java.util.Random;
import java.util.Scanner;

    public class q1 {
        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            int ch, i;
            Random rand = new Random();
            System.out.println("enter the value of n");
            int n = sc.nextInt();
            int arr[] = new int[n];
            System.out.println("1--Quit");
            System.out.println("2--Create Array");
            System.out.println("3--Display the original array");
            System.out.println("4--Sort the array ascending order by Insertion sort");
            System.out.println("5--Sort the array in any order using any algorithm");
            System.out.println("6--Time complexity to sort the array in best case");
            System.out.println("7--Time complexity to sort the array in worst case");
            System.out.println("8--Time complexity to sort the array in average case");
            boolean b = true;
            while (b) {
                System.out.println("Make your choice");
                ch = sc.nextInt();
                switch (ch) {
                    case 1:
                        b = false;
                        System.out.println("Quit");
                        break;
                    case 2:
                        for (i = 0; i < n; i++) {
                            arr[i] = rand.nextInt(50000);
                        }
                        break;
                    case 3:
                        for (i = 0; i < n; i++) {
                            System.out.println(arr[i]);
                        }
                        break;
                    case 4:
                        merge_sort(arr, 0,9,n);
                        break;
                    case 5:
                        bubble_sort_descending(arr, n);
                        break;
                    case 6: // best case
                        merge_sort(arr, 0,9,n);
                        long a = System.nanoTime();
                        merge_sort(arr, 0,9,n);
                        long z = System.nanoTime();
                        long best_case_time = z - a;
                        System.out.println("Total time to complete the step in best case = " + best_case_time);
                        break;
                    case 7:
                        bubble_sort_descending(arr, n);
                        long c = System.nanoTime();
                        merge_sort(arr, 0,9,n);
                        long d = System.nanoTime();
                        long worst_case_time = d - c;
                        System.out.println("Total time in worst case = " + worst_case_time);
                        break;
                    case 8:
                        long e = System.nanoTime();
                        merge_sort(arr, 0,9,n);
                        long f = System.nanoTime();
                        long average_case_time = f - e;
                        System.out.println("Total time in average case = " + average_case_time);
                        break;
                }
            }

        }

        static void merge_sort(int a[], int beg, int end,int n)
        {
            int mid;
            if(beg<end)
            {
                mid = (beg+end)/2;
                merge_sort(a,beg,mid,n);
                merge_sort(a,mid+1,end,n);
                merge(a,beg,mid,end,n);
            }
        }
        static void merge(int a[], int beg, int mid, int end,int n)
        {
            int i=beg,j=mid+1,k,index = beg;
            int temp[]=new int[n];
            while(i<=mid && j<=end)
            {
                if(a[i]<a[j])
                {
                    temp[index] = a[i];
                    i = i+1;
                }
                else
                {
                    temp[index] = a[j];
                    j = j+1;
                }
                index++;
            }
            if(i>mid)
            {
                while(j<=end)
                {
                    temp[index] = a[j];
                    index++;
                    j++;
                }
            }
            else
            {
                while(i<=mid)
                {
                    temp[index] = a[i];
                    index++;
                    i++;
                }
            }
            k = beg;
            while(k<index)
            {
                a[k]=temp[k];
                k++;
            }
        }
        static int bubble_sort_descending(int arr[], int n) {
            int i, j, temp, count = 0;
            count++;
            for (i = 0; i < n - 1; i++) {
                count++;
                for (j = 0; j < n - i - 1; j++) {
                    count++;
                    if (arr[j] < arr[j + 1]) {
                        count++;
                        temp = arr[j];
                        count++;
                        arr[j] = arr[j + 1];
                        count++;
                        arr[j + 1] = temp;
                        count++;
                    }
                }
            }
            count++;
            return count;
        }

    }

