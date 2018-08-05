import java.util.*;
import java.lang.*;
import java.io.*;

public class BBinary{
	public static void main (String[] args){
		List<Integer> listInt = new ArrayList<Integer>();
		Scanner in = new Scanner(System.in);
		int n = Integer.parseInt(in.nextLine());
		while(n > 0){
			if (n % 2 == 0){
				listInt.add(0);
			}else{
				listInt.add(1);
			}
			n /= 2;
		}
		
		for(int i = listInt.size()-1; i >= 0; i--){
			System.out.print(listInt.get(i));
		}
		System.out.print("\n");
		
		
	}
}