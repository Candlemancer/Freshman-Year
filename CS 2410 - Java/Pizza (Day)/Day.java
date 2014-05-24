// Jonathan Petersen 
// A01236750
// Chapter 6 Exercise 24
// Day Class and Implementation

import java.util.*;

class Day {

	//Data Members
	private String day;
	private Scanner cin = new Scanner(System.in);

	//Constructors
	public Day() 				{ day = "Sun"; }	
	public Day(Day another)	 	{ this.day = another.day; }
	public Day(String day) {
		//Verify User Input
		while(  !day.equals("Sun") &&
				!day.equals("Mon") &&
				!day.equals("Tue") &&
				!day.equals("Wed") &&
				!day.equals("Thu") &&
				!day.equals("Fri") &&
				!day.equals("Sat") ){
	
			System.out.print("Invalid day, please input the day " +
							 "of the week in a three-letter format. [Thu] ");	
			day = cin.next();
		}

		this.day = day;

		return;
	}

	//Accessors
	public Day getDay() 		{ return this; }
	public Day getTomorrow()	{ return this.addDays( 1); }
	public Day getYesterday()	{ return this.addDays(-1); }
	public String toString() 	{ return this.day; }

	//Method Calls
	public Day addDays(int numDays) {

		int today = 0;
		Day someday;

		//Convert the current day into today.
		if(day.equals("Sun")) today = 0; 
		if(day.equals("Mon")) today = 1; 
		if(day.equals("Tue")) today = 2; 
		if(day.equals("Wed")) today = 3; 
		if(day.equals("Thu")) today = 4; 
		if(day.equals("Fri")) today = 5; 
		if(day.equals("Sat")) today = 6; 

		//Combine the two values
		numDays = numDays % 7;
		today += numDays;
		while(today < 0) today += 7;

		//Convert today into a new day.
		switch(today) {
		 case 0: { someday = new Day("Sun"); break; }
		 case 1: { someday = new Day("Mon"); break; }
		 case 2: { someday = new Day("Tue"); break; }
		 case 3: { someday = new Day("Wed"); break; }
		 case 4: { someday = new Day("Thu"); break; }
		 case 5: { someday = new Day("Fri"); break; }
		 case 6: { someday = new Day("Sat"); break; }
		default: { someday = new Day("Sun"); break; }
		}

		return someday;  //And I'll be waiting. 

	}

	public static void main(String[] args) {

		Day donmingo = new Day();

		Day lunes = new Day();
		lunes = lunes.addDays(1);

		Day martes = new Day(lunes.getTomorrow());

		Day miercoles = new Day(martes.addDays(2).getYesterday());

		Day jueves = new Day("Thu");

		Day viernes = new Day(donmingo.addDays(-2));

		Day sabado = new Day(jueves.addDays(2 - 14));

		System.out.print("The days of the week in Spanish:   " + "\n" +
						 "Lunes     : " +     lunes.toString() + "\n" +
						 "Martes    : " +    martes.toString() + "\n" +
						 "Miercoles : " + miercoles.toString() + "\n" +
						 "Jueves    : " +    jueves.toString() + "\n" +
						 "Viernes   : " +   viernes.toString() + "\n" +
						 "Sabado    : " +    sabado.toString() + "\n" +
						 "Donmingo  : " +  donmingo.toString() + "\n" );	

		return;
	}

}