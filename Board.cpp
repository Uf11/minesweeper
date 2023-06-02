#include "Board.h"
Board::Board(int s)
{
	size = s;
	map = new Cell * [size];
	displaym = new Cell * [size];
	for (int i = 0; i < size; i++)
	{
		map[i] = new Cell[size];
		displaym[i] = new Cell[size];
		for (int j = 0; j < size; j++)
		{
			map[i][j].setsymbol('0');
			displaym[i][j].setsymbol('0');
		}
	}
}
void Board::copy()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (map[i][j].getopened() == true)
			{
				displaym[i][j].setsymbol(map[i][j].getsymbol());
			}
		}
	}
}
void Board::minegenerator()
{
	srand((unsigned int)time(NULL));
	int indexr = 0;
	int indexc = 0;
	int mine = 0;
	while (mine < size)
	{
		indexc = rand() % size;
		indexr = rand() % size;
		if (map[indexr][indexc].getsymbol() != 'M')
		{
			map[indexr][indexc].setsymbol('M');
			mine++;
		}
	}
}
void Board::printboard()
{
	/*cout << "  ";
	for (int i = 0; i < size; i++)
	{
		cout << i << " ";
	}
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << i << " ";
		for (int j = 0; j < size; j++)
		{
			map[i][j].printcell();
			cout << " ";
		}
		cout << endl;
	}*/
	cout << endl;
	cout << "x ";
	for (int i = 0; i < size; i++)
	{
		cout <<i << " ";
	}
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout <<i << " ";
		for (int j = 0; j < size; j++)
		{
			displaym[i][j].printcell();
			cout << " ";
		}
		cout << endl;
	}
}
int Board::getsize() const
{
	return size;
}
void Board::numbergenerator()
{
	char a;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (map[i][j].getsymbol() == 'M')
			{
				if (i == 0 && j == 0) {
					a = map[i][j + 1].getsymbol();
					if (a != 'M')
					{
						a++;
						map[i][j + 1].setsymbol(a);
					}
					a = map[i + 1][j].getsymbol();
					if (a != 'M')
					{
						a++;
						map[i + 1][j].setsymbol(a);
					}
					a = map[i + 1][j + 1].getsymbol();
					if (a != 'M')
					{
						a++;
						map[i + 1][j + 1].setsymbol(a);
					}
				}
				else if (i == 0 && j == size - 1)
				{
					a = map[i][j - 1].getsymbol();
					if (a != 'M')
					{
						a++;
						map[i][j - 1].setsymbol(a);
					}
					a = map[i + 1][j].getsymbol();
					if (a != 'M')
					{
						a++;
						map[i + 1][j].setsymbol(a);
					}
					a = map[i + 1][j - 1].getsymbol();
					if (a != 'M')
					{
						a++;
						map[i + 1][j - 1].setsymbol(a);
					}
				}
				else if (i == size - 1 && j == 0)
				{
					a = map[i][j + 1].getsymbol();
					if (a != 'M')
					{
						a++;
						map[i][j + 1].setsymbol(a);
					}
					a = map[i - 1][j + 1].getsymbol();
					if (a != 'M')
					{
						a++;
						map[i - 1][j + 1].setsymbol(a);
					}
					a = map[i - 1][j].getsymbol();
					if (a != 'M')
					{
						a++;
						map[i - 1][j].setsymbol(a);
					}

				}
				else if (i == size - 1 && j == size - 1)
				{
					a = map[i][j - 1].getsymbol();
					if (a != 'M')
					{
						a++;
						map[i][j - 1].setsymbol(a);
					}
					a = map[i - 1][j - 1].getsymbol();
					if (a != 'M')
					{
						a++;
						map[i - 1][j - 1].setsymbol(a);
					}

					a = map[i - 1][j].getsymbol();
					if (a != 'M')
					{
						a++;
						map[i - 1][j].setsymbol(a);
					}
				}
				else if (i == 0 && j > 0 && j < size)
				{
					a = map[i][j - 1].getsymbol();
					if (a != 'M')
					{
						a++;
						map[i][j - 1].setsymbol(a);
					}
					a = map[i + 1][j].getsymbol();
					if (a != 'M')
					{
						a++;
						map[i + 1][j].setsymbol(a);
					}
					a = map[i][j + 1].getsymbol();
					if (a != 'M')
					{
						a++;
						map[i][j + 1].setsymbol(a);
					}
					a = map[i + 1][j + 1].getsymbol();
					if (a != 'M')
					{
						a++;
						map[i + 1][j + 1].setsymbol(a);
					}
					a = map[i + 1][j - 1].getsymbol();
					if (a != 'M')
					{
						a++;
						map[i + 1][j - 1].setsymbol(a);
					}
				}
				else if (i == size - 1 && j > 0 && j < size)
				{
					a = map[i - 1][j].getsymbol();
					if (a != 'M')
					{
						a++;
						map[i - 1][j].setsymbol(a);
					}
					a = map[i][j - 1].getsymbol();
					if (a != 'M')
					{
						a++;
						map[i][j - 1].setsymbol(a);
					}
					a = map[i][j + 1].getsymbol();
					if (a != 'M')
					{
						a++;
						map[i][j + 1].setsymbol(a);
					}
					a = map[i - 1][j - 1].getsymbol();
					if (a != 'M')
					{
						a++;
						map[i - 1][j - 1].setsymbol(a);
					}
					a = map[i - 1][j + 1].getsymbol();
					if (a != 'M')
					{
						a++;
						map[i - 1][j + 1].setsymbol(a);
					}
				}
				else if (j == size - 1 && i > 0 && i < size)
				{
					a = map[i - 1][j].getsymbol();
					if (a != 'M')
					{
						a++;
						map[i - 1][j].setsymbol(a);
					}
					a = map[i + 1][j].getsymbol();
					if (a != 'M')
					{
						a++;
						map[i + 1][j].setsymbol(a);
					}
					a = map[i][j - 1].getsymbol();
					if (a != 'M')
					{
						a++;
						map[i][j - 1].setsymbol(a);
					}
					a = map[i - 1][j - 1].getsymbol();
					if (a != 'M')
					{
						a++;
						map[i - 1][j - 1].setsymbol(a);
					}
					a = map[i + 1][j - 1].getsymbol();
					if (a != 'M')
					{
						a++;
						map[i + 1][j - 1].setsymbol(a);
					}
				}
				else if (j == 0 && i > 0 && i < size)
				{
					a = map[i - 1][j].getsymbol();
					if (a != 'M')
					{
						a++;
						map[i - 1][j].setsymbol(a);
					}
					a = map[i + 1][j].getsymbol();
					if (a != 'M')
					{
						a++;
						map[i + 1][j].setsymbol(a);
					}
					a = map[i][j + 1].getsymbol();
					if (a != 'M')
					{
						a++;
						map[i][j + 1].setsymbol(a);
					}
					a = map[i - 1][j + 1].getsymbol();
					if (a != 'M')
					{
						a++;
						map[i - 1][j + 1].setsymbol(a);
					}
					a = map[i + 1][j + 1].getsymbol();
					if (a != 'M')
					{
						a++;
						map[i + 1][j + 1].setsymbol(a);
					}
				}
				else
				{
					a = map[i - 1][j - 1].getsymbol();
					if (a != 'M')
					{
						a++;
						map[i - 1][j - 1].setsymbol(a);
					}
					a = map[i - 1][j + 1].getsymbol();
					if (a != 'M')
					{
						a++;
						map[i - 1][j + 1].setsymbol(a);
					}
					a = map[i - 1][j].getsymbol();
					if (a != 'M')
					{
						a++;
						map[i - 1][j].setsymbol(a);
					}
					a = map[i][j - 1].getsymbol();
					if (a != 'M')
					{
						a++;
						map[i][j - 1].setsymbol(a);
					}
					a = map[i][j + 1].getsymbol();
					if (a != 'M')
					{
						a++;
						map[i][j + 1].setsymbol(a);
					}
					a = map[i + 1][j - 1].getsymbol();
					if (a != 'M')
					{
						a++;
						map[i + 1][j - 1].setsymbol(a);
					}
					a = map[i + 1][j].getsymbol();
					if (a != 'M')
					{
						a++;
						map[i + 1][j].setsymbol(a);
					}
					a = map[i + 1][j + 1].getsymbol();
					if (a != 'M')
					{
						a++;
						map[i + 1][j + 1].setsymbol(a);
					}
				}
			}
		}
	}
}
void Board::up(int r, int c)
{
	if (r >= 0 && r <= size && c >= 0 && c <= size)
	{
		for (int up = 1;r - up >= 0; up++)
		{
			if (map[r - up][c].getsymbol() == '0'|| map[r - up][c].getsymbol() == '-')
			{
				map[r - up][c].setsymbol('-');
				map[r - up][c].setopened(true);
				right(r - up, c);
				left(r - up, c);
			}
			else
			{
				map[r - up][c].setopened(true);
				break;
				
			}
		}
	}
}
void Board::down(int r, int c)
{
	if (r >= 0 && r <= size && c >= 0 && c <= size)
	{
		for (int down = 1; down + r < size; down++)
		{
			if (map[r + down][c].getsymbol() == '0')
			{
				map[r + down][c].setsymbol('-');
				map[r + down][c].setopened(true);
				right(r + down, c);
				left(r + down, c);
			}
			else
			{
				map[r + down][c].setopened(true);
				break;
			}
		}
	}
}
void Board::right(int r, int c) {
	if (r >= 0 && r < size && c >= 0 && c < size) {
		for (int right = 1;  c + right < size; right++)
		{
			if (map[r][c + right].getsymbol() == '0'|| map[r][c + right].getsymbol() == '-')
			{
				map[r][c + right].setsymbol('-');
				map[r][c + right].setopened(true);
				up(r, c + right);
				down(r, c + right);
			}
			else
			{
				map[r][c + right].setopened(true);
				break;
			}
		}
	}
}
void Board::left(int r, int c)
{
	if (r >= 0 && r < size && c >= 0 && c < size)
	{
		for (int left = 1; c - left >= 0; left++)
		{
			if (map[r][c - left].getsymbol() == '0'|| map[r][c - left].getsymbol() == '-')
			{
				map[r][c - left].setsymbol('-');
				map[r][c - left].setopened(true);
				up(r, c - left);
				down(r, c - left);
			}
			else
			{
				if (map[r][c - left].getsymbol() > '0')
					map[r][c - left].setopened(true);
				break;
			}
		}
	}
}
void Board::opener(int& r, int& c)
{
	if (map[r][c].getsymbol() !='0'&& map[r][c].getsymbol() != 'M')
	{
		map[r][c].setopened(true);
	}
	else if(map[r][c].getsymbol() == '0')
	{
		map[r][c].setsymbol('-');
		map[r][c].setopened(true);
		right(r, c);
		left(r, c);
		up(r, c);
		down(r, c);
	}
	else
	{
		r = -2;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (map[i][j].getsymbol() == 'M')
					map[i][j].setopened(true);
			}
		}
	}
	copy();
}
//Cell** Board::sm()
//{
//	return displaym;
//}
//Cell** Board::m()
//{
//	return map;
//}
Board::~Board()
{
	if (displaym != NULL) {
		for (int i = 0; i < size; i++)
		{
			delete[] displaym[i];
		}
		delete[] displaym;
	}
	if (map != NULL) {
		for (int i = 0; i < size; i++)
		{
			delete[] map[i];
		}
		delete[] map;
	}
}
void Board::play()
{
	cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	cout << "|||||||||||||||||||||||||||MINESWEEPER|||||||||||||||||||||||||||\n";
	cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	int again = 1;
	while (again == 1)
	{
		int k = 0;
		cout << "press '1' for EASY \npress '2' for MEDIUM\npress '3' for HARD \n Your option :";
		cin >> k;
		if (k == 1)
			k = 5;
		else if (k == 2)
			k = 7;
		else if (k == 3)
			k = 10;
		else
			k = 0;
		if (k > 0)
		{
			Boardp* usi;
			Board b1(k);
			usi = &b1;
			usi->minegenerator();
			usi->numbergenerator();
			/*RenderWindow app(VideoMode(400, 400), "Minesweeper!");
			Texture t;
			t.loadFromFile("images/tiles.jpg");
			Sprite s(t);
			int w = 32;
			Cell** ptrm;
			Cell** ptrsm;
			ptrm = b1.m();
			ptrsm = b1.sm();*/
			/*while (app.isOpen())
			{
				Vector2i pos = Mouse::getPosition(app);
				int x = pos.x / w;
				int y = pos.y / w;
				Event e;
				while (app.pollEvent(e))
				{
					if (e.type == Event::Closed)
						app.close();
					if (e.type == Event::MouseButtonPressed)
						if (e.key.code == Mouse::Left)
							ptrm[x][y].setsymbol(ptrsm[x][y].getsymbol());
				}
				app.clear(Color::White);
				for (int i = 1; i <= 10; i++)
					for (int j = 1; j <= 10; j++)
					{
						if (ptrm[x][y].getsymbol() == 'M')
							ptrsm[i][j].setsymbol(ptrm[i][j].getsymbol());
						s.setTextureRect(IntRect(ptrsm[i][j].getsymbol() * w, 0, w, w));
						s.setPosition(i * w, j * w);
						app.draw(s);
					}
				app.display();
			}*/
			system("cls");
			cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
			cout << "|||||||||||||||||||||||||||MINESWEEPER|||||||||||||||||||||||||||\n";
			cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n";
			usi->printboard();
			cout << endl;
			int x = 0, y;


			for (int i = 0; x != -1 && x != -2; i++)
			{
				cout << "Enter row number :";
				cin >> x;
				cout << "Enter colums number :";
				cin >> y;
				system("cls");
				cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
				cout << "|||||||||||||||||||||||||||MINESWEEPER|||||||||||||||||||||||||||\n";
				cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n";
				if (x < b1.getsize() && x >= 0 && y < b1.getsize() && y >= 0)
				{
					usi->opener(x, y);
					usi->printboard();
					if (x == -2)
					{
						cout << "\n\nGame LOST\n\nn";
						cout << "If you want to play again press 1 or enter any other key to continue :";
						cin >> again;
					}
				}
				else
				{
					cout << "Invalid values; Enter values again \n";
				}
			}
		}
		else
		{
			cout << "Invalid difficulty entered\n";
		}
	}
}
Board::Board()
{
	size = 0;
	displaym = NULL;
	map = NULL;
}