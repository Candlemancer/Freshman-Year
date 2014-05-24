// Jonathan Petersen
// A01236750
// Chapter 7 Exercise 21
// Pizza Menu Driver

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;

public class PizzaDriver extends JFrame {

	public static void main(String[] args) {

		JFrame pizzaFrame = new JFrame("Jon's Pizza Menu");

		pizzaFrame.setDefaultCloseOperation(EXIT_ON_CLOSE);
		pizzaFrame.getContentPane().add(new PizzaMenu());
		pizzaFrame.pack();
		pizzaFrame.setVisible(true);
	
		return;
	}

}