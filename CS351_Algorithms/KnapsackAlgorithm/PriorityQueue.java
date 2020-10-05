public class PriorityQueue {
    Node[] queue;
    int last;

    public PriorityQueue(int maxsize) {
        queue=new Node[maxsize+1];
		last=0;
    }




    public void enqueue(Node x) {
		if(isFull()) return;
		queue[++last]=x;
		bubbleup(last);
	}
	public void bubbleup(int pos) {
		if(pos==1) return;
		if(queue[pos].compareTo(queue[pos/2])<=0) return;
		swap(pos,pos/2);
		bubbleup(pos/2);
	}
	private void swap(int x, int y) {Node temp = queue[x]; queue[x]=queue[y]; queue[y]=temp;}
	
	public Node dequeue() {
		if(isEmpty()) return null;
		Node saved = queue[1];
		queue[1]=queue[last--];
		bubbledown(1);
		return saved;
	}
	public void bubbledown(int pos) {
		if(last<pos*2) return;
		int runt = pos*2;
		if(pos*2+1 <= last && queue[pos*2+1].compareTo(queue[pos*2])<0) runt++; //moves from left child to right child
		if(queue[pos].compareTo(queue[runt])>0){
			swap(pos,runt);
			bubbledown(runt);
		}
		
	}
	
	public Node getFront() {
		if(isEmpty()) return null;
		else return queue[1];
	}
	
	public void makeEmpty() {last=0;}
	public int size() {return last;}
	public boolean isEmpty() {return last <=0;}
	public boolean isFull() {return last>=queue.length-1;}
}