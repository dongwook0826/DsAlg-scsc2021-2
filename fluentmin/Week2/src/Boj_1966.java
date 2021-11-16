import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.io.IOException;
import java.util.StringTokenizer;

public class Boj_1966 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st1, st2; //st1은 테스트케이스의 첫 번째 줄, st2는 테스트케이스의 두 번째 줄 
		StringBuilder sb = new StringBuilder();
		
		
		int testCase = Integer.parseInt(br.readLine());
		
		while(testCase-- > 0) {
			Queue<Integer> queue = new LinkedList<>();
			st1 = new StringTokenizer(br.readLine(), " ");
			int N = Integer.parseInt(st1.nextToken());
			int M = Integer.parseInt(st1.nextToken());
			int[] ar = new int[N];
			
			st2 = new StringTokenizer(br.readLine(), " ");
			for(int i = 0; i < N; i++) {
				ar[i] = Integer.parseInt(st2.nextToken()); //테스트케이스의 두 번째 줄(중요도)의 배열 
				queue.offer(i);//각각의 배열 원소의 인덱스에 해당하는 큐 
			}
			
			/*
			찾고 싶은 것: ar[M]의 출력 순서 
			ar의 인덱스에 대응하는 queue 이용하기
			만약 배열의 첫번째 수보다 큰 수가 있다면, 그 사이에 있는 수들을 poll하여 뒤로 offer하기 
			배열의 첫번째 수보다 크거나 같은 수가 나온다면, poll하고 result 1추가 
			이 과정을 M이 poll 될 때까지 반복하고 난 뒤 result 출력 
			
			*/
			int result = 0;
			
			for(int i = 0; i < queue.size(); i++) {
				int first = queue.peek();
				int q = ar[first];
				
				if(q < ar[i]) {
					for(int j = 0; j < i; j++) {
						queue.offer(queue.poll());
					}
				}
				
				else {
					if(first != M) {
						queue.poll();
						result++;
						continue;
					}
				
					else {
						
						break;
					}
				}
			}
			sb.append(result + 1).append('\n');
			
		}
		System.out.println(sb);
	}

}
