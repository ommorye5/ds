import java.rmi.*;  
public class MyClient
{  
	public static void main(String args[])
	{  
		try
		{  
			Adder adderObject=(Adder)Naming.lookup("rmi://localhost:5000/RemoteObject");  
			System.out.println(adderObject.add(34,4));  
		}
		catch(Exception e){}  
	}  
}