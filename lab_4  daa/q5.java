package lab_4;
class Pair
{
    public int max, min;

    public Pair(int max, int min)
    {
        this.max = max;
        this.min = min;
    }
}
class Main
{
    public static void findMinAndMax(int[] A, int left, int right, Pair p)
    {
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
        findMinAndMax(A, 0, A.length - 1, p);

        System.out.println("The minimum array element is " + p.min);
        System.out.println("The maximum array element is " + p.max);
    }
}
