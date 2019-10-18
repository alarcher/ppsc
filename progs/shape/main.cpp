#include <iostream>

class Shape
{
	public :
		// Constructor
		Shape ( size_t i) : N_(i), X_(new double [2*i])
	{
	}
		// Destructor
		~Shape ()
		{
			delete [] X_;
		}
		//
		size_t num_vertices () { return N_; }
		double * x( size_t i ) { return X_ + 2 * i; }
		//virtual double length () = 0;
		//virtual double area () = 0;
		void info()
		{
			std::cout << "List of coordinates\n";
			for (int i = 0; i < N_; ++i)
			{
				std::cout << x(i)[0] << "\t";	
				std::cout << x(i)[1] << "\n";	
			}	
		}
	private :
		size_t N_;
		double * X_;
};

int main()
{
	size_t N = 1;
	Shape * S = new Shape(N);
	std::cout << "Shape with " << N << " vertices.\n";
	for (int i = 0; i < N; ++i)
	{
		std::cout << "Coord " << i << ":\n";
		std::cin >> S->x(i)[0];	
		std::cin >> S->x(i)[1];	
	}	
	S->info();
	delete S;
	return 0;
}
