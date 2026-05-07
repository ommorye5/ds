import java.rmi.*;  
import java.rmi.registry.*;  
public class MyServer
{  
	public static void main(String args[])
	{  
		try
		{  
			Adder adderObject=new AdderRemote();  
			Naming.rebind("rmi://localhost:5000/RemoteObject",adderObject);  
		}
		catch(Exception e)
		{
			System.out.println(e);
		}  
	}  
}  