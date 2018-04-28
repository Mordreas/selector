#include <iostream>
#include <string>
#include <map>
#include <list>
#include <sstream>

using namespace std;

map<int, string> parseInput() 
{
  map<int, string> data;
  string line;
  int index = 0;

  while(getline(cin, line))
  {
    data[++index] = line;
  }

  return data;
}

string promptUser(map<int, string>& data)
{
  char* id = ctermid(NULL);
  FILE* term = fopen(id, "rw");
  char* buffer = (char*)malloc(800);

  for(int idx = 1; idx <= data.size(); idx++)
  {
    if(data[idx].length() > 80)
    {
      cerr << idx << ") " << data[idx].substr(0, 79) << "..." << '\n';
    } else
    {
      cerr << idx << ") " << data[idx] << '\n';
    }
  } 

  cerr << '\n' << "choose which line to pass through: ";
  fgets(buffer, 80, term);

  return string(buffer);
}

void outputChoice(map<int, string> data, string choices)
{
  stringstream choicesStream(choices);

  list<string> choicesList;
  string subString;
  while(getline(choicesStream, subString, ','))
  {
    choicesList.push_back(subString);
  }

  for(string choice : choicesList)
  {
    cout << data[stoi(choice)] << endl;
  }
}

int main(int argc, char** argv)
{
  map<int, string> data = parseInput();
  
  switch(data.size())
  {
  case 0:
    return 1;
  case 1:
    cout << data[1];

    return 0;
  default:
    string choice = promptUser(data);
    outputChoice(data, choice);

    return 0;
  }
}

