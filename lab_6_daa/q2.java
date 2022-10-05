package lab_6;
import java.util.*;
public class q2
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int n,i,j;
        System.out.println("Enter no. of activities");
        n=sc.nextInt();
        String a[]=new String[n];
        int start[]=new int[n];
        int finish[]=new int[n];
        for(i=0;i<n;i++)
        {
            System.out.println("Enter activitiy");
            a[i]=sc.next();
            System.out.println("Enter Start time");
            start[i]=sc.nextInt();
            System.out.println("Enter Finish time");
            finish[i]=sc.nextInt();
        }
        System.out.println("Input table");
        System.out.println();
        for(i=0;i<n;i++)
        {
            System.out.print(a[i]+"  5" +
                    "");
        }
        System.out.println();
        for(i=0;i<n;i++)
        {
            System.out.print(start[i]+"   ");
        }
        System.out.println();
        for(i=0;i<n;i++)
        {
            System.out.print(finish[i]+" |");
        }
        System.out.println();
        System.out.println();
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(finish[i]>finish[j])
                {
                    int temp=finish[i];
                    finish[i]=finish[j];
                    finish[j]=temp;

                    int temp1=start[i];
                    start[i]=start[j];
                    start[j]=temp1;

                    String temp2=a[i];
                    a[i]=a[j];
                    a[j]=temp2;
                }
            }
        }
        System.out.println();
        System.out.println("After Sorting");
        System.out.println();
        for(i=0;i<n;i++)
        {
            System.out.print(a[i]+"  ");
        }
        System.out.println();
        for(i=0;i<n;i++)
        {
            System.out.print(start[i]+"  ");
        }
        System.out.println();
        for(i=0;i<n;i++)
        {
            System.out.print(finish[i]+"  ");
        }
        System.out.println();
        System.out.println();
        System.out.println("Output");
        System.out.print(a[0]);
        int x=0;
        System.out.println("Output Order");
        for(i=1;i<n;i++)
        {
            if(start[i]>=finish[x])
            {
                System.out.print("--->"+a[i]);
                x=i;
            }
        }
    }
}