#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_STATES 8
/*
A C F
B D C
C B H
D D E
E F G
F G B
G H A
H A D

Your starting state is: D
*/

typedef struct statemachine{
  char * name;
  struct statemachine *next0;
  struct statemachine *next1;

}state;

/*Array of states defining the finite state machine
Each index of the Array has 3 elements that is defined inside the struct*/

state fsm[MAX_STATES];


void initialize_states(){
  //State 0
  fsm[0].name="A";
  fsm[0].next0 = fsm + 2;//C
  fsm[0].next1 = fsm + 5;//F

   //State 1
  fsm[1].name="B";
  fsm[1].next0 = fsm + 3;//D
  fsm[1].next1 = fsm + 2;//C

   //State 2
  fsm[2].name="C";
  fsm[2].next0 = fsm + 1;//B
  fsm[2].next1 = fsm + 7;//H

   //State 3
  fsm[3].name="D";
  fsm[3].next0 = fsm + 3;//D
  fsm[3].next1 = fsm + 4;//E

   //State 4
  fsm[4].name="E";
  fsm[4].next0 = fsm + 5;//F
  fsm[4].next1 = fsm + 6;//G

   //State 5
  fsm[5].name="F";
  fsm[5].next0 = fsm + 6;//G
  fsm[5].next1 = fsm + 1;//B

   //State 6
  fsm[6].name="G";
  fsm[6].next0 = fsm + 7;//H
  fsm[6].next1 = fsm + 0;//A

   //State 7
  fsm[7].name="H";
  fsm[7].next0 = fsm + 0;//A
  fsm[7].next1 = fsm + 3;//D
}

void print(){
  int i;
  for(i=0; i < MAX_STATES; i++){
    fprintf(stdout,"%s %s %s\n",fsm[i].name, fsm[i].next0->name, fsm[i].next1->name );
  }

}


int main(int argc, char * argv[])
{
    fprintf(stdout,"PLEASE INPUT THE FOLLOWING CHARACTERS FOR DESIRED OPERATION:\n '0' for low state shift \n '1' for high state shift \n 'c' for changing the high/low of a state \n 'g' for garbage states \n 'd' for deleting all garbage state or 'd _' to delete specific garbage state\n");

  int x;
  char garbage[MAX_STATES];
  char input[5];
  char garbageList[8];

  state *current = fsm + 3;
  initialize_states();
  printf("%s\n", current->name);
  printf("\n");
  print();

  int i;
  //SHIFTING OF STATES OCCURS HERE
  for(i=0;i<20; i++){
    fgets(input, 6, stdin);
    //Printing
  if(input[0] == 'p'){
      print();
    }
  if(input[0] == '0'){
    fprintf(stdout, "%s\n",current->next0->name);
    current= current->next0;

  }
  if(input[0] == '1'){
    fprintf(stdout, "%s\n",current->next1->name);
    current= current->next1;

  }
  //Changing the States
  if(input[0] == 'c'){
     if(input[2] == '0')
    current->next0=fsm + input[4]-65;
  else if(input[2] == '1')
    current->next1=fsm + input[4]-65;
  }

  //Garbage State Collection
  if(input[0] == 'g'){
    x=0;
    strcpy(garbage,"");
    int i,j,k;

    for(i=0; i<MAX_STATES; i++){
      for(j=0; j<MAX_STATES; j++){

	if( (fsm[j].next0->name) == (fsm[i].name)  ||  (fsm[j].next1->name) ==  (fsm[i].name) ){

	garbage[x]=*fsm[i].name;
	x++;
	i++;
	j=0;
      }

      }

    }

    j = 0; i = 0; k = 0;

    for(i = 0; i< MAX_STATES; i++){
        if (*fsm[i].name == garbage[j]){
            j++;
        }
        else{
        garbageList[k] = *fsm[i].name;
        k++;
        }
    }

   // for (i = 0; i < k; i++){
    //    printf("%c", garbageList[i]);
    //}
    //printf("%d\n", x);
    for(k=0; k<x; k++){
      if( x == 8 && k == 0 ){
    fprintf(stdout,"NO GARBAGE\n");
      }
      else{
          if(k==0) printf("Garbage: ");

    fprintf(stdout,"%c ",garbageList[k]);}
        }
    printf("\n");


  }





 if(input[0] == 'd'){

 if(garbageList[0] == '\0'){
      fprintf(stdout,"No States Deleted");

    if(input[2] == '\0'){//Nothing after D
    i=0;
    fprintf(stdout,"Deleted: ");
      for(i=0;i<8;i++){


    fprintf(stdout,"%c ",garbageList[i]);

        memset(garbageList,' ',i);


    }
     fprintf(stdout,"\n");
        printf("\nGarbage: ");
    for(i=0;i<8;i++){
        fprintf(stdout,"%c ",garbageList[i]);}

   for(i=0;i<8;i++){
        memset(garbageList,' ',i);}

   } else {//Something after D
      i=0;
      for(i=0;i<8;i++){
	if(input[2] == garbageList[i] ){
 fprintf(stdout,"%c ",garbageList[i]);

	}
      }



     
    
    











    }
  }



 }


  if(input[0] == 't'){
    exit(0);
  }
 }
    exit(0);
 }
