//Jonathan Petersen
//A01236750
//Prints out some numbers and hours worked.


import java.text.*;

public class CH01_EX07 {

	public static final int SECRET = 11;
	public static final double RATE = 12.50;

	public static void main(String[] args){

		//Variable Declaration
		int num1, num2, newNum;
		String name;
		double hoursWorked, wages;

		//Executable Statements
		num1 = 15;
		num2 = 28;

		System.out.println("The value of num1 = " + num1 + " and the value of num2 = " + num2 + ".");

		newNum = (num1 * 2) + num2;

		System.out.println("The value of newNum = " + newNum + ".");

		newNum += SECRET;

		System.out.println("The new value of newNum = " + newNum + ".");

		name = "Cynthia Jacobson";

		hoursWorked = 45.50;

		wages = RATE * hoursWorked;

		System.out.println("Name: " + name);
		System.out.println("Pay Rate: $" + RATE);
		System.out.println("Hours Worked: " + hoursWorked);
		System.out.println("Salary: $" + wages);

	}

}