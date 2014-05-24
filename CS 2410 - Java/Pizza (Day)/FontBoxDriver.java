// Jonathan Petersen
// A01236750
// Chapter 7 Exercise 20
// Font Box Driver Code

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;


public class FontBoxDriver extends JFrame {

	public static void main(String[] args) {

		JFrame fontFrame = new JFrame("Text Manipulation");

		fontFrame.setDefaultCloseOperation(EXIT_ON_CLOSE);
		fontFrame.getContentPane().add(new FontBox());
		fontFrame.pack();
		fontFrame.setVisible(true);
	
		return;
	}

}