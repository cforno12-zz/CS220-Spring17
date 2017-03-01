rps player_cforno1(int round,rps *myhist,rps *opphist) {
	if(round <= 2){
		char i = rand()%3;
		switch(i) {
			case 0: return Rock;
			case 1: return Scissors;
		}	
		return Paper;
	} else {
		rps prev = opphist[round-1];
        	if(prev == Rock) {
         		return Paper;	
        	}
		if(prev == Paper){
			return Scissors;
		}
		if(prev == Scissors){
			return Rock;
		}
	}
	return Rock;
}

register_player(player_cforno1,"cforno1");
