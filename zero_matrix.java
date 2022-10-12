import java.util.Scanner;

public class matrix_zero {
    static void revert(int arr[][], int r, int c){
        int rows=arr.length;
        int cols=arr[0].length;
        if(r<0 || c<0 || r>rows || c>cols){
            return;
        }
        arr[r][c]=0;
        revert(arr, r-1, c);
        revert(arr, r+1, c);
        revert(arr, r, c-1);
        revert(arr, r, c+1);
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int matrix[][]=new int[3][3];
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                matrix[i][j]=sc.nextInt();
            }
        }
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                if(matrix[i][j]==0){
                    revert(matrix, i, j);
                }
            }
        }
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                System.out.println(matrix[i][j]);
            }
        }
    }
}
