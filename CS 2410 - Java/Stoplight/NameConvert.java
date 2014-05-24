//Jonathan Petersen
//A01236750
//Name conversion

import java.util.*;

public class CH03_EX01 {

	static Scanner cin = new Scanner(System.in);

	public static void main(String[] args) {

		String inputName, firstName, lastName;
		int commaIndex;

		//Get input from the user.
		System.out.print("Please enter a name in the form [Last Name],[First Name]\n");
		inputName = cin.next();

		//Find the comma.
		commaIndex = inputName.indexOf(',');

		//Substring before the comma is last name, after is first.
		firstName = inputName.substring(commaIndex + 1);
		lastName = inputName.substring(0, commaIndex);

		//Print out the revised name.
		System.out.print("The new name is " + firstName + " " + lastName + ".\n");


	}

}