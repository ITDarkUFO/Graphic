import java.util.Scanner;
import java.util.Arrays;
public class Points
{
    final static int N = 5;
	public static void main(String args[])
	{
		thdPoint[] arr = new thdPoint[N];

		for (int i = 0; i < 5; i++)
        {
            arr[i] = new thdPoint(N - i, N - i, N - i);
        }

        Arrays.sort(arr);

        System.out.println(arr[arr.length - 1].getPos());

	}
}

class odPoint
{
	protected double x;
	odPoint()
	{
		x = 0;
	}

	odPoint(double x)
	{
		this.x = x;
	}

	String getPos()
	{
		return Double.toString(x);
	}

	double distanceToOrigin()
	{
		return x;
	}

	double distanceFromPointToPoint(odPoint b)
	{
		return Math.abs(x - b.x);
	}
}

class twdPoint extends odPoint
{
	protected double y;

	twdPoint()
	{
		x = y = 0;
	}

	twdPoint(double x, double y)
	{
		this.x = x;
		this.y = y;
	}

	String getPos()
	{
		return "(" + x + ", " + y + ")";
	}

	double distanceToOrigin()
	{
		return Math.sqrt(Math.pow(x, 2) + Math.pow(y, 2));
	}

	double distanceFromPointToPoint(twdPoint b)
	{
		return Math.sqrt(Math.pow(b.x - x, 2) + Math.pow(b.y - y, 2));
	}
}

class thdPoint extends twdPoint implements Comparable
{
	protected double z;

	thdPoint()
	{
		x = y = z = 0;
	}

	thdPoint(double x, double y, double z)
	{
		this.x = x;
		this.y = y;
		this.z = z;
	}

	String getPos()
	{
		return "(" + x + ", " + y + ", " + z + ")";
	}

	double distanceToOrigin()
	{
		return Math.sqrt(Math.pow(x, 2) + Math.pow(y, 2) + Math.pow(z, 2));
	}

	double distanceFromPointToPoint(thdPoint b)
	{
		return Math.sqrt(Math.pow(b.x - x, 2) + Math.pow(b.y - y, 2) + Math.pow(b.z - z, 2));
	}

	public int compareTo(Object p)
	{
        thdPoint tmp = (thdPoint)p;
        return (int)(this.distanceToOrigin() - tmp.distanceToOrigin());
    }
}
