class Street {
    int streetNum, streetType; //streetType 0=nothing, 1=start, 2=wumpus, 3=blood, 4=crip, 5=bullets, 6=uber
    int[] connectedStreets = new int[3];
    String text;
    
	/**
	@param r = street number
	@param rt = street type
	@param c = array of connected streets
	@param t = flavor text
	*/
    public Street(int r, int rt, int[] c, String t) {
        streetType=rt;
        streetNum = r;
        connectedStreets = c;
        text = t;
    }
	/**
	@param t=street type
	*/
    public void setType(int t) {
        streetType = t;
    }
	/**
	@return street type
	*/
    public int getType() {
        return streetType;
    }
	/**
	@return street number
	*/
    public int getStreetNum() {
        return streetNum;
    }
	/**
	@param c = which connected street to return
	@return connected street of position c
	*/
    public int getConnect(int c) {
        return connectedStreets[c];
    }
	/**
	@return flavor text
	*/
    public String getFlavor() {
        return text;
    }
	/**
	@return street number, connected streets, and flavor text
	*/
    public String toString() {
        return "Street Number: " + streetNum + ", Connected Streets: "
                + connectedStreets[0] + " and " + connectedStreets[1] + " and "
                + connectedStreets[2] + ", Flavor Text: " + text;
    }
}