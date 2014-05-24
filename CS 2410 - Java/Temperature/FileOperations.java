//Jonathan Petersen
//A01236750
//Basic File Operations

import java.util.*;
import java.io.*;

public class CH02_EX17 {

	public static void main(String[] args) throws IOException {

		int firstSum, secondSum;
		int firstProd, secondProd;
		char letter;


		//File Input/Output Setup
		Scanner inFile = new Scanner(new FileReader("inData.txt"));
		PrintWriter outFile = new PrintWriter("outData.dat");

		//Read from file.
		firstSum   = inFile.nextInt();
		secondSum  = inFile.nextInt();
		letter     = inFile.next().charAt(0);
		firstProd  = inFile.nextInt();
		secondProd = inFile.nextInt();

		//Output
		outFile.println("The sum of " + firstSum + " and " + secondSum +
						" is: " + (firstSum + secondSum));
		outFile.println("The Unicode character that comes after " + letter +
						" is the character " + (char)(letter + 1));
		outFile.println("The product of " + firstProd + " and " + secondProd +
						" is: " + (firstProd * secondProd));

		//"Deconstructor"
		inFile.close();
		outFile.close();

	}

}