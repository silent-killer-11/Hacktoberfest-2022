import java.util.Arrays;

public class recursion {

    static void down(int n){
        if(n==0){ return; }        
        
        System.out.println(n);
        down(n-1);
    }

    static void up(int n){
        if(n==0){ return; }

        up(n-1);
        System.out.println(n);
    }
    static void pdi(int n){
        if(n==0){
            return;
        }
       
        System.out.println(n);
        pdi(n-1);
        System.out.println(n);
    }
    static void pdiskip(int n){
        if(n==0){ return; }
        if(n%2==1){
            System.out.println(n);
        } 
        pdiskip(n-1);
        if(n%2==0){
            System.out.println(n);
        }
    }
    static int fact(int n){
        if(n==0){
            return 1;
        }
        return n*fact(n-1);
    }

    static int fib(int n){
        if(n==1){ return 1; }
        if(n==0){ return 0; }
        return fib(n-1)+fib(n-2);
    }

    static boolean isSorted(int arr[], int i){
        if(i==arr.length-2){
            return true;
        }
        if(arr[i]<arr[i+1] && isSorted(arr, i+1)){
            return true;
        }
        else{
            return false;
        }
    }

    static int last_index(int arr[] ,int element,int i){
        
        if(i==arr.length){
            return -1;
        }
        int ans=last_index(arr, element, i+1);
        if(ans==-1){
            if(arr[i]==element){
                return i;
            }
            else{
                return -1;
            }
        }
        else{
            return ans;
        }
    }

    // public static int[] allindices(int arr[], int element,int index, int count){
        
    //     if(index==arr.length){
    //         int[] indices=new int[count];
           
    //     }

    //     if(arr[index]==element){
    //         allindices(arr, element, index+1, count+1);
    //     }
    //     else{
    //         allindices(arr, element, index+1, count);
    //     }

    //     if(arr[index]==element){
    //         indices[count]=index;
    //     }
    //     return indices;
    // }

    static void pattern(int n, int row, int coloumn){
        if(coloumn>n){ return; }

        if(row<=coloumn){
            System.out.print("*"+" ");
            pattern(n, row+1, coloumn);
        }
        else{
            row=1;
            System.out.println();
            pattern(n ,row, coloumn+1);
        }
    }
    static String swap(String str, int i, int j){
        char[] t=str.toCharArray();
        char temp=t[i];
        t[i]=t[j];
        t[j]=temp;
        String st="";
        for(char c: t){
            st=st+c;
        }
        return st;
    }
    static void bubble_sort(int arr[] , int i, int n){
        if(n==0){ return; }
        if(i==n){
            bubble_sort(arr, 0, n-1);
            return;
        }
        if(arr[i]>arr[i+1]){
            int temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
        bubble_sort(arr, i+1, n);
        
        
    }
    static int str_to_int(String s, int i, int n, int temp){
        if(s.length()==0){
            return temp;
        }

        return (temp*10)+Character.getNumericValue(s.charAt(i))+str_to_int(s, i+1, n ,temp);
    }

    static void getSubSequence(String str, int i, String cur){
        if(i==str.length()){
            System.out.println(cur);
            return;
        }

        getSubSequence(str, i+1, cur+str.charAt(i));
        getSubSequence(str, i+1, cur);
    }
    static void permutations(String str, int i, int n){
        //base case
        if(i==n){
            System.out.println(str);
            return;
        }
        //recursive case
        for(int j=i;j<=n;j++){
            str=swap(str, i, j);
            permutations(str, i+1, n);
            str=swap(str, i, j);
        }
    }
    static void convertpi(char[] s, int i ,int n){
        if(i==n){
            return;
        }
        if(s[i]=='p' && s[i+1]=='i'){
            System.out.print("3.14");
            convertpi(s, i+2, n);
        }
        else{
            System.out.print(s[i]);
            convertpi(s, i+1, n);
        }
    }
    
    static void towerOfHanoi(int n ,char source, char destination, char helper){
        if(n==0){
            return;
        }
        System.out.println("movement from "+source+" to "+destination);
        towerOfHanoi(n-1, source, helper, destination);
        towerOfHanoi(n-1, helper, destination, source);
    }
    
    static String removeDuplicates(String str){
        if(str.length()==0){
            return "";
        }

        char ch=str.charAt(0);
        String ans=removeDuplicates(str.substring(1));
        if(ch==ans.charAt(0)){
            return ans;
        }
        
        return ch+ans;
        
    }
    public static void main(String[] args){
        
        String s="pipiiiiipiipipi";
        // String cur="";
        // permutations(s, 0, s.length()-1);
        // towerOfHanoi(3, 'A', 'C', 'B');
        // convertpi(s.toCharArray(), 0, s.length());
        System.out.println(removeDuplicates(s));
    }   
}
