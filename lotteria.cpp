#include "game_board.h"
int main (){
	game_board newDay;	
	bool open = newDay.getIsOpen(), limit = newDay.getLimit();
	while(open == true && limit == false){
		newDay.take_ticket();
		open = newDay.getIsOpen();
		limit = newDay.getLimit();
	}
	
	cout<<"End day."<<endl;
	cout<<"Do you want see the report? [y,n]"<<endl;
	char y; cin>>y;
	if(y == 'y') newDay.report();
	
	return 0;
}
