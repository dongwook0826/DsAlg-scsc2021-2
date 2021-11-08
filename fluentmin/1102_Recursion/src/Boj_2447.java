import java.util.Scanner;

public class Boj_2447 {
	
	public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	
	int N = sc.nextInt();
	
	sc.close();
	
	System.out.print(Star(N));
	}


	public static String Star(int N) {
		if(N == 3) return "***\n* *\n***";
		return Star(N / 3) * 9;
	}

}