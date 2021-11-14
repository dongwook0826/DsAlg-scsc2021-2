import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;
import java.io.IOException;

public class Boj_1874_1 {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		Stack<Integer> stack = new Stack<>();
		
		int N = Integer.parseInt(br.readLine());
		int count = 0;
		int valueMemo = 0; //스택에 어떤 값을 추가(push)해야 하는지 기억해두는 변수 
		
		while(count < N) {
			
			int number = Integer.parseInt(br.readLine());
			
			if(number > valueMemo) {
				for(int i = valueMemo+1; i <= number; i++) {
					stack.push(i);
					sb.append('+').append('\n');
				}
				valueMemo = number; //주어진 number까지 push하였다
			}
			
			else if(number != stack.peek()) {
				sb.setLength(0);
				sb.append("No");
				break;
			}
			
			stack.pop();
			sb.append('-').append('\n');
			count++;
		}
		
		System.out.println(sb);
	}

}
