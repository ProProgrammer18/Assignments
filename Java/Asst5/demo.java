import arithmetic.add.add;
import arithmetic.divide.divide;
import arithmetic.multiply.multiply;
import arithmetic.square.square;
import arithmetic.squareroot.squareroot;
import arithmetic.sub.sub;

import java.util.*;

public class demo {
      public static void main(String[] args) {
        boolean i = true;
        double x, y;
        do {
            Scanner s = new Scanner(System.in);
            System.out.println("-------------------------------------------------------------------------------");

            System.out.println("Enter your choice: \n1.add\n2.sub\n3.multiply\n4.divide\n5.square\n6.squareroot\n7.Exit");
            int choice = s.nextInt();

            switch (choice) {
                case 1:
                    System.out.println("Enter two numbers:");
                    x = s.nextDouble();
                    y = s.nextDouble();
                    add a = new add();
                    a.add(x, y);
                    break;
                case 2:
                    System.out.println("Enter two numbers:");
                    x = s.nextDouble();
                    y = s.nextDouble();
                    sub b = new sub();
                    b.sub(x, y);
                    break;
                case 3:
                    System.out.println("Enter two numbers:");
                    x = s.nextDouble();
                    y = s.nextDouble();
                    multiply c = new multiply();
                    c.multiply(x, y);
                    break;
                case 4:
                    System.out.println("Enter two numbers:");
                    x = s.nextDouble();
                    y = s.nextDouble();
                    divide d = new divide();
                    d.divide(x, y);
                    break;
                case 5:
                    System.out.println("Enter the number:");
                    x = s.nextDouble();
                    square e = new square();
                    e.square(x);
                    break;
                case 6:
                    System.out.println("Enter the number:");
                    x = s.nextDouble();
                    squareroot f = new squareroot();
                    f.squareroot(x);
                    break;
                case 7:
                    i = false;
                    break;
                default: 
                    System.out.println("Select a valid option!!");
            }
        } while (i);
    }
}
