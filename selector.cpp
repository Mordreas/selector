#include <iostream>
#include <string>
#include <map>
#include <list>
#include <sstream>
#include <cctype>
#include <algorithm>


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

list<string> split(string input, char delimiter)
{
  input.erase(remove(input.begin(), input.end(), ' '), input.end());
  input.erase(remove(input.begin(), input.end(), '\n'), input.end());
  stringstream inputStream(input);
  list<string> output;
  string subString;
  
  while(getline(inputStream, subString, delimiter))
  {
    output.push_back(subString);
  }
  
  return output;
}

bool is_number(const string &input)
{
  return !input.empty() && all_of(input.begin(), input.end(), ::isdigit);
}

void outputLine(map<int, string> data, string input)
{
  if(is_number(input))
  {
    cout << data[stoi(input)] << endl;
  }
}

void outputRange(map<int, string> data, string input)
{
  list<string> range = split(input, '-');

  if(is_number(range.front()) && is_number(range.back()))
  {
    for(int idx = stoi(range.front()); idx <= stoi(range.back()); idx++)
    {
      cout << data[idx] << endl;
    }
  }
}

void outputChoice(map<int, string> data, string choices)
{
  list<string> choiceList = split(choices, ',');
  
  for(string choice : choiceList)
  {
    if(choice.find('-' != string::npos))
    {
      outputRange(data, choice);
    } 
    else
    {
      outputLine(data, choice);
    }
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

