package lab_4;

public class q7 {
    static void merge_sort(int a[], int beg, int end,int cnt,int finalLevel)
    {

        if(beg<end) {
            int mid = (beg + end) / 2;
            merge_sort(a, beg, mid,cnt+1,finalLevel);
            merge_sort(a, mid + 1, end,cnt+1,finalLevel);
            if (cnt >= finalLevel)
                merge(a, beg, mid, end);
            else
                return;
        }
    }

    static void merge(int a[], int beg, int mid, int end)
    {
        int i=beg,j=mid+1,k,index = beg;
        int temp[]=new int[a.length];
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

    static void printArray(int arr[])
    {
        int n = arr.length;
        for (int i=0; i<n; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }

    public static void main(String args[])
    {
        int arr[] = {0,3,1,5,8,2,4,6,7};
        int n=arr.length;

        System.out.println("Given Array");
        printArray(arr);

        q7 ob = new q7();
        ob.merge_sort(arr, 0, arr.length-1,0,3);

        System.out.println("\nArray condition at the "+ 3 + " level : ");
        printArray(arr);
    }
}