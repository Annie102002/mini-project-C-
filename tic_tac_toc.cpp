#include<iostream>
 using namespace std;
 char b[3][3]={ {'1','2','3'} ,{'4','5','6'},{'7','8','9'}};
  char turn = 'x'; 
  int row,col;  
  bool draw=false; 
 void display_board()
 {  system("cls");
   cout<<"\t"<<" T I C K C R O S S  G A M E"<<endl;
   cout<<"player1[x]"<<"\n"<<"player2[o]"<<endl;

   cout<<"     |     |     "<<endl;
   cout<<"   "<<b[0][0]<<" |"<<"   "<<b[0][1]<< " |"<<"   "<<b[0][2]<<"  "<<endl;
   cout<<"_____|_____|_____"<<endl;

   cout<<"     |     |     "<<endl;
   cout<<"   "<<b[1][0]<<" |"<<"   "<<b[1][1]<< " |"<<"   "<<b[1][2]<<"  "<<endl;
   cout<<"_____|_____|_____"<<endl;
  
   cout<<"     |     |     "<<endl;
   cout<<"   "<<b[2][0]<<" |"<<"   "<<b[2][1]<< " |"<<"   "<<b[2][2]<<"  "<<endl;
   cout<<"     |     |     "<<endl;
 }
 void player()
 { int choice;
   if(turn=='x')
    cout<<"player1[x] turn :"<<endl;
    else if(turn=='o')
     cout<<"player2[o] turn:"<<endl;
    cin>>choice;
    switch(choice)
     { case 1: row=0 ;col=0;break;
       case 2: row=0 ;col=1;break;
       case 3: row=0 ;col=2;break;
       case 4: row=1 ;col=0;break;
       case 5: row=1 ;col=1;break;
       case 6: row=1 ;col=2;break;
       case 7: row=2 ;col=0;break;
       case 8: row=2 ;col=1;break;
       case 9: row=2 ;col=2;break;
       default:
           cout<<"wrong choice";
              break;
     }
     if(turn=='x' && b[row][col]!='x'&&  b[row][col]!='o')
     {
      b[row][col]='x';
      turn= 'o';
     }
     else if(turn=='o'&& b[row][col]!='x'&&  b[row][col]!='o')
      {
        b[row][col]='o';
        turn ='x';
      }
      else{
        cout<<"box filles alraedy\n\n try again";
         player();
      }
      display_board();
 }
 bool gameover()
 { 
  for(int i=0;i<3;i++)
    {
        if(b[i][0]==b[i][1] &&b[i][0]==b[i][2]||b[0][i]==b[1][i] &&b[0][i]==b[2][0])
          return false;
      
       }
       if(b[0][0]==b[1][1]&&b[0][0]==b[2][2] ||b[2][0]==b[1][1]&&b[2][0]==b[0][2])
         return false;

       for(int i=0;i<3;i++)
       for(int j=0;j<3;j++)
         if(b[i][j] !='x' && b[i][j]!='o')
            return true;
      draw=true;
      return false;      
   
 }
  int main()
{  while(gameover()){
      display_board();
       player();
       gameover();
}
     if(turn =='o' && draw==false)
        cout<<"player1[x] win";
    else if(turn =='x'&& draw==false) 
        cout<<"player2[o] win";
        else 
        cout<<"game draw";
   return 0;
    }