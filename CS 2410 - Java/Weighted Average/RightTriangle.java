//Jonathan Petersen
//A01236750
//CH04 EX05
//Right Triangle

import java.util.*;
import static java.lang.Math.*;

public class RightTriangle {

	private static Scanner cin = new Scanner(System.in);

	public static void main(String[] args) {

		double sideOne, sideTwo, sideThr;

		System.out.print("Please enter the length of the first side of the triangle: ");
		sideOne = cin.nextDouble();
		System.out.print("Please enter the length of the second side of the triangle: ");
		sideTwo = cin.nextDouble();
		System.out.print("Please enter the length of the third side of the triangle: ");
		sideThr = cin.nextDouble();

		if( pow(sideOne, 2) + pow(sideTwo, 2) == pow(sideThr, 2) ||
			pow(sideTwo, 2) + pow(sideThr, 2) == pow(sideOne, 2) ||
			pow(sideThr, 2) + pow(sideOne, 2) == pow(sideTwo, 2)  ){

			System.out.print("The triangle is a right triangle!\n");
		}
		else System.out.print("The triangle is not a right triangle.\n");

		return;
	}

}