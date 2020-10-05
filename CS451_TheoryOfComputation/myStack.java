public class myStack{
	char[] items;
	int top;
	
	public myStack(int size) {
		items = new char[size];
		top = 0;
	}
	public myStack() {
		items = new char[100];
		top = 0;
	}
	
	public void push(char x) {
		if(isFull()) return;
		items[top] = x;
		top++;
	}
	public char pop() { return isEmpty()?'\u0000':items[--top]; }
	
	public char getTop() {
		if(isEmpty()) return '\u0000';
		return items[top-1];
		// return IsEmpty()?null:items[top-1];
		// return boolean?true:false;
		// if the boolean is true, it returns the first statement, otherwise it returns the second.
	}
	public void makeEmpty() {top=0;}
	public int size() {return top;}
	public boolean isEmpty() {return top==0;}
	public boolean isFull() {return top>=items.length;}
}
