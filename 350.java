
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class Main implements Callable<Integer> {

	private int Z, I, M, L;

	public Main(int z, int i, int m, int l) {
		Z = z;
		I = i;
		M = m;
		L = l;
	}

	public static void main(String[] args) throws Exception {

		ExecutorService pool = Executors.newFixedThreadPool(20);
		List<Future<Integer>> results = new ArrayList<Future<Integer>>();

		Scanner scan = new Scanner(System.in);
		while (scan.hasNext()) {
			int Z = scan.nextInt(), I = scan.nextInt(), M = scan.nextInt(), L = scan
					.nextInt();
			if(Z==0 && I == 0 && M == 0 && L == 0) break;
			results.add(pool.submit(new Main(Z, I, M, L)));
		}

		int t = 1;
		for (Future<Integer> f : results) {
			System.out.println(String.format("Case %d: %d", t++, f.get()));
		}
		pool.shutdown();

	}

	@Override
	public Integer call() throws Exception {
	
		int l2 = L;
		int c = 0;
		do
		{
			L = (Z * L + I) % M;
			l2 = (Z * l2 + I) % M;
			l2 = (Z * l2 + I) % M;
			c++;
		}while(l2 != L);
		return c;
	}

}
