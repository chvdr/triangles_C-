#include <iostream>
#include <math.h>

int main()
{
	const int N=4;
	bool flag = false;

	float aStrani[N];
	float bStrani[N];
	float cStrani[N];

	float aMediani[N];
	float bMediani[N];
	float cMediani[N];

	float radiusi[N];

	for (int i = 0; i < N; i++)
	{
		float a, b, c;
		do
		{
			flag = false;

			std::cout << "Vuvedi strana a na triugulnik " << i + 1 << ": ";
			std::cin >> a;
			std::cout << "Vuvedi strana b na triugulnik " << i + 1 << ": ";
			std::cin >> b;
			std::cout << "Vuvedi strana c na triugulnik " << i + 1 << ": ";
			std::cin >> c;

			if (a <= 0 || b <= 0 || c <= 0 || (a + b) <= c || (a + c) <= b || (b + c) <= a)
			{
				std::cout << "Nesushtestvuvasht triugulnik!\n";
				flag = true;
			}			
		} while (flag);

		aStrani[i] = a;
		bStrani[i] = b;
		cStrani[i] = c;

		aMediani[i] = (sqrt((2 * c*c) + (2 * b*b) - (a*a))) / 2;
		bMediani[i] = (sqrt((2 * c*c) + (2 * a*a) - (b*b))) / 2;
		cMediani[i] = (sqrt((2 * b*b) + (2 * a*a) - (c*c))) / 2;

		float p = (a + b + c) / 2;
		float S = sqrt(p*(p - a)*(p - b)*(p - c));
		float r = S / p;

		radiusi[i] = r;
	}

	for (int j = 0; j < N; j++)
	{
		std::cout << "Triugulnik " << j+1 << ": a=" << aStrani[j] << ", b=" << bStrani[j] << ", c=" << cStrani[j] << "\n";
		std::cout << "Ma=" << aMediani[j] << ", Mb=" << bMediani[j] << ", Mc=" << cMediani[j] << "\n";
		std::cout << "r=" << radiusi[j] << "\n";
	}


	float sredenRadius = 0;
	for (int k = 0; k < N; k++)
	{
		sredenRadius += radiusi[k];
	}

	sredenRadius = sredenRadius / N;

	int poMalki = 0;
	int poGolemi = 0;

	for (int k = 0; k < N; k++)
	{
		if (radiusi[k] < sredenRadius)
			poMalki++;
	}
	
	poGolemi = N - poMalki;

	std::cout << poMalki << " triugulnik(a) s po-maluk radius i " << poGolemi << " triugulnik(a) s po-golqm radius ot sr.aritm=" << sredenRadius << "\n";

	system("pause");
    return 0;
}



