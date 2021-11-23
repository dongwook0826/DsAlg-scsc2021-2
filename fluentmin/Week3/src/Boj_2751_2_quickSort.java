import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;

public class Boj_2751_2_quickSort {
	
	// 퀵 정렬을 quickSort 메소드로 구현하였습니다.
	// 실제 채점 시에 시간초과가 발생하는데, 퀵 정렬의 최대 소요시간에 가까운 테스트케이스(=거의 정렬된 배열)가 존재하는 것 같습니다. 
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int N = Integer.parseInt(br.readLine());
		int[] ar = new int[N];
		
		for(int i = 0; i < N; i++) {
			ar[i] = Integer.parseInt(br.readLine());
		}
		
		quickSort(ar);
		
		for(int e: ar) {
			sb.append(e).append('\n');
		}
		
		System.out.print(sb);
	}
	
	public static void quickSort(int[] a) {
		rightPivotSort(a, 0, a.length - 1);
	}
	
	// pivot 값을 가장 오른쪽에 있는 수로 설정하는 rightPivotSort 메소드 
	public static void rightPivotSort(int[] a, int low, int high) {
		if(low >= high) return; // 길이가 1인 배열은 정렬할 필요 없이 곧바로 return 해주기 
		
		int pivot = partition(a, low, high);
		rightPivotSort(a, low, pivot-1);
		rightPivotSort(a, pivot+1, high);
	}
	
	// pivot을 반환하고, pivot을 기준으로 왼쪽과 오른쪽에 배열을 만들어주는 메소드 
	public static int partition(int[] a, int left, int right) {
		int low = left;
		int high = right;
		int pivot = a[right];
		
		while(low < high) {
			while(a[high] > pivot && low < high) {
				high--;
			}
			while(a[low] <= pivot && low < high) {
				low++;
			}
			swap(a, low, high);
		}
		return high;
	}
	
	public static void swap(int[] a, int i, int j) {
		int tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
}
