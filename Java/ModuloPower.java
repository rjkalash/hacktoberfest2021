public class ModuloPower {

	public static void main(String[] args) {
		System.out.println(power(5, -4, 67));
	}
	
	public static long power(long a, int b, int p) {
		
		long res = 1;
		while(b > 0) {
			if((b & 1) != 0)
				res = (res * a % p) % p;
			a = (a % p * a % p) % p;
			b = b >> 1;
		}
		
		return res;
	}	

}
