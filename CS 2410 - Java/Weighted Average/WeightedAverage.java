//Jonathan Petersen
//A01236750
//CH04 EX17
//Weighted Average Calculator

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class WeightedAverage extends JFrame {

	//Setup of the GUI window. Lavels on top, then text, then buttons.
	private Container pane = getContentPane();

	private JLabel gradesL = new JLabel("Test Scores", SwingConstants.CENTER);
	private JLabel weightL = new JLabel("Weight"	 , SwingConstants.CENTER);

	//Class of four. Great.
	private JTextField grades1TF = new JTextField(10);
	private JTextField weight1TF = new JTextField(10);

	private JTextField grades2TF = new JTextField(10);
	private JTextField weight2TF = new JTextField(10);

	private JTextField grades3TF = new JTextField(10);
	private JTextField weight3TF = new JTextField(10);

	private JTextField grades4TF = new JTextField(10);
	private JTextField weight4TF = new JTextField(10);

	//A row for the total.
	private JLabel totalL = new JLabel("Average :"   , SwingConstants.RIGHT);
	private JTextField totalTF = new JTextField(10);

	//Buttons first, then handlers.
	private JButton calcB = new JButton("Calculate");
	private JButton exitB = new JButton("Exit");

	private CalcHandler calcH = new CalcHandler();
	private ExitHandler exitH = new ExitHandler();

	private static final int WIDTH = 325;
	private static final int HEIGHT = 250;


	//Constructors
	public WeightedAverage() {

		setTitle("Weighted Average Calculator");

		calcB.addActionListener(calcH);
		exitB.addActionListener(exitH);

		totalTF.setEditable(false);

		pane.setLayout(new GridLayout(7, 2));

		//Row 1
		pane.add(gradesL);
		pane.add(weightL);
		//Row 2
		pane.add(grades1TF);
		pane.add(weight1TF);
		//Row 3
		pane.add(grades2TF);
		pane.add(weight2TF);
		//Row 4
		pane.add(grades3TF);
		pane.add(weight3TF);
		//Row 5
		pane.add(grades4TF);
		pane.add(weight4TF);
		//Row 6
		pane.add(totalL);
		pane.add(totalTF);
		//Row 7
		pane.add(calcB);
		pane.add(exitB);

		setSize(WIDTH, HEIGHT);
		setVisible(true);
		setDefaultCloseOperation(EXIT_ON_CLOSE);

		return;
	}

	private class CalcHandler implements ActionListener {

		public void actionPerformed(ActionEvent e) {

			double average;

			//My Baby
			average = ((Double.parseDouble(grades1TF.getText()) * Double.parseDouble(weight1TF.getText()) +
						Double.parseDouble(grades2TF.getText()) * Double.parseDouble(weight2TF.getText()) +
						Double.parseDouble(grades3TF.getText()) * Double.parseDouble(weight3TF.getText()) +
						Double.parseDouble(grades4TF.getText()) * Double.parseDouble(weight4TF.getText()))/
					   (Double.parseDouble(weight1TF.getText()) + Double.parseDouble(weight2TF.getText()) +
					   	Double.parseDouble(weight3TF.getText()) + Double.parseDouble(weight4TF.getText())));

			totalTF.setText(Double.toString(average));

			return;
		}

	}

	private class ExitHandler implements ActionListener {

		public void actionPerformed(ActionEvent e) {

			System.exit(0);
			return;
		}

	}



	public static void main(String[] args) {

		WeightedAverage window = new WeightedAverage();
		return;
	}

}