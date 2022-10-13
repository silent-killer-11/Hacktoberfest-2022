import java.util.*;
class MyStack {
    static int capacity=0;
    static int top=0;
    static int arr[];

    MyStack(int size){
        arr=new int[size];
        capacity=size;
        top=-1;
    }

    static void push(int data){
        if(top>capacity){
            System.out.println("Stack Overflow");
            return;
        }
        else if(top==-1){
            top=0;
            arr[top]=data;
        }
        else{
            top++;
            arr[top]=data;
        }
    }

    static int pop(){
        int popped_data=0;
        if(top==-1){
            System.out.println("stack is Empty......");
            return -1;
        }
        else{
            popped_data=arr[top];
            top--;
        }
        return popped_data;
    }
    static boolean isFull(){
        if(top>capacity){
            return true;
        }
        else{
            return false;
        }
    }
    static boolean isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
    static int peek(){
        int p=0;
        if(top==-1){
            System.out.println("stack is Empty....");
            return -1;
        }
        else{
            p=arr[top];
        }
        return p;
    }
    static int size(){
        return top+1;
    }
    static int prefixEvaluation(String exp){
        Stack<Integer> sc=new Stack<>();
        for(int i=exp.length()-1;i>=0;i--){
            char c=exp.charAt(i);
            if(Character.isDigit(c)){
                sc.push(Character.getNumericValue(c));
            }
            else{
                int a=sc.peek(); sc.pop();
                int b=sc.peek(); sc.pop();
                if(c=='+'){ sc.push(a+b);}
                else if(c=='-'){ sc.push(Math.abs((a-b)));}
                else if(c=='*'){sc.push((a*b));}
                else{ sc.push((a/b));}
            }
        }
        return sc.peek();
    }
    
}

class stack{
    static int redundantParanthesis(String str){
        Stack<Character> s=new Stack<>();
        for(int i=0;i<str.length();i++){
            char c=str.charAt(i);
            if(c=='(' || c=='+' || c=='-' || c=='/' || c=='*'){
                s.push(c);
            }
            else if(c==')'){
                while(s.peek()!='('){
                    s.pop();
                }
                
            }
        }
        if(s.isEmpty()){
            return 0;
        }else{
            return s.size()/2;
        }
    }
    static int largestRectangle(int[] heights){
        int[] ps=new int[heights.length];
        int[] ns=new int[heights.length];
        Stack<Integer> sc=new Stack<>();
        for(int i=0;i<heights.length;i++){
            while(!sc.isEmpty() && heights[sc.peek()]>heights[i]){
                sc.pop();
            }
            if(!sc.isEmpty()){
                ps[i]=sc.peek();
            }else{
                ps[i]=-1;
            }
            sc.push(i);
        }
        sc=new Stack<>();
        for(int i=0;i<heights.length;i++){
            while(!sc.isEmpty() && heights[sc.peek()]>heights[i]){
                ns[sc.pop()]=i;   
            }
            sc.push(i);

        }
        while(!sc.isEmpty()){
            ns[sc.pop()]=heights.length;
        }
        int ans=0;
        for(int i=0;i<heights.length;i++){
            ans=Math.max(ans, heights[i]*(ns[i]-ps[i]-1));
        }
        return ans;
    }
    static int postfixEvaluation(String str){
        //Stack<Integer> sc=new Stack();
        MyStack sc=new MyStack(str.length());
        for(int i=0;i<str.length();i++){
            char c=str.charAt(i);
            if(Character.isDigit(c)){
                sc.push(Character.getNumericValue(c));
            }
            else{
                int a=sc.peek(); sc.pop();
                int b=sc.peek(); sc.pop();
                if(c=='+'){ sc.push(a+b); }
                else if(c=='-'){ sc.push(Math.abs((a-b)));}
                else if(c=='*'){sc.push((a*b));}
                else{ sc.push((Math.max(a, b)/Math.min(a, b)));}

            }
        }
            return sc.peek();
    }
    static int precedence(char c){
        if(c=='^'){ return 3; }
        else if(c=='+' || c=='-'){ return 1;}
        else if(c=='*' || c=='/'){ return 2; }
        else{ return -1; }
    }
    static String infix_postfix(String str){
        String ans="";
        Stack<Character> sc=new Stack<>();
        for(int i=0;i<str.length();i++){
            char c=str.charAt(i);
            if(c=='('){ sc.push(c); }
            else if(c>='a' && c<='z'){
                ans = ans +c;
            }
            else if(c==')'){
                while(!sc.isEmpty() && sc.peek()!='('){
                    ans=ans+sc.peek();
                    sc.pop();
                }
                sc.pop();
            }
            else{
                if(sc.isEmpty()  || precedence(sc.peek())<precedence(c)){
                    sc.push(c);
                }
                else{
                    while(precedence(sc.peek())>precedence(c)){
                        char ch=sc.pop();
                        if(ch!='('){ ans=ans+ch;}
                    }
                    sc.push(c);
                }
            }
        }
        while(!sc.isEmpty()){
            ans=ans+sc.pop();
        }
        return ans;
    }
    static String infix_prefix(String str){
        String ans="";
        Stack<Character> sc=new Stack<>();
        str=new StringBuilder(str).reverse().toString();
        for(int i=0;i<str.length();i++){
            char c=str.charAt(i);
            if(c==')'){
                sc.push(c);
            }else if(c>='a' && c<='z' || c>='A' && c<='Z'){
                ans=ans+c;
            }else if(c=='('){
                while(!sc.isEmpty() && sc.peek()!='('){
                    if(sc.peek()!=')'){ans=ans+sc.pop();}
                    else{
                        sc.pop();
                    }
                }
                if(!sc.isEmpty()){
                    sc.pop();
                }
            }else{
                while(!sc.isEmpty() && precedence(c)<precedence(sc.peek()) ){
                    ans=ans+sc.pop();
                }
                sc.push(c);
            }

        }
        return new StringBuilder(ans).reverse().toString();
    }
    public static void main(String[] args) {
        int[] arr={2,1,5,6,2,3};
        System.out.println(redundantParanthesis("((a+b)+c)"));
    }
}
//(a-b/c)*(a/k-l)
