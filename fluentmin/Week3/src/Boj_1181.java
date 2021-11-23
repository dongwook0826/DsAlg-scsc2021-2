import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.io.BufferedReader;
import java.io.IOException;

public class Boj_1181 {
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int N = Integer.parseInt(br.readLine());
		
		// 중복된 값을 먼저 제거해주기 위해 Set 자료구조 활용 
		Set<String> wordSet = new HashSet<>(); 
		
		for(int i=0; i<N; i++) {
			wordSet.add(br.readLine());
		}
		
		// 길이가 같은 단어들 내에서 사전 순으로 정렬해주기 위한 tmpList 생성 
		List<String> tmpList = new ArrayList<>();
		
		// 단어 길이가 최대 50으로 제한되어 있으므로 1부터 50까지의 단어 길이를 i로 놓고 반복문 돌리기 
		for(int i=1; i<=50; i++) {
			for(String s: wordSet) {
				if(s.length() == i) tmpList.add(s);
			}
			if(!tmpList.isEmpty()) {
				Collections.sort(tmpList);
				for(String t: tmpList) {
					sb.append(t).append('\n');
				}
					tmpList.clear();;
			}
			
		}
		
		System.out.println(sb);
	}

}
