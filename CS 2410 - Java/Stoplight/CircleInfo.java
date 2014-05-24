//Jonathan Petersen
//A01236750
//Circle info

import java.util.*;
import java.lang.*;

public class CH03_EX04 {

	static Scanner cin = new Scanner(System.in);

	public static void main(String[] args) {

		double firstX, firstY, secondX, secondY;

		//Input of values
		System.out.print("Please input two points in cartesian space (I.E. (X1, Y1) (X2, Y2)) \n" +
						 "in the format [X1] [Y1] [X2] [Y2].\n");
		firstX = cin.nextDouble();
		firstY = cin.nextDouble();
		secondX = cin.nextDouble();
		secondY = cin.nextDouble();

		//Print out information.
		System.out.print("The details of a circle with center at point (X1,Y1) and\n" +
						 "(X2, Y2) are as follows: \n");
	 	System.out.print("Radius: " + Double.toString( radius(firstX, firstY, secondX, secondY) ) + ".\n");	
	 	System.out.print("Circumference: " + Double.toString( circumference( radius(firstX, firstY, secondX, secondY) ) ) + ".\n");	
	 	System.out.print("Area: " + Double.toString( area( radius(firstX, firstY, secondX, secondY) ) ) + ".\n \n");	

	}

	public static double distance(double ax, double ay, double bx, double by) {
		return Math.pow( ( Math.pow((bx - ax), 2) + Math.pow((by - ay), 2) ) , 0.5);
	}

	public static double radius(double ax, double ay, double bx, double by) {
		return distance(ax, ay, bx, by);
	}

	public static double circumference(double r) {
		return (Math.PI * 2 * r);
	}

	public static double area(double r) {
		return (Math.PI * Math.pow(r, 2));
	}



}	