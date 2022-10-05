package lab_5;

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
        System.out.println("4--Sort the array ascending order by heap_sort");
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
                    heap_sort(arr);
                    break;
                case 5:
                    bubble_sort_descending(arr, n);
                    break;
                case 6: // best case
                    long a = System.nanoTime();
                    heap_sort(arr);
                    heap_sort(arr);
                    long z = System.nanoTime();
                    long best_case_time = z - a;
                    System.out.println("Total time to complete the step in best case = " + best_case_time);
                    //System.out.println("Number of steps in best case = " + best_case);
                    break;
                case 7: //worst
                    long c = System.nanoTime();
                    bubble_sort_descending(arr, n);
                    heap_sort(arr);
                    long d = System.nanoTime();
                    long worst_case_time = d - c;
                    //System.out.println("Number of steps in worst case = " + worst_case);
                    System.out.println("Total time in worst case = " + worst_case_time);
                    break;
                case 8: //average
                    long e = System.nanoTime();
                    heap_sort(arr);
                    long f = System.nanoTime();
                    long average_case_time = f - e;
                    //System.out.println("Total number of steps in average case = " + average_case);
                    System.out.println("Total time in average case = " + average_case_time);
                    break;
            }
        }
    }
    public static void heap_sort(int arr[])
    {
        int count=0;
        int n = arr.length;
        count++;
        // Build heap (rearrange array)
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);
        for (int i = n - 1; i > 0; i--) {
            // Move current root to end
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            heapify(arr, i, 0);
        }
    }


    static void heapify(int arr[], int n, int i)
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;


        if (l < n && arr[l] > arr[largest])
            largest = l;


        if (r < n && arr[r] > arr[largest])
            largest = r;


        if (largest != i) {
            int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;


            heapify(arr, n, largest);
        }
    }


    static void printArray(int arr[])
    {
        int n = arr.length;
        for (int i = 0; i < n; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }
    static void bubble_sort_descending(int arr[], int n) {
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
        //return count;
    }
}
