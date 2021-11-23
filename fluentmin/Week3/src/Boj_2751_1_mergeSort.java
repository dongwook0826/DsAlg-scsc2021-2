import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;

public class Boj_2751_1_mergeSort {
	
	// 병합 정렬을 mergeSort 메소드로 구현하였습니다. 
	
	public static int[] sorted;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int N = Integer.parseInt(br.readLine());
		int[] ar = new int[N];
		
		for(int i = 0; i < N; i++) {
			ar[i] = Integer.parseInt(br.readLine());
		}
		
		mergeSort(ar);
		
		for(int e: ar) {
			sb.append(e).append('\n');
		}
		
		System.out.print(sb);
	}
	
	
	// 병합 정렬 구현 
	public static void mergeSort(int[] a) {
		sorted = new int[a.length];
		mergeSort(a, 0, a.length - 1);
		sorted = null;
	}
	
	public static void mergeSort(int[] a, int left, int right) {
		if(left == right) return;
		
		int mid = (left + right) / 2;
		
		mergeSort(a, left, mid);
		mergeSort(a, mid+1, right);
		merge(a, left, mid, right);
		
	}
	
	private static void merge(int[] a, int left, int mid, int right) {
		int l = left;
		int r = mid + 1;
		int idx = left;
		
		while(l <= mid && r <= right) {
			if(a[l] <= a[r]) {
				sorted[idx] = a[l];
				idx++;
				l++;
			}
			else {
				sorted[idx] = a[r];
				idx++;
				r++;
			}
		}
		
		if(l > mid) {
			while(r <= right) {
				sorted[idx] = a[r];
				idx++; r++;
			}
		}
		else {
			while(l <= mid) {
				sorted[idx] = a[l];
				idx++; l++;
			}
		}
		for(int i = left; i <= right; i++) {
			a[i] = sorted[i];
		}
	}
		
	
}
