import javax.swing.JOptionPane;

public class Even {

	//Variable Declarations
	private int input;
	
	//Function Definitions
	public Even() {}


	public static void main(String[] args) {
		
		Even number = new Even();
		number.showDialog();

	}

	public void showDialog() {
		try {
			this.input = Integer.parseInt(JOptionPane.showInputDialog("Is your number Even? \nPlease enter a number."));
			this.calculate();
		}
		catch (final NumberFormatException e) {
			System.err.println("Invalid Input, please input a numerical value.");
		}
	}

	private void calculate() {
	if ((this.input % 2) == 0) { JOptionPane.showMessageDialog(null, "Yes, your number is even.");}
	if ((this.input % 2) == 1) { JOptionPane.showMessageDialog(null, "No, your number is odd.");}
	}

}
