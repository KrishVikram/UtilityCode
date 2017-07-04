// Number_Utils.cpp : Defines the entry point for the console application.
//

//Purpose: 1. Tells whether a entered number is a prime or not
	  // 2. If not, lists out all its factors and in addition
	  // 3. Gives the next closest prime to the entered number
// Might come handy when designing a Hash function to choose a prime according to the size of the input that you are working with.

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	unsigned long n;
	bool bisprime = true;
	std::vector<int> factors;
	std::cout << "Enter number:" << endl;
	cin >> n;
	if (n == 0 || n == 1) 
	{ 
		cout << "Next Biggest prime is: " << 2 <<endl; 
	}
	
	if (n == 2) { cout << "No is Prime by itself"; }

	for (int i = 2; i <= n / 2; i++)
	{
		if (n % i == 0)
		{
			bisprime = false;
			factors.push_back(i);
		}
	}
	if (bisprime)
	{
		cout << "No is Prime by itself";
		return 0;
	}
	else
	{
		cout << "Factors of the given number: " << endl;
		std::vector<int>::iterator it;
		for (it = factors.begin(); it != factors.end(); it++) 
		{
			cout << *it << " " << endl; 
		}
		cout << '\n';
		cout << "No of Factors: " << factors.size() << endl;
		while (!bisprime)
		{
			n = n + 1;
			for (int i = 2; i <= n / 2; i++)
			{
				if (n % i == 0)
				{
					bisprime = false;
				}
				else
				{
					bisprime = true;
				}
			}
			
		}
		cout << "Next Biggest prime is: " << n << endl;
		return 0;
	}
}
	
