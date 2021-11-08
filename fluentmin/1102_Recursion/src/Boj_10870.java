import java.util.Scanner;

public class Boj_10870 {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        sc.close();
        
        int fb = fibo(N + 1);
        System.out.println(fb);
    }

    public static int fibo(int N) {
        if(N == 1) return 0;
        if(N == 2) return 1;
        return fibo(N-1) + fibo(N-2);
    }
    
}
