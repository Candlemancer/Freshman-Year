//Jonathan Petersen
//A01236750
//Dog Info

package Dogs;

public class Dog {

	private String name;
	private int age;

	public void setInfo(String nameInput, int ageInput) {
		name = nameInput;
		age = ageInput;
	
	}

	public String getName() {
		return name;
	}

	public int getAge() {
		return age;
	}

	public int dogAgeInPersonYears() {
		return (age * 7);
	}

	public String toString() {
		return ("This dog's name is " + name + " and he is " + 
			     Integer.toString(age) + " years old. \n" +
			    "In person years that is " + 
			     Integer.toString(dogAgeInPersonYears()) + 
			    " years old.");
	}

}