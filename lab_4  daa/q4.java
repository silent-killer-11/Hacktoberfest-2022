package lab_4;
import java.util.*;
public class q4
{
    //brute force
    public static void brute_find_max_min(int A[])
    {
        int max=A[0];
        int min=A[0];
        for(int i=0;i<A.length;i++)
        {
            if(A[i] > max)
            {
                max=A[i];
            }
            if(A[i] < min)
            {
                min=A[i];
            }
        }
        System.out.println("Maximum element using brute force="+max);
        System.out.println("Minimum element using brute force="+min);
    }

    // Divide and conquer solution to find the minimum and maximum number in an array
    public static void findMinAndMax(int[] A, int left, int right, Pair p)
    {
        // if the array contains only one element

        if (left == right)
        {
            if (p.max < A[left]) {
                p.max = A[left];
            }

            if (p.min > A[right]) {
                p.min = A[right];
            }

            return;
        }
        if (right - left == 1)
        {
            if (A[left] < A[right])
            {
                if (p.min > A[left]) {
                    p.min = A[left];
                }

                if (p.max < A[right]) {
                    p.max = A[right];
                }
            }
            else {
                if (p.min > A[right]) {
                    p.min = A[right];
                }

                if (p.max < A[left]) {
                    p.max = A[left];
                }
            }

            return;
        }
        int mid = (left + right) / 2;
        findMinAndMax(A, left, mid, p);
        findMinAndMax(A, mid + 1, right, p);
    }

    public static void main(String[] args)
    {
        int[] A = { 7, 2, 9, 3, 1, 6, 7, 8, 4 };
        Pair p = new Pair(Integer.MIN_VALUE, Integer.MAX_VALUE);
        long z=System.nanoTime();
        findMinAndMax(A, 0, A.length - 1, p);
        long y=System.nanoTime();
        long x=y-z;
        System.out.println("The minimum array element using Divide and Conquer is " + p.min);
        System.out.println("The maximum array element using Divide and Conquer is " + p.max);
        System.out.println("Time requires using Divide and Conquer="+x);
        System.out.println();
        long m=System.nanoTime();
        brute_find_max_min(A);
        long n=System.nanoTime();
        long o=n-m;
        System.out.println("Time requires using Brute Force="+o);
    }
}