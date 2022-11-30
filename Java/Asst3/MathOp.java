import java.util.*;

class MathOp {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int a, b;
		double ans = 0;

		while (true) {
			System.out.println("1. Add");
			System.out.println("2. Subtract");
			System.out.println("3. Multiply");
			System.out.println("4. Divide");
			System.out.println("5. Square");
			System.out.println("6. Squareroot");
			System.out.println("7. Exit");

			System.out.println("Enter your choice: ");
			int x = sc.nextInt();

			switch (x) {
				case 1:
					System.out.println("Enter two integers");
					a = sc.nextInt();
					b = sc.nextInt();
					ans = a + b;
					System.out.println("Addition: " + ans);
					break;
				case 2:
					System.out.println("Enter two integers");
					a = sc.nextInt();
					b = sc.nextInt();
					ans = a - b;
					System.out.println("Substraction: " + ans);
					break;
				case 3:
					System.out.println("Enter two integers");
					a = sc.nextInt();
					b = sc.nextInt();
					ans = a * b;
					System.out.println("Multiplication: " + ans);
					break;
				case 4:
					System.out.println("Enter two integers");
					a = sc.nextInt();
					b = sc.nextInt();
					ans = a / b;
					System.out.println("Division: " + ans);
					break;
				case 5:
					System.out.println("Enter integer");
					a = sc.nextInt();
					ans = a * a;
					System.out.println("Square: " + ans);
					break;
				case 6:
					System.out.println("Enter integer");
					a = sc.nextInt();
					ans = Math.sqrt(a);
					System.out.println("Squareroot: " + ans);
					break;
				case 7:
					System.exit(0);
					System.out.println("Exiting...");
					break;
			}

		}
	}
}