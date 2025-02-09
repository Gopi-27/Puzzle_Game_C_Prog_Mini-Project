#include<stdio.h>
#include<stdlib.h>
#include<time.h>
// All functions
char Value[]="0123456789";
char p1name[30];
char p2name[30];
char p1pin;
char p2pin;
char cpin='C';
char cmove1;
char cmove2;
int move1;
int move2;
void DrawBoard(void);
int Checking(void);
char IsValidPin(char);
int TossChecking(int);
int IsValidPos(int);
int IsValidMove(int ,int,char);
void AskAgain(char);
void Swapping(int,char *,char *);
int AskPinPos(void);
void AskMove(void);

int IsValidPos2(int);
int AskPinPos2(void);
void AskMove2(void);
void AskAgain2(char);
int IsValidMove2(int ,int,char);

void DeclareWinner(int);
void Cornercase1_3(void);
void Cornercase1_7(void);
void Cornercase7_9(void);
void Cornercase3_9(void);

void DrawBoard(){
	printf("\t---------------------------------\n");
	printf("\t| %c | + + + + | %c | + + + + | %c |\n",Value[1],Value[2],Value[3]);
	printf("\t---------------------------------\n");
	printf("\t| + | x       | + |       x | + |\n");
	printf("\t| + |   x     | + |     x   | + |\n");
	printf("\t| + |     x   | + |   x     | + |\n");
	printf("\t| + |       x | + | x       | + |\n");
	printf("\t---------------------------------\n");
	printf("\t| %c | + + + + | %c | + + + + | %c |\n",Value[4],Value[5],Value[6]);
	printf("\t---------------------------------\n");
	printf("\t| + |       x | + | x       | + |\n");
	printf("\t| + |     x   | + |   x     | + |\n");
	printf("\t| + |   x     | + |     x   | + |\n");
	printf("\t| + | x       | + |       x | + |\n");
	printf("\t---------------------------------\n");
	printf("\t| %c | + + + + | %c | + + + + | %c |\n",Value[7],Value[8],Value[9]);
	printf("\t---------------------------------\n");
}
int Checking(void){
	if(Value[1]==Value[2] && Value[2]==Value[3]){
		return 0;
	}else if(Value[4]==Value[5] && Value[5]==Value[6]){
		return 0;
	}else if(Value[7]==Value[8] && Value[8]==Value[9]){
		return 0;
	}else if(Value[1]==Value[4] && Value[4]==Value[7]){
		return 0;
	}else if(Value[2]==Value[5] && Value[5]==Value[8]){
		return 0;
	}else if(Value[3]==Value[6] && Value[6]==Value[9]){
		return 0;
	}else if(Value[1]==Value[5] && Value[5]==Value[9]){
		return 0;
	}else if(Value[3]==Value[5] && Value[5]==Value[7]){
		return 0;
	}else {
		return 1;
	}
}

char IsValidpin(char pin){
	if(pin!='C'&& pin>='A' && pin<='Z'){
		return pin;
	}else{
		printf("Invalid Selection of Pin\n");
		printf("'%s' Enter Valid Pin ( A - Z Except 'C'):\n",p1name);
		scanf(" %c",&pin);
		return IsValidpin(pin);
	}
}

void Swapping(int move,char *a,char *b){
	char temp=*a;
	*a=move+48;
	*b=temp;
}
int IsValidMove(int p1,int p2,char pin){
	if(p2==p1){
		 	AskAgain(pin);
	}else if(Value[p2]==p1pin|| Value[p2]==cpin){
		AskAgain(pin);
	}else if(Value[p1]==pin){
	switch(p1){
		case 1:
			if(p2==2 || p2==5 ||p2==4){
					return 1;
			}else{
		 	AskAgain(pin);
			}
		 
		break;
		case 2:
		 if(p2==1|| p2==5|| p2==3){
			return 1;
		 }else{
		 AskAgain(pin);
		 }
		break;
		case 3:
		  if(p2==2|| p2==5|| p2==6){
		  	return 1;
		}else{
		 	AskAgain(pin);
		 }
		break;
		case 4: 
		 if(p2==1|| p2==5|| p2==7){
		 	return 1;
		 }else{
		 	AskAgain(pin);
		 }
		break;
		case 5: 
		 if(p2==1|| p2==2|| p2==3|| p2==4|| p2==6|| p2==7|| p2==8|| p2==9){
				return 1;
		 }else{
		 	AskAgain(pin);
		 }
		break;
		case 6: 
		 if(p2==3|| p2==5|| p2==9){
		   return 1;
		 }else{
		 	AskAgain(pin);
		 }
		break;
		case 7: 
		 if(p2==4|| p2==5|| p2==8){
		 return 1;
		 }else{
		 	AskAgain(pin);
		 }
		break;
		case 8: 
		 if(p2==5|| p2==7|| p2==9){
		 return 1;	
		 }else{
		 	AskAgain(pin);
		 }
		break;
		case 9: 
		 if(p2==5|| p2==6|| p2==8){
		 return 1;
		 }else{
		 	AskAgain(pin);
		 }
		break;
		default:
		AskAgain(pin);
		break;
	}
  }else{
	AskAgain(pin);
}
}
int main(){
	printf("--------------Welcome To The Game-----------\n");
	printf("-----------------Sample Borad---------------\n");
	DrawBoard();
	printf("------------------Game Menu------------------\n");
	printf("1. Human Vs Human\n");
	printf("2. Human Vs Computer\n");
	printf("---------------------------------------------\n");
	printf("Enter Your Choice (1 or 2):\n");
	char choice;
	scanf(" %c",&choice);
	while(1){
		if(choice=='1' || choice=='2'){
			break;
		}
		printf("Invalid Choice\n");
		printf("Enter Your Choice (1 or 2):\n");
		scanf(" %c",&choice);
	}
	// switching to the choice either H Vs H or C Vs H
	if(choice=='1'){
	printf("Can you Please Enter player-->1 Name:\n");
	scanf(" %[^\n]s",p1name);
	getchar();
	printf("Can you Please Enter Player-->2 Name:\n");
	scanf(" %[^\n]s",p2name);
	printf("-------------------------------------------\n");
	printf("WELCOME TO GAME '%s' , '%s' \n",p1name,p2name);
	printf("-------------------------------------------\n");
	printf("Let's Start the game\n");
	printf("-------------------------------------------\n");
	printf("Let's Decide Who Will start the Game First\n");
	printf("-------------------------------------------\n");
        srand(time(0));
		int Toss=rand();
		char p1toss;
		printf("'%s' Enter '0' for Heads or '1' for Tails:\n",p1name);
		scanf(" %c",&p1toss);
		while(1){
			if(p1toss=='1' || p1toss=='0'){
				break;
			}
			printf("Invalid Selection\n");
			printf("'%s' Enter '0' for Heads or '1' for Tails:\n",p1name);
	    	scanf(" %c",&p1toss);
		}
		int starter;
		if((p1toss=='0' && Toss%2==0) || (p1toss=='1' && Toss%2!=0)){
			printf("-------------------------------------------\n");
			printf("'%s'  Won the Toss\n",p1name);
			printf("-------------------------------------------\n");
			printf("'%s' is going to Start the Game first\n",p1name);
			starter=1;
		}else{
			printf("-------------------------------------------\n");
			printf(" '%s' Won The Toss\n",p2name);
			printf("-------------------------------------------\n");
			printf("'%s' is going to Start The Game first\n",p2name);
			starter=2;
		}
	printf("--------------Toss is successfully completed-----------\n");
	printf("-------------------------------------------------------\n");
	printf(" '%s' Enter Your  Pin (A - Z):\n",p1name);
	scanf(" %c",&p1pin);
	while(1){
		if(p1pin>='A' && p1pin<='Z'){
			break;
		}
		printf("Invalid Selection\n");
		printf(" '%s' Enter Your  Pin (A - Z):\n",p1name);
		scanf(" %c",&p1pin);
	}
	printf(" '%s' Enter Your Pin (A-Z except %c):\n",p2name,p1pin);
	scanf(" %c",&p2pin);
	while(1){
		if(p2pin!=p1pin && p2pin>='A' && p2pin<='Z'){
			break;
		}
		printf("Invalid Selection\n");
		printf(" '%s' Enter Your Pin (A-Z except %c):\n",p2name,p1pin);
		scanf(" %c",&p2pin);
	}
	cpin=p2pin;
	printf("----------------Pin's Selection is Succesfully Completed---------\n");
	printf(" %s's Pin is %c\n",p1name,p1pin);
	printf(" %s's Pin is %c\n",p2name,p2pin);
	printf("---------------Let's go the Game---------------\n");
		if(starter==1){
			DrawBoard();
			int pos;
			pos=AskPinPos();
			pos=IsValidPos(pos);
			Value[pos]=p1pin;
			DrawBoard();
			pos=AskPinPos2();
			pos=IsValidPos2(pos);
			Value[pos]=p2pin;
			DrawBoard();
			pos=AskPinPos();
			pos=IsValidPos(pos);
			Value[pos]=p1pin;
			DrawBoard();
			pos=AskPinPos2();
			pos=IsValidPos2(pos);
			Value[pos]=p2pin;
			DrawBoard();
			pos=AskPinPos();
			pos=IsValidPos(pos);
			Value[pos]=p1pin;
			int res=Checking();
			if(res==0){
				DrawBoard();
				printf("---------'%s' Won the Game------------\n",p1name);
				printf("------------------The Game is Over-----------------\n");
				return 5;
			}
			DrawBoard();
			pos=AskPinPos2();
			pos=IsValidPos2(pos);
			Value[pos]=p2pin;
			res=Checking();
			if(res==0){
				DrawBoard();
				printf("---------------'%s' Won the Game--------------\n",p2name);
				printf("---------------The Game is Over-------------------------\n");
				return 5;
			}
		
	}else{
		int pos;
		DrawBoard();
			pos=AskPinPos2();
			pos=IsValidPos2(pos);
			Value[pos]=p2pin;
			DrawBoard();
			pos=AskPinPos();
			pos=IsValidPos(pos);
			Value[pos]=p1pin;
			DrawBoard();
			pos=AskPinPos2();
			pos=IsValidPos2(pos);
			Value[pos]=p2pin;
			DrawBoard();
			pos=AskPinPos();
			pos=IsValidPos(pos);
			Value[pos]=p1pin;
			DrawBoard();
			pos=AskPinPos2();
			pos=IsValidPos2(pos);
			Value[pos]=p2pin;
			int res=Checking();
			if(res==0){
				DrawBoard();
				printf("-------------'%s' Won the Game----------------\n",p2name);
				printf("---------------------The Game is Over-------------\n");
				return 5;
		   }
		   DrawBoard();
			pos=AskPinPos();
		   pos=IsValidPos(pos);
		   Value[pos]=p1pin;
		   res=Checking();
		   if(res==0){
		   		DrawBoard();
		   		printf("----------------'%s' Won the Game------------------\n",p1name);
				printf("---------------------The Game is Over-----------------------\n");
				return 5;
		   }
		   
	}
	DrawBoard();
	printf("---------------------------------------------------\n");
	printf("------------It's time to Move YOUR pin's------------\n");
	printf("---------------------------------------------------\n");
	int ans;
	if(starter==1){
		while(Checking()==1){
			AskMove();
			ans=IsValidMove(move1,move2,p1pin);
			Swapping(move1,&Value[move1],&Value[move2]);
			DrawBoard();
			if(Checking()==0){
				printf("'%s' Won The Game\n",p1name);
				printf("----------The Game is Over-----------\n");
				return 5;
				break;
			}
			AskMove2();
			ans=IsValidMove2(move1,move2,p2pin);
			Swapping(move1,&Value[move1],&Value[move2]);
			DrawBoard();	
		}
		printf("-----------------'%s' Won The Game------------------\n",p2name);
	    printf("---------------------The Game is Over----------------------\n");
		return 5;
		
	}else{
		while(Checking()==1){
			AskMove2();
			ans=IsValidMove2(move1,move2,p2pin);
			Swapping(move1,&Value[move1],&Value[move2]);
			DrawBoard();
			if(Checking()==0){
				printf("--------------------'%s' Won The Game-----------------\n",p2name);
				printf("----------------------The Game is Over---------------------\n");
				return 5;
				break;
			}
			AskMove();
			ans=IsValidMove(move1,move2,p1pin);	
			Swapping(move1,&Value[move1],&Value[move2]);
			DrawBoard();
		}
		printf("'%s' Won The Game\n",p1name);
	    printf("----------The Game is Over-----------\n");
		return 5;
	}
			
	}else{
		// C  Vs H
		printf("Hi! Can You Please Enter Your Name:\n ");
		scanf(" %[^\n]s",p1name);
		getchar();
		printf("----------------------------------------------------\n");
		printf(" Mr./Ms. '%s' Welcome To the Game\n",p1name);
		printf("-----------------------------------------------------\n");
		printf("Let's Decide Who Will Start The Game First\n");
		printf("------------------------------------------------------\n");
		srand(time(0));
		int Toss=rand();
		char p1toss;
		printf("'%s' Enter '0' for Heads or '1' for Tails:\n",p1name);
		scanf(" %c",&p1toss);
		while(1){
			if(p1toss=='1' || p1toss=='0'){
				break;
			}
			printf("Invalid Selection\n");
			printf("'%s' Enter '0' for Heads or '1' for Tails:\n",p1name);
	    	scanf(" %c",&p1toss);
		}
		int starter;
		if((p1toss=='0' && Toss%2==0) || (p1toss=='1' && Toss%2!=0)){
			printf("-------------------------------------------\n");
			printf("'%s' You Won the Toss\n",p1name);
			printf("-------------------------------------------\n");
			printf("You are going to Start the Game first\n");
			starter=1;
		}else{
			printf("-------------------------------------------\n");
			printf("Computer won the Toss\n");
			printf("-------------------------------------------\n");
			printf("Computer is going to Start The Game first\n");
			starter=2;
		}
		printf("---------------------------------------------\n");
		printf("'%s' Enter Your pin ( A -Z Except 'C'):\n",p1name);
		scanf(" %c",&p1pin);
		p1pin=IsValidpin(p1pin);
		printf("---------------------------------------------\n");
		printf("'%s' You pin is %c\n",p1name,p1pin);
		printf("-------------Let's Start The Game-----------\n");
		// switch to the respective toss winner			
		if(starter==1){
			// player going to the game first
			DrawBoard();
	int pos1,pos2,pos3,ans;
	 pos1=AskPinPos();
    pos1=IsValidPos(pos1);
    Value[pos1]=p1pin;
    DrawBoard();
    printf("It's Computer Turn:\n");
  	switch(pos1){
  		case 2:
  			printf("Computer Pin-->1 Position is:5\n");
  			Value[5]=cpin;
  			DrawBoard();
  			pos2=AskPinPos();
  			pos2=IsValidPos(pos2);
  			Value[pos2]=p1pin;
  			DrawBoard();
  			printf("It's Computer Turn:\n");
  			switch(pos2){
  				case 1:
  					printf("Computer Pin-->2 Position is:3\n");
  					Value[3]=cpin;
  					DrawBoard();
  					pos3=AskPinPos();
  					pos3=IsValidPos(pos3);
  					Value[pos3]=p1pin;
  					DrawBoard();
  					printf("It's Computer Turn:\n");
  					if(pos3==7){
  						printf("Computer Pin-->3 Position is: 9\n");
  						Value[9]=cpin;
  						
  						DrawBoard();
  						printf("--------------------------------------------------------------------\n");
  						printf("----------------------It's Time To MOVE your Pin's------------------\n");
  						printf("--------------------------------------------------------------------\n");
  						AskMove();
  						ans=IsValidMove(move1,move2,p1pin);
  						Swapping(move1,&Value[move1],&Value[move2]);
  						DrawBoard();
  						printf("It's Computer Turn:\n");
  						printf("Computer Pin Position (From Which): 5\n");
  						printf("Computer Pin Position (To Which): 6\n");
  						Swapping(5,&Value[5],&Value[6]);
  						DrawBoard();
  						DeclareWinner(219);
					  }else{
					  	printf("Computer Pin-->3 Position is: 7\n");
					  	Value[7]=cpin;
					  	DrawBoard();
					  	DeclareWinner(217);
					  }
  					
  			    break;
  			    case 3:
  			    	printf("Computer Pin-->2 Position is:1\n");
  					Value[1]=cpin;
  					DrawBoard();
  					pos3=AskPinPos();
  					pos3=IsValidPos(pos3);
  					Value[pos3]=p1pin;
  					DrawBoard();
  					printf("It's Computer Turn:\n");
  					if(pos3==9){
  						printf("Computer Pin-->3 Position is: 7\n");
  						Value[7]=cpin;
  						DrawBoard();
  						printf("--------------------------------------------------------------------\n");
  						printf("----------------------It's Time To MOVE your Pin's------------------\n");
  						printf("--------------------------------------------------------------------\n");
  						AskMove();
  						ans=IsValidMove(move1,move2,p1pin);
  						Swapping(move1,&Value[move1],&Value[move2]);
  						DrawBoard();
  						printf("It's Computer Turn:\n");
  						printf("Computer Pin Position (From Which): 5\n");
  						printf("Computer Pin Position (To Which): 4\n");
  						Swapping(5,&Value[5],&Value[4]);
  						DrawBoard();
  						DeclareWinner(237);
					  }else{
					  	printf("Computer Pin-->3 Position is: 9\n");
					  	Value[9]=cpin;
					  	DrawBoard();
					  	DeclareWinner(239);
				}
  			    break;
  			    case 4:
  			    	printf("Computer Pin-->2 Position is:9\n");
  					Value[9]=cpin;
  					DrawBoard();
  					pos3=AskPinPos();
  					pos3=IsValidPos(pos3);
  					Value[pos3]=p1pin;
  					DrawBoard();
  					printf("It's Computer Turn:\n");
  					if(pos3==1){
  						printf("Computer Pin-->3 Position is: 7\n");
  						Value[7]=cpin;
  						DrawBoard();
  						printf("--------------------------------------------------------------------\n");
  						printf("----------------------It's Time To MOVE your Pin's------------------\n");
  						printf("--------------------------------------------------------------------\n");
  						AskMove();
  						ans=IsValidMove(move1,move2,p1pin);
  						Swapping(move1,&Value[move1],&Value[move2]);
  						DrawBoard();
  						printf("It's Computer Turn:\n");
  						printf("Computer Pin Position (From Which): 5\n");
  						printf("Computer Pin Position (To Which): 8\n");
  						Swapping(5,&Value[5],&Value[8]);
  						DrawBoard();
  						DeclareWinner(247);
					  }else{
					  	printf("Computer Pin-->3 Position is: 1\n");
					  	Value[1]=cpin;
					  	DrawBoard();
					  	DeclareWinner(241);
				}
  			    break;
  			    case 6:
  			    	printf("Computer Pin-->2 Position is:7\n");
  					Value[7]=cpin;
  					DrawBoard();
  					pos3=AskPinPos();
  					pos3=IsValidPos(pos3);
  					Value[pos3]=p1pin;
  					DrawBoard();
  					printf("It's Computer Turn:\n");
  					if(pos3==3){
  						printf("Computer Pin-->3 Position is: 9\n");
  						Value[9]=cpin;
  						DrawBoard();
  						printf("--------------------------------------------------------------------\n");
  						printf("----------------------It's Time To MOVE your Pin's------------------\n");
  						printf("--------------------------------------------------------------------\n");
  						AskMove();
  						ans=IsValidMove(move1,move2,p1pin);
  						Swapping(move1,&Value[move1],&Value[move2]);
  						DrawBoard();
  						printf("It's Computer Turn:\n");
  						printf("Computer Pin Position (From Which): 5\n");
  						printf("Computer Pin Position (To Which): 8\n");
  						Swapping(5,&Value[5],&Value[8]);
  						DrawBoard();
  						DeclareWinner(237);
					  }else{
					  	printf("Computer Pin-->3 Position is: 3\n");
					  	Value[3]=cpin;
					  	DrawBoard();
					  	DeclareWinner(239);
				}
  			    break;
  			    case 9:
  			    	printf("Computer Pin-->2 Position is:7\n");
  					Value[7]=cpin;
  					DrawBoard();
  					pos3=AskPinPos();
  					pos3=IsValidPos(pos3);
  					Value[pos3]=p1pin;
  					DrawBoard();
  					printf("It's Computer Turn:\n");
  					if(pos3==3){
  						printf("Computer Pin-->3 Position is: 1\n");
  						Value[1]=cpin;
  						DrawBoard();
  						printf("--------------------------------------------------------------------\n");
  						printf("----------------------It's Time To MOVE your Pin's------------------\n");
  						printf("--------------------------------------------------------------------\n");
  						AskMove();
  						ans=IsValidMove(move1,move2,p1pin);
  						Swapping(move1,&Value[move1],&Value[move2]);
  						DrawBoard();
  						printf("It's Computer Turn:\n");
  						printf("Computer Pin Position (From Which): 5\n");
  						printf("Computer Pin Position (To Which): 4\n");
  						Swapping(5,&Value[5],&Value[4]);
  						DrawBoard();
  						DeclareWinner(291);
					  }else{
					  	printf("Computer Pin-->3 Position is: 3\n");
					  	Value[3]=cpin;
					  	DrawBoard();
					  	DeclareWinner(293);
				}
  			    break;
  			    default :
  			    		printf("Computer Pin-->2 Position is:9\n");
  					Value[9]=cpin;
  					DrawBoard();
  					pos3=AskPinPos();
  					pos3=IsValidPos(pos3);
  					Value[pos3]=p1pin;
  					DrawBoard();
  					printf("It's Computer Turn:\n");
  					if(pos3==1){
  						printf("Computer Pin-->3 Position is: 3\n");
  						Value[3]=cpin;
  						DrawBoard();
  						printf("--------------------------------------------------------------------\n");
  						printf("----------------------It's Time To MOVE your Pin's------------------\n");
  						printf("--------------------------------------------------------------------\n");
  						AskMove();
  						
  						ans=IsValidMove(move1,move2,p1pin);
  						Swapping(move1,&Value[move1],&Value[move2]);
  						DrawBoard();
  						printf("It's Computer Turn:\n");
  						printf("Computer Pin Position (From Which): 5\n");
  						printf("Computer Pin Position (To Which): 6\n");
  						Swapping(5,&Value[5],&Value[6]);
  						DrawBoard();
  						DeclareWinner(273);
					  }else{
					  	printf("Computer Pin-->3 Position is: 1\n");
					  	Value[1]=cpin;
					  	DrawBoard();
					  	DeclareWinner(271);
				}
  			    break;
			  
			  }
  			break;
  			
  		case 4:
  			printf("Computer Pin-->1 Position is:5\n");
  			Value[5]=cpin;
  			DrawBoard();
  			pos2=AskPinPos();
  			pos2=IsValidPos(pos2);
  			Value[pos2]=p1pin;
  			DrawBoard();
  			printf("It's Computer Turn:\n");
  			if(pos2==1 || pos2==6){
  					printf("Computer Pin-->2 Position is:7\n");
  					Value[7]=cpin;
  					DrawBoard();
  					pos3=AskPinPos();
  					pos3=IsValidPos(pos3);
  					Value[pos3]=p1pin;
  					DrawBoard();
  					printf("It's Computer Turn:\n");
  					if(pos3==3){
  						printf("Computer Pin-->3 Position is: 9\n");
  						Value[9]=cpin;
  						DrawBoard();
  						printf("--------------------------------------------------------------------\n");
  						printf("----------------------It's Time To MOVE your Pin's------------------\n");
  						printf("--------------------------------------------------------------------\n");
  						AskMove();
  						ans=IsValidMove(move1,move2,p1pin);
  						Swapping(move1,&Value[move1],&Value[move2]);
  						DrawBoard();
  						printf("It's Computer Turn:\n");
  						printf("Computer Pin Position (From Which): 5\n");
  						printf("Computer Pin Position (To Which): 8\n");
  						Swapping(5,&Value[5],&Value[8]);
  						DrawBoard();
  						DeclareWinner(419);
					  }else{
					  	printf("Computer Pin-->3 Position is: 3\n");
					  	Value[3]=cpin;
					  	DrawBoard();
					  	DeclareWinner(413);
				}	
			  }else if(pos2==2 || pos2== 3){
			  		printf("Computer Pin-->2 Position is:9\n");
  					Value[9]=cpin;
  					DrawBoard();
  					pos3=AskPinPos();
  					pos3=IsValidPos(pos3);
  					Value[pos3]=p1pin;
  					DrawBoard();
  					printf("It's Computer Turn:\n");
  					if(pos3==1){
  						printf("Computer Pin-->3 Position is: 7\n");
  						Value[7]=cpin;
  						DrawBoard();
  						printf("--------------------------------------------------------------------\n");
  						printf("----------------------It's Time To MOVE your Pin's------------------\n");
  						printf("--------------------------------------------------------------------\n");
  						AskMove();
  						ans=IsValidMove(move1,move2,p1pin);
  						Swapping(move1,&Value[move1],&Value[move2]);
  						DrawBoard();
  						printf("It's Computer Turn:\n");
  						printf("Computer Pin Position (From Which): 5\n");
  						printf("Computer Pin Position (To Which): 8\n");
  						Swapping(5,&Value[5],&Value[8]);
  						DrawBoard();
  						DeclareWinner(427);
					  }else{
					  	printf("Computer Pin-->3 Position is: 1\n");
					  	Value[1]=cpin;
					  	DrawBoard();
					  	DeclareWinner(421);
				}
			  }else if(pos2==7 || pos2== 8){
			  		printf("Computer Pin-->2 Position is:1\n");
  					Value[1]=cpin;
  					DrawBoard();
  					pos3=AskPinPos();
  					pos3=IsValidPos(pos3);
  					Value[pos3]=p1pin;
  					DrawBoard();
  					printf("It's Computer Turn:\n");
  					if(pos3==9){
  						printf("Computer Pin-->3 Position is: 3\n");
  						Value[3]=cpin;
  						DrawBoard();
  						printf("--------------------------------------------------------------------\n");
  						printf("----------------------It's Time To MOVE your Pin's------------------\n");
  						printf("--------------------------------------------------------------------\n");
  						AskMove();
  						ans=IsValidMove(move1,move2,p1pin);
  						Swapping(move1,&Value[move1],&Value[move2]);
  						DrawBoard();
  						printf("It's Computer Turn:\n");
  						printf("Computer Pin Position (From Which): 5\n");
  						printf("Computer Pin Position (To Which): 2\n");
  						Swapping(5,&Value[5],&Value[2]);
  						DrawBoard();
  						DeclareWinner(473);
					  }else{
					  	printf("Computer Pin-->3 Position is: 9\n");
					  	Value[9]=cpin;
					  	DrawBoard();
					  	DeclareWinner(479);
				}
			  }else {
			  		printf("Computer Pin-->2 Position is:3\n");
  					Value[3]=cpin;
  					DrawBoard();
  					pos3=AskPinPos();
  					pos3=IsValidPos(pos3);
  					Value[pos3]=p1pin;
  					DrawBoard();
  					printf("It's Computer Turn:\n");
  					if(pos3==7){
  						printf("Computer Pin-->3 Position is: 1\n");
  						Value[1]=cpin;
  						DrawBoard();
  						printf("--------------------------------------------------------------------\n");
  						printf("----------------------It's Time To MOVE your Pin's------------------\n");
  						printf("--------------------------------------------------------------------\n");
  						AskMove();
  						ans=IsValidMove(move1,move2,p1pin);
  						Swapping(move1,&Value[move1],&Value[move2]);
  						DrawBoard();
  						printf("It's Computer Turn:\n");
  						printf("Computer Pin Position (From Which): 5\n");
  						printf("Computer Pin Position (To Which): 2\n");
  						Swapping(5,&Value[5],&Value[2]);
  						DrawBoard();
  						DeclareWinner(491);
					  }else{
					  	printf("Computer Pin-->3 Position is: 7\n");
					  	Value[7]=cpin;
					  	DrawBoard();
					  	DeclareWinner(497);
				}
			  }
  			break;
  			
  		case 6:
  			printf("Computer Pin-->1 Position is:5\n");
  			Value[5]=cpin;
  			DrawBoard();
  			pos2=AskPinPos();
  			pos2=IsValidPos(pos2);
  			Value[pos2]=p1pin;
  			DrawBoard();
  			printf("It's Computer Turn:\n");
  			if(pos2==1 || pos2==2 || pos2==4){
  				printf("Computer Pin-->2 Position is:7\n");
  					Value[7]=cpin;
  					DrawBoard();
  					pos3=AskPinPos();
  					pos3=IsValidPos(pos3);
  					Value[pos3]=p1pin;
  					DrawBoard();
  					printf("It's Computer Turn:\n");
  					if(pos3==3){
  						printf("Computer Pin-->3 Position is: 9\n");
  						Value[9]=cpin;
  						DrawBoard();
  						printf("--------------------------------------------------------------------\n");
  						printf("----------------------It's Time To MOVE your Pin's------------------\n");
  						printf("--------------------------------------------------------------------\n");
  						AskMove();
  						ans=IsValidMove(move1,move2,p1pin);
  						Swapping(move1,&Value[move1],&Value[move2]);
  						DrawBoard();
  						printf("It's Computer Turn:\n");
  						printf("Computer Pin Position (From Which): 5\n");
  						printf("Computer Pin Position (To Which): 8\n");
  						Swapping(5,&Value[5],&Value[8]);
  						DrawBoard();
  						DeclareWinner(619);
					  }else{
					  	printf("Computer Pin-->3 Position is: 3\n");
					  	Value[3]=cpin;
					  	DrawBoard();
					  	DeclareWinner(613);
				}
			  }else if(pos2==3){
			  	printf("Computer Pin-->2 Position is:9\n");
  					Value[9]=cpin;
  					DrawBoard();
  					pos3=AskPinPos();
  					pos3=IsValidPos(pos3);
  					Value[pos3]=p1pin;
  					DrawBoard();
  					printf("It's Computer Turn:\n");
  					if(pos3==1){
  						printf("Computer Pin-->3 Position is: 7\n");
  						Value[7]=cpin;
  						DrawBoard();
  						printf("--------------------------------------------------------------------\n");
  						printf("----------------------It's Time To MOVE your Pin's------------------\n");
  						printf("--------------------------------------------------------------------\n");
  						AskMove();
  						ans=IsValidMove(move1,move2,p1pin);
  						Swapping(move1,&Value[move1],&Value[move2]);
  						DrawBoard();
  						printf("It's Computer Turn:\n");
  						printf("Computer Pin Position (From Which): 5\n");
  						printf("Computer Pin Position (To Which): 8\n");
  						Swapping(5,&Value[5],&Value[8]);
  						DrawBoard();
  						DeclareWinner(637);
					  }else{
					  	printf("Computer Pin-->3 Position is: 1\n");
					  	Value[1]=cpin;
					  	DrawBoard();
					  	DeclareWinner(631);
				}
			  }else if(pos2==7 || pos2==8){
			  	printf("Computer Pin-->2 Position is:1\n");
  					Value[1]=cpin;
  					DrawBoard();
  					pos3=AskPinPos();
  					pos3=IsValidPos(pos3);
  					Value[pos3]=p1pin;
  					DrawBoard();
  					printf("It's Computer Turn:\n");
  					if(pos3==9){
  						printf("Computer Pin-->3 Position is: 3\n");
  						Value[3]=cpin;
  						DrawBoard();
  						printf("--------------------------------------------------------------------\n");
  						printf("----------------------It's Time To MOVE your Pin's------------------\n");
  						printf("--------------------------------------------------------------------\n");
  						AskMove();
  						ans=IsValidMove(move1,move2,p1pin);
  						Swapping(move1,&Value[move1],&Value[move2]);
  						DrawBoard();
  						printf("It's Computer Turn:\n");
  						printf("Computer Pin Position (From Which): 5\n");
  						printf("Computer Pin Position (To Which): 2\n");
  						Swapping(5,&Value[5],&Value[2]);
  						DrawBoard();
  						DeclareWinner(673);
					  }else{
					  	printf("Computer Pin-->3 Position is: 9\n");
					  	Value[9]=cpin;
					  	DrawBoard();
					  	DeclareWinner(679);
				}
			  }else{
			  	printf("Computer Pin-->2 Position is:3\n");
  					Value[3]=cpin;
  					DrawBoard();
  					pos3=AskPinPos();
  					pos3=IsValidPos(pos3);
  					Value[pos3]=p1pin;
  					DrawBoard();
  					printf("It's Computer Turn:\n");
  					if(pos3==7){
  						printf("Computer Pin-->3 Position is: 1\n");
  						Value[1]=cpin;
  						DrawBoard();
  						printf("--------------------------------------------------------------------\n");
  						printf("----------------------It's Time To MOVE your Pin's------------------\n");
  						printf("--------------------------------------------------------------------\n");
  						AskMove();
  						ans=IsValidMove(move1,move2,p1pin);
  						Swapping(move1,&Value[move1],&Value[move2]);
  						DrawBoard();
  						printf("It's Computer Turn:\n");
  						printf("Computer Pin Position (From Which): 5\n");
  						printf("Computer Pin Position (To Which): 2\n");
  						Swapping(5,&Value[5],&Value[2]);
  						DrawBoard();
  						DeclareWinner(691);
					  }else{
					  	printf("Computer Pin-->3 Position is: 7\n");
					  	Value[7]=cpin;
					  	DrawBoard();
					  	DeclareWinner(697);
				}
			  }
  			break;
  			
  		case 8:
  			printf("Computer Pin-->1 Position is:5\n");
  			Value[5]=cpin;
  			DrawBoard();
  			pos2=AskPinPos();
  			pos2=IsValidPos(pos2);
  			Value[pos2]=p1pin;
  			DrawBoard();
  			printf("It's Computer Turn:\n");
  			if(pos2==1 || pos2==2 ||pos2==4){
  				printf("Computer Pin-->2 Position is:3\n");
  					Value[3]=cpin;
  					DrawBoard();
  					pos3=AskPinPos();
  					pos3=IsValidPos(pos3);
  					Value[pos3]=p1pin;
  					DrawBoard();
  					printf("It's Computer Turn:\n");
  					if(pos3==7){
  						printf("Computer Pin-->3 Position is: 9\n");
  						Value[9]=cpin;
  						DrawBoard();
  						printf("--------------------------------------------------------------------\n");
  						printf("----------------------It's Time To MOVE your Pin's------------------\n");
  						printf("--------------------------------------------------------------------\n");
  						AskMove();
  						ans=IsValidMove(move1,move2,p1pin);
  						Swapping(move1,&Value[move1],&Value[move2]);
  						DrawBoard();
  						printf("It's Computer Turn:\n");
  						printf("Computer Pin Position (From Which): 5\n");
  						printf("Computer Pin Position (To Which): 6\n");
  						Swapping(5,&Value[5],&Value[6]);
  						DrawBoard();
  						DeclareWinner(819);
					  }else{
					  	printf("Computer Pin-->3 Position is: 7\n");
					  	Value[7]=cpin;
					  	DrawBoard();
					  	DeclareWinner(817);
				}
			  }else if(pos2==3 || pos2==6){
			  	printf("Computer Pin-->2 Position is:1\n");
  					Value[1]=cpin;
  					DrawBoard();
  					pos3=AskPinPos();
  					pos3=IsValidPos(pos3);
  					Value[pos3]=p1pin;
  					DrawBoard();
  					printf("It's Computer Turn:\n");
  					if(pos3==9){
  						printf("Computer Pin-->3 Position is: 7\n");
  						Value[7]=cpin;
  						DrawBoard();
  						printf("--------------------------------------------------------------------\n");
  						printf("----------------------It's Time To MOVE your Pin's------------------\n");
  						printf("--------------------------------------------------------------------\n");
  						AskMove();
  						ans=IsValidMove(move1,move2,p1pin);
  						Swapping(move1,&Value[move1],&Value[move2]);
  						DrawBoard();
  						printf("It's Computer Turn:\n");
  						printf("Computer Pin Position (From Which): 5\n");
  						printf("Computer Pin Position (To Which): 4\n");
  						Swapping(5,&Value[5],&Value[4]);
  						DrawBoard();
  						DeclareWinner(837);
					  }else{
					  	printf("Computer Pin-->3 Position is: 9\n");
					  	Value[9]=cpin;
					  	DrawBoard();
					  	DeclareWinner(839);
				}
			  }else if(pos2==7){
			  	printf("Computer Pin-->2 Position is:9\n");
  					Value[9]=cpin;
  					DrawBoard();
  					pos3=AskPinPos();
  					pos3=IsValidPos(pos3);
  					Value[pos3]=p1pin;
  					DrawBoard();
  					printf("It's Computer Turn:\n");
  					if(pos3==1){
  						printf("Computer Pin-->3 Position is: 3\n");
  						Value[3]=cpin;
  						DrawBoard();
  						printf("--------------------------------------------------------------------\n");
  						printf("----------------------It's Time To MOVE your Pin's------------------\n");
  						printf("--------------------------------------------------------------------\n");
  						AskMove();
  						ans=IsValidMove(move1,move2,p1pin);
  						Swapping(move1,&Value[move1],&Value[move2]);
  						DrawBoard();
  						printf("It's Computer Turn:\n");
  						printf("Computer Pin Position (From Which): 5\n");
  						printf("Computer Pin Position (To Which): 6\n");
  						Swapping(5,&Value[5],&Value[6]);
  						DrawBoard();
  						DeclareWinner(873);
					  }else{
					  	printf("Computer Pin-->3 Position is: 1\n");
					  	Value[1]=cpin;
					  	DrawBoard();
					  	DeclareWinner(871);
				}
			  }else{
			  	printf("Computer Pin-->2 Position is:7\n");
  					Value[7]=cpin;
  					DrawBoard();
  					pos3=AskPinPos();
  					pos3=IsValidPos(pos3);
  					Value[pos3]=p1pin;
  					DrawBoard();
  					printf("It's Computer Turn:\n");
  					if(pos3==3){
  						printf("Computer Pin-->3 Position is: 1\n");
  						Value[1]=cpin;
  						DrawBoard();
  						printf("--------------------------------------------------------------------\n");
  						printf("----------------------It's Time To MOVE your Pin's------------------\n");
  						printf("--------------------------------------------------------------------\n");
  						AskMove();
  						ans=IsValidMove(move1,move2,p1pin);
  						Swapping(move1,&Value[move1],&Value[move2]);
  						DrawBoard();
  						printf("It's Computer Turn:\n");
  						printf("Computer Pin Position (From Which): 5\n");
  						printf("Computer Pin Position (To Which): 4\n");
  						Swapping(5,&Value[5],&Value[4]);
  						DrawBoard();
  						DeclareWinner(691);
					  }else{
					  	printf("Computer Pin-->3 Position is: 3\n");
					  	Value[3]=cpin;
					  	DrawBoard();
					  	DeclareWinner(893);
				}
			  }
  			break;
  			//corner cases
  		case 1:
  			printf("Computer Pin-->1 Position is:5\n");
  			Value[5]=cpin;
  			DrawBoard();
  			pos2=AskPinPos();
  			pos2=IsValidPos(pos2);
  			Value[pos2]=p1pin;
  			DrawBoard();
  			printf("It's Computer Turn:\n");
  			switch(pos2){
  				case 3:
  				printf("Computer Pin-->2 Position is : 2\n");
  				Value[2]=cpin;
  				DrawBoard();
  				pos3=AskPinPos();
  				pos3=IsValidPos(pos3);
  				Value[pos3]=p1pin;
  				DrawBoard();
  				printf("It's Computer Turn\n");
  				if(pos3!=8){
  					printf("Computer Pin-->3 Position : 8\n");
  					Value[8]=cpin;
  					DrawBoard();
  					DeclareWinner(11);
  					return 5;
				  }
  				printf("Computer Pin-->3 Position is: 9\n");
  				Value[9]=cpin;
  				DrawBoard();
  				printf("--------------------------------------------------------------------\n");
  				printf("----------------------It's Time To MOVE your Pin's------------------\n");
  				printf("--------------------------------------------------------------------\n");
  				AskMove();
  				ans=IsValidMove(move1,move2,p1pin);
  				Swapping(move1,&Value[move1],&Value[move2]);
  				DrawBoard();
  				if(move1==1 && move2==4){
  					printf("It's Computer Turn\n");
  					printf("Computer Pin Position (From Which): 2\n");
  					printf("Computer Pin Postion (To Which ): 1\n");
  					Swapping(2,&Value[2],&Value[1]);
  					DrawBoard();
  					DeclareWinner(11);
				  }else if(move1==8 && move2==7){
				  	 printf("It's Computer Turn\n");
  					printf("Computer Pin Position (From Which): 9\n");
  					printf("Computer Pin Postion (To Which ): 8\n");
  					Swapping(9,&Value[9],&Value[8]);
  					DrawBoard();
  					DeclareWinner(11);
				  }else{
				  	Cornercase1_3();
				  }
  					
  					break;
  				case 4:
  					printf("Computer Pin-->2 Position is:7\n");
  					Value[7]=cpin;
  					DrawBoard();
  					pos3=AskPinPos();
  					pos3=IsValidPos(pos3);
  					Value[pos3]=p1pin;
  					DrawBoard();
  					printf("It's Computer Turn:\n");
  					if(pos3==3){
  						printf("Computer Pin-->3 Position is: 9\n");
  						Value[9]=cpin;
  						DrawBoard();
  						printf("--------------------------------------------------------------------\n");
  						printf("----------------------It's Time To MOVE your Pin's------------------\n");
  						printf("--------------------------------------------------------------------\n");
  						AskMove();
  						ans=IsValidMove(move1,move2,p1pin);
  						Swapping(move1,&Value[move1],&Value[move2]);
  						DrawBoard();
  						printf("It's Computer Turn:\n");
  						printf("Computer Pin Position (From Which): 5\n");
  						printf("Computer Pin Position (To Which): 8\n");
  						Swapping(5,&Value[5],&Value[8]);
  						DrawBoard();
  						DeclareWinner(149);
					  }else{
					  	printf("Computer Pin-->3 Position is: 3\n");
					  	Value[3]=cpin;
					  	DrawBoard();
					  	DeclareWinner(143);
				}
  					break;
  				case 7:
  		    	printf("Computer Pin-->2 Position is : 4\n");
  				Value[4]=cpin;
  				DrawBoard();
  				pos3=AskPinPos();
  				pos3=IsValidPos(pos3);
  				Value[pos3]=p1pin;
  				DrawBoard();
  				printf("It's Computer Turn\n");
  				if(pos3!=6){
  					printf("Computer Pin-->3 Position is : 6\n");
  					Value[6]=cpin;
  					DrawBoard();
  					DeclareWinner(11);
  					return 5;
				  }
  				printf("Computer Pin-->3 Position : 3\n");
  				Value[3]=cpin;
  				DrawBoard();
  				printf("--------------------------------------------------------------------\n");
  				printf("----------------------It's Time To MOVE your Pin's------------------\n");
  				printf("--------------------------------------------------------------------\n");
  				AskMove();
  				ans=IsValidMove(move1,move2,p1pin);
  				Swapping(move1,&Value[move1],&Value[move2]);
  				DrawBoard();
  				if(move1==7 && move2==8){
  					printf("It's Computer Turn\n");
  					printf("Computer Pin Position (From Which): 4\n");
  					printf("Computer Pin Postion (To Which ): 7\n");
  					Swapping(4,&Value[4],&Value[7]);
  					DrawBoard();
  					DeclareWinner(11);
				  }else if(move1==6 && move2==9){
				  	 printf("It's Computer Turn\n");
  					printf("Computer Pin Position (From Which): 6\n");
  					printf("Computer Pin Postion (To Which ): 9\n");
  					Swapping(6,&Value[6],&Value[9]);
  					DrawBoard();
  					DeclareWinner(11);
				  }else{
				  	Cornercase1_7();
				  }
  					
  					break;
  				case 9:
  					printf("Computer Pin-->2 Position is:2\n");
  					Value[2]=cpin;
  					DrawBoard();
  					pos3=AskPinPos();
  					pos3=IsValidPos(pos3);
  					Value[pos3]=p1pin;
  					DrawBoard();
  					printf("It's Computer Turn:\n");
  					if(pos3==8){
  						printf("Computer Pin-->3 Position is: 7\n");
  						Value[7]=cpin;
  						DrawBoard();
  						printf("--------------------------------------------------------------------\n");
  						printf("----------------------It's Time To MOVE your Pin's------------------\n");
  						printf("--------------------------------------------------------------------\n");
  						AskMove();
  						ans=IsValidMove(move1,move2,p1pin);
  						Swapping(move1,&Value[move1],&Value[move2]);
  						DrawBoard();
  						printf("It's Computer Turn:\n");
  						printf("Computer Pin Position (From Which): 2\n");
  						printf("Computer Pin Position (To Which): 3\n");
  						Swapping(2,&Value[2],&Value[3]);
  						DrawBoard();
  						DeclareWinner(197);
					  }else{
					  	printf("Computer Pin-->3 Position is: 8\n");
					  	Value[8]=cpin;
					  	DrawBoard();
					  	DeclareWinner(198);
				}
  					break;
  				case 6:
  					printf("Computer Pin-->2 Position is:8\n");
  					Value[8]=cpin;
  					DrawBoard();
  					pos3=AskPinPos();
  					pos3=IsValidPos(pos3);
  					Value[pos3]=p1pin;
  					DrawBoard();
  					printf("It's Computer Turn:\n");
  					if(pos3==2){
  						printf("Computer Pin-->3 Position is: 3\n");
  						Value[3]=cpin;
  						DrawBoard();
  						printf("--------------------------------------------------------------------\n");
  						printf("----------------------It's Time To MOVE your Pin's------------------\n");
  						printf("--------------------------------------------------------------------\n");
  						AskMove();
  						ans=IsValidMove(move1,move2,p1pin);
  						Swapping(move1,&Value[move1],&Value[move2]);
  						DrawBoard();
  						printf("It's Computer Turn:\n");
  						printf("Computer Pin Position (From Which): 8\n");
  						printf("Computer Pin Position (To Which): 7\n");
  						Swapping(8,&Value[8],&Value[7]);
  						DrawBoard();
  						DeclareWinner(163);
					  }else{
					  	printf("Computer Pin-->3 Position is: 2\n");
					  	Value[2]=cpin;
					  	DrawBoard();
					  	DeclareWinner(162);
				}
  					break;
  				default :
  					printf("Computer Pin-->2 Position is:3\n");
  					Value[3]=cpin;
  					DrawBoard();
  					pos3=AskPinPos();
  					pos3=IsValidPos(pos3);
  					Value[pos3]=p1pin;
  					DrawBoard();
  					printf("It's Computer Turn:\n");
  					if(pos3==7){
  						printf("Computer Pin-->3 Position is: 9\n");
  						Value[9]=cpin;
  						DrawBoard();
  						printf("--------------------------------------------------------------------\n");
  						printf("----------------------It's Time To MOVE your Pin's------------------\n");
  						printf("--------------------------------------------------------------------\n");
  						AskMove();
  						ans=IsValidMove(move1,move2,p1pin);
  						Swapping(move1,&Value[move1],&Value[move2]);
  						DrawBoard();
  						printf("It's Computer Turn:\n");
  						printf("Computer Pin Position (From Which): 5\n");
  						printf("Computer Pin Position (To Which): 6\n");
  						Swapping(5,&Value[5],&Value[6]);
  						DrawBoard();
  						DeclareWinner(189);
					  }else{
					  	printf("Computer Pin-->3 Position is: 7\n");
					  	Value[7]=cpin;
					  	DrawBoard();
					  	DeclareWinner(187);
				}
  					break;
			  }
  			break;
  			
  		case 3:
  			printf("Computer Pin-->1 Position is:5\n");
  			Value[5]=cpin;
  			DrawBoard();
  			pos2=AskPinPos();
  			pos2=IsValidPos(pos2);
  			Value[pos2]=p1pin;
  			DrawBoard();
  			printf("It's Computer Turn:\n");
  			switch(pos2){
  				case 1:
  				printf("Computer Pin-->2 Position is : 2\n");
  				Value[2]=cpin;
  				DrawBoard();
  				pos3=AskPinPos();
  				pos3=IsValidPos(pos3);
  				Value[pos3]=p1pin;
  				DrawBoard();
  				printf("It's Computer Turn\n");
  				if(pos3!=8){
  					printf("Computer Pin-->3 Position : 8\n");
  					Value[8]=cpin;
  					DrawBoard();
  					DeclareWinner(11);
  					return 5;
				  }
  				printf("Computer Pin-->3 Position is: 9\n");
  				Value[9]=cpin;
  				DrawBoard();
  				printf("--------------------------------------------------------------------\n");
  				printf("----------------------It's Time To MOVE your Pin's------------------\n");
  				printf("--------------------------------------------------------------------\n");
  				AskMove();
  				ans=IsValidMove(move1,move2,p1pin);
  				Swapping(move1,&Value[move1],&Value[move2]);
  				DrawBoard();
  				if(move1==1 && move2==4){
  					printf("It's Computer Turn\n");
  					printf("Computer Pin Position (From Which): 2\n");
  					printf("Computer Pin Postion (To Which ): 1\n");
  					Swapping(2,&Value[2],&Value[1]);
  					DrawBoard();
  					DeclareWinner(11);
				  }else if(move1==8 && move2==7){
				  	 printf("It's Computer Turn\n");
  					printf("Computer Pin Position (From Which): 9\n");
  					printf("Computer Pin Postion (To Which ): 8\n");
  					Swapping(9,&Value[9],&Value[8]);
  					DrawBoard();
  					DeclareWinner(11);
				  }else{
				  	Cornercase1_3();
				  }
  					break;
  				case 2:
  					printf("Computer Pin-->2 Position is:1\n");
  					Value[1]=cpin;
  					DrawBoard();
  					pos3=AskPinPos();
  					pos3=IsValidPos(pos3);
  					Value[pos3]=p1pin;
  					DrawBoard();
  					printf("It's Computer Turn:\n");
  					if(pos3==9){
  						printf("Computer Pin-->3 Position is: 7\n");
  						Value[7]=cpin;
  						DrawBoard();
  						printf("--------------------------------------------------------------------\n");
  						printf("----------------------It's Time To MOVE your Pin's------------------\n");
  						printf("--------------------------------------------------------------------\n");
  						AskMove();
  						ans=IsValidMove(move1,move2,p1pin);
  						Swapping(move1,&Value[move1],&Value[move2]);
  						DrawBoard();
  						printf("It's Computer Turn:\n");
  						printf("Computer Pin Position (From Which): 5\n");
  						printf("Computer Pin Position (To Which): 4\n");
  						Swapping(5,&Value[5],&Value[4]);
  						DrawBoard();
  						DeclareWinner(327);
					  }else{
					  	printf("Computer Pin-->3 Position is: 9\n");
					  	Value[9]=cpin;
					  	DrawBoard();
					  	DeclareWinner(329);
				}
  					break;
  				case 6:
  					printf("Computer Pin-->2 Position is:9\n");
  					Value[9]=cpin;
  					DrawBoard();
  					pos3=AskPinPos();
  					pos3=IsValidPos(pos3);
  					Value[pos3]=p1pin;
  					DrawBoard();
  					printf("It's Computer Turn:\n");
  					if(pos3==1){
  						printf("Computer Pin-->3 Position is: 7\n");
  						Value[7]=cpin;
  						DrawBoard();
  						printf("--------------------------------------------------------------------\n");
  						printf("----------------------It's Time To MOVE your Pin's------------------\n");
  						printf("--------------------------------------------------------------------\n");
  						AskMove();
  						ans=IsValidMove(move1,move2,p1pin);
  						Swapping(move1,&Value[move1],&Value[move2]);
  						DrawBoard();
  						printf("It's Computer Turn:\n");
  						printf("Computer Pin Position (From Which): 5\n");
  						printf("Computer Pin Position (To Which): 8\n");
  						Swapping(5,&Value[5],&Value[8]);
  						DrawBoard();
  						DeclareWinner(367);
					  }else{
					  	printf("Computer Pin-->3 Position is: 1\n");
					  	Value[1]=cpin;
					  	DrawBoard();
					  	DeclareWinner(361);
				}
  					break;
  				case 8:
  					printf("Computer Pin-->2 Position is:4\n");
  					Value[4]=cpin;
  					DrawBoard();
  					pos3=AskPinPos();
  					pos3=IsValidPos(pos3);
  					Value[pos3]=p1pin;
  					DrawBoard();
  					printf("It's Computer Turn:\n");
  					if(pos3==6){
  						printf("Computer Pin-->3 Position is: 9\n");
  						Value[9]=cpin;
  						DrawBoard();
  						printf("--------------------------------------------------------------------\n");
  						printf("----------------------It's Time To MOVE your Pin's------------------\n");
  						printf("--------------------------------------------------------------------\n");
  						AskMove();
  						ans=IsValidMove(move1,move2,p1pin);
  						Swapping(move1,&Value[move1],&Value[move2]);
  						DrawBoard();
  						printf("It's Computer Turn:\n");
  						printf("Computer Pin Position (From Which): 4\n");
  						printf("Computer Pin Position (To Which): 1\n");
  						Swapping(4,&Value[4],&Value[1]);
  						DrawBoard();
  						DeclareWinner(389);
					  }else{
					  	printf("Computer Pin-->3 Position is: 6\n");
					  	Value[6]=cpin;
					  	DrawBoard();
					  	DeclareWinner(386);
				}
  					break;
				case 9:
  				printf("Computer Pin-->2 Position is : 6\n");
  				Value[6]=cpin;
  				DrawBoard();
  				pos3=AskPinPos();
  				pos3=IsValidPos(pos3);
  				Value[pos3]=p1pin;
  				DrawBoard();
  				printf("It's Computer Turn\n");
  				if(pos3!=4){
  					printf("Computer Pin-->3 Position is : 4\n");
  					Value[4]=cpin;
  					DrawBoard();
  					DeclareWinner(11);
  					return 5;
				  }
  				printf("Computer Pin-->3 Position : 7\n");
  				Value[7]=cpin;
  				DrawBoard();
  				printf("--------------------------------------------------------------------\n");
  				printf("----------------------It's Time To MOVE your Pin's------------------\n");
  				printf("--------------------------------------------------------------------\n");
  				AskMove();
  				ans=IsValidMove(move1,move2,p1pin);
  				Swapping(move1,&Value[move1],&Value[move2]);
  				DrawBoard();
  				if(move1==3 && move2==2){
  					printf("It's Computer Turn\n");
  					printf("Computer Pin Position (From Which): 6\n");
  					printf("Computer Pin Postion (To Which ): 3\n");
  					Swapping(6,&Value[6],&Value[3]);
  					DrawBoard();
  					DeclareWinner(11);
				  }else if(move1==4 && move2==1){
				  	 printf("It's Computer Turn\n");
  					printf("Computer Pin Position (From Which): 7\n");
  					printf("Computer Pin Postion (To Which ): 4\n");
  					Swapping(7,&Value[7],&Value[4]);
  					DrawBoard();
  					DeclareWinner(11);
				  }else{
				  	Cornercase3_9();
				  }
  					break;
				default :
				printf("Computer Pin-->2 Position is:8\n");
  					Value[8]=cpin;
  					DrawBoard();
  					pos3=AskPinPos();
  					pos3=IsValidPos(pos3);
  					Value[pos3]=p1pin;
  					DrawBoard();
  					printf("It's Computer Turn:\n");
  					if(pos3==2){
  						printf("Computer Pin-->3 Position is: 1\n");
  						Value[1]=cpin;
  						DrawBoard();
  						printf("--------------------------------------------------------------------\n");
  						printf("----------------------It's Time To MOVE your Pin's------------------\n");
  						printf("--------------------------------------------------------------------\n");
  						AskMove();
  						ans=IsValidMove(move1,move2,p1pin);
  						Swapping(move1,&Value[move1],&Value[move2]);
  						DrawBoard();
  						printf("It's Computer Turn:\n");
  						printf("Computer Pin Position (From Which): 8\n");
  						printf("Computer Pin Position (To Which): 9\n");
  						Swapping(8,&Value[8],&Value[9]);
  						DrawBoard();
  						DeclareWinner(371);
					  }else{
					  	printf("Computer Pin-->3 Position is: 2\n");
					  	Value[2]=cpin;
					  	DrawBoard();
					  	DeclareWinner(372);
				}	
				break;	
  				
  					
			  }
			  
  			break;
  			
  		case 7:
  			printf("Computer Pin-->1 Position is:5\n");
  			Value[5]=cpin;
  			DrawBoard();
  			pos2=AskPinPos();
  			pos2=IsValidPos(pos2);
  			Value[pos2]=p1pin;
  			DrawBoard();
  			printf("It's Computer Turn:\n");
			 if(pos2==2 || pos2==3){
			 	printf("Computer Pin-->2 Position is:6\n");
  					Value[6]=cpin;
  					DrawBoard();
  					pos3=AskPinPos();
  					pos3=IsValidPos(pos3);
  					Value[pos3]=p1pin;
  					DrawBoard();
  					printf("It's Computer Turn:\n");
  					if(pos3==4){
  						printf("Computer Pin-->3 Position is: 1\n");
  						Value[1]=cpin;
  						DrawBoard();
  						printf("--------------------------------------------------------------------\n");
  						printf("----------------------It's Time To MOVE your Pin's------------------\n");
  						printf("--------------------------------------------------------------------\n");
  						AskMove();
  						ans=IsValidMove(move1,move2,p1pin);
  						Swapping(move1,&Value[move1],&Value[move2]);
  						DrawBoard();
  						printf("It's Computer Turn:\n");
  						printf("Computer Pin Position (From Which): 6\n");
  						printf("Computer Pin Position (To Which): 9\n");
  						Swapping(6,&Value[6],&Value[9]);
  						DrawBoard();
  						DeclareWinner(721);
					  }else{
					  	printf("Computer Pin-->3 Position is: 4\n");
					  	Value[4]=cpin;
					  	DrawBoard();
					  	DeclareWinner(724);
				}
			 } else if(pos2==4 || pos2==6){
			 	printf("Computer Pin-->2 Position is:1\n");
  					Value[1]=cpin;
  					DrawBoard();
  					pos3=AskPinPos();
  					pos3=IsValidPos(pos3);
  					Value[pos3]=p1pin;
  					DrawBoard();
  					printf("It's Computer Turn:\n");
  					if(pos3==9){
  						printf("Computer Pin-->3 Position is: 3\n");
  						Value[3]=cpin;
  						DrawBoard();
  						printf("--------------------------------------------------------------------\n");
  						printf("----------------------It's Time To MOVE your Pin's------------------\n");
  						printf("--------------------------------------------------------------------\n");
  						AskMove();
  						ans=IsValidMove(move1,move2,p1pin);
  						Swapping(move1,&Value[move1],&Value[move2]);
  						DrawBoard();
  						printf("It's Computer Turn:\n");
  						printf("Computer Pin Position (From Which): 5\n");
  						printf("Computer Pin Position (To Which): 2\n");
  						Swapping(5,&Value[5],&Value[2]);
  						DrawBoard();
  						DeclareWinner(743);
					  }else{
					  	printf("Computer Pin-->3 Position is: 9\n");
					  	Value[9]=cpin;
					  	DrawBoard();
					  	DeclareWinner(749);
				}
			 }else if(pos2==8){
			 	printf("Computer Pin-->2 Position is:9\n");
  					Value[9]=cpin;
  					DrawBoard();
  					pos3=AskPinPos();
  					pos3=IsValidPos(pos3);
  					Value[pos3]=p1pin;
  					DrawBoard();
  					printf("It's Computer Turn:\n");
  					if(pos3==1){
  						printf("Computer Pin-->3 Position is: 3\n");
  						Value[3]=cpin;
  						DrawBoard();
  						printf("--------------------------------------------------------------------\n");
  						printf("----------------------It's Time To MOVE your Pin's------------------\n");
  						printf("--------------------------------------------------------------------\n");
  						AskMove();
  						ans=IsValidMove(move1,move2,p1pin);
  						Swapping(move1,&Value[move1],&Value[move2]);
  						DrawBoard();
  						printf("It's Computer Turn:\n");
  						printf("Computer Pin Position (From Which): 5\n");
  						printf("Computer Pin Position (To Which): 6\n");
  						Swapping(5,&Value[5],&Value[6]);
  						DrawBoard();
  						DeclareWinner(783);
					  }else{
					  	printf("Computer Pin-->3 Position is: 1\n");
					  	Value[1]=cpin;
					  	DrawBoard();
					  	DeclareWinner(781);
				}
			 }else if(pos2==1){
			 	//corner
			 	printf("Computer Pin-->2 Position is : 4\n");
  				Value[4]=cpin;
  				DrawBoard();
  				pos3=AskPinPos();
  				pos3=IsValidPos(pos3);
  				Value[pos3]=p1pin;
  				DrawBoard();
  				printf("It's Computer Turn\n");
  				if(pos3!=6){
  					printf("Computer Pin-->3 Position is : 6\n");
  					Value[6]=cpin;
  					DrawBoard();
  					DeclareWinner(71);
  					return 5;
				  }
  				printf("Computer Pin-->3 Position : 3\n");
  				Value[3]=cpin;
  				DrawBoard();
  				printf("--------------------------------------------------------------------\n");
  				printf("----------------------It's Time To MOVE your Pin's------------------\n");
  				printf("--------------------------------------------------------------------\n");
  				AskMove();
  				ans=IsValidMove(move1,move2,p1pin);
  				Swapping(move1,&Value[move1],&Value[move2]);
  				DrawBoard();
  				if(move1==7 && move2==8){
  					printf("It's Computer Turn\n");
  					printf("Computer Pin Position (From Which): 4\n");
  					printf("Computer Pin Postion (To Which ): 7\n");
  					Swapping(4,&Value[4],&Value[7]);
  					DrawBoard();
  					DeclareWinner(11);
				  }else if(move1==6 && move2==9){
				  	 printf("It's Computer Turn\n");
  					printf("Computer Pin Position (From Which): 3\n");
  					printf("Computer Pin Postion (To Which ): 6\n");
  					Swapping(3,&Value[3],&Value[6]);
  					DrawBoard();
  					DeclareWinner(11);
				  }else{
				  	Cornercase1_7();
				  }
			 }else {
			 	//corner
			 	printf("Computer Pin-->2 Position is : 8\n");
  				Value[8]=cpin;
  				DrawBoard();
  				pos3=AskPinPos();
  				pos3=IsValidPos(pos3);
  				Value[pos3]=p1pin;
  				DrawBoard();
  				printf("It's Computer Turn\n");
  				if(pos3!=2){
  					printf("Computer Pin-->3 Position is : 2\n");
  					Value[2]=cpin;
  					DrawBoard();
  					DeclareWinner(11);
  					return 5;
				  }
  				printf("Computer Pin-->3 Position : 1\n");
  				Value[1]=cpin;
  				DrawBoard();
  				printf("--------------------------------------------------------------------\n");
  				printf("----------------------It's Time To MOVE your Pin's------------------\n");
  				printf("--------------------------------------------------------------------\n");
  				AskMove();
  				ans=IsValidMove(move1,move2,p1pin);
  				Swapping(move1,&Value[move1],&Value[move2]);
  				DrawBoard();
  				if(move1==2 && move2==3){
  					printf("It's Computer Turn\n");
  					printf("Computer Pin Position (From Which): 1\n");
  					printf("Computer Pin Postion (To Which ): 2\n");
  					Swapping(1,&Value[1],&Value[2]);
  					DrawBoard();
  					DeclareWinner(11);
				  }else if(move1==9 && move2==6){
				  	 printf("It's Computer Turn\n");
  					printf("Computer Pin Position (From Which): 8\n");
  					printf("Computer Pin Postion (To Which ): 9\n");
  					Swapping(8,&Value[8],&Value[9]);
  					DrawBoard();
  					DeclareWinner(11);
				  }else{
				  	Cornercase7_9();
				  }
			 }
  			break;
  			
  		case 9:
  			printf("Computer Pin-->1 Position is:5\n");
  			Value[5]=cpin;
  			DrawBoard();
  			pos2=AskPinPos();
  			pos2=IsValidPos(pos2);
  			Value[pos2]=p1pin;
  			DrawBoard();
  			printf("It's Computer Turn:\n");
  			switch(pos2){
  				case 2:
  				printf("Computer Pin-->2 Position is:4\n");
  					Value[4]=cpin;
  					DrawBoard();
  					pos3=AskPinPos();
  					pos3=IsValidPos(pos3);
  					Value[pos3]=p1pin;
  					DrawBoard();
  					printf("It's Computer Turn:\n");
  					if(pos3==6){
  						printf("Computer Pin-->3 Position is: 3\n");
  						Value[3]=cpin;
  						DrawBoard();
  						printf("--------------------------------------------------------------------\n");
  						printf("----------------------It's Time To MOVE your Pin's------------------\n");
  						printf("--------------------------------------------------------------------\n");
  						AskMove();
  						ans=IsValidMove(move1,move2,p1pin);
  						Swapping(move1,&Value[move1],&Value[move2]);
  						DrawBoard();
  						printf("It's Computer Turn:\n");
  						printf("Computer Pin Position (From Which): 4\n");
  						printf("Computer Pin Position (To Which): 7\n");
  						Swapping(4,&Value[4],&Value[7]);
  						DrawBoard();
  						DeclareWinner(923);
					  }else{
					  	printf("Computer Pin-->3 Position is: 6\n");
					  	Value[6]=cpin;
					  	DrawBoard();
					  	DeclareWinner(926);
				}	
  					break;
  				case 3:
					  printf("Computer Pin-->2 Position is : 6\n");
  				Value[6]=cpin;
  				DrawBoard();
  				pos3=AskPinPos();
  				pos3=IsValidPos(pos3);
  				Value[pos3]=p1pin;
  				DrawBoard();
  				printf("It's Computer Turn\n");
  				if(pos3!=4){
  					printf("Computer Pin-->3 Position is : 4\n");
  					Value[4]=cpin;
  					DrawBoard();
  					DeclareWinner(11);
  					return 5;
				  }
  				printf("Computer Pin-->3 Position : 7\n");
  				Value[7]=cpin;
  				DrawBoard();
  				printf("--------------------------------------------------------------------\n");
  				printf("----------------------It's Time To MOVE your Pin's------------------\n");
  				printf("--------------------------------------------------------------------\n");
  				AskMove();
  				ans=IsValidMove(move1,move2,p1pin);
  				Swapping(move1,&Value[move1],&Value[move2]);
  				DrawBoard();
  				if(move1==3 && move2==2){
  					printf("It's Computer Turn\n");
  					printf("Computer Pin Position (From Which): 6\n");
  					printf("Computer Pin Postion (To Which ): 3\n");
  					Swapping(6,&Value[6],&Value[3]);
  					DrawBoard();
  					DeclareWinner(11);
				  }else if(move1==4 && move2==1){
				  	 printf("It's Computer Turn\n");
  					printf("Computer Pin Position (From Which): 7\n");
  					printf("Computer Pin Postion (To Which ): 4\n");
  					Swapping(7,&Value[7],&Value[4]);
  					DrawBoard();
  					DeclareWinner(11);
				  }else{
				  	Cornercase3_9();
				  }	
  				    break;
  				case 6:
  					printf("Computer Pin-->2 Position is:3\n");
  					Value[3]=cpin;
  					DrawBoard();
  					pos3=AskPinPos();
  					pos3=IsValidPos(pos3);
  					Value[pos3]=p1pin;
  					DrawBoard();
  					printf("It's Computer Turn:\n");
  					if(pos3==7){
  						printf("Computer Pin-->3 Position is: 1\n");
  						Value[1]=cpin;
  						DrawBoard();
  						printf("--------------------------------------------------------------------\n");
  						printf("----------------------It's Time To MOVE your Pin's------------------\n");
  						printf("--------------------------------------------------------------------\n");
  						AskMove();
  						ans=IsValidMove(move1,move2,p1pin);
  						Swapping(move1,&Value[move1],&Value[move2]);
  						DrawBoard();
  						printf("It's Computer Turn:\n");
  						printf("Computer Pin Position (From Which): 5\n");
  						printf("Computer Pin Position (To Which): 2\n");
  						Swapping(5,&Value[5],&Value[2]);
  						DrawBoard();
  						DeclareWinner(961);
					  }else{
					  	printf("Computer Pin-->3 Position is: 7\n");
					  	Value[7]=cpin;
					  	DrawBoard();
					  	DeclareWinner(967);
				}	
  					break;
  				case 7:
  				printf("Computer Pin-->2 Position is : 8\n");
  				Value[8]=cpin;
  				DrawBoard();
  				pos3=AskPinPos();
  				pos3=IsValidPos(pos3);
  				Value[pos3]=p1pin;
  				DrawBoard();
  				printf("It's Computer Turn\n");
  				if(pos3!=2){
  					printf("Computer Pin-->3 Position is : 2\n");
  					Value[2]=cpin;
  					DrawBoard();
  					DeclareWinner(11);
  					return 5;
				  }
  				printf("Computer Pin-->3 Position : 1\n");
  				Value[1]=cpin;
  				DrawBoard();
  				printf("--------------------------------------------------------------------\n");
  				printf("----------------------It's Time To MOVE your Pin's------------------\n");
  				printf("--------------------------------------------------------------------\n");
  				AskMove();
  				ans=IsValidMove(move1,move2,p1pin);
  				Swapping(move1,&Value[move1],&Value[move2]);
  				DrawBoard();
  				if(move1==9 && move2==6){
  					printf("It's Computer Turn\n");
  					printf("Computer Pin Position (From Which): 8\n");
  					printf("Computer Pin Postion (To Which ): 9\n");
  					Swapping(8,&Value[8],&Value[9]);
  					DrawBoard();
  					DeclareWinner(11);
				  }else if(move1==2 && move2==3){
				  	 printf("It's Computer Turn\n");
  					printf("Computer Pin Position (From Which): 1\n");
  					printf("Computer Pin Postion (To Which ): 2\n");
  					Swapping(1,&Value[1],&Value[2]);
  					DrawBoard();
  					DeclareWinner(11);
				  }else{
				  	Cornercase7_9();
				  }
  					break;
  				case 8:
  					printf("Computer Pin-->2 Position is:7\n");
  					Value[7]=cpin;
  					DrawBoard();
  					pos3=AskPinPos();
  					pos3=IsValidPos(pos3);
  					Value[pos3]=p1pin;
  					DrawBoard();
  					printf("It's Computer Turn:\n");
  					if(pos3==3){
  						printf("Computer Pin-->3 Position is: 1\n");
  						Value[1]=cpin;
  						DrawBoard();
  						printf("--------------------------------------------------------------------\n");
  						printf("----------------------It's Time To MOVE your Pin's------------------\n");
  						printf("--------------------------------------------------------------------\n");
  						AskMove();
  						ans=IsValidMove(move1,move2,p1pin);
  						Swapping(move1,&Value[move1],&Value[move2]);
  						DrawBoard();
  						printf("It's Computer Turn:\n");
  						printf("Computer Pin Position (From Which): 5\n");
  						printf("Computer Pin Position (To Which): 4\n");
  						Swapping(5,&Value[5],&Value[4]);
  						DrawBoard();
  						DeclareWinner(981);
					  }else{
					  	printf("Computer Pin-->3 Position is: 3\n");
					  	Value[3]=cpin;
					  	DrawBoard();
					  	DeclareWinner(983);
				}	
  					break;
  				default :
  					printf("Computer Pin-->2 Position is:2\n");
  					Value[2]=cpin;
  					DrawBoard();
  					pos3=AskPinPos();
  					pos3=IsValidPos(pos3);
  					Value[pos3]=p1pin;
  					DrawBoard();
  					printf("It's Computer Turn:\n");
  					if(pos3==8){
  						printf("Computer Pin-->3 Position is: 7\n");
  						Value[7]=cpin;
  						DrawBoard();
  						printf("--------------------------------------------------------------------\n");
  						printf("----------------------It's Time To MOVE your Pin's------------------\n");
  						printf("--------------------------------------------------------------------\n");
  						AskMove();
  						ans=IsValidMove(move1,move2,p1pin);
  						Swapping(move1,&Value[move1],&Value[move2]);
  						DrawBoard();
  						printf("It's Computer Turn:\n");
  						printf("Computer Pin Position (From Which): 2\n");
  						printf("Computer Pin Position (To Which): 3\n");
  						Swapping(2,&Value[2],&Value[3]);
  						DrawBoard();
  						DeclareWinner(947);
					  }else{
					  	printf("Computer Pin-->3 Position is: 8\n");
					  	Value[8]=cpin;
					  	DrawBoard();
					  	DeclareWinner(948);
				}	
  					break;
  				
			  }
  			break;
  		
  		default :
  			printf("----Coming Soon-----------");
  			printf("Temperarly YOU Won The game");
  					//code need to be write;
  			break;
	  }
    	
			
		}else{
			// computer going to the game first
			DrawBoard();
				printf("It's Computer Turn\n");
				printf("Computer pin-->1 position is: 5\n");
				Value[5]=cpin;
				DrawBoard();
				int pos1;
				pos1=AskPinPos();
				pos1=IsValidPos(pos1);
				Value[pos1]=p1pin;
				DrawBoard();
				printf("It's computer Turn\n");
				switch(pos1){
					case 1:
						printf("Computer pin-->2 Position is: 6\n");
						Value[6]=cpin;
						break;
					case 2:
						printf("Computer pin-->2 Position is: 7\n");
						Value[7]=cpin;
						break;
					case 3:
						printf("Computer pin-->2 Position is: 8\n");
						Value[8]=cpin;
						break;
					case 4:
						printf("Computer pin-->2 Position is: 9\n");
						Value[9]=cpin;
						break;
					case 6:
						printf("Computer pin-->2 Position is: 1\n");
						Value[1]=cpin;
						break;
					case 7:
						printf("Computer pin-->2 Position is: 2\n");
						Value[2]=cpin;
						break;
					case 8:
						printf("Computer pin-->2 Position is: 3\n");
						Value[3]=cpin;
						break;
					default :
						printf("Computer pin-->2 Position is: 4\n");
						Value[4]=cpin;
						break;
				}
				DrawBoard();
				int pos2;
				pos2=AskPinPos();
				pos2=IsValidPos(pos2);
				Value[pos2]=p1pin;
				DrawBoard();
				printf("It's Computer Turn\n");
					switch(pos1){
						case 1:
							if(pos2==4){
								printf("Computer pin-->3 position is: 7\n");
								Value[7]=cpin;
								DrawBoard();
								int pos3;
								pos3=AskPinPos();
								pos3=IsValidPos(pos3);
								Value[pos3]=p1pin;
								DrawBoard();
								printf("It's Computer Turn\n");
								if(pos3==3){
									printf("Computer pin position (From Which): 6\n");
									printf("Computer pin position (To Which): 9\n");
									Value[9]=cpin;
									Value[6]='6';
									DrawBoard();
									printf("-----------------------------------------------------------\n");
									printf("----------------It's Time to Move Our pin's----------------\n");
									printf("-----------------------------------------------------------\n");
									AskMove();
									int ans=IsValidMove(move1,move2,p1pin);
									Swapping(move1,&Value[move1],&Value[move2]);
									DrawBoard();
									printf("It's Computer Turn\n");
									printf("Computer pin position (From Which): 5\n");
									printf("Computer pin position (To Which): 8\n");
									Value[8]=cpin;
									Value[5]='5';
								}else{
									printf("Computer pin position (From Which): 6\n");
									printf("Computer pin position (To Which): 3\n");
									Value[3]=cpin;
									Value[6]='6';
								}
							}else{
								printf("Computer pin-->3 position is: 4\n");
								Value[4]=cpin;
							}
							break;
						case 3:
							if(pos2==2){
								printf("Computer pin-->3 position is: 1\n");
								Value[1]=cpin;
								DrawBoard();
								int pos3;
								pos3=AskPinPos();
								pos3=IsValidPos(pos3);
								Value[pos3]=p1pin;
								DrawBoard();
								printf("It's Computer Turn\n");
								if(pos3==9){
									printf("Computer pin position (From Which): 8\n");
									printf("Computer pin position (To Which): 7\n");
									Value[7]=cpin;
									Value[8]='8';
									DrawBoard();
									printf("-----------------------------------------------------------\n");
									printf("----------------It's Time to Move Our pin's----------------\n");
									printf("-----------------------------------------------------------\n");
									AskMove();
									int ans=IsValidMove(move1,move2,p1pin);
									Swapping(move1,&Value[move1],&Value[move2]);
									DrawBoard();
									printf("It's Computer Turn\n");
									printf("Computer pin position (From Which): 5\n");
									printf("Computer pin position (To Which): 4\n");
									Value[4]=cpin;
									Value[5]='5';
								}else{
									printf("Computer pin position (From Which): 8\n");
									printf("Computer pin position (To Which): 9\n");
									Value[9]=cpin;
									Value[8]='8';
								}
							}else{
								printf("Computer pin-->3 position is: 2\n");
								Value[2]=cpin;
							}
							break;
						case 7:
							if(pos2==8){
								printf("Computer pin-->3 position is: 9\n");
								Value[9]=cpin;
								DrawBoard();
								int pos3;
								pos3=AskPinPos();
								pos3=IsValidPos(pos3);
								Value[pos3]=p1pin;
								DrawBoard();
								printf("It's Computer Turn\n");
								if(pos3==1){
									printf("Computer pin position (From Which): 2\n");
									printf("Computer pin position (To Which): 3\n");
									Value[3]=cpin;
									Value[2]='2';
									DrawBoard();
									printf("-----------------------------------------------------------\n");
									printf("----------------It's Time to Move Our pin's----------------\n");
									printf("-----------------------------------------------------------\n");
									AskMove();
									int ans=IsValidMove(move1,move2,p1pin);
									Swapping(move1,&Value[move1],&Value[move2]);
									DrawBoard();
									printf("It's Computer Turn\n");
									printf("Computer pin position (From Which): 5\n");
									printf("Computer pin position (To Which): 6\n");
									Value[6]=cpin;
									Value[5]='5';
								}else{
									printf("Computer pin position (From Which): 2\n");
									printf("Computer pin position (To Which): 1\n");
									Value[1]=cpin;
									Value[2]='2';
								}
							}else{
								printf("Computer pin-->3 position is: 8\n");
								Value[8]=cpin;
							}
							break;
						case 9:
							if(pos2==6){
								printf("Computer pin-->3 position is: 3\n");
								Value[3]=cpin;
								DrawBoard();
								int pos3;
								pos3=AskPinPos();
								pos3=IsValidPos(pos3);
								Value[pos3]=p1pin;
								DrawBoard();
								printf("It's Computer Turn\n");
								if(pos3==7){
									printf("Computer pin position (From Which): 4\n");
									printf("Computer pin position (To Which): 1\n");
									Value[1]=cpin;
									Value[4]='4';
									DrawBoard();
									printf("-----------------------------------------------------------\n");
									printf("----------------It's Time to Move Our pin's----------------\n");
									printf("-----------------------------------------------------------\n");
									AskMove();
									int ans=IsValidMove(move1,move2,p1pin);
									Swapping(move1,&Value[move1],&Value[move2]);
									DrawBoard();
									printf("It's Computer Turn\n");
									printf("Computer pin position (From Which): 5\n");
									printf("Computer pin position (To Which): 2\n");
									Value[2]=cpin;
									Value[5]='5';
								}else{
									printf("Computer pin position (From Which): 4\n");
									printf("Computer pin position (To Which): 7\n");
									Value[7]=cpin;
									Value[4]='4';
								}
							}else{
								printf("Computer pin-->3 position is: 6\n");
								Value[6]=cpin;
							}
							break;
						case 2:
							if(pos2==3){
								printf("Computer pin-->3 position is: 1\n");
								Value[1]=cpin;
								DrawBoard();
								int pos3;
								pos3=AskPinPos();
								pos3=IsValidPos(pos3);
								Value[pos3]=p1pin;
								DrawBoard();
								printf("It's Computer Turn\n");
								if(pos3==4){
									printf("Computer pin position (From Which): 7\n");
									printf("Computer pin position (To Which): 8\n");
									Value[8]=cpin;
									Value[7]='7';
									DrawBoard();
									printf("-----------------------------------------------------------\n");
									printf("----------------It's Time to Move Our pin's----------------\n");
									printf("-----------------------------------------------------------\n");
									AskMove();
									int ans=IsValidMove(move1,move2,p1pin);
									Swapping(move1,&Value[move1],&Value[move2]);
									DrawBoard();
									printf("It's Computer Turn\n");
									printf("Computer pin position (From Which): 8\n");
									printf("Computer pin position (To Which): 9\n");
									Value[9]=cpin;
									Value[8]='8';
								}else{
									printf("Computer pin position (From Which): 5\n");
									printf("Computer pin position (To Which): 4\n");
									Value[4]=cpin;
									Value[5]='5';
								}
							}else{
								printf("Computer pin-->3 position is: 3\n");
								Value[3]=cpin;
							}
							break;
						case 4:
							if(pos2==1){
								printf("Computer pin-->3 position is: 7\n");
								Value[7]=cpin;
								DrawBoard();
								int pos3;
								pos3=AskPinPos();
								pos3=IsValidPos(pos3);
								Value[pos3]=p1pin;
								DrawBoard();
								printf("It's Computer Turn\n");
								if(pos3==8){
									printf("Computer pin position (From Which): 9\n");
									printf("Computer pin position (To Which): 6\n");
									Value[6]=cpin;
									Value[9]='9';
									DrawBoard();
									printf("-----------------------------------------------------------\n");
									printf("----------------It's Time to Move Our pin's----------------\n");
									printf("-----------------------------------------------------------\n");
									AskMove();
									int ans=IsValidMove(move1,move2,p1pin);
									Swapping(move1,&Value[move1],&Value[move2]);
									DrawBoard();
									printf("It's Computer Turn\n");
									printf("Computer pin position (From Which): 6\n");
									printf("Computer pin position (To Which): 3\n");
									Value[6]=cpin;
									Value[6]='3';
								}else{
									printf("Computer pin position (From Which): 5\n");
									printf("Computer pin position (To Which): 8\n");
									Value[8]=cpin;
									Value[5]='5';
								}
								
							}else{
								printf("Computer pin-->3 position is: 1\n");
								Value[1]=cpin;
							}
							break;
						case 6:
							if(pos2==9){
								printf("Computer pin-->3 position is: 3\n");
								Value[3]=cpin;
								DrawBoard();
								int pos3;
								pos3=AskPinPos();
								pos3=IsValidPos(pos3);
								Value[pos3]=p1pin;
								DrawBoard();
								printf("It's Computer Turn\n");
								if(pos3==2){
									printf("Computer pin position (From Which): 1\n");
									printf("Computer pin position (To Which): 4\n");
									Value[4]=cpin;
									Value[1]='1';
									DrawBoard();
									printf("-----------------------------------------------------------\n");
									printf("----------------It's Time to Move Our pin's----------------\n");
									printf("-----------------------------------------------------------\n");
									AskMove();
									int ans=IsValidMove(move1,move2,p1pin);
									Swapping(move1,&Value[move1],&Value[move2]);
									DrawBoard();
									printf("It's Computer Turn\n");
									printf("Computer pin position (From Which): 4\n");
									printf("Computer pin position (To Which): 7\n");
									Value[7]=cpin;
									Value[4]='4';
								}else{
									printf("Computer pin position (From Which): 5\n");
									printf("Computer pin position (To Which): 2\n");
									Value[2]=cpin;
									Value[5]='5';
								}
							}else{
								printf("Computer pin-->3 position is: 9\n");
								Value[9]=cpin;
							}
							break;
						default:
							if(pos2==7){
								printf("Computer pin-->3 position is: 9\n");
								Value[9]=cpin;
								DrawBoard();
								int pos3;
								pos3=AskPinPos();
								pos3=IsValidPos(pos3);
								Value[pos3]=p1pin;
								DrawBoard();
								printf("It's Computer Turn\n");
								if(pos3==6){
									printf("Computer pin position (From Which): 3\n");
									printf("Computer pin position (To Which): 2\n");
									Value[2]=cpin;
									Value[3]='3';
									DrawBoard();
									printf("-----------------------------------------------------------\n");
									printf("----------------It's Time to Move Our pin's----------------\n");
									printf("-----------------------------------------------------------\n");
									AskMove();
									int ans=IsValidMove(move1,move2,p1pin);
									Swapping(move1,&Value[move1],&Value[move2]);
									DrawBoard();
									printf("It's Computer Turn\n");
									printf("Computer pin position (From Which): 2\n");
									printf("Computer pin position (To Which): 1\n");
									Value[1]=cpin;
									Value[2]='2';
								}else{
									printf("Computer pin position (From Which): 5\n");
									printf("Computer pin position (To Which): 6\n");
									Value[6]=cpin;
									Value[5]='5';
								}
								
							}else{
								printf("Computer pin-->3 position is: 7\n");
								Value[7]=cpin;
							}
							break;
					}
					if(Checking()==0){
						DrawBoard();
						printf("-------------Computer Won the Game--------------\n");
						printf("-----------------The Game is Over---------------\n");
						return 5;
					}
				
			
		}
	}
	
}


// FUNCTIONS TO REDUCE THE CODE


int IsValidPos(int num){
	if(num>0 && num<10 && Value[num]!=p1pin && Value[num]!=cpin){
		return num;
	}else{
		printf("Invalid Position:\n");
		printf("'%s' Enter Valid Position:",p1name);
		char ch;
		scanf(" %c",&ch);
		int pos=ch-'0';
		return IsValidPos(pos);
	}
}

int AskPinPos(void){
	char ch;
	printf(" '%s' It's Your Turn:\n",p1name);
	printf("Enter Your Pin Position:");
	scanf(" %c",&ch);
	return ch-'0';
}

int IsValidPos2(int num){
	if(num>0 && num<10 && Value[num]!=p1pin && Value[num]!=cpin){
		return num;
	}else{
		printf("Invalid Position:\n");
		printf("'%s' Enter Valid Position:",p2name);
		char ch;
		scanf(" %c",&ch);
		int pos=ch-'0';
		return IsValidPos(pos);
	}
}

int AskPinPos2(void){
	char ch;
	printf(" '%s' It's Your Turn:\n",p2name);
	printf("Enter Your Pin Position:");
	scanf(" %c",&ch);
	return ch-'0';
}


void AskAgain(char ch){
	    printf("'%s' Invalid Move\n",p1name);
		printf("Enter Valid positions\n");
		printf("Enter pin position (From Which):");
		scanf(" %c",&cmove1);
		printf("Enter pin position (To Which):");
		scanf(" %c",&cmove2);
		move1=cmove1-'0';
		move2=cmove2-'0';
		int ans=IsValidMove(move1,move2,ch);
}

void AskAgain2(char ch){
	    printf("'%s' Invalid Move\n",p2name);
		printf("Enter Valid positions\n");
		printf("Enter pin position (From Which):");
		scanf(" %c",&cmove1);
		printf("Enter pin position (To Which):");
		scanf(" %c",&cmove2);
		move1=cmove1-'0';
		move2=cmove2-'0';
		int ans=IsValidMove(move1,move2,ch);
}

int IsValidMove2(int p1,int p2,char pin){
	if(p2==p1){
		 	AskAgain2(pin);
	}else if(Value[p2]==p1pin|| Value[p2]==cpin){
		AskAgain2(pin);
	}else if(Value[p1]==pin){
	switch(p1){
		case 1:
			if(p2==2 || p2==5 ||p2==4){
					return 1;
			}else{
		 	AskAgain2(pin);
			}
		 
		break;
		case 2:
		 if(p2==1|| p2==5|| p2==3){
			return 1;
		 }else{
		 AskAgain2(pin);
		 }
		break;
		case 3:
		  if(p2==2|| p2==5|| p2==6){
		  	return 1;
		}else{
		 	AskAgain2(pin);
		 }
		break;
		case 4: 
		 if(p2==1|| p2==5|| p2==7){
		 	return 1;
		 }else{
		 	AskAgain2(pin);
		 }
		break;
		case 5: 
		 if(p2==1|| p2==2|| p2==3|| p2==4|| p2==6|| p2==7|| p2==8|| p2==9){
				return 1;
		 }else{
		 	AskAgain2(pin);
		 }
		break;
		case 6: 
		 if(p2==3|| p2==5|| p2==9){
		   return 1;
		 }else{
		 	AskAgain2(pin);
		 }
		break;
		case 7: 
		 if(p2==4|| p2==5|| p2==8){
		 return 1;
		 }else{
		 	AskAgain2(pin);
		 }
		break;
		case 8: 
		 if(p2==5|| p2==7|| p2==9){
		 return 1;	
		 }else{
		 	AskAgain2(pin);
		 }
		break;
		case 9: 
		 if(p2==5|| p2==6|| p2==8){
		 return 1;
		 }else{
		 	AskAgain2(pin);
		 }
		break;
		default:
		AskAgain2(pin);
		break;
	}
  }else{
	AskAgain2(pin);
}
}




void AskMove(void){
	printf("'%s' It's Your Turn:\n",p1name);
	printf("Enter Pin Position (From Which):");
	scanf(" %c",&cmove1);
	printf("Enter Pin Position (To Which):");
	scanf(" %c",&cmove2);
	move1=cmove1-'0';
	move2=cmove2-'0';
	
}

void AskMove2(void){
	printf("'%s' It's Your Turn:\n",p2name);
	printf("Enter Pin Position (From Which):");
	scanf(" %c",&cmove1);
	printf("Enter Pin Position (To Which):");
	scanf(" %c",&cmove2);
	move1=cmove1-'0';
	move2=cmove2-'0';
	
}


void DeclareWinner(int line){
	if(Checking()==0){
		printf("----------------Computer won The Game-------------\n");
		printf("----------------The Game is Over------------------\n");
		return ;
		 }else {
		printf("Error Occured in %d case check it\n",line);
	 	return ;
	 }
}
// exceptional case when infinity moves are going to happen corner cases
// 1st
void Cornercase7_9(){
	int ans;
	printf("It's Computer Turn\n");
	printf("Computer Pin Position (From Which):8\n");
	printf("Computer Pin Position (To Which): 7\n");
	Swapping(8,&Value[8],&Value[7]);
	DrawBoard();
	printf("--------------------------------------------------------------------\n");
  	printf("----------------------It's Time To MOVE your Pin's------------------\n");
  	printf("--------------------------------------------------------------------\n");
  	AskMove();
	ans=IsValidMove(move1,move2,p1pin);
	Swapping(move1,&Value[move1],&Value[move2]);
	DrawBoard();
	if(move1==9 && move2==8){
		//Automatically
		printf("It's Computer Turn\n");
		printf("Computer Pin Position (From Which): 5\n");
		printf("Computer Pin Position (To Which): 6\n");
		Swapping(5,&Value[5],&Value[6]);
		DrawBoard();
		printf("AUTO MOVING THE PINS\n");
		printf("'%s' It's Your Turn \n",p1name);
		printf("Your Move is 4--> 5\n");
		 Swapping(4,&Value[4],&Value[5]);
		 DrawBoard();
		printf(" Congartulations '%s'! YOU Won The GAME\n",p1name);
		printf("--------------The GAME is OVER---------------\n");
	}else if (move1==9 && move2==6){
		printf("It's Computer Turn\n");
		printf("Computer Pin Position (From Which): 7\n");
		printf("Computer Pin Position (To Which): 8\n");
		Swapping(3,&Value[3],&Value[2]);
		DrawBoard();
		printf("--------------------------------------------------------------------\n");
  		printf("----------------------It's Time To MOVE your Pin's------------------\n");
  		printf("--------------------------------------------------------------------\n");
  		AskMove();
		ans=IsValidMove(move1,move2,p1pin);
		Swapping(move1,&Value[move1],&Value[move2]);
		DrawBoard();
		if(move1==6 && move2==9){
			Cornercase7_9();
		}else{
			printf("It's Computer Turn \n");
			printf("Computer Pin Position (From Which): 8\n");
		    printf("Computer Pin Position (To Which): 9\n");
		    Swapping(8,&Value[8],&Value[9]);
		    DrawBoard();
		    DeclareWinner(799);
		} 
	}else{
		printf("It's Computer Turn\n");
		printf("Computer Pin Position (From Which): 7\n");
		printf("Computer Pin Position (To Which): 8\n");
		Swapping(7,&Value[7],&Value[8]);
		DrawBoard();
		printf("--------------------------------------------------------------------\n");
  		printf("----------------------It's Time To MOVE your Pin's------------------\n");
  		printf("--------------------------------------------------------------------\n");
  		AskMove();
		ans=IsValidMove(move1,move2,p1pin);
		Swapping(move1,&Value[move1],&Value[move2]);
		DrawBoard();
		if(move1==3 && move2==2){
			Cornercase7_9();
		}else{
			printf("It's Computer Turn\n");
			printf("Computer Pin Position (From Which): 1\n");
		    printf("Computer Pin Position (To Which): 2\n");
		    Swapping(1,&Value[1],&Value[2]);
		    DrawBoard();
		    DeclareWinner(792);
		}
		
	}
}

// 2nd
void Cornercase3_9(){
	int ans;
	printf("It's Computer Turn\n");
	printf("Computer Pin Position (From Which): 6\n");
	printf("Computer Pin Position (To Which): 9\n");
	Swapping(2,&Value[2],&Value[3]);
	DrawBoard();
	printf("--------------------------------------------------------------------\n");
  	printf("----------------------It's Time To MOVE your Pin's------------------\n");
  	printf("--------------------------------------------------------------------\n");
  	AskMove();
	ans=IsValidMove(move1,move2,p1pin);
	Swapping(move1,&Value[move1],&Value[move2]);
	DrawBoard();
	if(move1==3 && move2==6){
		//Automatically
		printf("It's Computer Turn\n");
		printf("Computer Pin Position (From Which): 5\n");
		printf("Computer Pin Position (To Which): 2\n");
		Swapping(5,&Value[5],&Value[2]);
		DrawBoard();
		printf("AUTO MOVING THE PINS\n");
		printf("'%s' It's Your Turn \n",p1name);
		printf("Your Move is 8--> 5\n");
		Swapping(8,&Value[8],&Value[5]);
		DrawBoard();
		printf(" Congartulations '%s'! YOU Won The GAME\n",p1name);
		printf("--------------The GAME is OVER---------------\n");
	}else if (move1==3 && move2==2){
		printf("It's Computer Turn\n");
		printf("Computer Pin Position (From Which): 9\n");
		printf("Computer Pin Position (To Which): 6\n");
		Swapping(9,&Value[6],&Value[6]);
		DrawBoard();
	    printf("--------------------------------------------------------------------\n");
  		printf("----------------------It's Time To MOVE your Pin's------------------\n");
  		printf("--------------------------------------------------------------------\n");
  		AskMove();
		ans=IsValidMove(move1,move2,p1pin);
		Swapping(move1,&Value[move1],&Value[move2]);
		DrawBoard();
		if(move1==2 && move2==3){
			Cornercase3_9();
		}else{
			printf("It's Computer Turn \n");
			printf("Computer Pin Position (From Which): 6\n");
		    printf("Computer Pin Position (To Which): 3\n");
		    Swapping(6,&Value[6],&Value[3]);
		    DrawBoard();
		    DeclareWinner(393);
		} 
	}else{
		printf("It's Computer Turn\n");
		printf("Computer Pin Position (From Which): 9\n");
		printf("Computer Pin Position (To Which): 6\n");
		Swapping(9,&Value[9],&Value[6]);
		DrawBoard();
		AskMove();
		ans=IsValidMove(move1,move2,p1pin);
		Swapping(move1,&Value[move1],&Value[move2]);
		DrawBoard();
		if(move1==1 && move2==4){
			Cornercase3_9();
		}else{
			printf("It's Computer Turn\n");
			printf("Computer Pin Position (From Which): 7\n");
		    printf("Computer Pin Position (To Which): 4\n");
		    Swapping(7,&Value[7],&Value[4]);
		    DrawBoard();
		    DeclareWinner(399);
		}
		
	}
}

// 3rd
void Cornercase1_7(){
	int ans;
	printf("It's Computer Turn\n");
	printf("Computer Pin Position (From Which): 4\n");
	printf("Computer Pin Position (To Which): 1\n");
	Swapping(4,&Value[4],&Value[1]);
	DrawBoard();
	printf("--------------------------------------------------------------------\n");
  	printf("----------------------It's Time To MOVE your Pin's------------------\n");
  	printf("--------------------------------------------------------------------\n");
  	AskMove();
	ans=IsValidMove(move1,move2,p1pin);
	Swapping(move1,&Value[move1],&Value[move2]);
	DrawBoard();
	if(move1==7 && move2==4){
		//Automatically
		printf("It's Computer Turn\n");
		printf("Computer Pin Position (From Which): 5\n");
		printf("Computer Pin Position (To Which): 8\n");
		Swapping(5,&Value[5],&Value[8]);
		DrawBoard();
		printf("AUTO MOVING THE PINS\n");
		printf("'%s' It's Your Turn \n",p1name);
		printf("Your Move is 2--> 5\n");
		 Swapping(2,&Value[2],&Value[5]);
		 DrawBoard();
		printf(" Congartulations '%s'! YOU Won The GAME\n",p1name);
		printf("--------------The GAME is OVER---------------\n");
		
	}else if (move1==7 && move2==8){
		printf("It's Computer Turn\n");
		printf("Computer Pin Position (From Which): 1\n");
		printf("Computer Pin Position (To Which): 4\n");
		Swapping(1,&Value[1],&Value[4]);
		DrawBoard();
	    printf("--------------------------------------------------------------------\n");
  		printf("----------------------It's Time To MOVE your Pin's------------------\n");
  		printf("--------------------------------------------------------------------\n");
  		AskMove();
		ans=IsValidMove(move1,move2,p1pin);
		Swapping(move1,&Value[move1],&Value[move2]);
		DrawBoard();
		if(move1==8 && move2==7){
			Cornercase1_7();
		}else{
			printf("It's Computer Turn \n");
			printf("Computer Pin Position (From Which): 4\n");
		    printf("Computer Pin Position (To Which): 7\n");
		    Swapping(4,&Value[4],&Value[7]);
		    DrawBoard();
		    DeclareWinner(177);
		} 
	}else{
		printf("It's Computer Turn\n");
		printf("Computer Pin Position (From Which): 1\n");
		printf("Computer Pin Position (To Which): 4\n");
		Swapping(1,&Value[1],&Value[4]);
		DrawBoard();
	    printf("--------------------------------------------------------------------\n");
  		printf("----------------------It's Time To MOVE your Pin's------------------\n");
  		printf("--------------------------------------------------------------------\n");
  		AskMove();
		ans=IsValidMove(move1,move2,p1pin);
		Swapping(move1,&Value[move1],&Value[move2]);
		DrawBoard();
		if(move1==9 && move2==6){
			Cornercase1_7();
		}else{
			printf("It's Computer Turn\n");
			printf("Computer Pin Position (From Which): 3\n");
		    printf("Computer Pin Position (To Which): 6\n");
		    Swapping(3,&Value[3],&Value[6]);
		    DrawBoard();
		    DeclareWinner(171);
		}
		
	}
}

// 4th
void Cornercase1_3(){
	int ans;
	printf("It's Computer Turn\n");
	printf("Computer Pin Position (From Which):2\n");
	printf("Computer Pin Position (To Which): 3\n");
	Swapping(2,&Value[2],&Value[3]);
	DrawBoard();
	    printf("--------------------------------------------------------------------\n");
  		printf("----------------------It's Time To MOVE your Pin's------------------\n");
  		printf("--------------------------------------------------------------------\n");
  		AskMove();
	ans=IsValidMove(move1,move2,p1pin);
	Swapping(move1,&Value[move1],&Value[move2]);
	DrawBoard();
	if(move1==1 && move2==2){
		//Automatically
		printf("It's Computer Turn\n");
		printf("Computer Pin Position (From Which): 5\n");
		printf("Computer Pin Position (To Which): 4\n");
		Swapping(5,&Value[5],&Value[4]);
		DrawBoard();
		printf("AUTO MOVING THE PINS\n");
		printf(" '%s' It's Your Turn \n",p1name);
		printf("Your Move is 6--> 5\n");
		 Swapping(6,&Value[6],&Value[5]);
		 DrawBoard();
		printf(" Congartulations '%s'! YOU Won The GAME\n",p1name);
		printf("--------------The GAME is OVER---------------\n");
		
	}else if (move1==1 && move2==4){
		printf("It's Computer Turn\n");
		printf("Computer Pin Position (From Which): 3\n");
		printf("Computer Pin Position (To Which): 2\n");
		Swapping(3,&Value[3],&Value[2]);
		DrawBoard();
	    printf("--------------------------------------------------------------------\n");
  		printf("----------------------It's Time To MOVE your Pin's------------------\n");
  		printf("--------------------------------------------------------------------\n");
  		AskMove();
		ans=IsValidMove(move1,move2,p1pin);
		Swapping(move1,&Value[move1],&Value[move2]);
		DrawBoard();
		if(move1==4 && move2==1){
			Cornercase1_3();
		}else{
			printf("It's Computer Turn \n");
			printf("Computer Pin Position (From Which): 2\n");
		    printf("Computer Pin Position (To Which): 1\n");
		    Swapping(2,&Value[2],&Value[1]);
		    DrawBoard();
		    DeclareWinner(131);
		} 
	}else{
		printf("It's Computer Turn\n");
		printf("Computer Pin Position (From Which): 3\n");
		printf("Computer Pin Position (To Which): 2\n");
		Swapping(3,&Value[3],&Value[2]);
		DrawBoard();
	    printf("--------------------------------------------------------------------\n");
  		printf("----------------------It's Time To MOVE your Pin's------------------\n");
  		printf("--------------------------------------------------------------------\n");
  		AskMove();
		ans=IsValidMove(move1,move2,p1pin);
		Swapping(move1,&Value[move1],&Value[move2]);
		DrawBoard();
		if(move1==7 && move2==8){
			Cornercase1_3();
		}else{
			printf("It's Computer Turn\n");
			printf("Computer Pin Position (From Which): 9\n");
		    printf("Computer Pin Position (To Which): 8\n");
		    Swapping(9,&Value[9],&Value[8]);
		    DrawBoard();
		    DeclareWinner(138);
		}
		
	}
}

