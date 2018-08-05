import java.util.*;
import java.lang.*;
import java.io.*;

public class Cetak
{
  public static void main (String[] args)
  {
    Scanner in = new Scanner(System.in);

    int n, angka;

    String tmp = in.nextLine();
    n = Integer.parseInt(tmp);

    angka = n%10;
    if(angka == 3)
    {
        System.out.println("Hore tanggal lahirku!");
    }
    else if(angka == 1 || angka == 4 || angka == 9)
    {
        System.out.println("Hore angka kuadrat kesukaanku!");
    }
    else
    {
        System.out.println("Bukan angka kesukaanku!");
    }
	

    while(n > 0)
    {
		n /= 10;
        angka = n%10;
        if(angka == 3)
        {
            System.out.println("Hore ada angka 3!");
        }
        else if(angka == 1 || angka == 4 || angka == 9)
        {
            System.out.println("Hore ada angka kuadrat!");
        }
        else
        {
            System.out.println("Bukan angka kesukaanku!");
        }
    }
  }
}
