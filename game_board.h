#ifndef GAME_BOARD_H
#define GAME_BOARD_H
#include "Cartella.h"
#include <cstdio>
#include <ctime>
//Aggiungere numero oro
class game_board{
	private:
	//Constant variables
		const int maxResource = 5000000; // 5 Milion
		const int winnerNumberSize = 20; // 10 winner finally number
	//Simple variables
		bool isOpen;
		bool limit;
		int cardPlayed;
		int playerAge;
		int minors;
		float totMoneyPlayed;
		float totWin;
		int totJackpot;
		int totGoldNumbers;
		
		float tempPayed;
		float tempMax;
		float maxPayed;
		list <int> winnerListNumbers;
	//Awards
		int* winnerNumber = new int [20];
		int goldNumber;
		
		
	public:
	game_board() {
		srand (time(NULL));
		isOpen = true;
		limit = false;
		cardPlayed = 0;
		totGoldNumbers = 0;
		totJackpot = 0;
		totWin = 0;
		minors = 0;
		tempMax = 0;
		tempPayed = 0;
		maxPayed = 0;
		totMoneyPlayed = 0;
		int n = 0;
		cout<<"Winner numbers: ";
		while(n<20){
		int num = rand()%90+1;
			if(addWinnerNumber(num,n)){
				winnerNumber[n] = num;
				cout<<winnerNumber[n]<<" - ";
				n += 1;
			}
		}
		goldNumber = winnerNumber[ rand()%20 ];
		cout<<"\nGold number: "<<goldNumber<<endl;
	}
	
	bool addWinnerNumber (int x,int n){
		for(int i=0;i<n;i++)
			if(winnerNumber[i] == x) return false;
		return true;
	}
	
	~game_board() { delete[] winnerNumber;}
	
	void report () {
		cout<<"Report:"<<endl;
		cout<<"Play maxims daily: 1000"<<endl;
		cout<<"Play done: "<<cardPlayed<<endl;
		cout<<"---"<<endl;
		cout<<"Money played in total: "<<totMoneyPlayed<<",00$"<<endl;
		cout<<"Money won in total: "<<totWin<<",00$"<<endl;
		cout<<"---"<<endl;
		cout<<"Winning numbers: ";
		cout<<winnerNumber[0];
		for(int it=1;it<10;it++) cout<<"-"<<winnerNumber[it];
		cout<<"\nGold number: "<<goldNumber<<endl;
		cout<<"Card with higher payout: ";
		for(auto it:winnerListNumbers) cout<<it<<" - ";
		cout<<"\nMoney wagered: "<<maxPayed<<",00$"<<endl;
		cout<<"Money won: "<<tempMax<<",00$"<<endl;
		cout<<"---"<<endl;
		cout<<"Total Jackpot: "<<totJackpot<<endl;
		cout<<"The gold number has been found "<<totGoldNumbers<<" times."<<endl;
		cout<<"---"<<endl;
		cout<<minors<<" minors tried to play."<<endl;
		cout<<"---"<<endl;
		if(totWin > totMoneyPlayed)
			cout<<"Based on the data collected, the day ended positively! Through the bets have been earned "<<totWin-totMoneyPlayed<<",00$"<<endl;
		else
			cout<<"Based on the data collected, the day ended negatively. "<<totMoneyPlayed-totWin<<",00$ they were lost to gambling."<<endl;
		return;
	}
	
	void take_ticket() {
		if(totMoneyPlayed < maxResource){
			if(cardPlayed < 1000){ //A maximum of 200 cards can be played
				playerAge = rand()%80+14;
				if(playerAge >= 18){ //If it is a minors or not
					Cartella newCard ( rand()%10+1, rand()%200+2); //New Card created: 0 < size < 11 && 1 < card cost < 201
					totMoneyPlayed += newCard.getCost();
					cardPlayed += 1;
					
					int temp = 0;
					while(temp < newCard.getSize()){
						if(newCard.addNumber(rand ()%90+1)){
							temp += 1;
						}
					}
					
					tempPayed = newCard.getCost();
					newCard.winORlose(winnerNumber);
					newCard.findGold(goldNumber);
					
					if(newCard.getGoldNumber()) totGoldNumbers += 1;
					
					float earn = newCard.moneyWin();
					if(earn > tempMax) {
						winnerListNumbers.clear();
						winnerListNumbers = newCard.getNumbers();
						maxPayed = tempPayed;
						tempMax = earn;
					}
					cout<<"The card number "<<cardPlayed<<" won:  "<<earn<<",00$"<<endl;
					totWin += earn;
					if(earn >= 1000000) totJackpot += 1;
					
				}
				else
					minors += 1;
			}
			else{
				limit = true;
			}
		}
		else{
			isOpen = false;
		}
	}
	list<int> getWinnerListNumbers () { return winnerListNumbers; }
	bool getIsOpen () { return isOpen; }
	bool getLimit () { return limit; }
	int getTotWin () { return totWin;}
	
};

#endif
