import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Stack;


public class Boj_4949 {

	public static void main(String[] args) throws IOException {
		InputStreamReader ir = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(ir);
		StringBuilder sb = new StringBuilder();
		
		String s;
		while(true) {
			s = br.readLine();
			if(s.equals(".")) break;
			
			else {
				sb.append(balance(s)).append('\n');
			}
		}
		
		System.out.print(sb);
		
	}
	public static String balance(String str) {
		Stack<Character> stack = new Stack<>();
		
		int N = str.length();
		
		for(int i = 0; i < N; i++) {
			char c = str.charAt(i);
			if(c == '(' || c == '[') {
				stack.push(c);
			}
			
			else if(c == ')') {
				if(stack.isEmpty() || stack.peek() != '(') {
					return "no";
				}
				else stack.pop();			
			}
			
			else if(c == ']') {
				if(stack.isEmpty() || stack.peek() != '[') {
					return "no";
				}
				else stack.pop();
			}
		}
		
		if(stack.empty()) {
			return "yes";
		}
		else {
			return "no";
		}
	
	}
	
}
