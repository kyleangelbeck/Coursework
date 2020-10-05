/**
	Assignment 3: Dating Game
	@author Kyle Angelbeck
	@author Lauren Marx
*/
import java.util.*;

public class MyDate implements DateInterface
{
	Date date = new Date();
	Calendar cal = Calendar.getInstance();
	
	int day;
	int month;
	int year;
	int DOW;

	/** sets the date
      @param m the month of the year (1-12)
      @param d the day of the mongth (1-31)
      @param y the year (four digits)
      @param dow the day of the week (0-6) */
  public void set(int m, int d, int y, int dow)
  {
	day=d;
	month=m;
	year=y;
	DOW=dow;  
  }
  /** @return the day of the month (1-31) */
  public int getDay()
  {
	  return day;
  }
  /** @return the day of the week (0-6) */
  public int getDow()
  {
	  return DOW;
  }
  /** @return the month of the year (1-12) */
  public int getMonth()
  {
	  return month;
  }
  /** @return the year (four digits) */
  public int getYear()
  {
	  return year;
  }
  /** moves the date forward by exactly one day */
  public void tomorrow()
  { 
	if(month==4 || month==6 || month==9 || month==11)  
	{  
		if(day<30)
		  {
			  day++;
		  }
		  else
		  {
			  day=1;
			  month++;
		  }
		  if(DOW<6)
		  {
			  DOW++;
		  }
		  else
		  {
			  DOW=0;
		  }
	}
	else if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)  
	{
		if(day<31)
		  {
			  day++;
		  }
		  else
		  {
			  day=1;
			  if(month<12)
			  {
				  month++;
			  }
			  else
			  {
				  month=1;
				  year++;
			  }
		  }
		  if(DOW<6)
		  {
			  DOW++;
		  }
		  else
		  {
			  DOW=0;
		  }
	}
	else
	{
		
		if((year>=1582 && ((year%4==0 && year%100!=0) || year%400==0)) || (year<1582 &&(year%4==0)))
		{
			if(day<29)
			  {
				  day++;
			  }
			  else
			  {
				  day=1;
				  month++;
			  }
			  if(DOW<6)
			  {
				  DOW++;
			  }
			  else
			  {
				  DOW=0;
			  }
		}
		else
		{
			if(day<28)
			  {
				  day++;
			  }
			  else
			  {
				  day=1;
				  month++;
			  }
			  if(DOW<6)
			  {
				  DOW++;
			  }
			  else
			  {
				  DOW=0;
			  }
		}
	}
  }
  /** @return the date as a String in the format "Monday March 18, 2002" */
  public String toString()
  {
	  String Month="";
	  String Day="";
	  if(month==1)
	  {
		  Month="January";
	  }
	  else if(month==2)
	  {
		  Month="Febuary";
	  }
	  else if(month==3)
	  {
		  Month="March";
	  }
	  else if(month==4)
	  {
		  Month="April";
	  }
	  else if(month==5)
	  {
		  Month="May";
	  }
	  else if(month==6)
	  {
		  Month="June";
	  }
	  else if(month==7)
	  {
		  Month="July";
	  }
	  else if(month==8)
	  {
		  Month="August";
	  }
	  else if(month==9)
	  {
		  Month="September";
	  }
	  else if(month==10)
	  {
		  Month="October";
	  }
	  else if(month==11)
	  {
		  Month="November";
	  }
	  else if(month==12)
	  {
		  Month="December";
	  }
	  
	  if(DOW==0)
	  {
		  Day="Sunday";
	  }
	  else if(DOW==1)
	  {
		  Day="Monday";
	  }
	  else if(DOW==2)
	  {
		  Day="Tuesday";
	  }
	  else if(DOW==3)
	  {
		  Day="Wednesday";
	  }
	  else if(DOW==4)
	  {
		  Day="Thursday";
	  }
	  else if(DOW==5)
	  {
		  Day="Friday";
	  }
	  else if(DOW==6)
	  {
		  Day="Saturday";
	  }
	  
	  return Day+" "+Month+" "+day+", "+year;
  }
  /** sets the date to today */
  public void today()
  {
	  year = cal.get(Calendar.YEAR);
	  month = cal.get(Calendar.MONTH) + 1;
	  day = cal.get(Calendar.DATE);
	  DOW = cal.get(Calendar.DAY_OF_WEEK) - 1;
  }
  /** Moves the date backword by exactly one day*/
  public void yesterday()
  {
	 if(month==5 || month==7 || month==10 || month==12)  
	{  
		if(day!=1)
		  {
			  day--;
		  }
		  else
		  {
			  day=30;
			  month--;
		  }
		  if(DOW!=0)
		  {
			  DOW--;
		  }
		  else
		  {
			  DOW=6;
		  }
	}
	else if(month==2 || month==4 || month==6 || month==8 || month==9 || month==11 || month==1)  
	{
		if(day!=1)
		  {
			  day--;
		  }
		  else
		  {
			  day=31;
			  if(month!=1)
			  {
				  month--;
			  }
			  else
			  {
				  month=12;
				  year--;
			  }
		  }
		  if(DOW!=0)
		  {
			  DOW--;
		  }
		  else
		  {
			  DOW=6;
		  }
	}
	else
	{
		if((year>=1582 && ((year%4==0 && year%100!=0) || year%400==0)) || (year<1582 &&(year%4==0)))
		{
			if(day!=1)
			  {
				  day--;
			  }
			  else
			  {
				  day=29;
				  month--;
			  }
			  if(DOW!=0)
			  {
				  DOW--;
			  }
			  else
			  {
				  DOW=6;
			  }
		}
		else
		{
			if(day!=1)
			  {
				  day--;
			  }
			  else
			  {
				  day=28;
				  month--;
			  }
			  if(DOW!=0)
			  {
				  DOW--;
			  }
			  else
			  {
				  DOW=6;
			  }
		}
	} 
  }
}
/*
Wednesday January 1, 3000
Wednesday January 1, 1800
Thursday January 2, 1800
Friday Febuary 9, 2018
*/