import java.util.*;

class Gradesheet{

	public static void main(String[] args){
	
	Scanner sc = new Scanner(System.in);
	System.out.println("Enter marks of PCM");
	int phy = sc.nextInt();
	int chem = sc.nextInt();
	int math = sc.nextInt();
	float total = 0,percentage=0;
	total = phy + chem + math;
	percentage = (total/300)*100;
	System.out.println("Percentage obtained : " + percentage);

	if(percentage>=90)
	System.out.println("Grade A");
	else if(percentage>=80)
	System.out.println("Grade B");
	else if(percentage>=70)
	System.out.println("Grade C");
	else if(percentage>=60)
	System.out.println("Grade D");
	else
	System.out.println("Grade Fail");
}
}