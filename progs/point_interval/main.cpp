#include <iostream>
#include <cmath>

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
		virtual double length () = 0;
		virtual double area () = 0;
		void info()
		{
			std::cout << "List of coordinates\n";
			for (int i = 0; i < N_; ++i)
			{
				std::cout << x(i)[0] << "\t";	
				std::cout << x(i)[1] << "\n";	
			}	
			std::cout << "Length = " << this->length() << "\n";
			std::cout << "Area   = " << this->area() << "\n";
		}
	private :
		size_t N_;
		double * X_;
};

class Point : public Shape
{
	public:
	  Point() : Shape(1) {}

		double length () { return 0.0; }
		double area () { return 0.0;}
};

class Interval : public Shape
{
	public:
	  Interval() : Shape(2) {}

		double length ()
		{
			double n = (x(1)[0] - x(0)[0])*(x(1)[0] - x(0)[0])
               + (x(1)[1] - x(0)[1])*(x(1)[1] - x(0)[1]);
			return std::sqrt(n);
		}
		double area () { return 0.0;}
};

int main(int argc, char**argv)
{
	Shape * S = nullptr;
	size_t N = atoi(argv[1]);
  switch(N)
	{
		case 1: S = new Point(); break;
		case 2: S = new Interval(); break;
		default:
			std::cout << "Unknown shape\n";
  }
	if (S == nullptr) return 1;

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
