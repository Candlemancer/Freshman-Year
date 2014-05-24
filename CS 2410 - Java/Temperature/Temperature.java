//Jonathan Petersen
//A01236750
//TempConvert, Java Style

import javax.swing.*;

public class CH02_EX21 {

	public static void main(String[] args) {

		double cel, fah;

		//Input box for Fahrenheit.
		fah = Double.parseDouble(JOptionPane.showInputDialog("Please input a temperature in degrees Fahrenheit."));

		//Convert the numbers.
		cel = (fah - 32) * (5.0 / 9.0);

		//Output box.
		JOptionPane.showMessageDialog(null, String.format("%3.2f° Fahrenheit is equal to%n%3.2f° Celsius.", fah, cel),
									  "Temperature Conversion", JOptionPane.INFORMATION_MESSAGE);

		System.exit(0);

	}

}