#include<stdio.h>
int continue_or_not();// menu function
int pick_choice();// menu function
void menu();	//menu function

int common(int, int, int,int);		//part 1
int is_number_prime( int , int );	//part 1

void f(int);	//Part 3

int if_fits_formula(int, int,int);	//Part 4 function
int find_digit_number(int);		//Part 4 function

char find_the_frst_cptl(char []);//Part 5 function

int main(int argc, char const *argv[])
{
	menu();
	return 0;
}

void menu()
{
	int number, nmbr_of_dgt, fit_or_not;;
	int select;
	char str[100],ch;
	int n1,n2,arr1[50],arr2[50];
	//in part 1
	int initial_factor=2;			//it can be change in function (part 1)
	int result;
	int flag=0;						//for dont get in the while loop in the recursive common function (part 1)
	//flag alow to changing prime factor number (part 1)
	select=pick_choice();

	while(select!=6)
	{
			if (select==1)
		{
			printf("Input the fist number:");
			scanf("%d",&n1);
			printf("Input the second number:");
			scanf("%d",&n2);		
			result =common(n1,n2,initial_factor,flag);
			printf("The product of the common divisors (GCD) = %d\n\n",result );
  			select=continue_or_not();

			
		}
		else if(select==2)
		{
			printf("I didnt make second part...\n");
			select=continue_or_not();

		}
		else if(select==3)
		{	
			printf("Please Enter any number to function :");
  			scanf("%d", &number);
  			f(number);
  			select=continue_or_not();
		}
		else if(select==4)
		{
			printf("Input:");
			scanf("%d",&number);
			nmbr_of_dgt=find_digit_number(number);
			fit_or_not=if_fits_formula(number,nmbr_of_dgt,nmbr_of_dgt);
			
			if (fit_or_not==number)
			{
				printf("Output: Equal\n");
			}
			else
				printf("Output: Not Equal\n");

			select=continue_or_not();
		}
		else if(select==5)
		{
			printf("Input:");
			scanf("%s",str);
			ch=find_the_frst_cptl(str);
			printf("Output:%c\n",ch);
			select=continue_or_not();
		}
		else if(select!=6)
		{
			printf("\nWrong input pick again\n\n");
			select=pick_choice();

		}
	}	
}
int pick_choice()
{
	int select;
	printf("-----------------------------------------------------------------\n");
	printf("1-Find multipliers of numbers					|\n2-Sort an array							|\n3-Calculating function in recursively				|\n4-Control Function whether					|\n5-Checks whether the number provides value			|\n6-Exit								|\n");
	printf("-----------------------------------------------------------------\nSelect:");	
	scanf("%d",&select);
	return select;
}
int continue_or_not()
{
	int select;
	char a;
	printf("Do you want to continue (y/n)\n");
	scanf(" %c",&a);
	if (a=='y')
	{
		select=pick_choice();
		return select;
	}
	else if (a=='n')
	{
		return 6;
	}

	else
		return 0;				//wrong input so he/she will go "else if(select!=6) case so s/he will be pick again 

}
//Part 3
void f(int n)
{
	if (n>1)
	{
		if (n%2==0)
		{
			printf("%d ",(n/2));
			f(n/2);
		}
		else
		{
			printf("%d ",(3*n)+1);
			f((3*n)+1);
		}
	}
	else
		printf("\n");			//when function end
}

//Part 4
int if_fits_formula(int n1, int static_digit, int dinamic_digit )	// i take the 3 input two of them about digit 
{
	int result=1,i,divisor=10,a;									// one of them is stable other one is can change 
	if (n1<divisor)
	{
		for ( i = 0; i <static_digit ; ++i)
		{
			result*=n1;
		}
		return result;
	}
	else
	{
		for (int i = 0; i < dinamic_digit; ++i)
		{
			divisor*=divisor;
		}

		a=n1/divisor;							//its 1 element of number

		for ( i = 0; i <static_digit ; ++i)
		{
			result*=a;
		}

		result=result+if_fits_formula(n1%divisor,static_digit,dinamic_digit-1);	
		return result;

	}

}
int find_digit_number(int n1)				//to find the number of digit in recursive
{
	if (n1<=9)
	{
		return 1;
	}
	else
	{
		if (n1/10>0)
		{
			return 1+find_digit_number(n1/10);
		}
	}
}
//Part 5
char find_the_frst_cptl(char str[])
{
	if (str[0]=='\0')
	{
		return ' ';						//return white space because there is no uppercase letter
	}

	else if (str[0]<='Z' && str[0]>='A')
	{
		return str[0];
	}

	else
		find_the_frst_cptl(&str[1]);
}

//Part 1
int is_number_prime(int prime_factor, int divisor)			//this function controls the whether divisor is prime or not
{
	int flag=0;

	if (divisor<=2)
	{
		return flag;
	}

	else if (prime_factor%divisor==0)
	{
		flag++;
		return flag;
	}

	else
		return flag+is_number_prime(prime_factor,divisor-1);
}
// Part 1
int common(int n1,int n2,int prime_factor, int flag)		//This returns product of the common prime numbers
{
	int i;
	int divisor;
	int result=1;

	while(flag!=0)
	{
		prime_factor++;
		divisor=prime_factor-1;							//incresing untill value prime
		flag=is_number_prime(prime_factor,divisor);
	}
	flag=0;

	if (prime_factor>n1 || prime_factor>n2)				// if prime number biigger than our numbers function should be stop
	{
		return 1;
	}

	else
	{
		if (n1%prime_factor==0 && n2%prime_factor==0)
		{
			flag=0;
			n1=n1/prime_factor;
			n2=n2/prime_factor;
			return prime_factor*common(n1,n2,prime_factor,flag=0);		//prime numbers product with result because it divedes both of them
		}

		else if (n1%prime_factor==0 && n2%prime_factor!=0)
		{
			n1=n1/prime_factor;
			return common(n1,n2,prime_factor,flag=1);
		}

		else if (n1%prime_factor!=0 && n2%prime_factor==0)
		{
			n2=n2/prime_factor;
			return common(n1,n2,prime_factor,flag=1);

		}

		else if (n1%prime_factor!=0 && n2%prime_factor!=0)
		{

			return common(n1,n2,prime_factor++,flag=1);
		}
	}
}