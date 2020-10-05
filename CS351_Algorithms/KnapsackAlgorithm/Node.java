class Node implements Comparable {
    Node left, right, parent;
    int profit, weight, index;
    double bound, ratio;

    //for root node
    public Node() {}

    //for child nodes
    public Node(Node n) {
        parent = n;
    }

    public int getBenefit() {return profit;}
    public int getWeight() {return weight;}
    public int getIndex() {return index;}
    public double getBound() {return bound;}
    public double getRatio() {return ratio;}
    public Node getLeft() {return left;}
    public Node getRight() {return right;}
    public Node getParent() {return parent;}

    public void setBound(int b) {bound = b;}
    public void setLeft(Node n) {left = n;}
    public void setRight(Node n) {right = n;}

    //fill data of node as if this is a left node
    public void fillLeft(Item[] items, int maxWeight) {
        index = parent.getIndex() + 1;
        profit = parent.getBenefit() + items[index-1].getBenefit();
        weight = parent.getWeight() + items[index-1].getWeight();
        ratio = items[index-1].getRatio();
        //set bound to 0 if w>W
        if(weight > maxWeight) {
            bound = 0;
        } else {
            bound = parent.getBound();
        }
    }

    //fill data of node as if this is a right node
    public void fillRight(Item[] items) {
        index = parent.getIndex() + 1;
        profit = parent.getBenefit();
        weight = parent.getWeight();
        ratio = items[index-1].getRatio();
    }

    @Override
    public String toString() {
        return "Benefit: " + profit + "\nWeight: " + weight +"\nBound: " + bound + "\n";
    } 

    public int compareTo(Object o) {
        //Make o an Item
		return Double.compare(ratio, ((Node)o).getRatio());
	}
}