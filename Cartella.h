#ifndef CARTELLA_H
#define CARTELLA_H
#include <iostream>
#include <list>
using namespace std;
class Cartella{
	private:
		int size;
		float cost;
		list <int> numbers;
		int numbersFound;
		bool goldNumber;
		
	public:
		Cartella() {}
		Cartella(int _size, float _cost) : size(_size), cost(_cost) {}
		
		list<int> getNumbers () { return numbers; }
		
		bool addNumber(int newNumber) {
			for(auto it:numbers){
				if(it == newNumber) return false;
			}
			numbers.push_back(newNumber);
			goldNumber = false;
			return true;
		}
		
		void findGold (int num){
			for(auto it:numbers) 
				if(it == num){
					goldNumber = true;
					return;
				}
			goldNumber = false;
		}
		
		void winORlose (int* winnerNumber) { 
		numbersFound = 0;
			for(int i=0;i<10;i++)
				for(auto it:numbers){
					if(winnerNumber[i] == it){
						numbersFound += 1;
					}
				}
			return;
		}
		float moneyWin () {
		switch (size){
				case 0:
					return 0;
				break;
				
				case 1:
				//Winner number
					if (numbersFound == 1 && goldNumber == false) return cost *= 3;
				//Gold number
					else if (numbersFound == 1 && goldNumber == true) return cost *= 63;
				break;
				
				case 2:
				//Winner number
					if (numbersFound == 2 && goldNumber == false) return cost *= 14;
				//Gold number
					else if(numbersFound == 1 && goldNumber == true) return cost *= 25;
					else if(numbersFound == 2 && goldNumber == true) return cost *= 70;
					break;
					
				case 3:
				//Winner number
				 	if (numbersFound == 2 && goldNumber == false) return cost *= 2;
				 	else if (numbersFound == 3 && goldNumber == false) return cost *= 50;
				//Gold number
					else if(numbersFound == 1 && goldNumber == true) return cost *= 15;
				 	else if(numbersFound == 2 && goldNumber == true) return cost *= 25;
					break;
					
				case 4:
				//Winner number
					if (numbersFound == 2 && goldNumber == false) return cost *= 1;
					else if (numbersFound == 3 && goldNumber == false) return cost *= 10;
					else if (numbersFound == 4 && goldNumber == false) return cost *= 100;
				//Gold number
					else if(numbersFound == 1 && goldNumber == true) return cost *= 10;
					else if(numbersFound == 2 && goldNumber == true) return cost *= 15;
					else if(numbersFound == 3 && goldNumber == true) return cost *= 40;
					else if(numbersFound == 4 && goldNumber == true) return cost *= 300;
					break;
					
				case 5:
				//Winner Number
					if (numbersFound == 2 && goldNumber == false) return cost *= 1;
					else if (numbersFound == 3 && goldNumber == false) return cost *= 4;
					else if (numbersFound == 4 && goldNumber == false) return cost *= 15;
					else if (numbersFound == 5 && goldNumber == false) return cost *= 150;
				//Gold number
					else if(numbersFound == 1 && goldNumber == true) return cost *= 10;
					else if(numbersFound == 2 && goldNumber == true) return cost *= 15;
					else if(numbersFound == 3 && goldNumber == true) return cost *= 20;
					else if(numbersFound == 4 && goldNumber == true) return cost *= 40;
					else if(numbersFound == 5 && goldNumber == true) return cost *= 400;
					break;
					
				case 6:
				//Winner number
					if (numbersFound == 3 && goldNumber == false) return cost *= 2;
					else if (numbersFound == 4 && goldNumber == false) return cost *= 10;
					else if (numbersFound == 5 && goldNumber == false) return cost *= 100;
					else if (numbersFound == 6 && goldNumber == false) return cost *= 1000;
				//Gold number
					else if(numbersFound == 1 && goldNumber == true) return cost *= 10;
					else if(numbersFound == 2 && goldNumber == true) return cost *= 10;
					else if(numbersFound == 3 && goldNumber == true) return cost *= 10;
					else if(numbersFound == 4 && goldNumber == true) return cost *= 25;
					else if(numbersFound == 5 && goldNumber == true) return cost *= 250;
					else if(numbersFound == 6 && goldNumber == true) return cost *= 2500;
					break;
					
				case 7:
				//Winner number
					if (numbersFound == 0 && goldNumber == false) return cost *= 1;
					else if (numbersFound == 4 && goldNumber == false) return cost *= 4;
					else if (numbersFound == 5 && goldNumber == false) return cost *= 40;
					else if (numbersFound == 6 && goldNumber == false) return cost *= 400;
					else if (numbersFound == 7 && goldNumber == false) return cost *= 2000;
				//Gold number
					else if(numbersFound == 1 && goldNumber == true) return cost *= 10;
					else if(numbersFound == 2 && goldNumber == true) return cost *= 7;
					else if(numbersFound == 3 && goldNumber == true) return cost *= 7;
					else if(numbersFound == 4 && goldNumber == true) return cost *= 10;
					else if(numbersFound == 5 && goldNumber == true) return cost *= 100;
					else if(numbersFound == 6 && goldNumber == true) return cost *= 1000;
					else if(numbersFound == 7 && goldNumber == true) return cost *= 5000;
					break;
					
				case 8:
				//Winner number
					if (numbersFound == 0 && goldNumber == false) return cost *= 1;
					else if (numbersFound == 5 && goldNumber == false) return cost *= 20;
					else if (numbersFound == 6 && goldNumber == false) return cost *= 200;
					else if (numbersFound == 7 && goldNumber == false) return cost *= 1000;
					else if (numbersFound == 8 && goldNumber == false) return cost *= 10000;
				//Gold number
					else if(numbersFound == 1 && goldNumber == true) return cost *= 8;
					else if(numbersFound == 2 && goldNumber == true) return cost *= 3;
					else if(numbersFound == 3 && goldNumber == true) return cost *= 5;
					else if(numbersFound == 4 && goldNumber == true) return cost *= 10;
					else if(numbersFound == 5 && goldNumber == true) return cost *= 50;
					else if(numbersFound == 6 && goldNumber == true) return cost *= 500;
					else if(numbersFound == 7 && goldNumber == true) return cost *= 2500;
					else if(numbersFound == 8 && goldNumber == true) return cost *= 30000;
					break;
					
				case 9:
				//Winner number
					if (numbersFound == 0 && goldNumber == false) return cost *= 2;
					else if (numbersFound == 5 && goldNumber == false) return cost *= 10;
					else if (numbersFound == 6 && goldNumber == false) return cost *= 40;
					else if (numbersFound == 7 && goldNumber == false) return cost *= 400;
					else if (numbersFound == 8 && goldNumber == false) return cost *= 2000;
					else if (numbersFound == 9 && goldNumber == false) return cost *= 100000;
				//Gold number
					else if(numbersFound == 1 && goldNumber == true) return cost *= 5;
					else if(numbersFound == 2 && goldNumber == true) return cost *= 3;
					else if(numbersFound == 3 && goldNumber == true) return cost *= 5;
					else if(numbersFound == 4 && goldNumber == true) return cost *= 10;
					else if(numbersFound == 5 && goldNumber == true) return cost *= 25;
					else if(numbersFound == 6 && goldNumber == true) return cost *= 100;
					else if(numbersFound == 7 && goldNumber == true) return cost *= 1000;
					else if(numbersFound == 8 && goldNumber == true) return cost *= 50000;
					else if(numbersFound == 9 && goldNumber == true) return cost *= 250000;
					
					break;
					
				case 10:
				//Winner number
					if (numbersFound == 0 && goldNumber == false) return cost *= 2;
					else if (numbersFound == 5 && goldNumber == false) return cost *= 5;
					else if (numbersFound == 6 && goldNumber == false) return cost *= 15;
					else if (numbersFound == 7 && goldNumber == false) return cost *= 150;
					else if (numbersFound == 8 && goldNumber == false) return cost *= 1000;
					else if (numbersFound == 9 && goldNumber == false) return cost *= 20000;
					else if (numbersFound == 10 && goldNumber == false) {
					cout<<"-***JECKPOT***-"<<endl;
					return cost *= 1000000;
					}
				//Gold number
					else if(numbersFound == 1 && goldNumber == true) return cost *= 10;
					else if(numbersFound == 2 && goldNumber == true) return cost *= 3;
					else if(numbersFound == 3 && goldNumber == true) return cost *= 3;
					else if(numbersFound == 4 && goldNumber == true) return cost *= 5;
					else if(numbersFound == 5 && goldNumber == true) return cost *= 20;
					else if(numbersFound == 6 && goldNumber == true) return cost *= 40;
					else if(numbersFound == 7 && goldNumber == true) return cost *= 400;
					else if(numbersFound == 8 && goldNumber == true) return cost *= 3000;
					else if(numbersFound == 9 && goldNumber == true) return cost *= 50000;
					else if(numbersFound == 10 && goldNumber == true) return cost *= 250000;
					
					break;
					
				default:
					cout<<"Errore!"<<endl;
					return -1;
					break;
			}
			return 0;
		}
		float getCost() { return cost; }
		int getSize() { return size; }
		bool getGoldNumber() { return goldNumber; }

};

#endif
