//Jonathan Petersen
//A01236750
//Dog Info

import Dogs.Dog;
import java.util.*;

public class CH03_EX08 { 

	static Scanner cin = new Scanner(System.in);

	public static void main(String[] argsr) {


		Dog myDog = new Dog();
		Dog yourDog = new Dog();


		//Setup my dog.
		myDog.setInfo("Felix", 7);

		//Setup your dog.
		System.out.print("I see you have a dog. \n" + "What is your dog's name and age? [Fido 3]\n");
		yourDog.setInfo(cin.next(), Integer.parseInt(cin.next()));

		//Compare dogs.
		System.out.print("The info for my dog is: \n");
		System.out.print(myDog.toString() + "\n\n");
		System.out.print("The info for your dog is: \n");
		System.out.print(yourDog.toString() + "\n");



	}



}

