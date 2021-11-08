import java.util.Scanner;

public class Boj_11730 {
	public static StringBuilder sb = new StringBuilder();
	public static void main(String[] args) {
		
		
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		
		sc.close();
		
		move(N, 1, 2, 3);
		
		System.out.print(sb);
	}
	
	public static void move(int N, int start, int destination, int spare) {
		
	
		
		if(N == 1) {
			sb.append(start + " " + spare + "\n");
		}
		else {
			
			move(N-1, start, destination, spare);
			sb.append(start + " " + destination + "\n");
			move(N-1, destination, spare, start);
			
		}
	}
}
