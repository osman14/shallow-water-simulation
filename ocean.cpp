# include <fstream>
# include<stdlib.h>
# include <iostream>
using namespace std ;

float g = 9.81; 


class grid
{
    private:
    float dx, dy, x, y, dt, t, h; 
    
    
    public:
     //** Constructor**//
       grid(){}
         grid( float grid_x,float grid_y,float x_long,float y_long,float grid_time,float time,float depth)
         {
               dx=grid_x;
                dy=grid_y;
                x=x_long;
                y=y_long;
                dt=grid_time;
                t=time;
                h=depth;
         }
    /////////////////////////////////////////

    float setDepth(float depth)
    {
        h=depth;
      
    }
    float set(float grid_x,float grid_y,float grid_time,float time)
    {
        dx=grid_x;
        dy=grid_y;
        dt=grid_time;
        t=time;
    }
    void show()
    {
        cout << "The grid spacing in X direction =  "<< dx<< endl;
        cout << "The grid spacing in Y direction =   "<< dy<<endl;
        cout << "The time interval =  " << dt << endl;
        cout << "The simulation will run for  "<< t <<" seconds"<< endl;
        cout << "The depthis  "<< h <<" meters"<< endl;
    }







};




int main ()
{
   
  //***Reade data  from txt file***// 
    float grid_x, grid_y, x_long, y_long, grid_time, time, depth;
    depth = 10.0 ;
    x_long=500.0;
    y_long=500.0;

 
        ifstream param;
        param.open ( "param.txt" );
        if (param.fail())
        {
            cerr<<"Something go wrong during file opening! "<< endl;
            exit(1);
        }
        
    param >> grid_x >> grid_y >> grid_time >>time ;
///////////////////////////////////////////////////////////////////////////

    grid gr(grid_x, grid_y, x_long, y_long, grid_time, time, depth);
    gr.set( grid_x, grid_y, grid_time, time);
    gr.setDepth(depth);
    gr.show();
    







}