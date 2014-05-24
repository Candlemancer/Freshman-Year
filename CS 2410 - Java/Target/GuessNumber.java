//Jonathan Petersen
//A01236750
//Chapter 5 Exercize 16
//Number Guessing Game

import java.util.*;

public class GuessNumber {

	static final int TARGET = (int) (Math.random() * 100);

	static Scanner cin = new Scanner(System.in);

	public static void main(String[] args) {

		int guess, difference;

		//Create a for loop for the user's seven guesses.
		for(int i=0; i<7; i++) {
			
			System.out.print("Please guess a number between one and one-hundred.\n" +
							 "You have " + (7 - i) + " attempts remaining. [1-100]: ");	
			guess = cin.nextInt();
			difference = Math.abs(guess - TARGET);

			//Guess is correct
			if(guess == TARGET) {System.out.print("You guessed it! Congratulations!\n\n"); return;}

			//Low Guesses
			if(guess < TARGET &&  difference >= 50                    ) {System.out.print("Your guess was very low.\n\n");			continue;}
			if(guess < TARGET && (difference >= 30 && difference < 50)) {System.out.print("Your guess was low.\n\n");				continue;}
			if(guess < TARGET && (difference >= 15 && difference < 30)) {System.out.print("Your guess was moderately low.\n\n");	continue;}
			if(guess < TARGET && (difference >= 01 && difference < 15)) {System.out.print("Your guess was somewhat low.\n\n");		continue;}

			//High Guesses
			if(guess > TARGET &&  difference >= 50                    ) {System.out.print("Your guess was very high.\n\n");			continue;}
			if(guess > TARGET && (difference >= 30 && difference < 50)) {System.out.print("Your guess was high.\n\n");				continue;}
			if(guess > TARGET && (difference >= 15 && difference < 30)) {System.out.print("Your guess was moderately high.\n\n");	continue;}
			if(guess > TARGET && (difference >= 01 && difference < 15)) {System.out.print("Your guess was somewhat high.\n\n");		continue;}

		}

		System.out.print("Sorry, you didn't guess the number. Better luck next time.\n");
		return;
	}

}