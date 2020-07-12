import java.util.Scanner;
class RootsFinder
{
	public static void main(String args[])
	{
		Scanner in = new Scanner(System.in);
		System.out.print("Введите значения коэффициентов квадратного уравнения: ");
		double a = in.nextDouble(), b = in.nextDouble(), c = in.nextDouble();
		double D = b*b - 4*a*c;
		if (a == 0)
		{
			System.out.println("x = " + (-c/b));
		}
		else if (b == 0)
		{
			System.out.println("x1 = " + Math.sqrt(c/a));
			System.out.println("x2 = -" + Math.sqrt(c/a));
		}
		else
		{
			if (D > 0)
			{
				System.out.println("x1 = " + (-b + Math.sqrt(D))/(2*a));
				System.out.println("x2 = " + (-b - Math.sqrt(D))/(2*a));
			}
			else if (D == 0)
			{
				System.out.println("x1 = " + (-b + Math.sqrt(D))/(2*a));
			}
			else
			{
				System.out.println("Корней нет");
			}
		}
	}
}
