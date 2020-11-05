#include <array>
#include <iostream>

void mvp(int n, double ** A, double * x,
         double * y)
{
  for (int i = 0; i < n; ++i)
  {
    y[i] = 0.0; 
    for (int j = 0; j < n; ++j)
    {
      y[i] += A[i][j] * x[j];
    }
  }
}

int main()
{
   // C-style array of fixed size
   {
     double x[3] = { 1.0, 1.0, 1.0 }; 
     std::cout << "sizeof x[3] : " << sizeof(x) << "\n";
     double A[3][3] = { 
       { 0.3, 0.4, 0.3 },
       { 0.7, 0.1, 0.2 },
       { 0.5, 0.5, 0.0 }
     };
   }
   // C-style array of variable size
   {
     int n = 3;
     double * x = new double[n]; 
     std::cout << "sizeof x : " << sizeof(x) << "\n";
     x[0] = 1.0;
     x[1] = 1.0;
     x[2] = 1.0;
     double ** A = new double*[n]; 
     for (int i = 0; i < n; ++i)
     {
       A[i] = new double[n];
     }
     //
     A[0][0] = 0.3;
     A[0][1] = 0.4;
     A[0][2] = 0.3;
     A[1][0] = 0.7;
     A[1][1] = 0.1;
     A[1][2] = 0.2;
     A[2][0] = 0.5;
     A[2][1] = 0.5;
     A[2][2] = 0.0;
     
     double * y = new double[n]; 
     mvp(n, A, x, y); 
     for (int i = 0; i < n; ++i)
     {
       std::cout << y[i] << "\n";
     }
     delete [] y;
     for (int i = 0; i < n; ++i)
     {
       delete [] A[i];
     }
     delete [] A;
     delete [] x;
   }
   // std::array
   {
     std::array<double, 3> x{ 1.0, 1.0, 1.0};
   }
   return 0;
}
