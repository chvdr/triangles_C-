#include <iostream> 
#include <cmath>
using namespace std;

// Function declaration						// Return value / explanations / notes
double pp(double xx, double yy, double zz);	// half perimeter
double s(double x, double y, double z);		// surface area of the triangle
double r(double u, double v, double w);		// radius of circle, inside of triangle
double ma(double x, double y, double z);	// median to intercept a
double mb(double x, double y, double z);	// median to intercept b
double mc(double x, double y, double z);	// median to intercept c
bool triangle_exists(double x, double y, double z);	//Check if such triangle (with fences a, b, c) exists

// ------------------------ Main ----------------------------
int main()
{
	// Setting up the value of N (N<25) - number of triangles. 
	int N=0;
	while ((N<=0)||(N>=25))
	{
		cout << "Number of triangles to be observed. Type 0 to exit. N="; cin >> N;
		if (N == 0) {
			cout << "Program aborted by user. Exiting. ";
			return 100;
		}
	};
	int i=0;
	double triangleset[N][7];
	for (i=1; i<=N; i++)
	{
		cout << "a="; double a; cin >> a; triangleset[i][0]=a;
		cout << "b="; double b; cin >> b; triangleset[i][1]=b;
		cout << "c="; double c; cin >> c; triangleset[i][2]=c;
		// TO DO: Check if such triangle (with fences a, b, c) exists?
		if (not(triangle_exists(a,b,c)))
		{
			cout << "Such triangle not exists. Exiting. ";
			return 200; 
		} // Othrwise, the triangle exists and we can proceed further. 
		triangleset[i][3]=ma(a,b,c);
		triangleset[i][4]=mb(a,b,c);
		triangleset[i][5]=mc(a,b,c);
		triangleset[i][6]=r(a,b,c);
	};
	double sum=0;
	for (i=1; i<=N; i++)
		sum += triangleset[i][6];

	double r_average=sum/N;

        cout << "######################## Average=" << r_average;

	int j=0;

	for (i=1; i<=N; i++)
	{
		if (triangleset[i][6]<=r_average)
			j++;
	};
	cout << "There are " << j << " triangles w. radius, smaller or equal to average value. ";

	j=0;
	for (i=1; i<=N; i++)
	{
		if (r_average < triangleset[i][6])
			j++;
	};
	cout << "There are " << j << " triangles w. radius, LARGER than average value. ";

	// this is only a break before the program exits:
        char a;
        cout << "Program finished. Press <Enter> key TWICE to exit program: "
        cin >> a;

	return 0;			// exit code 0 means OK 

} // End of main
// ------------------------ Main ----------------------------


double pp(double xx, double yy, double zz)
{
	return (xx+yy+zz)/2;
}

double s(double x, double y, double z)
{
	double p=pp(x,y,z);		// p contains a half of parameter
	double ss=p*(p-x)*(p-y)*(p-z);
	return sqrt(ss);
}

double r(double u, double v, double w)
{
	return s(u,v,w)/pp(u,v,w);
}

double ma(double x, double y, double z)
{
	double temp=sqrt(2*(y*y+z*z)-x*x);
	return temp;
}

double mb(double x, double y, double z)
{
	double temp=(2*(x*x+z*z)-y*y);
	return temp;
}

double mc(double x, double y, double z)
{
	double temp=(2*(x*x+y*y)-z*z);
	return temp;
}

bool triangle_exists(double x, double y, double z)
{
	bool a,b,c;
	a=(z+y>x); b=(x+z>y); c=(x+y>z);
	// return value: triangle w. x, y, z exists
	return (a&&b&&c);
}

