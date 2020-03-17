class Complex
{
	double real, image;
	
	Complex()
	{
		real = image = 0;
	}
	
	Complex(double real, double image)
	{
		this.real = real;
		this.image = image;
	}

	public void ShowNumber()
	{
		System.out.println(real + " + " + image + "i");
	}
	public void Absolute()
	{
		System.out.println(Math.sqrt(real*real + image*image));
	}
	public void Compare(long c)
	{
		if ((long)(Math.sqrt(real*real + image*image)) < c)
			System.out.println(true);
		else
			System.out.println(false);
	}
}
