import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int T,cn = 1;
		T = sc.nextInt();
		while(cn <= T){
			BigInteger a,LCM = BigInteger.ONE;
			int n;

			n = sc.nextInt();
			while(n > 0){
				a = sc.nextBigInteger();
				if( a.compareTo(BigInteger.ZERO) == 0 && LCM.compareTo(BigInteger.ZERO) == 0 )
					LCM = BigInteger.ZERO;
				else
				    LCM = (a.multiply(LCM)).divide(a.gcd(LCM));
				n--;
			}
			System.out.println("Case " + cn + ": " + LCM);
            System.gc();
			cn++;
		}
	}
}
