package squareroot;
import java.lang.Math;
import java.util.*;
public class Squareroot {
    
    public void squareroot(){
        Scanner s = new Scanner(System.in);
        double a;
        System.out.println("Enter two numbers:");
        a = s.nextInt();
        System.out.println("Squareroot: "+ Math.sqrt((double)a));
        System.out.println("-------------------------------------------------------------------------------\n");

    }
}
