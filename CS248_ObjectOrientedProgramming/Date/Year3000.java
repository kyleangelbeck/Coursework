import java.io.*;

/**
  Driver class for The Dating Game programming assignment.
  @author Jon Sorenson
*/
public class Year3000
{
  public static void main(String [] args) throws IOException
  {
    DateInterface d = new MyDate();
    d.set(1,25,2015,0);
    while(d.getYear()<3000)
    {
      d.tomorrow();
    }
	System.out.println(d);
	d.set(1,25,2015,0);
	while(d.getYear()>1799)
	{
		d.yesterday();
	}
	d.tomorrow();
    System.out.println(d);
	while(d.getYear()>999)
	{
		d.yesterday();
	}
	d.tomorrow();
	System.out.println(d);
	d.today();
	System.out.println(d);
  }
}