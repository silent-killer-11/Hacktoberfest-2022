// JAVA Code to count number of
// rectangles in N*M grid
import java.util.*;

class GFG {
	
	public static long rectCount(int n, int m)
	{
		return (m * n * (n + 1) * (m + 1)) / 4;
	}
	
	/* Driver program to test above function */
	public static void main(String[] args)
	{
		int n = 5, m = 4;
	System.out.println(rectCount(n, m));
	}
}

// This code is contributed by Arnav Kr. Mandal.
