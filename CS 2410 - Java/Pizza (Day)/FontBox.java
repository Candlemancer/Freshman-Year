// Jonathan Petersen
// A01236750
// Chapter 7 Exercise 20
// Font Box Class

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;

class FontBox extends JPanel {

	private static final int HSIZE = 410;
	private static final int VSIZE = 150;
	
	private JCheckBox boldCB;
	private JCheckBox italicCB;
	private JComboBox fontDD;
	private ButtonGroup colorGroup;
	private JRadioButton redRB;
	private JRadioButton blueRB;
	private JPanel styleP;
	private JPanel colorP;
	private JPanel fontP;
	private JPanel textP;

	private Color currentColor = Color.black;
	private int intBold	  = Font.PLAIN;
	private int intItalic = Font.PLAIN;

	private String[] fonts = {"Serif", "Courier", "Arial", "Century Gothic", "Dialog"};
	private String currentFont = "Arial";

	private EventHandler cbHandler;


	public FontBox() {
		//Data members
		
		//Initialize Handlers of all types.
		cbHandler = new EventHandler();

		//Initialize all of the various buttons and labels.
		styleP	 = new JPanel();
		boldCB	 = new JCheckBox("Bold");
		boldCB.setSize(100, 30);
		boldCB.addItemListener(cbHandler);
		italicCB = new JCheckBox("Italics");
		italicCB.setSize(100, 30);
		italicCB.addItemListener(cbHandler);

		fontP	 = new JPanel();
		fontDD	 = new JComboBox(fonts);
		fontDD.setMaximumRowCount(3);
		fontDD.setSize(80, 30);
		fontDD.addItemListener(cbHandler);

		colorP	 = new JPanel();
		redRB	 = new JRadioButton("Red");
		redRB.setSize(80, 30);
		redRB.addItemListener(cbHandler);
		blueRB	 = new JRadioButton("Blue");
		blueRB.setSize(80, 30);
		blueRB.addItemListener(cbHandler);

		textP	 = new TextPanel();

		colorGroup = new ButtonGroup();
		colorGroup.add(redRB);
		colorGroup.add(blueRB);

		//Add Working Components to the Layout
		setLayout(new BorderLayout());

		add(textP, BorderLayout.PAGE_START);
			textP.setPreferredSize(new Dimension(100, 50));

		add(styleP, BorderLayout.LINE_START);
			styleP.setLayout(new BoxLayout(styleP, BoxLayout.PAGE_AXIS));
			styleP.add(boldCB);
			styleP.add(italicCB);

		add(fontP, BorderLayout.CENTER);
			fontP.setLayout(new BoxLayout(fontP, BoxLayout.PAGE_AXIS));
			fontP.add(fontDD);

		add(colorP, BorderLayout.LINE_END);
			colorP.setLayout(new BoxLayout(colorP, BoxLayout.PAGE_AXIS));
			colorP.add(redRB);
			colorP.add(blueRB);


		setPreferredSize(new Dimension(HSIZE, VSIZE));
	}


	private class EventHandler implements ItemListener {

		public void itemStateChanged(ItemEvent e) {
			
			if(e.getSource() == boldCB) {
				if(e.getStateChange() == ItemEvent.SELECTED)   intBold = Font.BOLD;
				if(e.getStateChange() == ItemEvent.DESELECTED) intBold = Font.PLAIN;
			}
			if(e.getSource() == italicCB) {
				if(e.getStateChange() == ItemEvent.SELECTED)   intItalic = Font.ITALIC;
				if(e.getStateChange() == ItemEvent.DESELECTED) intItalic = Font.PLAIN;
			}

			if(e.getSource() == redRB)  currentColor = Color.red;
			if(e.getSource() == blueRB) currentColor = Color.blue;

			if(e.getSource() == fontDD) currentFont = fonts[fontDD.getSelectedIndex()];

			repaint();
			return;
		}

	}

	private class TextPanel extends JPanel {

		public void paintComponent(Graphics g) {
			super.paintComponent(g);
			g.setColor(currentColor);
			g.setFont(new Font(currentFont, intBold + intItalic, 24));
			g.drawString("Welcome to Java Programming", 10, 30);

			return;
		}

	}

}