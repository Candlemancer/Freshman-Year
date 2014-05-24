//Jonathan Petersen
//A01236750
//CH04 EX03

import java.util.*;

public class NumChar {

	private static Scanner cin = new Scanner(System.in);

	public static void main(String[] args) {

		int input = -1;

		System.out.print("Please enter a number between 0 and 35: ");
		input = Integer.parseInt(cin.next());

		//Output the input if it's less than 10.
		if(input <  10) System.out.println(Integer.toString(input));
		//Or the corresponding letter if it's larger.
		if(input >=	10)	System.out.println((char)(input + 55));

		return;		
	}


}