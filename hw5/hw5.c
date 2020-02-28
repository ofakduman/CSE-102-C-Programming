#include<stdio.h>
#include<stdlib.h>

#define DICT_SIZE 15
#define WORD_LEN 10
#define LINE_LEN 18

int get_line_size (char *line) {
	char *ch_iter = line; // so as not to lose beginning of line
	int counter = 0;
	// go until you see new line or null char
	while(*ch_iter != '\n' && *ch_iter != '\0') {
		ch_iter++; // next char
		counter++; // increment counter
	}
	
	return counter;
}

void copy_string(char *source, char *destination) {
	// get iterators over original pointers
	char *src_iter = source;
	char *dst_iter = destination;
	// until null char
	while (*src_iter != '\0') {
		// copy pointers
		*dst_iter = *src_iter;
		// advance to next char
		src_iter++;
		dst_iter++;
   }
   // terminate string
   *dst_iter = '\0';
}

void remove_newline(char *line) {
	char *ch_iter = line;
	// go until you see new line
	while(*ch_iter != '\n') {
		ch_iter++; // next char

	}
	*ch_iter = '\0'; // overwrite new line

}

void print_dictionary(char *dict[]) {
	int i;
	for(i = 0 ; i < DICT_SIZE ; i++) {
		printf("%s\n", dict[i]);
	}
}

void print_coord(int coord[DICT_SIZE][4]) {
	int i, j;
	for(i = 0 ; i < DICT_SIZE ; i++) {
		for(j = 0 ; j < 4 ; j++) {
			printf("%d ", coord[i][j]);
		}
		printf("\n");
	}
}


//to genarate a random character
char random_character()
{	
	char rndmchr;
	int random;
	random=97+(rand()%26);	//in ascii a=97 z=97+26-1

	rndmchr=random;
	
	return rndmchr;
}

//this function for fill the whole map with randomly
void fill_whole_map(char puzzle[][DICT_SIZE])
{
	int i,j;
	for (i = 0; i < DICT_SIZE; ++i)
	{
		
		for (j = 0; j < DICT_SIZE ;++j)
		{				
			puzzle[i][j]=random_character();	
		}
	}
}

//this function for show the whole puzzle
void show_puzzle(char puzzle[][DICT_SIZE])
{
	int i,j;
	printf("  ");
	for (int i = 0; i <DICT_SIZE ; ++i)
	{
		printf("%3d",i+1 );
	}
	
	printf("\n    ");
	for (int i = 0; i <DICT_SIZE ; ++i)
	{
		printf("_  " );
	}

	printf("\n");

	for (i = 0; i < DICT_SIZE; ++i)
	{
		printf("%2d |",i+1 );
		for (j = 0; j < DICT_SIZE ;++j)
		{				
			printf("%c  ",puzzle[i][j]);
		}
		printf("\n");
		
	}
}
//This function empty the contents of the array
void remove_word_array(char *word)
{
	int i;
	for (int i = 0; i < WORD_LEN; ++i)
	{
		*(word+i)='\0';
	}
}

void fill_map_with_dicts(char puzzle[][DICT_SIZE],int coord[][4],char *dict[])
{
	int x,x1,x2,y,y1,y2;
	int i,j,k;
	int word_leght;

	//for find to the direction of the word
	//For fill the every word
	for (i = 0; i <DICT_SIZE ; ++i)
	 {
	 	//firstly we should know lenght of the word
	 	word_leght=get_line_size(dict[i]);
	 	//printf("WORD_LEN=%d\n",word_leght);

	 	x1=coord[i][0];			//coordinates of one word
	 	y1=coord[i][1];
	 	x2=coord[i][2];
	 	y2=coord[i][3];
	 	x=x2-x1;				//x and y holds whether the axes increase or not in [x,y] directions
	 	y=y2-y1;

	 	if (x1==x2)				//if x1 and x2 are equal it means the word writing horizontal
	 	{
	 		
	 		if (y2>y1)			//we already know its writing horizontal but through where so we look the other axis
	 		{
	 			//if y2 > y1 it must write through east
	 			
	 			//now we can write in to the map
	 			for (j= 0;  j<word_leght-1 ; j++)
	 			{

	 				puzzle[x1][y1+j]=dict[i][j];	 				
	 			}	 			
	 		}
	 		else		//on the other hand we should write through west because in horizontal there is no way
	 		{
	 			for (j=0;  j<word_leght-1 ; j++)
	 			{
	 				puzzle[x2][y1-j]=dict[i][j];	 				
	 			}
	 		}
	 	}
	 	else if (y1==y2)		//if y1==y2 the word must write vertical
	 	{
	 		if (x2>x1)
	 		{
	 			for (j= 0;  j<word_leght-1 ; j++)
	 			{
	 				puzzle[x1+j][y1]=dict[i][j];	 				
	 			}
	 		}
	 		else
	 		{	 			
	 			for (j=0;  j<word_leght-1 ; j++)
	 			{
	 				puzzle[x1-j][y1]=dict[i][j];	 				
	 			}
	 		}
	 	}
	 	else	 	//finished the main direction now we can go a head diagonal directions
	 	{
	 		if (x>0 && y>0)			//if x and y are increased 
	 		{
	 			for (j= 0;  j<word_leght-1 ; j++)
	 			{
	 				puzzle[x1+j][y1+j]=dict[i][j];
	 			}
	 		}
	 		else if (x<0 && y<0)
	 		{	 			
	 			for (j= 0;  j<word_leght-1 ; j++)
	 			{
	 				puzzle[x1-j][y1-j]=dict[i][j]; 				
	 			}
	 		}

	 		else if (x>0 && y<0)
	 		{
	 			for (j= 0;  j<word_leght-1 ; j++)
	 			{
	 				puzzle[x1+j][y1-j]=dict[i][j];	 				
	 			}
	 			
	 		}
	 		else if (x<0 && y>0)
	 		{
	 			for (j= 0;  j<word_leght-1 ; j++)
	 			{
	 				puzzle[x1-j][y1+j]=dict[i][j];
	 			}
	 		}
	 	}
	} 

}

int is_exit(char quit[])
{
	if (quit[0]=='e' && quit[1]=='x' && quit[2]=='i' && quit[3]=='t' &&  quit[4]==' ' && *(quit+5)=='g' && *(quit+6)=='a' && *(quit+7)=='m' && *(quit+8)=='e')
	{
		return 1;
	}

	else
	return 0;
}
void convet_to_uppercase(char *dict[], int founded_word, int word_size)
{
	printf("		You found: %s \n\n",dict[founded_word] );			//to feedback the founded word
	int i;
	for (int i = 0; i < word_size; ++i)
		dict[founded_word][i]-=32;
}
void search_the_word(char puzzle[DICT_SIZE][DICT_SIZE], int word_size, char *word, int row, int column,char *dict[])
{
	int temp,temp2;
	int i,j;
	int matched_counter=0;
	int found=0;
	int founded_word;
	int founded_word_size;
	//Is the word matched in the puzzled word
	for (i = 0; i <DICT_SIZE ; ++i)
	{
		for (j = 0; j <word_size ; ++j)
		{
			if (dict[i][j]==word[j])
				matched_counter++;
		}
		if (matched_counter==word_size)
		{	
			founded_word=i;						// hold the founded word number in array, i will used this only for make uppercase the letters of the word
			founded_word_size=get_line_size(dict[founded_word]);			//
			founded_word_size--;				//minus 1 because the last element of string \0
			if (founded_word_size==matched_counter)			//matched word and aim word should be same character
			{				
				found=1;					//if find the word we can go a head else serch function over 
				matched_counter=0;
			}			
		}
		else
			matched_counter=0;
	}

	if (!found)
	{
		printf("There is no word like this %s\n",word );
	}
	//now we can search 8 way
	else
	{	
		matched_counter=0;				//i will use again int found because i should search 8 other directions 
		found=0;							//in horizontal through the east	
		
		if (!found )		//now it can be typed through the east
		{
			for (i = 0; i <word_size ; ++i)
			{	
				if (puzzle[row][column+i]==word[i])
					matched_counter++;
			}
			if (matched_counter==word_size)
			{
				found++;
				convet_to_uppercase(dict,founded_word,word_size);					//to convet to uppercase
			}
			else							//The coordinate can be either the beginning or the end of a word.
			{	
				matched_counter=0;					//so now we assume cordinates are end of the word 
				temp=column-word_size+1;			
				for (i = 0; i <word_size ; ++i)
				{	
					if (puzzle[row][temp+i]==word[i])
						matched_counter++;
				}
					if (matched_counter==word_size)
				{
					found++;
					convet_to_uppercase(dict,founded_word,word_size);					//to convet to uppercase
				}
				matched_counter=0;
			}
		}
		if (!found)				//it can typed reverse in horizontal
		{
			temp=column;
			for (i = 0; i <word_size ; ++i)
			{
				if (puzzle[row][temp-i]==word[i])
					matched_counter++;
			}
			if (matched_counter==word_size)
			{
				found++;
				convet_to_uppercase(dict,founded_word,word_size);					//to convet to uppercase
			}
			else							//The coordinate can be either the beginning or the end of a word.
			{	
				matched_counter=0;					//so now we assume cordinates are end of the word 
				temp=column+word_size-1;
				for (i = 0; i <word_size ; ++i)
				{	
					if (puzzle[row][temp-i]==word[i])
						matched_counter++;
				}
					if (matched_counter==word_size)
				{
					found++;
					convet_to_uppercase(dict,founded_word,word_size);					//to convet to uppercase
				}
			}
		}
		//in verticall up to down
		if (!found)
		{	matched_counter=0;
			temp=row;		
			for (i = 0; i <word_size ; ++i)
			{
				if (puzzle[temp+i][column]==word[i])
					matched_counter++;
			}
			if (matched_counter==word_size)
			{
				found++;
				convet_to_uppercase(dict,founded_word,word_size);					//to convet to uppercase
			}
			else							//The coordinate can be either the beginning or the end of a word.
			{	
				matched_counter=0;					//so now we assume cordinates are end of the word 
				temp=row-word_size+1;			
				for (i = 0; i <word_size ; ++i)
				{	
					if (puzzle[temp+i][column]==word[i])
						matched_counter++;
				}
					if (matched_counter==word_size)
				{
					found++;
					convet_to_uppercase(dict,founded_word,word_size);					//to convet to uppercase
				}
				matched_counter=0;
			}
		}
		
		if (!found)			//in vertical down to up
		{	
			temp=row;		
			for (i = 0; i <word_size ; ++i)
			{
				if (puzzle[temp-i][column]==word[i])
					matched_counter++;
			}

			if (matched_counter==word_size)
			{
				found++;
				convet_to_uppercase(dict,founded_word,word_size);					//to convet to uppercase
			}

			else							//The coordinate can be either the beginning or the end of a word.
			{	
				matched_counter=0;					//so now we assume cordinates are end of the word 
				temp=row+word_size-1;
				for (i = 0; i <word_size ; ++i)
				{	
					if (puzzle[temp-i][column]==word[i])
						matched_counter++;
				}
					if (matched_counter==word_size)
				{
					found++;
					convet_to_uppercase(dict,founded_word,word_size);					//to convet to uppercase
				}
			}
		}
		if (!found)			//now I'm checking diagonals through south-east
		{	
			matched_counter=0;
			temp=row;
			temp2=column;		
			for (i = 0; i <word_size ; ++i)
			{
				if (puzzle[temp+i][temp2+i]==word[i])
					matched_counter++;
			}
			if (matched_counter==word_size)
			{
				found++;
				convet_to_uppercase(dict,founded_word,word_size);					//to convet to uppercase
			}
			else							//The coordinate can be either the beginning or the end of a word.
			{	
				matched_counter=0;					//so now we assume cordinates are end of the word 
				temp=row-word_size+1;
				temp2=column-word_size+1;			
				for (i = 0; i <word_size ; ++i)
				{	
					if (puzzle[temp+i][temp2+i]==word[i])
						matched_counter++;
				}
					if (matched_counter==word_size)
				{
					found++;
					convet_to_uppercase(dict,founded_word,word_size);					//to convet to uppercase
				}
			}
		}
		if (!found)			//now I'm checking diagonals through north-west
		{	
			matched_counter=0;
			temp=row;
			temp2=column;		
			for (i = 0; i <word_size ; ++i)
			{
				if (puzzle[temp-i][temp2-i]==word[i])
					matched_counter++;
			}
			if (matched_counter==word_size)
			{
				found++;
				convet_to_uppercase(dict,founded_word,word_size);					//to convet to uppercase
			}

			else							//The coordinate can be either the beginning or the end of a word.
			{	
				matched_counter=0;					//so now we assume cordinates are end of the word 
				temp=row+word_size-1;
				temp2=column+word_size-1;			
				for (i = 0; i <word_size ; ++i)
				{	
					if (puzzle[temp-i][temp2-i]==word[i])
						matched_counter++;
				}
					if (matched_counter==word_size)
				{
					found++;
					convet_to_uppercase(dict,founded_word,word_size);					//to convet to uppercase
				}
				matched_counter=0;
			}
		}
		if (!found)			//now I'm checking diagonals through north-east
		{	
			matched_counter=0;
			temp=row;
			temp2=column;		
			for (i = 0; i <word_size ; ++i)
			{
				if (puzzle[temp-i][temp2+i]==word[i])
					matched_counter++;
			}
			if (matched_counter==word_size)
			{
				found++;
				convet_to_uppercase(dict,founded_word,word_size);					//to convet to uppercase
			}
			else							//The coordinate can be either the beginning or the end of a word.
			{	
				matched_counter=0;					//so now we assume cordinates are end of the word 
				temp=row+word_size-1;
				temp2=column-word_size+1;			
				for (i = 0; i <word_size ; ++i)
				{	
					if (puzzle[temp-i][temp2+i]==word[i])
						matched_counter++;
				}
					if (matched_counter==word_size)
				{
					found++;
					convet_to_uppercase(dict,founded_word,word_size);					
				}
				matched_counter=0;
			}
		}
		if (!found)			//now I'm checking diagonals through north-east
		{	
			matched_counter=0;
			temp=row;
			temp2=column;		
			for (i = 0; i <word_size ; ++i)
			{
				if (puzzle[temp+i][temp2-i]==word[i])
					matched_counter++;
			}
			if (matched_counter==word_size)
			{
				found++;
				convet_to_uppercase(dict,founded_word,word_size);					
			}
			else							
			{	
				matched_counter=0;					//so now we assume cordinates are end of the word 
				temp=row-word_size+1;
				temp2=column+word_size-1;			
				for (i = 0; i <word_size ; ++i)
				{	
					if (puzzle[temp+i][temp2-i]==word[i])
						matched_counter++;
				}
					if (matched_counter==word_size)
				{
					found++;
					convet_to_uppercase(dict,founded_word,word_size);					
				}
				matched_counter=0;
			}
		}
			if (!found)
			printf("There is no this word in inputs coordinates: %s\n",word );
	}
}
int is_game_already_finished(char *dict[])
{
	int i,uppercase_letter,j,k;
	int lenght,finish=0;

	for (int i = 0; i <  DICT_SIZE; ++i)
	{
		lenght=get_line_size(dict[i]);

		for (j = 0; j < lenght; ++j)
		{
			if (dict[i][j]>90)			//this means there are already lower case letter so game is not finished yet.
				finish++;			
		}
	}

	if (finish==0)
		finish=1;
	else 
		finish=0;

	return finish;
}

int main(){
	char character;
	char temp;
	char *dict[DICT_SIZE];
    int coord[DICT_SIZE][4];    
    char line[LINE_LEN];
    char word[WORD_LEN];
	FILE *fp = fopen("word_hunter.dat", "r");
	int row,column,exit=0;			//to get the value as a return of the exit function 
	int i,j,finish=0;
	int word_size=0;				//to hold the word size
	char puzzle[DICT_SIZE][DICT_SIZE];
	int line_counter = 0;
	int dict_counter = 0;
	while(fgets(line, LINE_LEN, fp) != NULL) {
		if(line_counter%5 == 0) {
			dict[dict_counter] = (char*) malloc(sizeof(char) * get_line_size(line));
			remove_newline(line);
			copy_string(line, dict[dict_counter]);
		} else if (line_counter%5 == 1){
			coord[dict_counter][0] = atoi(line);
		} else if (line_counter%5 == 2){			
			coord[dict_counter][1] = atoi(line);		
		} else if (line_counter%5 == 3){
			coord[dict_counter][2] = atoi(line);
		} else if (line_counter%5 == 4){
			coord[dict_counter][3] = atoi(line);
			dict_counter++;
		}
		line_counter++;
	}
	fill_whole_map(puzzle);
	fill_map_with_dicts(puzzle,coord,dict);
	show_puzzle(puzzle);		
	printf("Welcome to Puzzle game Find the hidden words\n");
	while(!exit && finish==0)
	{	
		printf("If you find a word typed the word otherwise to quit typed exit game\n");
		scanf (" %[^\n]%*c", word);		//to get the whole string with the spaces
		exit=is_exit(word);				// to check if user typed exit game
		
		if (exit==0 )					// if dont so continue program
		{	
			word_size=get_line_size(word);			//to hold the size of the word
			printf("Input the coordinate of the word(r=row, c=column)\nrow:");
			scanf("%d",&row);
			printf("column:");
			scanf("%d",&column);
			row+=-1;						//added -1 because arrays starts with 0
			column+=-1;
			search_the_word(puzzle,word_size,word,row,column,dict);
			remove_word_array(word);
			fill_map_with_dicts(puzzle,coord,dict);			//to write the new uppercase words uppercase in puzzle in convet_to_uppercase function 
			finish=is_game_already_finished(dict);			//if all words founded program should finished
			if (finish==1)
			{
				printf("	Congratulation You Found all Words!\n");
			}
			else
				show_puzzle(puzzle);
		}
			
		
	}
	
	
	
	
	
	fclose(fp);


		
	return 0;
}






