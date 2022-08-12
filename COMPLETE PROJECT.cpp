#include<iostream>
using namespace std;

 char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
 char turn=  'X';
 int row,colum;
 bool draw = false;
 
void display_board()
{
system("cls");
system("color E5");
cout<<" \tT i c k   C r o s s   G a m e"<<endl;    
	cout<<" \t   Player1 [X]"<<endl;
	cout<<" \t   Player2 [O]\n";
    cout<<"\t\t\t     |     |     \n";
    cout<<"\t\t\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  \n";
    cout<<"\t\t\t_____|_____|_____\n";
    cout<<"\t\t\t     |     |     \n";
    cout<<"\t\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  \n";
    cout<<"\t\t\t_____|_____|_____\n";
    cout<<"\t\t\t     |     |     \n";
    cout<<"\t\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  \n";
    cout<<"\t\t\t     |     |     \n";
}

player_turn(){
    int choice;
    
    if(turn == 'X')
     cout<<"\n\tPlayer1 [X] turn:";
     if(turn == 'O')
     cout<<"\n\tPlayer2 [O] turn:";
    cin>>choice;
     switch(choice){
     	 case 1: row=0; colum=0; break; 
		 case 2: row=0; colum=1; break;
		 case 3: row=0; colum=2; break;
		 case 4: row=1; colum=0; break;
		 case 5: row=1; colum=1; break;
		 case 6: row=1; colum=2; break;
		 case 7: row=2; colum=0; break;
		 case 8: row=2; colum=1; break;
		 case 9: row=2; colum=2; break;
		    	
     		default:
     			cout<<"invalid number"<<endl;
     			break;
	 }
	 if(turn =='X'&& board[row][colum]!='X' && board[row][colum]!='O')
	 {
	 	board[row][colum]='X';
	 	turn = 'O';
	 }
	 else if(turn == 'O' && board[row][colum]!='X' && board[row][colum]!='O')
	   {
		 board[row][colum]='O';
	    turn = 'X';}
	    else{
	    	cout<<"box already filled!\n pleas try again!!\n\n";
	    	player_turn();
		}
}
bool gameover(){
	// check win
	int i,j;
	for(i=0;i<3;i++)
	if(board[i][0]==board[i][1] && board[i][0]==board[i][2] || board[0][i]==board[1][i] && board[0][i]==board[2][i])
	return false;
	if(board[0][0]==board[1][1] && board[0][0]==board[2][2] || board[0][2]==board[1][1] && board[0][2]==board[2][0] )
	return false;
	//if any box not filled
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	if(board[i][j] !='X' &&  board[i][j]!='O')
	return true;
	
	//draw
	draw = true;
	return false;
}
 main()
{
	while(gameover())
	{
	display_board();
    player_turn();
     display_board();
     gameover();
}
if(turn == 'X' && draw == false)
cout<<"Player2 [O] Wins !! Congratulation\n";
else if(turn == 'O' && draw == false)
cout<<"Player1 [X] Wins !! Congratulation\n";
else
{
cout<<"GAME DRAW !! \n";}	
}
