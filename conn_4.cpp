#include<iostream>
#include<windows.h>

using namespace std;

char conn_4[7][6];
int counter[7] = { 0 };
void print() {
	system("color 06");
	cout << "\t\t\t************************* CONNECT 4 GAME **************************\n\n\n";
	for (int i = 5; i >=0; i--)
	{
	cout << endl << "\t\t\t\t\t  |   +   +   +   +   +   +   |\n";
		cout << "\t\t\t\t\t"  << "  |";
		for (int j = 0; j < 7; j++) {
			char x = ' ';
			if (conn_4[j][i]=='X' or conn_4[j][i] == 'O')
			{
				x = conn_4[j][i];
			}
			cout  <<" "<< x << " |";
		}
	}
		cout << endl << "\t\t\t\t\t   ___________________________";
		cout << endl << "\t\t\t\t\t  |_1_|_2_|_3_|_4_|_5_|_6_|_7_|";
}
bool is_win(int x) {
	int win = 0;
	bool iswin = 0;
	for (int i = 0; i < counter[x] - 1; i++)
	{
		if (conn_4[x][i] == conn_4[x][i + 1] && (conn_4[x][i] == 'X' or conn_4[x][i]=='O'))
		{
			++win;
		}
		else
		{
			win = 0;
		}
		if (win == 3)
		{
			iswin = 1;
			break;
		}

	}

	win = 0;
	if (!iswin) {
		for (int i = 0; i < 6; i++)
		{
			if (conn_4[i][counter[x] - 1] == conn_4[i + 1][counter[x] - 1] && (conn_4[i][counter[x] - 1] == 'X' or conn_4[i][counter[x] - 1] == 'O'))
			{
				win++;
			}
			else
			{
				win = 0;
			}


			if (win == 3)
			{
				iswin = 1;
				break;
			}

		}
		if (!iswin)
		{

		win = 0;
		int x_a = 0, y_a = 0;
		if (x > counter[x]-1)
		{
			x_a = x - (counter[x]-1);
		}
		else
			y_a = (counter[x]-1) - x;
		while (x_a < 6 && y_a < 5)
		{
			if (conn_4[x_a][y_a] == conn_4[x_a + 1][y_a + 1] && (conn_4[x_a][y_a] == 'X' or conn_4[x_a][y_a] == 'O'))
			{
				win++;
			}
			else
			{
				win = 0;
			}


			if (win == 3)
			{
				
				iswin = 1;
				break;
			}
			x_a++; y_a++;
		}

		}
	}
	return iswin;
};
bool is_end() {
	int co = 0;

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 6; j++) {
			if (!(conn_4[i][j] == 'X' || conn_4[i][j] == 'O'))
			{
				return 0;
				break;
			}
			else
			{
				co++;
			}

		}
	}
	if (co == (6 * 7))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main() {
	int x = 1, y = 1; char c = 'X';
	print();
	while (true)
	{
		if (is_end())
		{
			system("color 04");
			cout << "\n\n\t\t\tNO ONE WON \n";
			break;
		}
		cout << "\n\n\t\t\t\t\tselect the x coulmn form 1 to 7 ::", cin >> x;
		if (0 < x && x <= 7)
		{
			x--;
			if (counter[x] < 6) {

				conn_4[x][counter[x]] = c;
				if (c == 'X')
				{
					c = 'O';
				}
				else
				{
					c = 'X';
				}
				counter[x]++;
			}
			else
			{
				cout << "this coulmn is full\n";
				system("color 04");

				if (is_end())
				{
					break;
				}
				continue;
			}
		}
		else
		{

			system("color 04");
			cout << "\n\n\t\t\t\t\tinsert a valid column please :/\n";
			continue;
		}
		system("CLS");
		print();
		if (is_win(x))
		{
			system("color 0A");
			cout << "\n\n\n\t\tWINNER IS :: " << conn_4[x][counter[x] - 1] << endl;
			break;
		}
	}
	system("pause");
}