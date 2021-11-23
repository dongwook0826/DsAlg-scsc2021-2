import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.Map;
import java.util.HashMap;
import java.util.StringTokenizer;


public class Boj_18870 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int N = Integer.parseInt(br.readLine());
		int[] ar= new int[N];
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		for(int i=0; i<N; i++) {
			ar[i]= Integer.parseInt(st.nextToken());
		}
		
		Map<Integer, Integer> map = new HashMap<>();
		int cnt = 0;
		
		// ar을 정렬하기 위하여 깊은복사 
		int[] sortedAr = ar.clone();
		Arrays.sort(sortedAr);
		
		for(int i = 0; i < N; i++) {
			// 중복 제외하기 위해 map에 key가 이미 있는 경우를 배제 
			if(!map.containsKey(sortedAr[i])) {
				map.put(sortedAr[i], cnt++);
			}
		}
		
		for(int i = 0; i < N; i++) {
			sb.append(map.get(ar[i])).append(" ");
		}
		
		
		System.out.println(sb);
	}
	
}
