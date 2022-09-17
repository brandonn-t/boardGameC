#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct Grid{
  char value;
  struct Grid * up;
  struct Grid * down;
  struct Grid * left;
  struct Grid * right;
  
};

  struct Grid * addNode(char value){

  struct Grid * newNode = (struct Grid *) malloc(sizeof(struct Grid));


  if (newNode == NULL) {
      return NULL;
  }

    else{
      newNode->value = value;
      newNode->right = NULL;
      newNode->left = NULL;
      newNode->up = NULL;
      newNode->down = NULL;
    }


    return newNode;
  }

int addArr(char*p, int * idx){
  //Function which takes integers from malloc string and calculates the sum of points for each player
  int i;
  int sum;
  sum  = 0;
  for(i = 0; i < *idx; ++i){
    if(p[i] == '1'){
      sum = sum + 1;
    }
    else if(p[i] == '2'){
      sum = sum + 2;

    }else if(p[i] == '3'){
      sum = sum + 3;

    }
    else{
      printf("this should never print\n");
      return 0;
    }
  }

  return sum;

}

void createRow(struct Grid* node1,struct Grid* node2, struct Grid* node3,
	       struct Grid* node4, struct Grid* node5, struct Grid* node6 ){
 
  //Creates a row of nodes by initializing each nodes left and right components
  //node1
  node1->right = node2;
  node1->left = NULL;

  node2->right = node3;
  node2->left = node1;

  node3->right = node4;
  node3->left = node2;

  node4->right = node5;
  node4->left = node3;

  node5->right = node6;
  node5->left = node4;

  node6->right = NULL;
  node6->left = node5;
  
}

void createColumn(struct Grid* node1,struct Grid* node2, struct Grid* node3,
	       struct Grid* node4, struct Grid* node5, struct Grid* node6 ){
    //this function creates a column by initializing each nodes up and down pointers
    
  node1->up = NULL;
  node1->down = node2;

  node2->up =node1;
  node2->down = node3;

  node3->up =node2;
  node3->down = node4;

  node4->up =node3;
  node4->down = node5;

  node5->up =node4;
  node5->down = node6;

  node6->up =node5;
  node6->down = NULL;


  
} 
void printGraph(struct Grid* node1,struct Grid* node2, struct Grid* node3,
	       struct Grid* node4, struct Grid* node5, struct Grid* node6){
      //prints the chart by printing each row from the head node
  int i;
  for(i=0; i<6;++i){
    printf(" %c ", node1->value);
    node1 = node1->right;
  }

  printf("\n");
   for(i=0; i<6;++i){
    printf(" %c ", node2->value);
    node2 = node2->right;
  }
   printf("\n");

    for(i=0; i<6;++i){
    printf(" %c ", node3->value);
    node3 = node3->right;
  }

    printf("\n");
     for(i=0; i<6;++i){
    printf(" %c ", node4->value);
    node4 = node4->right;
  }

     printf("\n");
      for(i=0; i<6;++i){
    printf(" %c ", node5->value);
    node5 = node5->right;
  }

      printf("\n");
       for(i=0; i<6;++i){
    printf(" %c ", node6->value);
    node6 = node6->right;
  }
  printf("\n");
  printf("\n");



}


void checkNull(char * direc, struct Grid * node, int* torf){
  //checks if the node in the direction is null if it is null torf = 0
  if(strcmp(direc, "UP") == 0){

    
    if(node->up == NULL){
      
    }
    else {
      *torf = 1;
    }
  }
  else if(strcmp(direc, "DOWN") == 0){
    if(node->down == NULL){
      
    }
   else {
     *torf = 1;
    }
  }
  else if(strcmp(direc, "LEFT") == 0){
    
    if(node->left == NULL){
    }
    else {
      *torf = 1;
    }
 
  }
  else if(strcmp(direc, "RIGHT") == 0){
    if(node->right == NULL){
     
    }
    else {
      *torf = 1;
    }
  }
  //upleft
  else if(strcmp(direc, "UPLEFT") == 0){
    if(node->left == NULL){
    }
    else if(node->up == NULL){
    }
    else {
      *torf = 1;
    }
  }
  //upRight
  else if(strcmp(direc, "UPRIGHT") == 0){
    if(node->right == NULL){
    }
    else if(node->up == NULL){
    }
    else {
      *torf = 1;
    }
  }
  //down left
  else if(strcmp(direc, "DOWNLEFT") == 0){
    if(node->left == NULL){
    }
    else if(node->down == NULL){
    }
    else {
      *torf = 1;
    }
  }
  //downRight
  else if(strcmp(direc, "DOWNRIGHT") == 0){


    if(node->right == NULL){
     }
    else if(node->down == NULL){
    }
    else {
      *torf = 1;
    }
  }
  
}

struct Grid * move(struct Grid * nodeMove, char * direc, int spaces, bool dia, char * arr, int * idx){
  //moves the node, uses directions and number of spaces.
  //initializes the node to '.' after it moves

  int nullCheck;
  int * nullP = &nullCheck;
  struct Grid *fail;
  int i;



    if(strcmp(direc, "UP") == 0){

      if(dia){

        for(i = 0; i< spaces; ++i){
        nodeMove = nodeMove->up;
        }
      }
      else if(dia == false){
          nodeMove->value = '.';
          for(i = 0; i< spaces; ++i){
          nodeMove = nodeMove->up;
          }
      }
    }
    else if(strcmp(direc, "DOWN") == 0){
      if(dia){

        for(i = 0; i< spaces; ++i){
        nodeMove = nodeMove->down;
        }
      }
      else if(dia == false){
          

          nodeMove->value = '.';
          for(i = 0; i< spaces; ++i){
          nodeMove = nodeMove->down;
          }
          

      }
    }
    else if(strcmp(direc, "LEFT") == 0){
      if(dia){

        for(i = 0; i< spaces; ++i){
        nodeMove = nodeMove->left;
        }
      }
      else if(dia == false){
          
          nodeMove->value = '.';

          for(i = 0; i< spaces; ++i){
          nodeMove = nodeMove->left;
          }
          

      }
    }
    else if(strcmp(direc, "RIGHT") == 0){
      if(dia){

        for(i = 0; i< spaces; ++i){
        nodeMove = nodeMove->right;
        }
      }
      else if(dia == false){
          
          nodeMove->value = '.';


          for(i = 0; i< spaces; ++i){
          nodeMove = nodeMove->right;
          }
          

      }
      
    }

    //1 upL 2 upR 3 DL 4 DR
    else if(strcmp(direc, "UPLEFT") == 0){
      

      if(nodeMove->up->value != '.'){
        // printf("im in if\n");
        nodeMove->value = '.';

        nodeMove = move(nodeMove, "UP", spaces, true, arr, idx);
        nodeMove = move(nodeMove, "LEFT", spaces, true, arr, idx);
        
      }else if(nodeMove->left->value != '.'){
        nodeMove = move(nodeMove, "LEFT", spaces, true, arr, idx);
        nodeMove = move(nodeMove, "UP", spaces, true, arr, idx);
      }
      else{
        //printf("you cant go that way!");
        fail->value = '7';
        return fail;
      }
      
    }
    else if(strcmp(direc, "UPRIGHT") == 0){
      
      
      if(nodeMove->up->value != '.'){
        //printf("im in if\n");
        
        //arr[*idx] = nodeMove->value;
        //(*idx)++;

        nodeMove->value = '.';

        nodeMove = move(nodeMove, "UP", spaces, true, arr, idx);
        nodeMove = move(nodeMove, "RIGHT", spaces, true, arr, idx);
        
      }else if(nodeMove->right->value != '.'){
        nodeMove = move(nodeMove, "RIGHT", spaces, true, arr, idx);
        nodeMove = move(nodeMove, "UP", spaces, true, arr, idx);
      }
      else{
        //printf("you cant go that way!");
        fail->value = '7';
        return fail;
      }

    }
    //Down left
    else if(strcmp(direc, "DOWNLEFT") == 0){
      

      if(nodeMove->down->value != '.'){
        // printf("im in if\n");
        arr[*idx] = nodeMove->value;
        (*idx)++;

        nodeMove->value = '.';

        nodeMove = move(nodeMove, "DOWN", spaces, true, arr, idx);
        nodeMove = move(nodeMove, "LEFT", spaces, true, arr, idx);
        
      }else if(nodeMove->left->value != '.'){
        nodeMove = move(nodeMove, "LEFT", spaces, true, arr, idx);
        nodeMove = move(nodeMove, "DOWN", spaces, true, arr, idx);
      }
      else{
        //printf("you cant go that way!");
        fail->value = '7';
        return fail;
      }

    }
    else if(strcmp(direc, "DOWNRIGHT") == 0){
      //arr[*idx] = nodeMove->value;
      //(*idx)++;
      nodeMove->value = '.';
    
      if(nodeMove->down->value != 0){
        
        nodeMove = move(nodeMove, "DOWN", spaces, true, arr, idx);
        nodeMove = move(nodeMove, "RIGHT", spaces, true, arr, idx);
        
      }else if(nodeMove->right->value != '.'){
      
        nodeMove = move(nodeMove, "RIGHT", spaces, true, arr, idx);
        nodeMove = move(nodeMove, "DOWN", spaces, true, arr, idx);
      }
      else{
        
        fail->value = '7';
        return fail;
      }
    }

    return nodeMove;
  }

struct Grid * moveCheck(struct Grid * nodeMove, char * direc, int spaces, bool dia, char * arr, int *idx){
 //moves node into anywhere on the grid even invalid spaces in order to check wether the move is valid.
 
 
  int nullCheck;
  int * nullP = &nullCheck;
  struct Grid * fail;
  fail = nodeMove;
  int i;



    if(strcmp(direc, "UP") == 0){

      if(dia){

        for(i = 0; i< spaces; ++i){
        nodeMove = nodeMove->up;
        }
      }
      else if(dia == false){
          //arr[*idx] = nodeMove->value;
          //*idx = *idx +1;

          //nodeMove->value = '.';
          for(i = 0; i< spaces; ++i){
          nodeMove = nodeMove->up;
          }
      }
    }
    else if(strcmp(direc, "DOWN") == 0){
      if(dia){

        for(i = 0; i< spaces; ++i){
        nodeMove = nodeMove->down;
        }
      }
      else if(dia == false){
          //arr[*idx] = nodeMove->value;
          //*idx = *idx +1;

          //nodeMove->value = '.';
          for(i = 0; i< spaces; ++i){
          nodeMove = nodeMove->down;
          }
          

      }
    }
    else if(strcmp(direc, "LEFT") == 0){
      if(dia){

        for(i = 0; i< spaces; ++i){
        nodeMove = nodeMove->left;
        }
      }
      else if(dia == false){
         // arr[*idx] = nodeMove->value;
          //*idx = *idx +1;
          //nodeMove->value = '.';

          for(i = 0; i< spaces; ++i){
          nodeMove = nodeMove->left;
          }
          

      }
    }
    else if(strcmp(direc, "RIGHT") == 0){
      if(dia){
        for(i = 0; i< spaces; ++i){
        nodeMove = nodeMove->right;
        }
      }
      else if(dia == false){

          for(i = 0; i< spaces; ++i){
          nodeMove = nodeMove->right;
          }
      }
      
    }

    //1 upL 2 upR 3 DL 4 DR
    else if(strcmp(direc, "UPLEFT") == 0){
      
      
      if(nodeMove->up->value != '.'){
        // printf("im in if\n");
        //arr[*idx] = nodeMove->value;
        //*idx = *idx +1;
        //nodeMove->value = '.';

        nodeMove = move(nodeMove, "UP", spaces, true, arr, idx);
        nodeMove = move(nodeMove, "LEFT", spaces, true, arr, idx);
        
      }else if(nodeMove->left->value != '.'){
        nodeMove = move(nodeMove, "LEFT", spaces, true, arr, idx);
        nodeMove = move(nodeMove, "UP", spaces, true, arr, idx);
      }
      else{
        //printf("you cant go that way!");
        fail->value = '7';
        return fail;
      }
      
    }
    else if(strcmp(direc, "UPRIGHT") == 0){
      
      
      if(nodeMove->up->value != '.'){
        //printf("im in if\n");
        
       // arr[*idx] = nodeMove->value;
       // *idx = *idx +1;
       // nodeMove->value = '.';

        nodeMove = move(nodeMove, "UP", spaces, true, arr, idx);
        nodeMove = move(nodeMove, "RIGHT", spaces, true, arr, idx);
        
      }else if(nodeMove->right->value != '.'){
        nodeMove = move(nodeMove, "RIGHT", spaces, true, arr, idx);
        nodeMove = move(nodeMove, "UP", spaces, true, arr, idx);
      }
      else{
        //printf("you cant go that way!");
        fail->value = '7';
        return fail;
      }

    }
    //Down left
    else if(strcmp(direc, "DOWNLEFT") == 0){
      

      if(nodeMove->down->value != '.'){
        // printf("im in if\n");
        //arr[*idx] = nodeMove->value;
       // *idx = *idx +1;
       // nodeMove->value = '.';

        nodeMove = move(nodeMove, "DOWN", spaces, true, arr, idx);
        nodeMove = move(nodeMove, "LEFT", spaces, true, arr, idx);
        
      }else if(nodeMove->left->value != '.'){
        nodeMove = move(nodeMove, "LEFT", spaces, true, arr, idx);
        nodeMove = move(nodeMove, "DOWN", spaces, true, arr, idx);
      }
      else{
        //printf("you cant go that way!");
        fail->value = '7';
        return fail;
      }

    }
    else if(strcmp(direc, "DOWNRIGHT") == 0){
    //  arr[*idx] = nodeMove->value;
     // *idx = *idx +1;
     // nodeMove->value = '.';
    
      if(nodeMove->down->value != '.'){
        
        nodeMove = move(nodeMove, "DOWN", spaces, true, arr, idx);
        nodeMove = move(nodeMove, "RIGHT", spaces, true, arr, idx);
        
      }else if(nodeMove->right->value != '.'){
      
        nodeMove = move(nodeMove, "RIGHT", spaces, true, arr, idx);
        nodeMove = move(nodeMove, "DOWN", spaces, true, arr, idx);
      }
      else{
        
        fail->value = '7';
        return fail;
      }
    }

    return nodeMove;
  }

bool spaceCheck(struct Grid * node, char * direc, int spaces, bool dia, char * arr, int * idx, int * torfp){

  //checks if the space is valid
  //checks if NULL checks if '.' checks if player/AI is in the space and checks if you can access the place diagonally

  int i;
  struct Grid * dummy;
  dummy = node;
  for(i = 0; i < spaces; ++i){
    *torfp = 0;

     checkNull(direc, dummy, torfp);

     
      //dummy = moveCheck(dummy, direc, 1, dia, arr, idx);
      
     if(*torfp == 0){
       //printf("you hit a wall\n");
        return false;
     }
      dummy = moveCheck(dummy, direc, 1, dia, arr, idx);

     if(dummy->value == '.'){
       //printf("the spot %d in that direction has already been taken\n", i);
        return false;
      }
      else if(dummy->value == 'A'){
        //printf("you hit a player A");
        return false;
      }
      else if(dummy->value == 'P'){
        //printf("you hit a player P");
      }
    
    //printf("im seg faulting: %c\n", dummy->value);
    //dummy = moveCheck(dummy, direc, 1, dia, arr, idx);
    
    if(dummy->value == '7'){
      //printf("you cant get to that spot diagonally\n");
      dummy = node;
      return false;
    }
     // printf("2dummy value is: %c\n", dummy->value);

    *torfp = 0;
  }

  
   *torfp = 0;
  return true;
}

//function which checks if there are any spaces left for the user/AI to move 
bool anySpaces(struct Grid * node, char * arr, int * idx, int * torfp){
  //checks if there are any available spaces near the node

  bool result = false;
  //checking up
  result = spaceCheck(node, "UP", 1, false, arr, idx, torfp);
  if(result){
    return true;
  }

  result = spaceCheck(node, "DOWN", 1, false, arr, idx, torfp);
  if(result){
    return true;
  }
  result = spaceCheck(node, "LEFT", 1, false, arr, idx, torfp);
  if(result){
    return true;
  }
  result = spaceCheck(node, "RIGHT", 1, false, arr, idx, torfp);
  if(result){
    return true;
  }
  //diagonals 

  result = spaceCheck(node, "UPLEFT", 1, true, arr, idx, torfp);
  if(result){
    return true;
  }
  result = spaceCheck(node, "UPRIGHT", 1, true, arr, idx, torfp);
  if(result){
    return true;
  }
  result = spaceCheck(node, "DOWNLEFT", 1, true, arr, idx, torfp);
  if(result){
    return true;
  }
  result = spaceCheck(node, "DOWNRIGHT", 1, true, arr, idx, torfp);
  if(result){
    return true;
  }


  *torfp = 0;

  return result;

}

char * bestMove(struct Grid * nodeMove, char * arr, int *idx, int highestNum, int * torfp){
  //AI algorithum which locates the best move in the 8 directions near it

  struct Grid * dummy;
  int ctoN = 0;
  dummy = nodeMove;
  *torfp = 0;

  checkNull("UP", dummy, torfp);
  if(*torfp == 0){

  }
  else{
  dummy = moveCheck(dummy, "UP", 1, false, arr, idx);
  ctoN = dummy->value - '0';
  if(ctoN == highestNum){
    return "UP";
  }
  }
  ctoN = 0;
  *torfp = 0;
  dummy = nodeMove;



  checkNull("DOWN", dummy, torfp);
  if(*torfp == 0){

  }
  else{
  dummy = moveCheck(dummy, "DOWN", 1, false, arr, idx);
  ctoN = dummy->value - '0';
  if(ctoN == highestNum){
    return "DOWN";
  }
  }
  ctoN = 0;
  *torfp = 0;
  dummy = nodeMove;




  checkNull("LEFT", dummy, torfp);
  if(*torfp == 0){

  }
  else{
  dummy = moveCheck(dummy, "LEFT", 1, false, arr, idx);
  ctoN = dummy->value - '0';
  if(ctoN == highestNum){
    return "LEFT";
  }
  }
  ctoN = 0;
  *torfp = 0;
  dummy = nodeMove;


  checkNull("RIGHT", dummy, torfp);
  if(*torfp == 0){

  }
  else{
  dummy = moveCheck(dummy, "RIGHT", 1, false, arr, idx);
  ctoN = dummy->value - '0';
  if(ctoN == highestNum){
    return "RIGHT";
  }
  }
  ctoN = 0;
  *torfp = 0;
  dummy = nodeMove;



  checkNull("UPLEFT", dummy, torfp);
  if(*torfp == 0){

  }
  else{
  dummy = moveCheck(dummy, "UPLEFT", 1, true, arr, idx);
  ctoN = dummy->value - '0';
  if(ctoN == highestNum){
    return "UPLEFT";
  }
  }
  *torfp = 0;
  ctoN = 0;
  dummy = nodeMove;



  checkNull("UPRIGHT", dummy, torfp);
  if(*torfp == 0){

  }
  else{
  dummy = moveCheck(dummy, "UPRIGHT", 1, true, arr, idx);
  ctoN = dummy->value - '0';
  if(ctoN == highestNum){
    return "UPRIGHT";
  }
  }
  *torfp = 0;
  ctoN = 0;
  dummy = nodeMove;


  checkNull("DOWNLEFT", dummy, torfp);
  if(*torfp == 0){

  }
  else{
dummy = moveCheck(dummy, "DOWNLEFT", 1, true, arr, idx);
  ctoN = dummy->value - '0';
  if(ctoN == highestNum){
    return "DOWNLEFT";
  }
  }
  *torfp = 0;
  ctoN = 0;
  dummy = nodeMove;



checkNull("DOWNRIGHT", dummy, torfp);
if(*torfp == 0){

  }
  else{
dummy = moveCheck(dummy, "DOWNRIGHT", 1, true, arr, idx);
  ctoN = dummy->value - '0';
  if(ctoN == highestNum){
    return "DOWNRIGHT";
  }
  }
  *torfp = 0;
  ctoN = 0;
  dummy = nodeMove;

  bestMove(nodeMove, arr, idx, highestNum - 1, torfp);


}

void strInterpret(char * str, int * num, char * direc){

  //function which parses the string taken as an input by the user

  int i;
  int num1;
  for(i = 0; i < 10; ++i){
    if(str[i] == ' '){
      break;
    }
    direc[i] = str[i];
  }

  direc[i] = '\0';
  num1 = str[i + 1] - '0';
  *num = num1;

  
}

void scanner(char * scanArr){
  //takes input from the user for direction and number of spaces

  printf("Which way would you like to move?\n");
  fgets(scanArr, 15, stdin); 
}

struct Grid * playerMove(struct Grid * node, char * direc, int * spaces, bool dia, char * arr, int * idx, int * torfp, char * scanArr){
  //playermove
  //dia should be false 
  // arr holds points and idx is the index.
  //scanArr is a malloc string to hold the contents from the scan.
  //takes spaces and direc 
  //check for valid space
  //if input is an invalid space then return false
  struct Grid * noSpace;
  noSpace = node;
  

  struct Grid * playerNode;
  playerNode = node;

  

  if(anySpaces(node, arr, idx, torfp) == false){
    noSpace->value = '0';
    return noSpace; 
  }

  scanner(scanArr);
  strInterpret(scanArr, spaces, direc);
  

  if(spaceCheck(node, direc, *spaces, dia, arr, idx, torfp)) {
    playerNode = move(playerNode,direc, *spaces, dia, arr, idx);
    arr[*idx] = playerNode->value;
    (*idx)++;
    return playerNode;
  }
  else{
    playerMove(node, direc, spaces, dia, arr, idx, torfp, scanArr);
  }


}

struct Grid * AiMove(struct Grid * node, bool dia, char * arr, int * idx, int * torfp){
  //AI Move 
  // checks if theres space
  //picks the best available move
  //checks if the move is aviable
  struct Grid * noSpace;
  noSpace = node;
    

  struct Grid * AI;
  AI = node;

  

  if(anySpaces(AI, arr, idx, torfp) == false){
    noSpace->value = '0';
    return noSpace; 
  }

  
  char * bestDirec = malloc(10);
  
  bestDirec = bestMove(AI, arr, idx, 3, torfp);
  printf("%s\n", bestDirec);

  if(spaceCheck(AI, bestDirec, 1, dia, arr, idx, torfp)) {
    

    AI = move(AI, bestDirec, 1, dia, arr, idx);
    arr[*idx] = AI->value;
    (*idx)++;
    return AI; 
  }
  else{
    AiMove(AI, dia, arr, idx, torfp);
  }

}



int main() {
  //first column
  //struct Grid * node, char * direc, int spaces, bool dia, char * arr, int * idx, int * torfp
  struct Grid * dummy1;
  struct Grid * dummy2;
  char c1;
  char c2;
 
  char * direcArr = malloc(sizeof(char) * (20));
  int s;
  int * spaces = &s;
  *spaces = 0;

  bool dia = false;

  char * pArray = malloc(sizeof(char) * (20));
  int indexP;
  int *idxP = &indexP;
  *idxP = 1;

  char * aArray = malloc(sizeof(char) * (20));
  int indexA;
  int *idxA = &indexA;
  *idxA = 1;

  pArray[0] = '2';
  aArray[0] = '2';


  int tf;
  int * torfp = &tf;
  *torfp = 0;

  int tfA;
  int * torfpA = &tfA;
  *torfpA = 0;

  char * scanArr = malloc(sizeof(char) * (20));
  

  struct Grid *oneOne = addNode('1');
  struct Grid *oneTwo =  addNode('1');
  struct Grid *oneThree = addNode('1');
  struct Grid *oneFour = addNode('1');
  struct Grid *oneFive = addNode('1');
  struct Grid *oneSix = addNode('1');

  //second column
  struct Grid *twoOne = addNode('1');
  struct Grid *twoTwo = addNode('2');
  struct Grid *twoThree = addNode('2');
  struct Grid *twoFour = addNode('2');
  struct Grid *twoFive = addNode('2');
  struct Grid *twoSix = addNode('1');

  //third column
  struct Grid *threeOne = addNode('1');
  struct Grid *threeTwo = addNode('2');
  struct Grid *threeThree = addNode('3');
  struct Grid *threeFour = addNode('3');
  struct Grid *threeFive = addNode('2');
  struct Grid *threeSix = addNode('1');
  //fourth column
  struct Grid *fourOne = addNode('1');
  struct Grid *fourTwo = addNode('2');
  struct Grid *fourThree = addNode('3');
  struct Grid *fourFour = addNode('3');
  struct Grid *fourFive = addNode('2');
  struct Grid *fourSix = addNode('1');
  //fifth column
  struct Grid *fiveOne = addNode('1');
  struct Grid *fiveTwo = addNode('2');
  struct Grid *fiveThree = addNode('2');
  struct Grid *fiveFour = addNode('2');
  struct Grid *fiveFive = addNode('2');
  struct Grid *fiveSix = addNode('1');
  //sixth column
  struct Grid *sixOne = addNode('1');
  struct Grid *sixTwo = addNode('1');
  struct Grid *sixThree = addNode('1');
  struct Grid *sixFour = addNode('1');
  struct Grid *sixFive = addNode('1');
  struct Grid *sixSix = addNode('1');


  createRow(oneOne,twoOne,threeOne,fourOne,fiveOne,sixOne);
  createRow(oneTwo,twoTwo,threeTwo,fourTwo,fiveTwo,sixTwo);
  createRow(oneThree,twoThree,threeThree,fourThree,fiveThree,sixThree);

  createRow(oneFour,twoFour,threeFour,fourFour,fiveFour,sixFour);
  createRow(oneFive,twoFive,threeFive,fourFive,fiveFive,sixFive);
  createRow(oneSix,twoSix,threeSix,fourSix,fiveSix,sixSix);

  createColumn(oneOne, oneTwo, oneThree, oneFour, oneFive, oneSix);
  createColumn(twoOne, twoTwo, twoThree, twoFour, twoFive, twoSix);
  createColumn(threeOne, threeTwo, threeThree, threeFour, threeFive, threeSix);

  createColumn(fourOne, fourTwo, fourThree, fourFour, fourFive, fourSix);
  createColumn(fiveOne, fiveTwo, fiveThree, fiveFour, fiveFive, fiveSix);
  createColumn(sixOne, sixTwo, sixThree, sixFour, sixFive, sixSix);

  dummy1 = twoTwo;
  c1 = dummy1->value;
  dummy2 = fiveFive;
  c2 = dummy2->value;
  int turns;

  
  //dummy2->value = c2;



  int total1 = 0;
  int total2 = 0;

  for(turns = 0; turns < 36; ++turns){
  dummy1->value = 'P';
  dummy2->value = 'A';
  printGraph(oneOne, oneTwo, oneThree, oneFour, oneFive, oneSix);
  dummy1->value = c1;

  dummy1 = playerMove(dummy1, direcArr, spaces, false, pArray, idxP, torfp, scanArr);
  c1 = dummy1->value;

  dummy1->value = 'P';
  dummy2->value = 'A';
  printGraph(oneOne, oneTwo, oneThree, oneFour, oneFive, oneSix);
  dummy2->value = c2;

  dummy2 = AiMove(dummy2, false, aArray, idxA, torfpA);
  c2 = dummy2->value;



  //printf("%s \n", pArray);
 // printf("%s \n", aArray);



  if(c1 == '0' && c2 == '0'){
    total1 = addArr(pArray, idxP);
    total2 = addArr(aArray, idxA);

    if(total1 > total2){
      printf("Player Wins!!\n");
    }
    else{
      printf("AI wins! \n");
    }
    
    printf("Player total: %i\n", total1);
    printf("AI total: %i\n", total2);
    
    break;

  }
  }

  return 0;
}
