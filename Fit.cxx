
#include "FitsUtils.h"
#include "ModelUtils.h"




int main()
{


     //CCfits::FITS::setVerboseMode(true);

     try
     {
        vector <xypoint> orders;
        orders = ReadFits("HIP_10670_fixed.fits");
        cout<<"There are "<<orders.size()<<" orders found!"<<endl;
     }
     
     catch (CCfits::FitsException&) 
     // will catch all exceptions thrown by CCfits, including errors
     // found by cfitsio (status != 0). 
     {             
        cerr << " Fits Exception Thrown by test function \n";       
     }
    return 0;
}



