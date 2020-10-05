import java.io.*;
import java.util.*;

class Project2 {
    public static void main(String [] args) {
        myStack s = new myStack();
        Scanner inputScanner = new Scanner(System.in);
        String input = inputScanner.nextLine();
        int i = 0;  //index of string
        String state = "s0";


        System.out.println("input string: " + input);
        //fill stack
        boolean done = false;
        while(!done) {
            switch(state) {
                case "s0":
                    System.out.println("State 0");
                    s.push('#');
                    state = "s1";
                    break;

                case "s1":
                    System.out.println("State 1");
                    if(input.charAt(i) == '(') {
                        s.push('(');
                        i++;
                        break;
                    }
                    if(Character.isDigit(input.charAt(i))) {
                        state = "s2";
                        i++;
                        break;
                    }
                    state = "sReject";
                    break;

                case "s2":
                    System.out.println("State 2");
                    if(Character.isDigit(input.charAt(i))) {
                        i++;
                        break;
                    }
                    if(input.charAt(i) == '+' || input.charAt(i) == '*' || input.charAt(i) == '-') {
                        state = "s3";
                        i++;
                        break;
                    }
                    if(input.charAt(i) == '/') {
                        state = "s4";
                        i++;
                        break;
                    }
                    state = "sReject";
                    break;

                case "s3":
                    System.out.println("State 3");
                    if(Character.isDigit(input.charAt(i))) {
                        i++;
                        state = "s5";
                        break;
                    }
                    state = "sReject";
                    break;

                case "s4":
                    System.out.println("State 4");
                    if(Character.isDigit(input.charAt(i)) && input.charAt(i) != '0') {
                        i++;
                        state = "s5";
                        break;
                    }
                    state = "sReject";
                    break;

                case "s5":
                    System.out.println("State 5");
                    if(Character.isDigit(input.charAt(i))) {
                        i++;
                        break;
                    }
                    if(input.charAt(i) == '+' || input.charAt(i) == '*' || input.charAt(i) == '-') {
                        state = "s3";
                        i++;
                        break;
                    }
                    if(input.charAt(i) == '/') {
                        state = "s4";
                        i++;
                        break;
                    }
                    if(input.charAt(i) == ')') {
                        char temp = s.pop();
                        if(temp != '(') {
                            state = "sReject";
                            break;
                        } else {
                            i++;
                            state = "s6";
                            break;
                        }
                    }
                    if(input.charAt(i) == '=') {
                        char temp = s.pop();
                        if(temp != '#') {
                            state = "sReject";
                            break;
                        } else {
                            i++;
                            state = "s7";
                            break;
                        }
                    }
                    state = "sReject";
                    break;
            
                case "s6":
                    System.out.println("State 6");
                    if(input.charAt(i) == ')') {
                        char temp = s.pop();
                        if(temp != '(') {
                            state = "sReject";
                            break;
                        } else {
                            i++;
                            break;
                        }
                    }
                    if(input.charAt(i) == '=') {
                        char temp = s.pop();
                        if(temp != '#') {
                            state = "sReject";
                            break;
                        } else {
                            i++;
                            state = "s7";
                            break;
                        }
                    }
                    state = "sReject";
                    break;
                
                case "s7":
                    System.out.println("State 7");
                    if(i == input.length()) {
                        state = "sAccept";
                        break;
                    }
                    state = "sReject";
                    break;

                case "sAccept":
                    System.out.println("This String is Accepted");
                    done = true;
                    break;
                
                case "sReject":
                System.out.println("This String is Rejected");
                done = true;
                break;
            }
        }
    }
}