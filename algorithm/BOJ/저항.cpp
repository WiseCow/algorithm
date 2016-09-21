//https://www.acmicpc.net/problem/1076
#include<iostream>
using namespace std;

int main()
{
	long long result = 0;
	for (int i = 0; i < 3; i++)
	{
		char input[50];
		cin >> input;
		if (i == 0)
		{
			switch (input[0])
			{
			case 'b':
				switch (input[1])
				{
				case 'l':
					switch (input[2])
					{
					case 'a':
						break;
					case 'u':
						result += 60;
						break;
					}
					break;
				case 'r':
					result += 10;
					break;
				}
				break;
			case 'r':
				result += 20;
				break;
			case 'o':
				result += 30;
				break;
			case 'y':
				result += 40;
				break;
			case 'g':
				switch (input[3])
				{
				case 'e':
					result += 50;
					break;
				case 'y':
					result += 80;
					break;
				}
				break;
			case 'v':
				result += 70;
				break;
			case 'w':
				result += 90;
				break;
			}
		}
		else if (i == 1)
		{
			switch (input[0])
			{
			case 'b':
				switch (input[1])
				{
				case 'l':
					switch (input[2])
					{
					case 'a':
						break;
					case 'u':
						result += 6;
						break;
					}
					break;
				case 'r':
					result += 1;
					break;
				}
				break;
			case 'r':
				result += 2;
				break;
			case 'o':
				result += 3;
				break;
			case 'y':
				result += 4;
				break;
			case 'g':
				switch (input[3])
				{
				case 'e':
					result += 5;
					break;
				case 'y':
					result += 8;
					break;
				}
				break;
			case 'v':
				result += 7;
				break;
			case 'w':
				result += 9;
				break;
			}
		}
		else if (i == 2)
		{
			switch (input[0])
			{
			case 'b':
				switch (input[1])
				{
				case 'l':
					switch (input[2])
					{
					case 'a':
						break;
					case 'u':
						result *= 1000000;
						break;
					}
					break;
				case 'r':
					result *= 10;
					break;
				}
				break;
			case 'r':
				result *= 100;
				break;
			case 'o':
				result *= 1000;
				break;
			case 'y':
				result *= 10000;
				break;
			case 'g':
				switch (input[3])
				{
				case 'e':
					result *= 100000;
					break;
				case 'y':
					result *= 100000000;
					break;
				}
				break;
			case 'v':
				result *= 10000000;
				break;
			case 'w':
				result *= 1000000000;
				break;
			}

		}
	}

	cout << result << endl;
}