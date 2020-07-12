import java.util.Scanner;
class Example
{
	public static void main(String args[])
	{
		Scanner in = new Scanner(System.in);
		double a = in.nextDouble(), b = in.nextDouble();
		Complex num, num2;
		num = new Complex(a, b);
		num2 = new Complex();
		num.ShowNumber();
		num2.ShowNumber();
		num.Compare(in.nextLong());
		num.Absolute();
	}
}
