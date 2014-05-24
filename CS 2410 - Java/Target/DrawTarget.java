//Jonathan Petersen
//A01236750
//Chapter 5 Exercise 25
//Show a Target on the screen.

import java.awt.*;
import javax.swing.*;

public class DrawTarget extends JPanel {

	public DrawTarget() {

		setBackground(Color.green);
		setPreferredSize(new Dimension(200, 200));

		return;
	}

	@Override
	public void paintComponent(Graphics g) {

		super.paintComponent(g);

		//For each ring in the target, draw a circle.
		for(int i=1; i<=6; i++) {
			//Color the Circle
			if((i % 2) == 0) g.setColor(Color.red);
			else g.setColor(Color.white);

			//Draw the circle
			g.fillOval( (25 + (11 * i)), (25 + (11 * i)), (150 - (22 * i)), (150 - (22 * i)) );

		}

	}

}