import java.util.Scanner;

public class Boj_10872 {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		sc.close();
		
		int fac = factorial(N);
		System.out.println(fac);
	}
	
	public static int factorial(int N) {
		if(N <= 1) return 1;
		return N * factorial(N-1);
	}
	
}
