#include <iostream>
#include <cmath>
using namespace std;

// Function declaration                         // Stoinost, opisanie i poiasnenia
double pp(double xx, double yy, double zz);     // poluperimeter
double s(double x, double y, double z);         // liceto na triugulnika
double r(double u, double v, double w);         // radius na vpisanata okrujnost
double ma(double x, double y, double z);        // medianata na a
double mb(double x, double y, double z);        // medianata na b
double mc(double x, double y, double z);        // medianata na c
bool triangle_exists(double x, double y, double z);     // Sushtestwuwa li triugulnik sus strani a,b,c?

// ------------------------ Main ----------------------------
int main()
{
        // Utochniawane na broia na triugulnicite N: (N<25)
        int N=0;
        while ((N<=0)||(N>=25))
        {
                cout << "Broi triugulnici, 0 za izhod/otkaz. N="; cin >> N;
                if (N == 0) {
                        cout << "Programata e prkusnata. Izlizane. ";
                        return 100;
                }
        }

        int i=0;
        double triangleset [N][7];
        for (i=1; i<=N; i++)
        {
                cout << "a="; double a; cin >> a; triangleset[i][0]=a;
                cout << "b="; double b; cin >> b; triangleset[i][1]=b;
                cout << "c="; double c; cin >> c; triangleset[i][2]=c;
                // Prowerka dali sushtestwuwa triugulnik sus strani a, b, c
                if (not(triangle_exists(a,b,c)))
                {
                        cout << "Triugulnik s vuvedenite strani ne sushtestwuwa. Izlizane ot programata. ";
                        return 200;
                } 
                triangleset[i][3]=ma(a,b,c);
                triangleset[i][4]=mb(a,b,c);
                triangleset[i][5]=mc(a,b,c);
                triangleset[i][6]=r(a,b,c);
        }
        double sum=0;
        for (i=1; i<=N; i++)
                sum += triangleset[i][6];

        double r_average=sum/N;

        cout << "{R_sredno_aritmetichno}=" << r_average;

        int j=0;

        for (i=1; i<=N; i++)
        {
            if (triangleset[i][6]<=r_average)
                j++;
        }
        cout << "Imame " << j << " triugulnici s radius, nenadminavasht srednia. ";

        cout << "Imame " << N-j << " triugulnici s radius, PO-GOLIAM ot srednia.  ";

	char a; 
	cout << "Gotowo!. Natisni <Enter> DWA PYTI za izlizane: "
	cin >> a;

        return 0;                       // exit code 0 means OK

} // End of main
// ------------------------ Main ----------------------------


// poluperimeter
double pp(double xx, double yy, double zz)
{
        return (xx+yy+zz)/2;
}

// S --> Liceto 
double s(double x, double y, double z)
{
        double p=pp(x,y,z);             // p - POLUperimetur
        double ss=p*(p-x)*(p-y)*(p-z);
        return sqrt(ss);
}

// radius na VPISANATA okrujnost
double r(double u, double v, double w)
{
        return s(u,v,w)/pp(u,v,w);
}

double ma(double x, double y, double z)
{
        double temp=sqrt(2*(y*y+z*z)-x*x)/2;
        return temp;
}

double mb(double x, double y, double z)
{
        double temp=(2*(x*x+z*z)-y*y)/2;
        return temp;
}

double mc(double x, double y, double z)
{
        double temp=(2*(x*x+y*y)-z*z)/2;
        return temp;
}

bool triangle_exists(double x, double y, double z)
{
        bool a,b,c;
        a=(z+y>x); b=(x+z>y); c=(x+y>z);
        return (a&&b&&c);
}


