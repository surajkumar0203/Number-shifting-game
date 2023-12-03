#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<conio.h>

void textcolor(int);
// print board
void Print_Board(int board[][4])
{
    textcolor(10);
    printf("\n\n\t\t      Number Puzzle Game\n\n");
    textcolor(7);
    printf("\t     ___________________________________\n");
    printf("\t    |        |        |        |        |\n");
    for(int i=0;i<4;i++)
    {
        
        printf("\t    |");
        for(int j=0;j<4;j++)
        {
            if(board[i][j]==16 || board[i][j]==0)
            {
                board[i][j]=0;
                printf("        |");
            }
            else
                printf(" %3d    |",board[i][j]);
        }
        printf("\n");
        printf("\t    |________|________|________|________|\n");
        
        if(i!=3)
            printf("\t    |        |        |        |        |");
        printf("\n");
        
    }
}// end of Print_Board

// check duplicate duplicate element if present return element if not then return 0.
int check_duplicate_element(int a[][4],int num)
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(num==a[i][j])
            {
                return num;
            }
        }
    }
    return 0;
}// end of check_duplicate_element()

void create_random_number(int board[][4])
{
    srand(time(NULL));
    int number;
    int i,j;
    for(i=0;i<4;i++)
    {
        j=0;
        while(j<4)
        {
            number=(rand()%(16-1+1))+1;
            // if rand function create duplicate element 
            if(check_duplicate_element(board,number)==0)
            {
                board[i][j]=number;
                j++;
            }
        }
    }
}// end of create_random_number()

// Where Zero Present present in array  (Zero replace with space).
int Check_Zero(int move,int board[][4])
{
    
    int i;
    /*
        when 0 present in index 0 (row)
        Down arrow not work.
    */
    // Down arrow key
    if(move==80)
    {
        for(i=0;i<4;i++)
        {
            if(board[0][i]==0)
                return 0;
        }
    }
    /*
        when 0 present in Left column 
        Right arrow not work.
    */
    // Right arrow key
    else if(move==77)
    {
        for(i=0;i<4;i++)
        {
            if(board[i][0]==0)
                return 0;
        }
    }
    /*
        when 0 present in index 3 (row)
        Up arrow not work.
    */
    //   Up arrow key
    else if(move==72)
    {
        for(i=0;i<4;i++)
        {
            if(board[3][i]==0)
                return 0;
        }
    }
    /*
        when 0 present in right column 
        Left arrow not work.
    */
    // Left arrow key
    else if(move==75)
    {
        for(i=0;i<4;i++)
        {
            if(board[i][3]==0)
                return 0;
        }
    }

    return 1;
}//end of check_zero()
void swap(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}//end of swap()
void Direction(int move,int board[][4])
{
    int i,j;
    // move Left side.
    if(move==75)
    {
        if(Check_Zero(move,board))
        {
            for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                {
                    if(board[i][j]==0)
                    {
                        swap(&board[i][j],&board[i][j+1]);
                        return;
                    }
                }
            }
        }
    }
    // move Right
    if(move==77)
    {
        if(Check_Zero(move,board))
        {
            for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                {
                    if(board[i][j]==0)
                    {
                        swap(&board[i][j],&board[i][j-1]);
                        return;
                    }
                }
            }
        }
    }
    // move up
    if(move==72)
    {
        if(Check_Zero(move,board))
        {
            for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                {
                    if(board[i][j]==0)
                    {
                        swap(&board[i][j],&board[i+1][j]);
                        return;
                    }
                }
            }
        }
    }
    // move down
    if(move==80)
    {
        if(Check_Zero(move,board))
        {
            for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                {
                    if(board[i][j]==0)
                    {
                        swap(&board[i][j],&board[i-1][j]);
                        return;
                    }
                }
            }
        }
    }
    
}//end of Direction()
int winner_check(int board[][4])
{
    int k=1;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(board[i][j]==k)
            {
                k++;
            }// check board[][] element is sorted or not
            else
                return 0;
            

            if(i==3 && j==2)// index board[3][3] has space;
                return 1;
        }

    }
}// end of winner_check()
void textcolor(int color_name)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color_name);// text color change
}
void Rule_of_the_game()
{
    
    printf("\t\tNUMBER PUZZLE GAME\n\n");
    
    
    textcolor(12);
    printf("\t\tRULE OF THIS GAME\n\n");
    
    printf("1. You can move only 1 step at a time by arrow key\n");
    textcolor(7);
    
    printf("\tMove Up    : by Up arrow Key\n");
    printf("\tMove Down  : by Down arrow Key\n");
    printf("\tMove Right : by Right arrow Key\n");
    printf("\tMove Left  : by Left arrow Key\n");
    textcolor(12);
    
    printf("2. You can move number at empty position only\n\n");
    printf("3. For each valid move : your number of move will decreased by 1\n");
    printf("4. Wining situation : Number in a 4x4 matrix should be in order from 1 to 15\n");


    textcolor(10);
    printf("5. You have 500 Chance to Move Number\n");
    int k=1;
    textcolor(7);
    
    printf("\n\t\tWinning Situation:\n\n");
    textcolor(6);
    printf("\t     ---------------------------\n");
    for(int i=0;i<4;i++)
    {
        printf("\t    |");
        for(int j=0;j<4;j++)
        {
            if(i==3 && j==3)
            {
                printf("      |");
                break;
            }
            printf(" %4d |",k++);
        }
        if(i==3)
            break;
        
        printf("\n");
        
    }
    printf("\n");
    printf("\t     ---------------------------\n");
    textcolor(7);
    printf("6. You can exit the game at any time by pressing 'E' or 'e'\n");
    printf("So Try to win in minimum no of move\n");
    printf("press any key to continue the game!");
    printf("\nBEST OF LUCK\n");
}//end of Rule_of_the_game()

void terminate_game()
{
    textcolor(11);
    printf("Plese Wait ");
    int k=0;
    while(k!=2)
    {
        for(int j=0;j<=10;j++)
        {
            printf(".");
            Sleep(200);
        }
        for(int j=0;j<=10;j++)
        {
            printf("\b \b");
            Sleep(200);
        }
        k++;
    }
    Sleep(10);
    printf("\nYour Game Is Successfull Exit.\n");
    system("color 7");
}//end of terminate_game()

int Start_Game(char Name[])
{
    int board[4][4]={0};
    char ch;
    int chance=500;

    textcolor(7);
    printf("\tPlayer Name: %s\t",Name);
    printf("Chance : %d",chance);
    
    create_random_number(board);
    Print_Board(board);
    
    while(chance)
    {
        
        ch=getch();
        if(ch=='E' || ch=='e')
        {
            terminate_game();
            exit(0);
        }
        if(ch==75 || ch== 72 || ch==80 || ch==77) // user press arrow key then execute
        {
            chance--;
            Direction(ch,board);
            system("cls");
            printf("\tPlayer Name: %s\t",Name);
            printf("Chance : %d",chance);
            Print_Board(board);
            if(winner_check(board))
            {
                textcolor(10);
                printf("You Are Winner! %c %c\n",002,002); // ☻==002
                break;
            }
            
        }  
    }
    return chance;
}
int main()
{
    
    char Name[50];
    system("cls");
    Rule_of_the_game();
    getch();
    
    system("cls");
    
    printf("Player Name: ");
    fgets(Name,50,stdin);
    
    system("cls");
    
    int c;
    int chance;
    while(1)
    {
        
        chance=Start_Game(Name);
        
        if(chance==0)
        {
            system("cls");
            textcolor(12);
            printf("\tYou LOSE !\n");
        }

        
      
        textcolor(11);
        printf("Are You Play Game Again? press any number to Play press 0 to exit: ");
        c=getche();
        
        system("cls");
        if(c=='0')// terminate the program.
        {
            terminate_game();
            return 0;
        }
    }
    
}