import java.util.*;

interface Vehicle {
	String passengerName = "OM";
	int maxPassenger = 3;
	int maxSpeed = 30;
}

interface LandVehicle extends Vehicle{
	int numWheels = 4;
	void drive();
}

interface SeaVehicle extends Vehicle{
	int displacement = 1000;
	void launch();
}

class Car implements LandVehicle
{
	String carName = "Car";
	public void input(){
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter name of Car: ");
		carName = sc.nextLine();
	}
	public void drive(){
		System.out.println(passengerName+" driving " + carName + " at the speed of "+ maxSpeed+" km/hr with "+maxPassenger+" others" );
	}
}

class Hovercraft implements LandVehicle,SeaVehicle
{
	String hoverName = "HoverCraft";
	public void input(){
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter name of HoverCraft: ");
		hoverName = sc.nextLine();
	}
	public void drive(){
		System.out.println(passengerName+" driving " + hoverName + " at the speed of "+ maxSpeed+" km/hr with "+maxPassenger+" others" );
	}
	public void launch(){
		System.out.println(passengerName+" swimming " + hoverName + " at the speed of "+ maxSpeed+" km/hr with "+maxPassenger+" others" );
	}
}

class Ship implements SeaVehicle
{
	String shipName = "Titanic";
	public void input(){
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter name of Ship: ");
		shipName = sc.nextLine();
	}
	public void launch(){
		System.out.println(passengerName+" swimming " + shipName + " at the speed of "+ maxSpeed+" km/hr with "+maxPassenger+" others" );
	}
}


class interfaceUsed{

    
public static void main(String arg[]){
	System.out.println("Land vehicle:");
	Car l=new Car();
    l.input();
    l.drive();
    
	System.out.println("*****Hovercraft vehicle******");
	Hovercraft l1=new Hovercraft();
    l1.input();
	l1.drive();
    l1.launch();

	System.out.println("*****Sea vehicle******");
	Ship s=new Ship();
	s.input();
    s.launch();

}
}