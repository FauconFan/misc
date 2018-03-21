package src.utils;

public class Tuple <T, Q>
{
	public final T first;
	public final Q second;

	public Tuple(T t, Q q)
	{
		this.first  = t;
		this.second = q;
	}

	public T getFirst()
	{
		return (this.first);
	}

	public Q getSecond()
	{
		return (this.second);
	}
}
