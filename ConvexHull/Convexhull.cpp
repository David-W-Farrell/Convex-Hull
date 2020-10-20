// David Farrell
#include <iostream>
#include <vector>
using namespace std;
#include "Cilli.h"

//stores 2 points

struct Point {
   double xx, yy;
   Point(double x, double y) : xx(x), yy(y) {}
};

//returns the slope between 2 given points

double slope(Point &A, Point&B) 
{
   return (A.yy - B.yy) / (A.xx-B.xx);
}	   

ostream & operator<<( ostream & out, const Point & P) 
{
   out << "(" << P.xx << "," << P.yy << ")";
   return out;
}

void getHull(vector<Point> list )
{
   
   Cilli C;

   //following 2 lines inserts indexes 0 and 1 into the list

   C.insertItem( 0 ); 
   C.insertItem( 1);
   int temp = 0;
   const int resetTemp = 0;
   
   for(unsigned int adder=2; adder<list.size(); adder++) 
   {

      int start = C.getValAtHandle( ); 
      int S=start;
      int L=start;
      
      temp = resetTemp; //resets temp to 0
      temp = C.getValAtHandle(); //resets value of temp to the handle val

      /*

         loops through the list by moving the handle forward until the handle is 
         at the original value of the handle stored by the temp variable

      */

      do{

         C.moveHandleForward(); //moves the handle forward in the list

            //if the slope is bigger it enters this if statement and sets S to the index at handle

         if(slope(list[C.getValAtHandle()], list[adder]) < slope(list[S], list[adder])){

            S = C.getValAtHandle();

         }

      } while(temp != C.getValAtHandle());

      temp = resetTemp; //sets temp to 0

      temp = C.getValAtHandle(); // sets temp to the value at handle

      /*

         loops through the list by moving the handle forward until the handle is 
         at the original value of the handle stored by the temp variable

      */
   
      do{
         
         C.moveHandleForward(); //moves handle forward in the list

         //if the slope is bigger it enters this if statement and sets L to the index at handle

         if(slope(list[C.getValAtHandle()], list[adder]) > slope(list[L], list[adder])){

            L = C.getValAtHandle();

         }
        
      } while(temp != C.getValAtHandle());

      // loop sets the handle to the index value of L
      
      do{

         C.moveHandleForward();

      } while(C.getValAtHandle() != L);


      // deletes nodes between L node and S node 

      do{

         C.moveHandleBack(); //moves handle back in the list

         //if the handle isnt at S, deletes the node

         if(C.getValAtHandle() != S){
          
            C.deleteItem();
         
         }
            
      }while(S != C.getValAtHandle());

      //inserts index of adder into the list

      C.insertItem( adder );

      C.dumpForwards( );
      //cout << adder << ", " << "S= " << S << " - L= " << L << endl;
   }
  
   //moves the handle back, sets temp to the handles value and prints the points in a do while loop

   C.moveHandleBack();

   temp = resetTemp; //resets temp to 0
   temp = C.getValAtHandle(); //sets temp to the value at the handle

   //loops through the contents of the list, and prints the points associated with the given index

   do{

      C.moveHandleForward(); //moves handle forwards
      
      //prints the points in format

      cout << "(" << list[C.getValAtHandle()].xx << "," << list[C.getValAtHandle()].yy << ")";
      cout << "   ";

   }while(temp != C.getValAtHandle());
   cout << endl;

}

int main()
{
   
   int N;
   cin >> N;
   int x,y;
   vector<Point> list;
   for(int i=0; i<N; i++) {


      cin >> x >> y;
          
      list.emplace_back(x,y);
     

   } 
   getHull(list); 

}
