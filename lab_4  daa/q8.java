package lab_4;


public class q8
{
    /* function that consider last element as pivot,
place the pivot at its exact position, and place
smaller elements to left of pivot and greater
elements to right of pivot.  */
    int partition (int a[], int start, int end)
    {
        int pivot = a[end]; // pivot element
        int i = (start - 1);

        for (int j = start; j <= end - 1; j++)
        {
            // If current element is smaller than the pivot
            if (a[j] < pivot)
            {
                i++; // increment index of smaller element
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
        int t = a[i+1];
        a[i+1] = a[end];
        a[end] = t;
        return (i + 1);
    }

    /* function to implement quick sort */
    void quick(int a[], int start, int end,int cnt,int finallevel) /* a[] = array to be sorted, start = Starting index, end = Ending index */
    {
        if (start < end)
        {
            if (cnt <= finallevel)
            {
                int p = partition(a, start, end);
            }
            else
            {
                return;
            }
            int p = partition(a, start, end);  //p is partitioning index
            quick(a, start, p - 1,cnt+1,finallevel);
            quick(a, p + 1, end,cnt+1,finallevel);
        }
    }

    /* function to print an array */
    void printArr(int a[], int n)
    {
        int i;
        for (i = 0; i < n; i++)
            System.out.print(a[i] + " ");
    }
    public static void main(String[] args) {
        int a[] = { 13, 18, 27, 2, 19, 25 };
        int n = a.length;
        System.out.println("\nBefore sorting array elements are - ");
        q8 q1 = new q8();
        q1.printArr(a, n);
        q1.quick(a, 0, n - 1,0,2);
        System.out.println("\nAfter sorting array elements are - ");
        q1.printArr(a, n);
        System.out.println();
    }
}