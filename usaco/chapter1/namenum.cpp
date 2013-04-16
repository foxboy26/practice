/*
ID: foxboy21
PROG: namenum
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

char l[24] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y'};

string input;
string output;
set<string> dic;
int count = 0;

void dfs(int level, int n, ofstream& fout)
{
  if (level == n)
  {
    if (dic.find(output) != dic.end())
    {
      count++;
      fout << output << "\n";
    }
  }
  else
  {
    for (int i = 0; i < 3; i++)
    {
      output[level] = l[(input[level] - '2') * 3 + i];  
      dfs(level + 1, n, fout);
    }
  }
}

int main()
{
  ifstream fin("namenum.in");
  ofstream fout("namenum.out");
  
  fin >> input;

  ifstream fdata("dict.txt");
  string word;
  while(fdata >> word)
  {
    dic.insert(word);
  }
  fdata.close();

  output = input;
  
  dfs(0, input.length(), fout);

  if (count == 0)
  {
    fout << "NONE\n";
  }

  fin.close();
  fout.close();

  return 0;
}
