/*How to get prime numbers and the sum of them. This was a chalenge that I blew because I got nervous and after the time was up I couldn't stop until I had figured out how to solve it*/

public class Main
{
  public static void main (String[]args)
  {
    int num = 1;
    int sum = 0;

    for (int j = 2; j <= 1000; j++)
      {
          num = 1;
        	for (int i = 2; i <= j; i++)
        	  {
        	    if (j % i == 0 && i != j)
        	      {
            		num = 0;
            		break;
        	      }
        	      
        	  }
    
    	if (num == 1)
    	  {
    	    System.out.println (j);
    	    sum += j;
    
    	  }


      }
      
      System.out.println (sum);

  }




}
