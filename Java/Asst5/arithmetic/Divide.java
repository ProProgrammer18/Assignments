package arithmetic;

import java.util.Scanner;

public class Divide {
    public void divide(){
        Scanner s = new Scanner(System.in);
        double a,b;
        System.out.println("Enter two numbers:");
        a = s.nextInt();
        b = s.nextInt(); 
        System.out.println("Division: "+ (double)(a/b));
        System.out.println("-------------------------------------------------------------------------------\n");

    }
}
