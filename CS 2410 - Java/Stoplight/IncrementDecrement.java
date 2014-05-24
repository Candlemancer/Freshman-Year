//Jonathan Petersen
//A01236750
//Increment and Decrement

import javax.swing.*;
import java.util.*;
import java.awt.*;
import java.awt.event.*;

public class CH03_EX10 extends JFrame {

	private Scanner cin = new Scanner(System.in);

	private JLabel inputOne, inputTwo;
	private JButton decrement, increment;

	private DecrementButtonHandler dHandler;
	private IncrementButtonHandler iHandler;

	private Container pane;

	private static final int WIDTH = 350;
	private static final int HEIGHT = 100;

	private	int numberOne, numberTwo;

	public CH03_EX10() {

		System.out.print("Please enter two numbers seperated by a space. [9 23] :");
		numberOne = Integer.parseInt(cin.next());
		numberTwo = Integer.parseInt(cin.next());

		//Create Two labels
		inputOne = new JLabel(Integer.toString(numberOne), SwingConstants.CENTER);
		inputTwo = new JLabel(Integer.toString(numberTwo), SwingConstants.CENTER);

		//And the two buttons
		decrement = new JButton("Decrement");
		dHandler = new DecrementButtonHandler();
		decrement.addActionListener(dHandler);

		increment = new JButton("Increment");
		iHandler = new IncrementButtonHandler();
		increment.addActionListener(iHandler);

		//Now create the window.
		setTitle("Increment and Decrement");
		pane = getContentPane();
		pane.setLayout(new GridLayout(2, 2));
		pane.add(inputOne);
		pane.add(inputTwo);
		pane.add(increment);
		pane.add(decrement);

		//And display it.
		setSize(WIDTH, HEIGHT);
		setVisible(true);
		setDefaultCloseOperation(EXIT_ON_CLOSE);

	}

	private class DecrementButtonHandler implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			inputTwo.setText(Integer.toString(--numberTwo));
		}
	}

	private class IncrementButtonHandler implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			inputOne.setText(Integer.toString(++numberOne));
		}
	}

	public static void main(String[] args) {
		CH03_EX10 demoObject = new CH03_EX10();
	}

}