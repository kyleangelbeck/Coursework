/**
	Program 4: Hunt the Mobster
	@author Kyle Angelbeck
*/
import java.io.*;
import java.util.*;
public class HtW {
    public static void main(String[] args) throws IOException {
		//room variables
        Scanner data = new Scanner(new FileReader("file.txt"));
        int numS = data.nextInt();
        int numB = data.nextInt();
        int numC = data.nextInt();
        Street[] streets = new Street[numS];
        
		//game variables
        Scanner cin=new Scanner(System.in);
        boolean mobsterAlive=true; //change
        int currentStreet = 1;
        int bullets = 3;
        boolean foundSupply = false;
        boolean foundUber = false;
        
        //make sure there are enough streets.
        //Start, Mobster, Uber, Supply, numB, numC
        if(numS < numB + numC + 4) {
            System.out.println("There are not enough streets.");
            System.exit(0);
        }
        
        //creates 10 streets
        for(int i = 0; i < numS; i++) {
            int sn = data.nextInt();
            int[] cs = new int[3];
            for(int j = 0; j < 3; j++) {
                cs[j] = data.nextInt();
            }
            String ft = data.nextLine();
            ft = data.nextLine();
            streets[i] = new Street(sn, 0, cs, ft);
            if(sn == 1) {
                streets[i].setType(1);
                currentStreet = sn-1;
            }
        }
        
		//fills streets
        placeMobster(streets, numS);
        placeBloods(streets, numB, numS);
        placeCrips(streets, numC, numS);
        placeSupply(streets, numS);
        placeUber(streets, numS);
        
		//actual playing of the game
        while(mobsterAlive) {
			printInfo(streets, bullets, currentStreet);
			
            System.out.println("(M)ove or (S)hoot?");
            char action=cin.next().charAt(0);
            System.out.println("Which Street?");
            int target=cin.nextInt();
            if(target != streets[currentStreet].getConnect(0) &&
               target != streets[currentStreet].getConnect(1) &&
               target != streets[currentStreet].getConnect(2))
            {
                System.out.println("There are no intersections to that street!");
            } else  if(action == 'M') {
                currentStreet=target-1;
                if (isDead(streets, currentStreet))
                {
                    System.out.println("You have died!");
                    mobsterAlive=false;
                } else if(streets[currentStreet].getType()==5 && !foundSupply) {
                    System.out.println("You replenished your bullets!");
                    bullets=3;
                    foundSupply=true;
                } else if(streets[currentStreet].getType()==6 && !foundUber) {
                    int tempUber;
                    do {
                    tempUber = (int)(numS*Math.random());
                    } while(currentStreet == tempUber);
                    System.out.println("You were moved to Street " + (tempUber+1) + " by your uber!");
                    currentStreet = tempUber;
                    foundUber = true;
                    if (isDead(streets, currentStreet)) {
                        System.out.println("You have died!");
                        mobsterAlive=false;
                    } else if(streets[currentStreet].getType()==5 && !foundSupply) {
                        System.out.println("You replenished your bullets!");
                        bullets=3;
                        foundSupply=true;
                    }
                }
            } else if(action == 'S') {
                if(bullets <= 0) {
                    System.out.println("You have no bullets.");
                } else if(streets[target-1].getType()==2){
                    System.out.println("You Win!!");
                    mobsterAlive=false;
                } else {
                    System.out.println("You didn't hit anything");
                    bullets--;
                }
            } else {
                System.out.println("That is not a valid action!");
            }
        }
    }
	/**
	Place the mobster in a random empty room
	@param streets=array of streets
	@param numS=number of total streets
	*/
    public static void placeMobster(Street[] streets, int numS) {
        int temp = (int)(numS*Math.random());
        if(streets[temp].getType()==0) {
            streets[temp].setType(2);
        } else {
            placeMobster(streets, numS);
        }
    }
	/**
	Place the spiders in a random empty room
	@param streets=array of streets
	@param numB=number of spider streets to be created
	@param numS=number of total streets
	*/
    public static void placeBloods(Street[] streets, int numB, int numS) {
        int tempBlood = 0;
        while(tempBlood < numB) {
            int temp = (int)(numS*Math.random());
            if(streets[temp].getType()==0) {
                streets[temp].setType(3);
                tempBlood++;
            }
        }
    }
	/**
	Place the pits in a random empty room
	@param streets=array of streets
	@param numB=number of blood streets to be created
	@param numS=number of total streets
	*/
    public static void placeCrips(Street[] streets, int numC, int numS) {
        int tempCrip = 0;
        while(tempCrip < numC) {
            int temp = (int)(numS*Math.random());
            if(streets[temp].getType()==0) {
                streets[temp].setType(4);
                tempCrip++;
            }
        }
    }
	/**
	Place the supply room in a random empty room
	@param streets=array of streets
	@param numS=number of total streets
	*/
    public static void placeSupply(Street[] streets, int numS) {
        int temp = (int)(numS*Math.random());
        if(streets[temp].getType()==0) {
            streets[temp].setType(5);
        } else {
            placeSupply(streets, numS);
        }
    }
	/**
	Place the bats in a random empty room
	@param streets=array of streets
	@param numS=number of total streets
	*/
    public static void placeUber(Street[] streets, int numS) {
        int temp = (int)(numS*Math.random());
        if(streets[temp].getType()==0) {
            streets[temp].setType(6);
        } else {
            placeUber(streets, numS);
        }
    }
	/**
	Checks if the player has entered a deadly room
	@param streets=array of streets
	@param currentStreet=room the player is in
	@return true if the player should die, false if the player is in a safe room
	*/
    public static boolean isDead(Street[] streets, int currentStreet) {
        return streets[currentStreet].getType()==2 ||
               streets[currentStreet].getType()==3 ||
               streets[currentStreet].getType()==4;
    }
	public static void printInfo(Street[] streets, int bullets, int currentStreet) {
		System.out.println("You are in Street " + streets[currentStreet].getStreetNum());
        System.out.println("You have " + bullets + " bullets");
        System.out.println(streets[currentStreet].getFlavor());
        System.out.println("There are intersections to streets "
                           + streets[currentStreet].getConnect(0) + ", "
                           + streets[currentStreet].getConnect(1) + ", and "
                           + streets[currentStreet].getConnect(2));
			
		if(streets[streets[currentStreet].getConnect(0)-1].getType()==3 ||
		   streets[streets[currentStreet].getConnect(1)-1].getType()==3 ||
		   streets[streets[currentStreet].getConnect(2)-1].getType()==3)
		{
			System.out.println("You hear a faint gunshot.");
		}
		if(streets[streets[currentStreet].getConnect(0)-1].getType()==4 ||
		   streets[streets[currentStreet].getConnect(1)-1].getType()==4 ||
		   streets[streets[currentStreet].getConnect(2)-1].getType()==4)
		{
			System.out.println("You smell a drugged up gangster.");
                }
		if(streets[streets[currentStreet].getConnect(0)-1].getType()==2 ||
		   streets[streets[currentStreet].getConnect(1)-1].getType()==2 ||
		   streets[streets[currentStreet].getConnect(2)-1].getType()==2)
		{
			System.out.println("You sense a mobster!");
		}
	}
}