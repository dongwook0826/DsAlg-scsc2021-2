import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.io.IOException;
import java.util.StringTokenizer;

public class Boj_11866 {
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Queue<Integer> queue = new LinkedList<>();
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		StringBuilder sb = new StringBuilder();
		sb.append('<');
		
		// 1부터 N까지의 수를 담은 큐 만들기 
		for(int i = 1; i < N + 1; i++) {
			queue.offer(i);
		}
		
		// N회 시행하며 큐에서 하나씩 수를 빼서 StringBuilder에 넣어주기 
		while(N-- > 0) {
			for(int i = 1; i < K + 1; i++) {
				if(i != K) {
					queue.offer(queue.poll());
				}
				else {
					sb.append(queue.poll()).append(", ");
				}
			}
		}
		sb.reverse().delete(0, 2).reverse().append('>');
		System.out.println(sb);
	}

}
