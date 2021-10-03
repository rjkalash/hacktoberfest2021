public class StringPowerset {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String str = "abc";
		int index = 0;
		String curr = "";
		powerset(str, index, curr);

	}
	
	public static void powerset(String s, int i, String curr) {
		if(i == s.length()) {
			System.out.println(curr);
			return;
		}
		
		powerset(s, i+1, curr+s.charAt(i));
		powerset(s, i+1, curr);
			
	}

}
