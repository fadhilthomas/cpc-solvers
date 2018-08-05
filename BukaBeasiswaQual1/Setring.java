import java.util.*;
import java.lang.*;
import java.io.*;

public class Setring
{
  public static void main (String[] args)
  {
    Scanner in = new Scanner(System.in);
	int c;

    String word = in.nextLine();
    int r = Integer.parseInt(in.nextLine());
	
	
	for(char ch : word.toCharArray()){
		c = 0;			
		while(c < r){
			ch = (char)(ch + 1);
			if(ch=='{'){
				ch = 'a';
			}
			c++;
		}
		System.out.print(ch);
	}
	System.out.print("\n");
  }
}