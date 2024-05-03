/*
 * nimToWin.cpp
 * Created on: Nov 27, 2023
 * Authors: Martin Berro Madero & Sam Menna
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <ctime>
#include <random>
#include <string>
#include <cmath>
using namespace std;
string playerOneName{"Player 1"};
string playerTwoName{"Player 2"};
const size_t tnoh=10;  //max number of heaps for creating the arrays used in option 2 (user vs PC)
const size_t tnot=1023;  //max number of tokens for creating the arrays used in option 2 (user vs PC)
int nim_to_win_option1(vector<int> &rowA, vector<int> &rowB, vector<int> &rowC, vector<int> &rowD, vector<int> &rowE, int& total_number_of_tokens, int& player_turn);
void userVsPC(array<array<int,tnot>,tnoh>&);
int total_number_of_tokens{ 0 };
int total_number_of_heaps{ 0 };
int player_turn{ 0 };
//Main program
int main()
{
	int option{ 0 };
	int rowA_tokens{ 0 };
	int rowB_tokens{ 0 };
	int rowC_tokens{ 0 };
	int rowD_tokens{ 0 };
	int rowE_tokens{ 0 };
	//Player(s) choose a game mode
	cout << "***Welcome to NimToWin!***\n\nPlease choose a game mode:\n1- Two players (user vs user)\n2- Single player (PC vs user)\n3- Exit" << endl;
	cin >> option;
	while ((option != 1) && (option != 2) && (option != 3)){
		cout << "\nInvalid game mode, please try again\n" << endl;
		cout << "Please choose a game mode:\n1- Two players (user vs user)\n2- Single player (PC vs user)\n3- Exit" << endl;
		cin >> option;
	}
	//If option 1 is chosen (player vs player)
	if (option == 1){
		cout << "What is the name of the first player?";
		cin >> playerOneName;
		cout << "What is the name of the second player?";
		cin >> playerTwoName;
		cout << "How many tokens would you like to use? (must be at least 1) ";
		cin >> total_number_of_tokens;
		while (total_number_of_tokens <= 0){
			cout << "How many tokens would you like to use? ";
			cin >> total_number_of_tokens;
		}
		cout<<"\n---------------------------------------------------------------------------";
		cout<<"\nHere is the game:\n";
		//Rows are created randomly with the number of tokens
		default_random_engine engine(static_cast<unsigned int>(time(nullptr)));
		uniform_int_distribution<unsigned int> rowA_generator(0, (total_number_of_tokens / 2));
		rowA_tokens = rowA_generator(engine);
		uniform_int_distribution<unsigned int> rowC_generator(0, (total_number_of_tokens / 2));
		rowC_tokens = rowC_generator(engine);
		uniform_int_distribution<unsigned int> rowD_generator(0, (total_number_of_tokens - (rowC_tokens + rowA_tokens)));
		rowD_tokens = rowD_generator(engine);
		uniform_int_distribution<unsigned int> rowE_generator(0, (total_number_of_tokens - (rowC_tokens + rowA_tokens + rowD_tokens)));
		rowE_tokens = rowE_generator(engine);
		rowB_tokens = total_number_of_tokens - (rowC_tokens + rowA_tokens + rowD_tokens + rowE_tokens);
		vector<int> rowA(rowA_tokens);
		vector<int> rowB(rowB_tokens);
		vector<int> rowC(rowC_tokens);
		vector<int> rowD(rowD_tokens);
		vector<int> rowE(rowE_tokens);
		//Nim_to_win_option1 function is activated and will return the number of turns before the end of the game
		int winner = nim_to_win_option1(rowA, rowB, rowC, rowD, rowE, total_number_of_tokens, player_turn);
		//If the amount of turns is odd, player 1 has won, else player 2 has won
		if(winner%2)
			cout<<endl<<playerOneName<<" has won!!!\n";
		else
			cout<<endl<<playerTwoName<<" has won!!!\n";
		cout<<"\n***Game Over***\n";
	}
	//If option 2 is chosen
	else if (option == 2){
		cout<<"What is your name? ";
		cin>>playerOneName;
		cout<<"How many heaps would you like to use? (must be at least 1 and at most 10) ";
		cin>>total_number_of_heaps;
		while (total_number_of_heaps <= 0 || total_number_of_heaps > 10){
			cout<<"\nThe answer should be at least 1 and at most 10. How many heaps would you like to use? ";
			cin>>total_number_of_heaps;
		}
		cout<<"How many tokens would you like to use? (must be at least 1) ";
		cin>>total_number_of_tokens;
		while(total_number_of_tokens <= 0 || total_number_of_tokens > 1023 ){
			cout<<"\nThe answer should be at least 1 and at most 1023. How many tokens would you like to use? ";
			cin>>total_number_of_tokens;
		}
		char whoStarts{'y'};
		cout<<"Would you like to start first? (y/n) ";
		cin>>whoStarts;
		if(whoStarts=='n')
			player_turn++;
		int tokensThatFit=pow(2,total_number_of_heaps)-1;
		while(total_number_of_tokens > tokensThatFit){
			cout << "\nOnly "<<tokensThatFit<<" tokens fit in "<<total_number_of_heaps<<" heaps.\nHow many heaps would you like to use? ";
			cin >> total_number_of_heaps;
			while(total_number_of_heaps <= 0 || total_number_of_heaps > 10){
				cout << "\nThe answer should be at least 1 and at most 10. How many heaps would you like to use? ";
				cin >> total_number_of_heaps;
			}
			for(int i{0}; i<total_number_of_heaps;i++){
				tokensThatFit+=pow(2,i);
			}
		}
		//Create and initialize a big 2-dimensional array to zeros
		array<array<int,tnot>, tnoh>gameArray{};
		for(size_t i{0}; i<tnoh; i++){
			for(size_t j{0}; j<tnot; j++){
				gameArray[i][j]=0;
			}
		}
		//Add the tokens according to the binary number weight
		int numOfTokens=total_number_of_tokens;
		for(size_t i{0}; i<tnoh;i++)
			for(size_t j{0}; j<tnot; j++)
				if(j<pow(2,i) && numOfTokens>0){
					gameArray[i][j]=1;
					numOfTokens--;
				}
		//Print the game
		cout<<"\n---------------------------------------------------------------------------";
		cout<<endl<<"Here is the game:\n";
		for(int i{0}; i<total_number_of_heaps;i++){
			cout<<(char)(i+65)<<": ";
			for(int j{0}; j<total_number_of_tokens; j++){
				if(gameArray[i][j]!=0)
				cout<<"O ";
			}
			cout<<endl;
		}
		//Call the userVsPlayer function
		userVsPC(gameArray);
		cout<<"\n\n***Game Over***\n";
	}
	//If option 3 is chosen
	else{
		cout<<"\n***Game Over***\n";
	}
	return 0;
}
//Function declarations:
int nim_to_win_option1(vector<int>& rowA, vector<int>& rowB, vector<int>& rowC, vector<int>& rowD, vector<int>& rowE, int& total_number_of_tokens, int& player_turn){
	static char row_char{ 'L' };
	static int token_move{ 0 };
	if (total_number_of_tokens==0)
		return player_turn;
	cout << "A: ";
	for (int item : rowA){
		cout << item;
	}
	cout << endl << "B: ";
	for (int item : rowB){
		cout << item;
	}
	cout << endl << "C: ";
	for (int item : rowC){
		cout << item;
	}
	cout << endl << "D: ";
	for (int item : rowD){
		cout << item;
	}
	cout << endl << "E: ";
	for (int item : rowE){
		cout << item;
	}
	cout << endl;
	if (player_turn % 2 == 0){
		cout<<endl<<playerOneName<< ", please select a row and either 1 or 2 tokens (ex: \"B2\" or \"D 1\"): ";
	}
	else{
		cout<<endl<<playerTwoName<< ", please select a row and either 1 or 2 tokens (ex: \"B2\" or \"D 1\"): ";
	}
	cin >> row_char;
	cin >> token_move;
	while ((token_move > 2) || (token_move < 1) || (row_char > 69) || (row_char < 65)){
		cout << "Invalid move, please try again ";
		if (player_turn % 2 == 0){
			cout <<playerOneName<< ", select a row and either 1 or 2 tokens (ex: B 2, D 1...): ";
		}
		else{
			cout <<playerTwoName<< ", select a row and either 1 or 2 tokens (ex: B 2, D 1...): ";
		}
		cin >> row_char;
		cin >> token_move;
	}
	size_t tmove=token_move;
	if (row_char == 'A'){
		if (tmove > rowA.size()){
			cout << "Impossible move, please try again\n";
			return nim_to_win_option1(rowA, rowB, rowC, rowD, rowE, total_number_of_tokens, player_turn);
		}
		else if (token_move == 1){
			rowA.erase(rowA.begin());
			total_number_of_tokens -= 1;
			++player_turn;
			return nim_to_win_option1(rowA, rowB, rowC, rowD, rowE, total_number_of_tokens, player_turn);
		}
		else{
			rowA.erase(rowA.begin());
			rowA.erase(rowA.begin());
			total_number_of_tokens -= 2;
			++player_turn;
			return nim_to_win_option1(rowA, rowB, rowC, rowD, rowE, total_number_of_tokens, player_turn);
		}
	}
	else if (row_char == 'B'){
		if (tmove > rowB.size()){
			cout << "Impossible move, please try again\n";
			return nim_to_win_option1(rowA, rowB, rowC, rowD, rowE, total_number_of_tokens, player_turn);
		}
		else if (token_move == 1){
			rowB.erase(rowB.begin());
			total_number_of_tokens -= 1;
			++player_turn;
			return nim_to_win_option1(rowA, rowB, rowC, rowD, rowE, total_number_of_tokens, player_turn);
		}
		else{
			rowB.erase(rowB.begin());
			rowB.erase(rowB.begin());
			total_number_of_tokens -= 2;
			++player_turn;
			return nim_to_win_option1(rowA, rowB, rowC, rowD, rowE, total_number_of_tokens, player_turn);
		}
	}
	else if (row_char == 'C'){
		if (tmove > rowC.size()){
			cout << "Impossible move, please try again\n";
			return nim_to_win_option1(rowA, rowB, rowC, rowD, rowE, total_number_of_tokens, player_turn);
		}
		else if (token_move == 1){
			rowC.erase(rowC.begin());
			total_number_of_tokens -= 1;
			++player_turn;
			return nim_to_win_option1(rowA, rowB, rowC, rowD, rowE, total_number_of_tokens, player_turn);
		}
		else{
			rowC.erase(rowC.begin());
			rowC.erase(rowC.begin());
			total_number_of_tokens -= 2;
			++player_turn;
			return nim_to_win_option1(rowA, rowB, rowC, rowD, rowE, total_number_of_tokens, player_turn);
		}
	}
	else if (row_char == 'D'){
		if (tmove > rowD.size()){
			cout << "Impossible move, please try again\n";
			return nim_to_win_option1(rowA, rowB, rowC, rowD, rowE, total_number_of_tokens, player_turn);
		}
		else if (token_move == 1){
			rowD.erase(rowD.begin());
			total_number_of_tokens -= 1;
			++player_turn;
			return nim_to_win_option1(rowA, rowB, rowC, rowD, rowE, total_number_of_tokens, player_turn);
		}
		else{
			rowD.erase(rowD.begin());
			rowD.erase(rowD.begin());
			total_number_of_tokens -= 2;
			++player_turn;
			return nim_to_win_option1(rowA, rowB, rowC, rowD, rowE, total_number_of_tokens, player_turn);
		}
	}
	else if (row_char == 'E'){
		if (tmove > rowE.size()){
			cout << "Impossible move, please try again\n";
			return nim_to_win_option1(rowA, rowB, rowC, rowD, rowE, total_number_of_tokens, player_turn);
		}
		else if (token_move == 1){
			rowE.erase(rowE.begin());
			total_number_of_tokens -= 1;
			++player_turn;
			return nim_to_win_option1(rowA, rowB, rowC, rowD, rowE, total_number_of_tokens, player_turn);
		}
		else{
			rowE.erase(rowE.begin());
			rowE.erase(rowE.begin());
			total_number_of_tokens -= 2;
			++player_turn;
			return nim_to_win_option1(rowA, rowB, rowC, rowD, rowE, total_number_of_tokens, player_turn);
		}
	}
	return 0;
}
void userVsPC(array<array<int,tnot>,tnoh>&game){
	int numOfTokens{0};
	char row_char{'A'};
	int token_move{1};
	for(int i{0}; i<=total_number_of_heaps;i++)
		for(int j{0}; j<=total_number_of_tokens;j++){
			if(game[i][j]==1)
				numOfTokens++;
		}
	if (numOfTokens<=1){  //base case
		if(numOfTokens==0){
			if(player_turn%2==0)
				cout<<"\nYou lost!";
			else
				cout<<"\nYou won "<<playerOneName<<"!!";
			return;
		}
	}
	if (player_turn%2==0){
		cout<<endl<<playerOneName<<", please select a row and either 1 or 2 tokens (ex: B 2, D 1...): ";
		cin>>row_char;
		cin>>token_move;
	}
	else{
		//Create an array representing the number of tokens on each heap
		array<int,tnoh>computerArray;
		for(int heap{0}; heap<total_number_of_heaps;heap++){
			int tokensInHeap{0};
			for(int t{0}; t<total_number_of_tokens; t++){
				if(game[heap][t]!=0)
					tokensInHeap++;
				}
			computerArray[heap]=tokensInHeap;
		}
		//Determine how many heaps have tokens in them
		int heapsWithTokens{0};
		for(int i{0}; i<total_number_of_heaps; i++)
			if(computerArray[i]>0)
				heapsWithTokens++;
		//Determine the number of tokens in the most populated heap
		int mostTokensInHeap{0};
		for(int i{0}; i<total_number_of_heaps; i++)
			if(computerArray[i]>mostTokensInHeap)
				mostTokensInHeap=computerArray[i];
		//Determine the number of heaps with one token
		int heapsWithOneToken{0};
		for(int i{0}; i<total_number_of_heaps; i++)
			if(computerArray[i]==1)
				heapsWithOneToken++;
		//Determine the number of heaps with two tokens
		int heapsWithTwoTokens{0};
		for(int i{0}; i<total_number_of_heaps; i++)
			if(computerArray[i]==2)
				heapsWithTwoTokens++;
		//Determine the number of heaps with three tokens
		int heapsWithThreeTokens{0};
		for(int i{0}; i<total_number_of_heaps; i++)
			if(computerArray[i]==3)
				heapsWithThreeTokens++;
		//Create an array for the heap states
		array<int,10>heapState{};
		for(int i{0}; i<total_number_of_heaps; i++){
			if(computerArray[i]==0)
				heapState[i]=0;
			else if(computerArray[i]==1)
				heapState[i]=1;
			else if(computerArray[i]==2)
				heapState[i]=2;
			else if(computerArray[i]==3)
				heapState[i]=-5;
			else if(computerArray[i]>3 && computerArray[i]%3!=0)
				heapState[i]=5;
			else if(computerArray[i]>3 && computerArray[i]%3==0)
				heapState[i]=-5;
			}
		//Determine the number of disadvantaged heaps
		int disadvantagedHeaps{0};
		for(int i{0}; i<total_number_of_heaps; i++){
			if(heapState[i]==-5 || heapState[i]==3 ){
				disadvantagedHeaps++;
			}
		}
/////////////////////////////////////////////////////
		cout<<"\nComputer's turn:\n";
		//Determine a course of action
		//If only one active heap is left:
		if(heapsWithTokens==1){
			for(int i{0}; i<total_number_of_heaps;i++){
				//if there is only one token
				if(computerArray[i]==1){
					row_char=(char)(i+65);
					token_move=1;
					//cout<<"1-Computer wins";
					break;
				}
				//if there is only two tokens
				else if (computerArray[i]==2){
					row_char=(char)(i+65);
					token_move=2;
					//cout<<"2-Computer wins";
					break;
				}
				//if there are three tokens
				else if (computerArray[i]==3){
					row_char=(char)(i+65);
					token_move=2;
					//cout<<"3-Maximize moves (computer loosing-remove 1)";
					break;
				}
				//if there are more than three tokens
				else if (computerArray[i]>3){
					if(computerArray[i]%3!=0){
						row_char=(char)(i+65);
						token_move=computerArray[i]%3;
						//cout<<"4-Subtract the reminder %3 to change the heap to disadvantaged state";
						break;
					}
					else{
						row_char=(char)(i+65);
						token_move=1;
						//cout<<"5-Maximize moves (computer loosing-remove 1)";
						break;
					}
				}
			}
		}
		//If multiple heaps are active
		else if(heapsWithTokens>1){
			//If all the heaps have only token
			if(mostTokensInHeap==1){
				for(int i{0}; i<total_number_of_heaps; i++)
					if(computerArray[i]==1){
						row_char=(char)(i+65);
						token_move=1;
						//cout<<"6-Forced to remove token";
						break;
					}
			}
 			//If the largest heap has at most 3 tokens
			else if(mostTokensInHeap<=3){
				for(int i{0}; i<total_number_of_heaps; i++){
					//If the largest heap has at most 1 token
					if(mostTokensInHeap==1){
						row_char=(char)(i+65);
						token_move=1;
						//cout<<"7-Remove 1 (no option. If active heaps are odd=winning, else=loosing)";
						break;
					}
					//if there is only one H2 and even H1s
					else if(heapsWithTwoTokens==1 && heapsWithOneToken%2==0 && computerArray[i]==2){
						row_char=(char)(i+65);
						token_move=2;
						//cout<<"8-Keep H1s even (remove 2 from H2)";
						break;
					}
					//if there is only one H2 and there are odd H1s
					else if(heapsWithTwoTokens==1 && heapsWithOneToken%2!=0 && computerArray[i]==2){
						row_char=(char)(i+65);
						token_move=1;
						//cout<<"9-Make H1s even (remove 1 from H2)";
						break;
					}
					//if there is more than one (even number) of H2s and H1s are also even
					else if(heapsWithTwoTokens>1 && heapsWithTwoTokens%2==0 && heapsWithOneToken%2==0 && computerArray[i]==2){
						row_char=(char)(i+65);
						token_move=1;
						//cout<<"10-Maximize moves (loosing-remove 1 from H2)";
						break;
					}
					//if there is more than one (even number) of H2 and H1s are odd
					else if(heapsWithTwoTokens>1 && heapsWithTwoTokens%2==0 && heapsWithOneToken%2!=0 && computerArray[i]==1){
						row_char=(char)(i+65);
						token_move=1;
						//cout<<"11-Make H1s even (remove 1 from H1)";
						break;
					}
					//if there is more than one (odd number) of H2 and H1s are even
					else if(heapsWithTwoTokens>1 && heapsWithTwoTokens%2!=0 && heapsWithOneToken%2==0 && computerArray[i]==1){
						row_char=(char)(i+65);
						token_move=1;
						//cout<<"12-Make H2s even (remove 2 from H2)";
						break;
					}
					//if there is more than one (odd number) of H2 and H1s are also odd
					else if(heapsWithTwoTokens>1 && heapsWithTwoTokens%2!=0 && heapsWithOneToken%2!=0 && computerArray[i]==1){
						row_char=(char)(i+65);
						token_move=1;
						//cout<<"13-Make both even (remove 1 from H2)";
						break;
					}
					//if there are only heaps with 1 or 3 tokens and H1s are even
					else if(heapsWithOneToken%2==0 && heapsWithTwoTokens==0 && computerArray[i]==3){
						row_char=(char)(i+65);
						token_move=1;
						//cout<<"14-Keep H1s even (loosing-remove 1 from H3)";
						break;
					}
					//if there are only heaps with 1 or 3 tokens and H1s are odd
					else if(heapsWithThreeTokens>0 && heapsWithOneToken%2!=0 && heapsWithTwoTokens==0 && computerArray[i]==1){
						row_char=(char)(i+65);
						token_move=1;
						//cout<<"15-Make H1s even (remove 1 from H1)";
						break;
					}
					//if there are only heaps with 2 or 3 tokens and H2s are even
					else if(heapsWithTwoTokens%2==0 && heapsWithOneToken==0 && computerArray[i]==3){
						row_char=(char)(i+65);
						token_move=1;
						//cout<<"16-Keep H2s even (loosing-remove 1 from H3)";
						break;
					}
					//if there are only heaps with 2 or 3 tokens and H2s are odd
					else if(heapsWithTwoTokens%2!=0 && heapsWithOneToken==0 && computerArray[i]==3){
						row_char=(char)(i+65);
						token_move=1;
						//cout<<"17-Make H2s even (remove 1 from H3)";
						break;
					}
					//if all heaps have 3 tokens
					else if(heapsWithThreeTokens==heapsWithTokens && computerArray[i]==3){
						row_char=(char)(i+65);
						token_move=1;
						//cout<<"18-Maximize moves (loosing-remove 1)";
						break;
					}
				}
			}
			//If the largest heap has more than 3 tokens
			else if(mostTokensInHeap>3){
				for(int i{0}; i<total_number_of_heaps; i++){
					if(computerArray[i]>3){
						if(computerArray[i]%3==0 && heapsWithOneToken!=0 && heapsWithTwoTokens==0){
							for(int j{0}; j<total_number_of_heaps; j++){
								if(computerArray[j]==1){
									row_char=(char)(j+65);
									token_move=1;
									//cout<<"19-Make H1s even";
									break;
								}
							}
						}
						else if(computerArray[i]%3==0 && heapsWithOneToken!=0 && heapsWithTwoTokens==1){
							for(int j{0}; j<total_number_of_heaps; j++){
								if(computerArray[j]==2){
									row_char=(char)(j+65);
									token_move=1;
									//cout<<"20-Make H1s even";
									break;
								}
							}
						}
						else if(computerArray[i]%3==0 && heapsWithTwoTokens%2!=0){
							for(int j{0}; j<total_number_of_heaps; j++){
								if(computerArray[j]==2){
									row_char=(char)(j+65);
									token_move=2;
									//cout<<"21-Let the opponent start the disadvantaged heap by eliminating a heap";
									break;
								}
							}
						}
						else if(computerArray[i]%3!=0){
							row_char=(char)(i+65);
							token_move=computerArray[i]%3;
							//cout<<"22-Subtract the reminder %3 to change the heap to disadvantaged state";
							break;
						}
						else{
							row_char=(char)(i+65);
							token_move=1;
							//cout<<"23-Maximize moves (loosing-remove 1)";
							break;
						}
					}
				}
			}
		}
	}
	while ( (token_move > 2) || (token_move < 1) || (row_char > (65+total_number_of_heaps)) || (row_char < 65)){
		cout<<"Invalid move, please try again.\n";
		cout<<playerOneName<<", please select a row and either 1 or 2 tokens (ex: B 2, D 1...): ";
		cin>>row_char;
		cin>>token_move;
		}
	int heapIndex=((int)row_char)-65;
	int tokensInHeap{0};
	for(int i{0}; i<=total_number_of_tokens;i++){
		if (game[heapIndex][i]==1)
			tokensInHeap++;
		}
	if(token_move>tokensInHeap){
		cout<<"\nCan't do that, lets try again.\n";
		userVsPC(game);
		return;
	}
	//Modify the gameArray
	game[heapIndex][tokensInHeap-1]=0;
	if(token_move==2)
		game[heapIndex][tokensInHeap-2]=0;
	cout<<"\n***"<<token_move<<" tokens removed from heap "<<row_char<<"***"<<endl;
	//print the game
	for(int i{0}; i<total_number_of_heaps;i++){
		cout<<(char)(i+65)<<": ";
		for(int j{0}; j<total_number_of_tokens; j++){
			if(game[i][j]!=0)
			cout<<"O ";
		}
		cout<<endl;
	}
	total_number_of_tokens-=token_move;
	player_turn++;
	userVsPC(game);
}




