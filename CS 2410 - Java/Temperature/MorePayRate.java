//Jonathan Petersen
//A01236750
//HW02 - Assigment 1

//Part A
import java.util.*;

public class CH02_EX01 {

	//Part C
	static final int  SECRET = 11;
	static final double RATE = 12.50;


	public static void main(String[] args) {

		//Part D
		int num1, num2, newNum;
		String name;
		double hoursWorked, wages;

		//Part B
		Scanner console = new Scanner(System.in);

		//Part E
		System.out.print("Please enter two integers seperated by a space: ");
		num1 = console.nextInt();
		num2 = console.nextInt();

		//Part F, Part M
		System.out.println("The value of the first number (num1) is " + num1 + ".\n" +
						   "The value of the second number (num2) is " + num2 + ".");

		//Part G, Part M
		newNum = (num1 * 2) + num2;
		System.out.println("The value of the new number (newNum) is " + newNum + ".");

		//Part H, Part M
		newNum += SECRET;
		System.out.println("The secret value of the new number is " + newNum + ".");

		//Part I
		System.out.print("Please enter your last name: ");
		name = console.next();

		//Part M
		System.out.println("The name you have entered is " + name);

		//Part J
		System.out.print("Please enter the number of hours you have worked: [0.00-70.00] ");
		hoursWorked = console.nextDouble();

		//Part M
		System.out.println(String.format("The number of hours you entered was %3.2f.", hoursWorked));

		//Part K
		wages = RATE * hoursWorked;

		//Part M
		System.out.printf("The resulting wages for this data would be $%3.2f.%n", wages);

		//Part L
		System.out.println(String.format("Name: %13s", name));
		System.out.println(String.format("Pay Rate:    $%3.2f", RATE));
		System.out.println(String.format("Hours Worked: %3.2f", hoursWorked));
		System.out.println(String.format("Wages:      $%3.2f", wages));

	}

}