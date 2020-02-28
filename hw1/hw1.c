#include<stdio.h>
#define RED 0
#define YELLOW 1
#define BLUE 2
#define BLACK 3
#define WHITE 4
#define SQUARE 1
#define RECTANGULAR 2
#define CIRCULAR 3
#define PI 3.14							//In the homework says you can use pi=3 but i decided to use 3.14 because its more right
#include<math.h>                       //To use sqrt and floor functions
#include<time.h>						// To generate the random atack power
#include <stdlib.h>						// for srand() function in genarate random number
double CreateBody (int);	
int setColor(int);
double loadMoves(int, double);
int SetAtackPower(int,int);
void ShowPokemon(int, double, int, double, int);

int main(int argc, char const *argv[])
{
 int shape,color,atack_power;          
 double size_of_body, move_lenght;
	shape=RECTANGULAR;              						 //RECTANGULAR / CIRCULAR / SQUARE // Pick one of them
	size_of_body=CreateBody(shape);
	color = 9999229;
	color= setColor(color);
	move_lenght= loadMoves(shape, size_of_body);							
	atack_power=SetAtackPower(555,999);											
	ShowPokemon(shape,size_of_body,color,move_lenght,atack_power);
	
	return 0;
}

double CreateBody( int shape)
{	
	int r,r2;										//Two variables enough to calculate area of rectangular
	if (shape==1)									
	{
		printf("Input edge of Square pokemon->");		//Taking edge of inputs in the function
		scanf("%d",&r);
		return (r*r);
	}

	else if (shape==2)
	{
		printf("Input edges of Rectangular pokemon->");		
		scanf("%d %d",&r,&r2);
		return (r*r2);
	}

	else if (shape==3)
	{
		printf("Input r of Circular pokemon->");		
		scanf("%d",&r);
		return ((4.0/3)*PI*r*r);					//Area of circular
	}
	else
		printf("Wrong Input try again!!!\n");			//warning for wrong input 


	return shape;
}

int setColor(int color)
{	
	
	if (0<color && color<1000)							//if color number between 0 and 1000 return mod 5 in the other hand return 1
	{
		color=color%5;

		return color;

	}

	else{
		return 1;
		}
}

double loadMoves(int shape, double body_size)	//moves depent of edge so we can find the edge whith use bodysize
{
	float edge;									//Calculating acording to area of object 
	if (shape==1)
	{
		edge=sqrt(body_size);
		return 4*edge;
	}
	else if (shape==2)
	{
		edge=body_size/5.0;						//In the home work 'Assume that the shorter edge is 5 if the shape is rectangular'
		return 2*(edge+5);
	}
	else if (shape==3)
	{
		edge=sqrt(body_size*(3/4.0)*(1.0/PI));	//body size= area of circular in circular so that if we can use reverse math we can find (r)
		return 2*PI*edge;
	}
}
int SetAtackPower(int lower_bound, int upper_bound)
{
	int random;
	srand(time(NULL));

	if (lower_bound==upper_bound)
	{
		return lower_bound;							// to fix when inputs are same(example lower=5 upper=5)
	}
	else
	{
		upper_bound=upper_bound-lower_bound;		//if we have 2 limits (parameters) in random numbers we have to define limits,
		random=(rand()%upper_bound)+lower_bound;	//to define limits i made theese calculations.
	}
	

	
	
	return random;
}

void ShowPokemon(int shape, double body_size, int color, double move_length, int atack_power)
{
	float edge;									//edge of square,rectangular and r of circular

	printf("________________________________________________________________________________\n\n");			//for the out separate output and input.					
	if (shape==1)
	{
		edge=move_length/4.0;											//dont input the edge of object so again calculate

		for (int i = 0; i <edge; ++i)
		{
			for (int j = 0; j <edge; ++j)
			{
				printf("X");
			}
			printf("\n");
		}

	printf("\nName: Square Pokemon\n");


	}

	else if (shape==2)
	{
		edge=body_size/5;								//To find the other edge of rectangular
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < edge; ++j)
			{
				printf("X");
			}

			printf("\n");
		}

			printf("\nName: Rectangular Pokemon\n");

	}

	else if (shape==3)
	{
	edge=move_length/(2*PI);   //To find the r of circle
	int i, j,r;
	r=floor(edge);				// To define the whether r is odd or not so r must be integer
	
	if (r==2)				// I tried the fix circular when input is 2 bu i didnt so i did like this
	{
		printf("    x\n");
		printf("x       x\n");
		printf("    x\n");
	}


	else if (r%2==1 )					 
	{
		r=r/2+1;                     // to fix the pattern. (r r represent the half of hexagon lines)
		for(i=1; i<=r; i++)
    {
        for(j=r; j>i; j--)			 //to design left up corner tab space
        {
            printf("	");
        }
      printf("X");					 //after space put the X
        for(j=1; j<2*i-1; j++)
        {
            printf("	");			 //same line the other X's space
        }
      if(i!=1)
        {
        	printf("X"); 			//There is 1 X top and bottom line 
        	printf("\n");
        }
        	
      else 
      	 printf("\n");

    }
    
    for(i=r-1; i>=1; i--)			// other side of circular same the top side
    {
        for(j=r; j>i; j--)				
        {
            printf("	");
        }
      printf("X");
        for(j=1; j<2*i-1; j++)
        {
            printf("	");
        }
        if(i!=1)
        {
        	printf("X"); 
        	printf("\n");
        }
        	
      else 
      	 printf("\n");
    	 

	}
	}

    else if (r%2==0 )					//if radius is even we have to use white space so modded 2
    {
    	r=r/2+1;
    	for(i=1; i<=r; i++)
    {
        for(j=r; j>i; j--)
        {
        	if (j==3 && i==2)
        	{
        		printf("          ");  //to fix the left X of near the top X
        	}
        	else
            printf("        ");			//normal white space in the circular
        }
      	printf("X");
        for(j=1; j<2*i-1; j++)
        {	
        	if (j==2 && i==2)
        	{
        		printf("    ");    //to fix the right X of near the top X
        	}
        	else
				 printf("        "); //normal white space in the circular
        } 
        if(i!=1)
        {
        	printf("X"); 
        	printf("\n");
        }
        	
        else 
      	 printf("\n");
    }
    
    for(i=r-1; i>=1; i--)
    {
        for(j=r; j>i; j--)
        {	
        	if (i==2 && j==3)
        	{
        	 printf("          ");	//to fix the left X of near the bottom X

        	}
        	else
            	printf("        ");  //normal white space in the circular
        }
      printf("X");
        for(j=1; j<2*i-1; j++)
        {
        	if (j==2 && i==2)
        	{
        		printf("    ");		//normal white space in the circular
        	}
        	else
            	printf("        "); //to fix the right X of bottom X
        }
        if(i!=1)
        {
        	printf("X"); 
        	printf("\n");
        }
        	
        else 
      	   printf("\n");
    }
    }

	printf("\nName: Circular Pokemon\n");

	}


	printf("Size: %.2f\n",body_size );
	
	if (color== RED)
		printf("Color= Red\n");
	
	else if (color== YELLOW)
		printf("Color: Yellow\n");

	else if (color== BLUE)
		printf("Color: Blue\n");

	else if (color== BLACK)
		printf("Color: Black\n");

	else if (color== WHITE)
		printf("Color: White\n");
	
	printf("Move: %.2f\n",move_length);
	printf("Attack Power: %d\n",atack_power);


}
