import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;
import java.io.IOException;
import java.util.StringTokenizer;

public class Boj_17298 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Stack<Integer> stack = new Stack<>();
		StringTokenizer st;
		
		int N = Integer.parseInt(br.readLine());
		
		st =  new StringTokenizer(br.readLine(), " ");
		
		int[] ar = new int[N];
		
		for(int i = 0; i < N; i++) {
			ar[i] = Integer.parseInt(st.nextToken()); //주어진 수열을 배열 형식으로
		}
		
		for(int i = 0; i < N; i++) {
			while(!stack.isEmpty() && ar[stack.peek()] < ar[i]) {
				ar[stack.pop()] = ar[i];
			}
			
			stack.push(i);
		}
		
		while(!stack.isEmpty()) {
			ar[stack.pop()] = -1;
		}
		
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < N; i++) {
			sb.append(ar[i]).append(' ');
		}
		
		System.out.print(sb);
	}
}
