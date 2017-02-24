#include <iostream>

using namespace std;


int main()
{
    int full=0;
    int semi=0;
    int rad;
    int in ;
    while (1)
    {
        cin >> in;
        if (cin.eof())
            break;
        full=0;
        semi=0;
        rad=(2*in)-1;
        for (int i=in;i>0;i--)
        {
            for (int j=in;j>0;j--)
            {
               
                if ((4*(i*i+j*j)<=rad*rad) && (4*((i-1)*(i-1)+(j-1)*(j-1))<rad*rad))
                {
                   full++;
                   continue;
                }    
                else if ((4*(i*i+j*j)>rad*rad) && (4*((i-1)*(i-1)+(j-1)*(j-1))<rad*rad))
                {
                    semi++;
                    continue;
                }    
            }
       }
       cout << "In the case n = " << in << ", " << 4*semi << " cells contain segments of the circle." << endl;
       cout << "There are " << 4*full << " cells completely contained in the circle." << endl << endl ;

   }
   return 0;
}               
        
        
