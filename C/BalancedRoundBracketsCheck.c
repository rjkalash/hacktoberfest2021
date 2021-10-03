//to check whether the parenthesis are balanced in a given expression.  
#include<stdio.h>  
int main()  
{  

	//the array containing the expression
    char expression[50];  
    int x=0, i=0;  
    printf("\nPlease Enter the expression");  
    scanf("%s", expression); 
	 
//get the inpjut iteratively until user ask to stop program     
 while(expression[i]!= '\0')  
    {  
    // if the ith position in the expression contains'(' ,increment x
     if(expression[i]=='(')  
        {  
            x++;    
        }  
     // if the ith position in the expression contains')' ,decrement x     
     else if(expression[i]==')')  
        {  
            x--;  
			//if no more open brackets, get out of the loop 
            if(x<0)  
            break;  
        }  
    //stepping into next character in the expression
    i++;         
    }  
    // x=0 means no more open or close brckets left.. paranthesis balanced!  
    if(x==0)  
    {  
        printf("Expression has balanced paranthesis");  
    }  
      
    else  
    {  
        printf("Unbalanced Paranthesis");  
    }  
    return 0;  
}  
