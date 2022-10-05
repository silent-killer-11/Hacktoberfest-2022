package lab_4;

import java.util.Scanner;

public class q6 {
    //brute force
    public static int brute_exponent(int n,int exp)
    {
        int p=1;
        for(int i=1;i<=exp;i++)
        {
            p=p*n;
        }
        return p;
    }
    public static int exponent(int n,int exp)
    {
        if(exp==0)
        {
            return 1;
        }
        int expn1=exponent(n,exp/2);
        int xp=expn1 * expn1;
        if(exp%2==1)
        {
            xp=xp*n;
        }
        return xp;
    }
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        long s=(int)Math.pow(10,3);
        System.out.println("Enter the number and exponent");
        int n=sc.nextInt();
        int exp=sc.nextInt();
        long z=System.nanoTime();
        System.out.println("Exponent using Brute force = "+brute_exponent(n,exp));
        long y=System.nanoTime();
        long x=y-z;
        long x1=x/s;
        System.out.println("Time required in brute force="+x1);
        System.out.println();
        long m=System.nanoTime();
        System.out.println("Exponent using Divide and Conquer force = "+exponent(n,exp));
        long n1=System.nanoTime();
        long o=n1-m;
        long o1=o/s;
        System.out.println("Time required in Divide and Conquer="+o1);
    }
}
