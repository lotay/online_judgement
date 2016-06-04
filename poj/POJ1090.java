import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	static int rings[] = null;
	static BigInteger steps[] = null;
	static BigInteger ONE = new BigInteger("1");
	static BigInteger ZERO = new BigInteger("0");
	static int n;

	static void init() {
		steps[0] = new BigInteger("0");
		for (int i = 1; i <= n; i++) {
			steps[i] = steps[i - 1].shiftLeft(1).add(ONE);
		}
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		n = scanner.nextInt();
		rings = new int[n + 1];
		steps = new BigInteger[n + 1];
		init();
		for (int i = 1; i <= n; i++) {
			rings[i] = scanner.nextInt();
		}
//		solve();
		System.out.println(off(n));
		scanner.close();
	}
	static BigInteger on(int k) {
		if (k == 1) {
			if (rings[k] == 0)
				return ONE;
			return ZERO;
		}
		if (rings[k] == 0) {
			return on(k - 1).add(ONE).add(steps[k - 1]);
		}
		return off(k - 1);
	}

	static BigInteger off(int k) {
		if (k == 1) {
			if (rings[k] == 0)
				return ZERO;
			return ONE;
		}
		if (rings[k] == 0){
			for (int i = k; i > 0; i--)
				if (rings[i] != 0)
					return off(i);
			return off(1);
		}
		return on(k - 1).add(ONE).add(steps[k - 1]);
	}
}