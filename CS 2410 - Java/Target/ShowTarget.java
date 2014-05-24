//Jonathan Petersen
//A01236750
//Chapter 5 Exercise 25
//Show a Target on the screen.

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class ShowTarget extends JFrame {

	private final static int WIDTH = 400;
	private final static int HEIGHT = 400;

	public static void main(String[] args) {

		JFrame targetFrame = new JFrame("Target");

		targetFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		targetFrame.getContentPane()
				   .add(new DrawTarget());

	//  targetFrame.pack();
	    targetFrame.setVisible(true);

	    return;
	}


}

