// Jonathan Petersen
// A01236750
// Chapter 7 Exercise 21
// Pizza Menu Class

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;

class PizzaMenu extends JPanel {

	private static final int HSIZE = 500;
	private static final int VSIZE = 320;
	
	private JCheckBox toppingPepperoni;
	private JCheckBox toppingSausage;
	private JCheckBox toppingPineapple;
	private JCheckBox toppingRedPepper;
	private JCheckBox toppingCanadianBacon;
	private JCheckBox toppingMushrooms;
	private JCheckBox toppingOnions;
	private ButtonGroup sizeGroup;
	private JRadioButton largeRB;
	private JRadioButton mediumRB;
	private JRadioButton smallRB;
	private ButtonGroup crustGroup;
	private JRadioButton thinRB;
	private JRadioButton standardRB;
	private JRadioButton panRB;
	private JTextArea orderTA;
	private JButton orderB;
	private JLabel welcomeL;
	private JLabel toppingL;
	private JLabel sizeL;
	private JLabel crustL;
	private JLabel orderL;
	private JPanel welcomeP;
	private JPanel typeP;
	private JPanel toppingP;
	private JPanel crustP;
	private JPanel sizeP;
	private JPanel orderP;

	private ItemHandler itemHandler;
	private ActionHandler actionHandler;

	private String[] toppings = {"NO", "NO", "NO", "NO", "NO", "NO", "NO"};
	private String currentSize = "Large";
	private String currentCrust = "Standard";

	private double totalCost = 0.00;

	public PizzaMenu() {
		
		//Initialize Handlers of all types.
		itemHandler = new ItemHandler();
		actionHandler = new ActionHandler();

		//Initialize all of the various buttons and labels.
		welcomeP	 = new JPanel();
		welcomeL	 = new JLabel("Welcome to Pizzaron!", SwingConstants.CENTER);
		welcomeL.setFont(new Font("Serif", Font.BOLD, 24));

		toppingP	 = new JPanel();
		toppingL 	 = new JLabel("Toppings - 90¢ ea.", SwingConstants.LEFT);
		toppingPepperoni	 = new JCheckBox("Pepperoni");
		toppingPepperoni.setSize(100, 30);
		toppingPepperoni.addItemListener(itemHandler);
		toppingSausage = new JCheckBox("Sausage");
		toppingSausage.setSize(100, 30);
		toppingSausage.addItemListener(itemHandler);
		toppingPineapple = new JCheckBox("Pineapple");
		toppingPineapple.setSize(100, 30);
		toppingPineapple.addItemListener(itemHandler);
		toppingRedPepper = new JCheckBox("Red Peppers");
		toppingRedPepper.setSize(100, 30);
		toppingRedPepper.addItemListener(itemHandler);
		toppingCanadianBacon = new JCheckBox("Canadian Bacon");
		toppingCanadianBacon.setSize(100, 30);
		toppingCanadianBacon.addItemListener(itemHandler);
		toppingMushrooms = new JCheckBox("Mushrooms");
		toppingMushrooms.setSize(100, 30);
		toppingMushrooms.addItemListener(itemHandler);
		toppingOnions = new JCheckBox("Onions");
		toppingOnions.setSize(100, 30);
		toppingOnions.addItemListener(itemHandler);

		typeP	 = new JPanel();

		sizeP	 = new JPanel();
		sizeL 	 = new JLabel("Pizza Sizes: ", SwingConstants.LEFT);
		largeRB	 = new JRadioButton("Large  $19.00");
		largeRB.setSize(100, 30);
		largeRB.addItemListener(itemHandler);
		mediumRB	 = new JRadioButton("Medium $15.00");
		mediumRB.setSize(100, 30);
		mediumRB.addItemListener(itemHandler);
		smallRB	 = new JRadioButton("Small  $10.00");
		smallRB.setSize(100, 30);
		smallRB.addItemListener(itemHandler);

		crustP	 = new JPanel();
		crustL 	 = new JLabel("Crust Types: ", SwingConstants.LEFT);
		thinRB	 = new JRadioButton("Thin Crust");
		thinRB.setSize(100, 30);
		thinRB.addItemListener(itemHandler);
		standardRB	 = new JRadioButton("Standard Crust");
		standardRB.setSize(100, 30);
		standardRB.addItemListener(itemHandler);
		panRB	 = new JRadioButton("Pan");
		panRB.setSize(100, 30);
		panRB.addItemListener(itemHandler);

		orderP	 = new JPanel();
		orderL   = new JLabel("Your Order is as Follows: ");
		orderL.setSize(80, 60);
		orderTA	 = new JTextArea();
		orderTA.setEditable(false);
		orderB 	 = new JButton("Checkout");
		orderB.setSize(80, 60);
		orderB.addActionListener(actionHandler);

		sizeGroup = new ButtonGroup();
		sizeGroup.add(largeRB);
		sizeGroup.add(mediumRB);
		sizeGroup.add(smallRB);

		crustGroup = new ButtonGroup();
		crustGroup.add(thinRB);
		crustGroup.add(standardRB);
		crustGroup.add(panRB);

		//Add Working Components to the Layout
		setLayout(new BorderLayout());

		add(welcomeP, BorderLayout.PAGE_START);
			welcomeP.setPreferredSize(new Dimension(100, 50));
			welcomeP.add(welcomeL);

		add(toppingP, BorderLayout.LINE_START);
			toppingP.setLayout(new BoxLayout(toppingP, BoxLayout.PAGE_AXIS));
			toppingP.add(toppingL);
			toppingP.add(toppingPepperoni);
			toppingP.add(toppingSausage);
			toppingP.add(toppingPepperoni);
			toppingP.add(toppingSausage);
			toppingP.add(toppingPineapple);
			toppingP.add(toppingRedPepper);
			toppingP.add(toppingCanadianBacon);
			toppingP.add(toppingMushrooms);
			toppingP.add(toppingOnions);

		add(typeP, BorderLayout.CENTER);
			typeP.setLayout(new BoxLayout(typeP, BoxLayout.PAGE_AXIS));
			typeP.add(Box.createRigidArea(new Dimension(0,5)));
			typeP.add(sizeP);
				sizeP.setLayout(new BoxLayout(sizeP, BoxLayout.PAGE_AXIS));
				//sizeP.add(Box.createRigidArea(new Dimension(10,10)));
				sizeP.add(sizeL);
				sizeP.add(largeRB);
				sizeP.add(mediumRB);
				sizeP.add(smallRB);
			typeP.add(crustP);
				crustP.setLayout(new BoxLayout(crustP, BoxLayout.PAGE_AXIS));
				crustP.add(Box.createRigidArea(new Dimension(0,5)));
				crustP.add(crustL);
				crustP.add(thinRB);
				crustP.add(standardRB);
				crustP.add(panRB);

		add(orderP, BorderLayout.LINE_END);
			orderP.setLayout(new BoxLayout(orderP, BoxLayout.PAGE_AXIS));
			orderP.setPreferredSize(new Dimension(200, 300));
			orderL.setAlignmentX(Component.CENTER_ALIGNMENT);
			orderP.add(orderL);
			orderP.add(orderTA);
			orderB.setAlignmentX(Component.CENTER_ALIGNMENT);
			orderP.add(orderB);

		setPreferredSize(new Dimension(HSIZE, VSIZE));
	}


	private class ItemHandler implements ItemListener {

		public void itemStateChanged(ItemEvent e) {
			
			if(e.getSource() == toppingPepperoni) {
				if(e.getStateChange() == ItemEvent.SELECTED)   toppings[0] = "Pepperoni";
				if(e.getStateChange() == ItemEvent.DESELECTED) toppings[0] = "NO";
			}
			if(e.getSource() == toppingSausage) {
				if(e.getStateChange() == ItemEvent.SELECTED)   toppings[1] = "Sausage";
				if(e.getStateChange() == ItemEvent.DESELECTED) toppings[1] = "NO";
			}
			if(e.getSource() == toppingPineapple) {
				if(e.getStateChange() == ItemEvent.SELECTED)   toppings[2] = "Pineapple";
				if(e.getStateChange() == ItemEvent.DESELECTED) toppings[2] = "NO";
			}
			if(e.getSource() == toppingRedPepper) {
				if(e.getStateChange() == ItemEvent.SELECTED)   toppings[3] = "Red Peppers";
				if(e.getStateChange() == ItemEvent.DESELECTED) toppings[3] = "NO";
			}
			if(e.getSource() == toppingCanadianBacon) {
				if(e.getStateChange() == ItemEvent.SELECTED)   toppings[4] = "Canadian Bacon";
				if(e.getStateChange() == ItemEvent.DESELECTED) toppings[4] = "NO";
			}
			if(e.getSource() == toppingMushrooms) {
				if(e.getStateChange() == ItemEvent.SELECTED)   toppings[5] = "Mushrooms";
				if(e.getStateChange() == ItemEvent.DESELECTED) toppings[5] = "NO";
			}
			if(e.getSource() == toppingOnions) {
				if(e.getStateChange() == ItemEvent.SELECTED)   toppings[6] = "Onions";
				if(e.getStateChange() == ItemEvent.DESELECTED) toppings[6] = "NO";
			}

			if(e.getSource() == largeRB)  currentSize = "Large";
			if(e.getSource() == mediumRB) currentSize = "Medium";
			if(e.getSource() == smallRB)  currentSize = "Small";

			if(e.getSource() == thinRB)  	currentCrust = "Thin";
			if(e.getSource() == standardRB) currentCrust = "Standard";
			if(e.getSource() == panRB)  	currentCrust = "Pan";

			return;
		}

	}

	private class ActionHandler implements ActionListener {

		public void actionPerformed(ActionEvent e) {

			if(e.getActionCommand().equals("Checkout")){

				orderTA.setText("Current Toppings: \n");
				for(int i=0; i<toppings.length; i++) {

					if(!toppings[i].equals("NO")) {
						orderTA.append(toppings[i] + "\n");
						totalCost += 0.90;
					}

				}

				orderTA.append("\n");

				orderTA.append("Current Crust: " + currentCrust + "\n");
				orderTA.append("Current Size : " + currentSize + "\n");
				if(currentSize == "Large") totalCost += 19.00;
				if(currentSize == "Medium") totalCost += 15.00;
				if(currentSize == "Small") totalCost += 10.00;

				orderTA.append("\n");

				orderTA.append("-------------------------\n");
				orderTA.append(String.format("TOTAL: $%.2f \n", totalCost));

				totalCost = 0.0;
			}

		}

	}

}