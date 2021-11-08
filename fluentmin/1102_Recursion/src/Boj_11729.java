import java.util.Scanner;

public class Boj_11729 {
	public static StringBuilder sb = new StringBuilder();
	public static void main(String[] args) {
		
		
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		
		sc.close();
		
		move(N, 1, 2, 3);
		
		System.out.println((int)(Math.pow(2, N) - 1));
		System.out.print(sb);
	}
	
	public static void move(int N, int from, int spare, int to) {
		
		if(N == 1) {
			sb.append(from + " " + to + "\n");
		}
		else {
			
			move(N-1, from, to, spare);
			sb.append(from + " " + to + "\n");
			move(N-1, spare, from, to);
			
		}
	}
}
