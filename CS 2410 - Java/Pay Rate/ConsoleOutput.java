//Jonathan Petersen
//A01236750
//Combines some numbers.

public class CH01_EX04 {

	public static final int COUNT = 3;

	public static void main(String[] args){



		//Variable Statements
		int num1, num2, num3;
		int average;

		//Executable Statements
		num1 = 125;
		num2 =  28;
		num3 = -25;

		average = (num1 + num2 + num3) / COUNT;

		System.out.println("The first number is: "  + num1);
		System.out.println("The second number is: " + num2);
		System.out.println("The third number is: "  + num3);
		System.out.println("The average is: "       + average);

	}

}