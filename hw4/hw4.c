#include<stdio.h>
typedef enum{linear,quadratic}attack_type;
typedef enum{Charmander,Pikachu,Squirtle,Bulbasaur,Pidgeotto,Ratata,Mug,Caterpie,Zubat,Krabby}pokemon;

void oaks_laboratory(char [][11], pokemon [], pokemon *);
void pokedex(char [][11], int range[], attack_type [],int [], int []);
void catch_a_pokemon(char [][11], pokemon [],pokemon *);
void show_Pokemons(char [][11], pokemon [] , int);
void release_a_pokemon(char [][11], pokemon [],pokemon *);
void battle(char [][11], int [], attack_type [], int [], int [], pokemon []);
void menu(pokemon [], pokemon [],pokemon *,int [] , attack_type [] ,int [] ,int [],char [][11] );
void show_my_pokemons(char [][11],pokemon *);
void show_area (char [][11],int [][8],int [][4]);
int main()
{	
	pokemon Pokemons[10]={Charmander,Pikachu,Squirtle,Bulbasaur,Pidgeotto,Ratata,Mug,Caterpie,Zubat,Krabby};
	pokemon *my_Pokemons;
	pokemon user_Pokemons[4]={-1,-1,-1,-1};			//-1 means empty in this array
	my_Pokemons=user_Pokemons;


	int attack_power[10]={500,350,300,400,250,250,350,200,350,300};
	attack_type type[10]={quadratic,linear,linear,linear,quadratic,linear,quadratic,quadratic,linear,linear};
	int range[10]={1,3,4,3,2,2,1,2,3,2};
	int stamina[10]={2200,1500,1700,2500,1900,2500,3000,1200,1250,2600};
	char Pokemon_name[10][11]={{"Charmander"},{"Pikachu"},{"Squirtle"},{"Bulbasaur"},{"Pidgeotto"},{"Ratata"},{"Mug"},{"Caterpie"},{"Zubat"},{"Krabby"}};

	menu(Pokemons, user_Pokemons, my_Pokemons ,attack_power ,type ,range ,stamina ,Pokemon_name );

	return 0;
}

void pokedex(char Pokemon_name[][11], int range[], attack_type type[],int attack_power[], int stamina[])
{
	
	int i,j,k,wordcounter=0;
	int correctcounter=0;					//Count the matched letters
	int temp;								// hold the matched array's number
	char input_the_name[20];
	int exit=0;
	printf("Please type name of the Pokémon (type exit to close Pokedex):\n");
	scanf("%s",input_the_name);
	if (input_the_name[0]=='e' && input_the_name[1]=='x' && input_the_name[2]=='i' && input_the_name[3]=='t')
	{
		exit++;
	}
	while(exit==0)
	{
			for (int i = 0;input_the_name[i]!='\0' ; ++i)
		{
			wordcounter++;
		}

		//for find the name of the pokemon
		for (i = 0; i <=10; ++i)
		{
			for (j = 0; j <=wordcounter ; ++j)
			{
				if (Pokemon_name[i][j]==input_the_name[j])
				{
					correctcounter++;
				}

				temp=-1;										//to express absence

				//if the words are matched to get out the loop
				if (correctcounter==wordcounter+1)					//+1 is also compare to '\0' the last cell of array
				{
					temp=i;
					i=100;
				}
				
			}

			correctcounter=0;			//for every word has started again
		}

		if (temp==-1)
		{
			printf("Unfortunately we did not have %s pokemon!!\n",input_the_name );
		}

		else
		{
			printf("\n\nName	: %s\n",input_the_name);
			if (type[temp]==0)
			{
			printf("A. Type : linear\n" );
			}
			else
			printf("A. Type : Quadratic\n" );

			printf("Range	: %d block\n",range[temp]);
			printf("A. Power: %d\n",attack_power[temp] );
			printf("Stamina : %d \n",stamina[temp] );
		}

		//To use again string
		for (int i = 0; i < wordcounter; i++)
		{
			input_the_name[i]='\0';							
		}
		correctcounter=0;				//To again compare the strings
		wordcounter=0;


		printf("\n\nPlease type name of the Pokémon (type exit to close Pokedex):\n");
		scanf("%s",input_the_name);

		if (input_the_name[0]=='e' && input_the_name[1]=='x' && input_the_name[2]=='i' && input_the_name[3]=='t')
		{
			exit++;
		}
	}
	

}
void oaks_laboratory(char Pokemon_name[][11], pokemon Pokemons[],pokemon *my_Pokemons)
{	
	int names;
	int countfillingcell=0,i;
	int pokemon_count;
	int menu_select;
	printf("Welcome to Laboratory of Professor Oak. ");
	while(menu_select!=5)
	{
		printf("How can I help you?\n1) Show Pokémons\n2) Catch a Pokémon\n3) Release a Pokémon\n4) Show my pocket\n5) Back\nSelect:");
		scanf("%d",&menu_select);
		printf("\n");
		switch(menu_select)
		{
		
			case 1: 
				show_Pokemons(Pokemon_name,Pokemons,pokemon_count);

				break;

			case 2:
			
				show_Pokemons(Pokemon_name,Pokemons,pokemon_count);
				catch_a_pokemon(Pokemon_name,Pokemons,my_Pokemons);		

				break;

			case 3:
				
				printf("\n");
				release_a_pokemon(Pokemon_name,Pokemons,my_Pokemons);
				printf("\n");

				break;

			case 4:

				printf("\n\nYour Pokemons:\n");
				show_my_pokemons(Pokemon_name,my_Pokemons);

				printf("\n\n");
				break;

			case 5:

				break;
		}
			
	}
}

void show_Pokemons(char Pokemon_name[][11], pokemon Pokemons[], int pokemon_count)
{
	printf("\n\n");
	for (pokemon_count = 0; pokemon_count <10 ; ++pokemon_count)
	{
		printf("%d - %s\n",Pokemons[pokemon_count],Pokemon_name[pokemon_count] );
	}
}
void catch_a_pokemon(char Pokemon_name[][11], pokemon Pokemons[], pokemon *my_pocket)
{	
	int emptycounter=0;
	int flag2=0;
	int select;
	int flag=0;
	int beginng_of_array=0,i;

	for (int i = 0; i < 4; ++i)
		{
			if (*(my_pocket+i)==-1)
			{
				emptycounter++;
				flag2=1;						//Contrtol the empty cell
			}

		}

		if (flag2!=1)
		{
			printf("Your packet is full!\n");
		}
		else	
		printf("Pick only %d different Pokemon:\n",emptycounter);
	
	while(beginng_of_array<3 && flag2==1)

	{
	
		scanf("%d",&select);

		//select between the showen pokemons
		if (select>9 || 0>select)
		{
			flag++;
		}

		//to find the beginning of array`s cell
		i=0;
		while(*(my_pocket+i)!=-1)
		{
			i++;

		}
		beginng_of_array=i;

		//control the whether select once pokemon
		for (i = 0; i < 4; ++i)
		{
			if (*(my_pocket+i)==select)
			{
				flag++;
			}
		}

	
		if (flag==0)
		{
			*(my_pocket+beginng_of_array)=select;
		}
		else 
		{
			printf("Try agin, Wrong input!\n");

		}

		for (int i = 0; i < 4; ++i)
		{
			if (*(my_pocket+i)==-1)
			{
				flag2=1;						//Contrtol the empty cell
			}
			else
				flag2=0;
		}

		flag=0;
	
	}
}

void release_a_pokemon(char Pokemon_name[][11], pokemon Pokemons[],pokemon *my_pocket)
{
	int selected;
	int names;
	printf("Your Pokemons:\n");
	show_my_pokemons(Pokemon_name,my_pocket);


	printf("\n\n");

	printf("Release Which Pokemon, wanna quit press -1:\n");
	scanf("%d",&selected);
	while(selected!=-1)
		{
			if (selected<4 && -1<selected )
			{
				if (*(my_pocket+selected)==-1)				//-1 means empty cell
				{
					printf("This input is already empty!\n" );
				}

				else
					*(my_pocket+selected)=-1;
			}
			else
				printf("Wrong input try again!\n");
			
			
			printf("Release Which Pokemon, wanna quit press -1:\n");
			scanf("%d",&selected);



		}

}
void menu(pokemon Pokemons[],pokemon user_Pokemons[],pokemon *my_Pokemons, int attack_power[],attack_type type[],int range[],int stamina[],char Pokemon_name[][11])

{
	int select=-1;
	printf("Please select an option to continue:\n1) Open Pokedex\n2) Go to Oak’s Laboratory\n3) Enter the tournament\n4) Exit\n" );
	printf("Select:");
	scanf("%d",&select);
	while(select!=4)
	{

		printf("\n");
		if (select==1)
		{
			pokedex(Pokemon_name,range,type,attack_power,stamina);
		}

		else if (select==2)
		{
			oaks_laboratory(Pokemon_name,Pokemons,my_Pokemons);
		}

		else if (select==3)
		{
				battle(Pokemon_name,range,type,attack_power,stamina,user_Pokemons);
		}

		else if (select!=4)
		{
			printf("Wrong input try again!\n");
		}
		printf("Please select an option to continue:\n1) Open Pokedex\n2) Go to Oak’s Laboratory\n3) Enter the tournament\n4) Exit\n" );
		scanf("%d",&select);

	}



}
void battle(char Pokemon_name[][11], int range[], attack_type type[], int attack_power[], int stamina[], pokemon user_Pokemons[])
{	
	int located_pokemon[4]={-1,-1,-1,-1};//To control dont pick more than one times in user pokemons
	int area[16][8];
	int pokemon_staminas[2][4];
	int error=0,select;
	pokemon *my_Pokemons;
	my_Pokemons=user_Pokemons;
	int i,j=0,k,row,column;
	int located_pokemon_counter=-1;
	int emptycounter=0;
	int temp;


	//-1 means there is no pokemon in this array's cell
	for ( i = 0; i < 16; ++i)
	{
		for ( j = 0; j < 8; ++j)
		{
			area[i][j]=-1;
		}
	}

	printf("\nWelcome to tournement!\nYour Pokemons:\n");
	
	//to control at least picked four pokemon
	for (int i = 0; i < 4; ++i)
	{
		if (user_Pokemons[i]==-1)
		{
			error++;
		}
	}
	if (error>0)
	{

		printf("According to rule of tournement you have to have at least four pokemon please get %d pokemons\n\n",error );
	}


	else
	{	
		show_area(Pokemon_name, area, pokemon_staminas);
		printf("\n\n");
		show_my_pokemons(Pokemon_name,my_Pokemons);			//to show the pokemon
		printf("\nPick the one of the pokemon and locate pokemons\n");
		
		
		for(i=0; i<4; i++)							//there are for pokemon and loop will be occured 4 times
		{

			
	
			
			printf("Pick one Pokemon(between 0-4):");
			
			emptycounter=0;							//for get the while loop

			scanf("%d",&select);
			//this control for dont input again same pokemon
			while(error!=0 || emptycounter==0 || select<0 || select>4) 
			{	
				
				for (int k = 0; k < 4; ++k)
				{
					error=0;
					if (located_pokemon[k]==*(my_Pokemons+select))
					{												
						temp=select;												
					}					
					
				}
				if (temp==select)
				{
					
					printf("You picked again same pokemon Pls pick another one:");
					scanf("%d",&select);
				}
				else
					emptycounter++;						//to quit the wile loop if there is picked on

				if (select<0 || select>4)
				{
					printf("Pls pick pokemon between 0-4 include 0 and 4\n");
					scanf("%d",&select);
				}


			}
			
			
			printf("\nPick column(1-8):");	
			scanf("%d",&column);

			while (8<column || column<1)
			{
				
				printf("Column must be 1 to 8 include 1 and 8\n");
				scanf("%d",&column);
				
			}
				
			
			printf("\nPick the row(1-2):");
			scanf("%d",&row);
			while (2<row || row<1)
			{
						
				printf("\nRow must be 1 to 2 include 1 and 2:");
				scanf("%d",&row);
				
			}
			if (area[16-(row*2)][column-1]==-1)										//if this cell is empty
			{
			pokemon_staminas[0][select]=stamina[*(my_Pokemons+select)];			//i take the pokemons stamina and fill the new array with the pokemon's stamina
			located_pokemon[select]=*(my_Pokemons+select);	
			area[16-(row*2)][column-1]=*(my_Pokemons+select);
			area[15-((row-1)*2)][column-1]=pokemon_staminas[0][select];	//I take the stamina here
			show_area(Pokemon_name, area, pokemon_staminas);
			}
			else
			{
				printf("Alreay another pokemon located here please check Column an row and try agin\n");			//if already located to this cell another pokemon
				 i--;		 																			
			}
			
			
	
			
	
		}
	}





	
	
}

void show_my_pokemons(char Pokemon_name[][11],pokemon *my_Pokemons)
{
	int i;

	for (int i = 0; i < 4; ++i)
	{
		if (*(my_Pokemons+i)==-1)
		{
			printf("%d-Empty!! please catch a pokemon\n",i );
		}
		else
			printf("%d-%s\n",i,Pokemon_name[*(my_Pokemons+i)] );
	}
}
void show_area (char Pokemon_name[][11], int area[][8],int pokemon_staminas[][4])
{
	int i,j,k;
	char Pokemon_sname[10][11]={{"Cha"},{"Pik"},{"Squ"},{"Bul"},{"Pid"},{"Rat"},{"Mug"},{"Cat"},{"Zub"},{"Kra"}};

	
	

	for (int i = 0; i < 16; ++i)
	{
		if (i%2==0)
		{
			printf("-----------------------------------------------------------------\n");

		}

		for (int j = 0; j < 8 ; ++j)
		{	
			if (area[i][j]==-1)
			{	
				if (j==0)
				{
					printf("|	|");
				}
				else
				printf("	|");

			}
			else
			{	if (i%2==0)
				{
					if ( j==0)
					{
						printf("| %s	|",Pokemon_sname[area[i][j]] );
					}
					else
						printf("  %s	|",Pokemon_sname[area[i][j]] );


				
				}
				else if (i%2==1)
				{
					if (j==0)
					{
						printf("|  %d	|",area[i][j] );

					}
					else
						printf(" %d  |",area[i][j] );

				}

				

				
			}		


		}
		printf("\n");
	}
	printf("-----------------------------------------------------------------\n");




}
