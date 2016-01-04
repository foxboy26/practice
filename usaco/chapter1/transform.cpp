/*
ID: foxboy21
PROG: transform
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isRotate90(char p[][10], char q[][10], int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      if (q[j][size - 1 -i] != p[i][j])
      {
        return false;
      }
    }
  }
  
  return true;
}

bool isRotate180(char p[][10], char q[][10], int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      if (q[size - 1 - i][size - 1 - j] != p[i][j])
      {
        return false;
      }
    }
  }
  
  return true;
}

bool isRotate270(char p[][10], char q[][10], int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      if (q[size - 1 - j][i] != p[i][j])
      {
        return false;
      }
    }
  }

  return true;
}

bool isReflection(char p[][10], char q[][10], int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      if (p[i][j] != q[i][size - 1 - j])
      {
        return false;
      }
    }
  }

  return true;
}

bool isCombination(char p[][10], char q[][10], int size)
{
  char r[10][10];
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      r[i][j] = p[i][size - 1 - j];
    }
  }
  
  return isRotate90(r, q, size) || isRotate180(r, q, size) || isRotate270(r, q, size);
}

bool isNoChange(char p[][10], char q[][10], int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      if (p[i][j] != q[i][j])
        return false;
    }
  }
  
  return true;
}

int main()
{
  ifstream fin("transform.in");
  ofstream fout("transform.out");

  int n;
  char p[10][10];
  char q[10][10];

  fin >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      fin >> p[i][j];
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      fin >> q[i][j];
    }
  }

  if (isRotate90(p, q, n))
    fout << 1 << "\n";
  else if (isRotate180(p, q, n))
    fout << 2 << "\n";
  else if (isRotate270(p, q, n))
    fout << 3 << "\n";
  else if (isReflection(p, q, n))
    fout << 4 << "\n";
  else if (isCombination(p, q, n))
    fout << 5 << "\n";
  else if (isNoChange(p, q, n))
    fout << 6 << "\n";
  else
    fout << 7 << "\n";

  fin.close();
  fout.close();

  return 0;
}
