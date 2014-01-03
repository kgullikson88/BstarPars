#ifndef FITSUTILS_H
#define FITSUTILS_H

#include <CCfits/CCfits>
#include <cmath>
#include <vector>
#include <string>

using namespace std;


struct xypoint
{
    vector<double> x;
    vector<double> y;
    vector<double> cont;
    vector<double> err;
};



/*
  This function will read an fits file with my format,
    and return a vector of xypoints (one for each order).
*/
vector <xypoint> ReadFits(char* fname)
 {
     vector<string> hdus(999);
     vector<xypoint> orders;
     int i=0;

     // Open the file
     auto_ptr<CCfits::FITS> pInfile(new CCfits::FITS(fname,CCfits::Read,true));
     
     CCfits::ExtHDU& table = pInfile->extension(1);

     //Begin reading data
     bool done = false;
     while (!done)
     {
       // Open the given extension
       try
       {
         table = pInfile->extension(i+1);
       }
       catch (CCfits::FITS::NoSuchHDU &)
       {
         break;
       }
         
       // Get the best number of rows to read at once
       int rowsize = table.getRowsize();

       // Make an xypoint instance
       xypoint order;

       // Read in the appropriate columns to 'order'
       table.column("wavelength").read(order.x, 0, rowsize);
       table.column("flux").read(order.y, 0, rowsize);
       table.column("continuum").read(order.cont, 0, rowsize);
       table.column("error").read(order.err, 0, rowsize);
       //for (size_t j=0; j<order.x.size(); ++j)
       //{
       //  cout<<order.x[j]<<"\t"<<order.y[j]<<"\t"<<order.cont[j]<<endl;
       //}
       //cout<<"\n\n\n"<<endl;

       orders.push_back(order);
       
       i++;
     }
     return orders;
}



#endif
