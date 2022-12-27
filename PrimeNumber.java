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


/*Javascript code

function main (params) {
    const primeNumbers = [];
    //Starts from 2 since 2 is the first prime number;
    for(var j = 2; j<= 1000;j++){
        if(DecidePrime(j) == 1){
            primeNumbers.push(j);
        }
    }
    
    var sum = primeNumbers.reduce(SumArray, 0);
    
    return sum;
}

//Returns 1 for prime number and  0 for non prime number
function DecidePrime(num){
    
    for(var i = 2; i <= 1000; i++){
        if(num <= i){
            break;
        }
        if(num % i == 0 && num != i){
            return 0;
            break;
        }
    }
    
    return 1;
}

//Auxiliary for the reduce function
function SumArray(total, num){
    return total + num;
} */
