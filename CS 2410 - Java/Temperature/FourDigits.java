//Jonathan Petersen
//A012356750
//Split a four digit number into four lines.

import java.util.*;
import java.math.*;

public class CH02_EX07 {

	public static void main(String[] args) {

		//Variables
		Scanner console = new Scanner(System.in);
		String number;

		//Input
		System.out.print("Please enter a four digit integer: ");
		number = console.next();

		//Output
		System.out.println(number.charAt(0));
		System.out.println(number.charAt(1));
		System.out.println(number.charAt(2));
		System.out.println(number.charAt(3));

	}

}