/*
ID: foxboy21
PROG: gift1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Member
{
  string name;
  int current_money;
  int initial_money;
};

int main()
{
  ifstream fin("gift1.in");
  ofstream fout("gift1.out");

  int NP;
  string sender, receiver[10];
  int left_money, sent_money, budget, receive_num;
  Member member[10];

  fin >> NP;
  
  for (int i = 0; i < NP; i++)
  {
    fin >> member[i].name;
    member[i].current_money = 0;
    member[i].initial_money = 0;
  }

  while (fin >> sender)
  {
    fin >> budget >> receive_num;

    for (int i = 0; i < receive_num; i++)
    {
      fin >> receiver[i];
    }
    
    left_money = sent_money = 0;
    if (receive_num > 0)
    {
      left_money = budget % receive_num;
      sent_money = budget / receive_num;
    }

    for (int i = 0; i < NP; i++)
    {
      if (member[i].name == sender)
      {
        member[i].current_money += left_money;
        member[i].initial_money += budget;
      }

      for(int j = 0; j < receive_num; j++)
      {
        if (member[i].name == receiver[j])
        {
          member[i].current_money += sent_money;
        }
      }
    }
  }

  for (int i = 0; i < NP; i++)
  {
    fout << member[i].name << " " << member[i].current_money - member[i].initial_money << "\n";
  }

  fin.close();
  fout.close();

  return 0;
}
