public class Item implements Comparable {
    int id;
    int weight;
    int benefit;
    double ratio;

    //Constructor
    public Item(int i, int w, int b) {
        id = i;
        weight = w;
        benefit = b;
        ratio = b/w;
    }

    public int getWeight() {
        return weight;
    }

    public int getBenefit() {
        return benefit;
    }

    public double getRatio() {
        return ratio;
    }

    public int compareTo(Object o) {
        //Make o an Item
		return Double.compare(ratio, ((Item)o).getRatio());
	}
}