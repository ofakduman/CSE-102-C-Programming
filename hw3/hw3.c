#include<stdio.h>
#include<stdlib.h>   //to use the atoi function
#include<string.h>
#include<math.h>		//to use the power function

int sub(int,int);
int mult(int, int);
int div1(int,int);
int modul(int,int);
int power_t(int,int);
int doit(int f(), int , int );
int add(int ,int );


void take_grades(int [] );
double calculate_homework(int []);
void take_exam_grades(int []);
double calculate_lab(int []);
double calculate_all(int,int [],int);


void menu();	



int main()
{
	
	menu();

	return 0;
}





void menu()
{
	int add1=0,substraction=0,multiplication=0,division=0,modulo=0,power=0;	
	int spaces=0;					//I count the spaces in the character array because of the user can take input 1 or 2
	int result=0;					//The result
	int end_of_array,beginning_of_array,beginning_of_array2,end_of_array2;		//To define end and starting array
	int tempcounter=0;						//to count the temprory array`s cells
	char operat[30];
	char temp[30];					//Temproary array for copy values from main array
	int number, number1, number2;			//Numbers which doing operation with 



	int homework_grades[10];
	int lab_grades[10];
	int exams[2];
	double avarage_homework;							//Avarage of homeworks
	double avarage_lab;
	double weighted_avarage;							//The result of all notes according to weighted avarage


	int height;											//For the pattern
    int space, i,j,k;
    printf("Input the height:");

	int entered_number;

	while(entered_number!=4)
	{
		printf("\n\n\n***** MENU *****\n");
		printf("1. Simple Calculator\n2. Calculating student`s weighted grades\n3. Draw a pattern\n4. Exit\n");
		printf("\nChoice:");
		scanf("%d",&entered_number);

	switch(entered_number)
	{
			
		case 1:	
	

	printf("Press the e to exit!\n");
	scanf("%[^\n]",&operat);			//to get the whole string


	while(operat[0]!='E' && operat[0]!='e')				// to quit when press e or E
	{

		for(i=0 ; operat[i]!='\0' ; i++)  //For the count whether 1 or 2 input for exmp. + 99 78 there are 2 spaces and three input first one (+) second one(99) the last one is (78)
		{
			if (operat[i]==' ')
			{
				spaces++;
			}
		}


		for(i=0 ; operat[i]!=' ' ; i++)// to find the first input 
		{
			if (operat[i]=='-')
			{
				substraction++;
			}
		}

		for(i=0 ; operat[i]!=' ' ; i++)
		{ 
			if (operat[i]=='*')
			{
				multiplication++;
			}
		}

		for(i=0 ; operat[i]!=' ' ; i++)
		{
			if (operat[i]=='/')
			{
				division++;
			}
		}


		for(i=0 ; operat[i]!=' ' ; i++)
		{
			if (operat[i]=='+')
			{
				add1++;
			}
		}

		for(i=0 ; operat[i]!=' ' ; i++)
		{
			if (operat[i]=='*')
			{
				power++;
			}
		}

		for(i=0 ; operat[i]!=' ' ; i++)
		{
			if (operat[i]=='%')
			{
				modulo++;
			}
		}


		if (spaces==1)												// This means there are 1 number and 1 operator so there is 1 space (+ 77)
		{

			for (int i = 0; i < operat[i]!='\0'; ++i)
			{
			end_of_array=i;												//to define and of array
			}

			for (int i = 0; operat[i]!='\0'; ++i)
			{
				if (operat[i]==' ')
				{
					beginning_of_array=i+1;								//The beginning of the first number
				}

			}

			for (i=beginning_of_array; i <= end_of_array; ++i)
			{
			temp[tempcounter]=operat[i];								//To carry out the number to another array
			tempcounter++;
			}

			number=atoi(temp);											//Finally we obtain a integer number
			tempcounter=0;												//to use again the temp counter
			memset(temp, 0, sizeof(temp));								// to clear the array

		}




		else if (spaces==2)												// This means there are 2 number and 1 operator so there is 2 spaces
		{

			for (int i = 0; i < operat[i]!='\0'; ++i)
			{
			end_of_array2=i;												//to define and of array
			}


			for (int i = 0; operat[i]!=' '; ++i)
			{
				//to find the first space
			}
			beginning_of_array=i+1;

			for (i=beginning_of_array ; operat[i]!='\0'; ++i)
			{
				if (operat[i]==' ')
				{
					beginning_of_array2=i+1;								//The beginning of the second number
				}
			}

			end_of_array=beginning_of_array2-2;												//The end of to the first array because of between

			for (int i=beginning_of_array; i <= end_of_array; ++i)			//between beginning of second and ending of fisrt array there must be 1 space 
			{
			temp[tempcounter]=operat[i];								//To carry out the number to another array
			tempcounter++;
			}

			tempcounter=0;												//To use again temp counter
			number1=atoi(temp);											//Finally we obtain a integer number
			memset(temp, 0, sizeof(temp));								// to clear the array

			for (i=beginning_of_array2; i <= end_of_array2; ++i)			//between beginning of second and ending of fisrt array there must be 1 space 
			{
			temp[tempcounter]=operat[i];								//To carry out the number to another array
			tempcounter++;
			}

			tempcounter=0;												//To use again temp counter

			number2=atoi(temp);

			memset(temp, 0, sizeof(temp));								// to clear the array


		}



		if (add1==1 && spaces==2)
		{

			result=doit(add,number1,number2);
			printf("%d\n",result);

		}

		else if (add1==1 && spaces==1)
		{

			result=doit(add,result,number);
			printf("%d\n",result);

		}


		else if (substraction==1 && spaces==1)
		{

			result=doit(sub,result,number);
			printf("%d\n",result);

		}

		else if (substraction==1 && spaces==2)
		{

			result=doit(sub,number1,number2);
			printf("%d\n",result);

		}


		else if (multiplication==1 && spaces==1)
		{

			result=doit(mult,result,number);
			printf("%d\n",result);

		}

		else if (multiplication==1 && spaces==2)
		{

			result=doit(mult,number1,number2);
			printf("%d\n",result);

		}


		else if (division==1 && spaces==1)
		{

			result=doit(div1,result,number);
			printf("%d\n",result);

		}

		else if (division==1 && spaces==2)
		{

			result=doit(div1,number1,number2);
			printf("%d\n",result);

		}

		else if (power==2 && spaces==1)
		{

			result=doit(power_t,result,number);
			printf("%d\n",result);

		}

		else if (power==2 && spaces==2)
		{

			result=doit(power_t,number1,number2);
			printf("%d\n",result);

		}

		else if (modulo==1 && spaces==1)
		{

			result=doit(modul,result,number);
			printf("%d\n",result);

		}

		else if (modulo==1 && spaces==2)
		{

			result=doit(modul,number1,number2);
			printf("%d\n",result);

		}




		memset(operat, 0, sizeof(temp));								// to clear the array

		


		beginning_of_array=0;											//All of theese are for the use calculation again
		end_of_array=0;
		beginning_of_array2=0;
		end_of_array2=0;
		add1=0;
		substraction=0;
		multiplication=0;
		division=0;
		power=0;
		modulo=0;
		spaces=0;

		scanf(" %[^\n]",&operat);			//to get the whole string

	}


			break;





		case 2:	

			printf("\nInput the homework grades\n");
			take_grades(homework_grades);						//Take the whole homework grades
			avarage_homework=calculate_homework(homework_grades);
			printf("avarage_homework:%.2f\n",avarage_homework );
			
			printf("\nInput the lab grades\n");
			take_grades(lab_grades);							//Take the whole lab grades
			avarage_lab=calculate_lab(lab_grades);			//I took the inputs in the calculate_lab function
			printf("avarage_lab:%.2f\n",avarage_lab );


			

			take_exam_grades(exams);						//takes the inputs (midterm and final exam) in the exams array


			weighted_avarage=calculate_all(avarage_homework,exams,avarage_lab);  


			printf("\nThe Weighted avarage:%.2f\n",weighted_avarage );
					



			break;

		case 3:

		printf("Input the height:");
		scanf("%d",&height);
		printf("\n\n\n\n");
		for (int i = 1; i <= height; ++i)
 	   {
	        for (space = height-i; space >0 ; space--)
	        {
	            printf(" ");
	        }
	        printf("/");

	        for ( j = 2*i-2; j >0; j--)                 //number of * will be (x-1)2
	        {
	            printf("*");
	        }

	        printf("\\");


	        printf("\n");
   		 }

   		 for (i = 1; i <= height; ++i)                   //the bottom part of pattern
    	{
	        for (space = 1; space <i ; space++)
	        {
	            printf(" ");
	        }
	        printf("\\");
	        for (j = 2*(height-i); j > 0; j--)
	        {
	            printf("*");
	        }

	        printf("/");


	        printf("\n");
	    }



			break;

		case 4:


			break;

		default:
				printf("Error Invalid Input\n\n\n");

		}
	}
}

int doit(int f(int a , int b), int number12, int number22)
{
	int c;
	c=f(number12, number22);
	return c;
}
		
int add(int number1,int number2)
{	
	int k;
	k=number1+number2;
	return k;
}
int sub(int number1,int number2)
{	
	int k;
	k=number1-number2;
	return k;
}

int mult(int number1,int number2)
{	
	int k;
	k=number1*number2;
	return k;
}

int div1(int number1,int number2)
{	
	int k;
	k=number1/number2;
	return k;
}

int power_t(int number1,int number2)
{	
	int k;
	k= pow(number1,number2);
	return k;
}

int modul(int number1,int number2)
{	
	int k;
	k=number1%number2;
	return k;
}




//Input the homework grades
void take_grades(int homework[])
{
	int i;


	for (int i = 0; i < 10; ++i)
	{
		printf("[%d]= ",i+1 );						
		scanf("%d",&homework[i]);
	}
}

//Take the midterm and final exam`s note
void take_exam_grades(int exams[])
{	
	for (int i = 0; i < 2; ++i)
	{	
		if (i==0)
		{
			printf("Input the Midterm exam result:");
		}
		else
			printf("Input the Final exam result:");


		scanf("%d",&exams[i]);
	}
}

//Caldulate the avarage of the homework`s grade
double calculate_homework(int homework_grades[])
{	
	double sum=0;

	for (int i = 0; i <10 ; ++i)
	{
		sum+=homework_grades[i];	
	}

	return sum/10.0;
}

double calculate_lab(int lab_grades[])
{
	double avarage=0;
	int i;



	for (int i = 0; i < 10; ++i)
	{
		avarage+=lab_grades[i];
	}


	return avarage/10.0;
}


//The result of all notes according to weighted avarage
double calculate_all(int avarage_homework, int exams[], int avarage_lab)
{
	double w_homework, w_lab, w_midterm, w_final , result;

	w_homework=(avarage_homework/10.0);

	w_lab=(avarage_lab/10.0)*2;

	w_midterm=(exams[0]/10.0)*3;

	w_final=(exams[1]/10.0)*4;

	result=w_final+w_midterm+w_lab+w_homework;

	return result;
}
