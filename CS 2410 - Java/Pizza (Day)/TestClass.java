// Jonathan Petersen
// A01236750
// Chapter 6 Exercise 24

class TestClass {

	private int x;
	private int y;

//////////////////////////////Part A//////////////////////////////////////////

	//Default Constructor
	public TestClass() {
		x = 0;
		y = 0;

		return;
	}

	//Initialization Constructor
	public TestClass(int x, int y) {
		this.x = x;
		this.y = y;

		return;
	}

	//Return the sum of the two numbers.
	public int sum() {
		return (x + y);
	}

	//Output the values of x and y.
	public String toString() {
		return ("The value of \"x\" is: " + x + "\n"
			  + "The value of \"y\" is: " + y);
	}

///////////////////////////////Part B/////////////////////////////////////////

	//Driver code
	public static void main(String[] args) {
		TestClass oneTestClass = new TestClass();
		TestClass twoTestClass = new TestClass(2, 5);

		System.out.println("The sum of one is: " + Integer.toString(oneTestClass.sum()) );
		System.out.print(twoTestClass.toString() + "\n");

		return;
	}

}