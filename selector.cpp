#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char** argv)
{
  map<int, string> data;
  string line;
  int index = 0;

  while(getline(cin, line))
  {
    data[++index] = line;
  }

  char* id = ctermid(NULL);
  FILE* term = fopen(id, "rw");
  char* buffer = (char*)malloc(800);

  for(int idx = 1; idx <= index; idx++)
  {
    if(data[idx].length() > 30)
    {
      cerr << idx << ") " << data[idx].substr(0, 29) << "..." << '\n';
    } else
    {
      cerr << idx << ") " << data[idx] << '\n';
    }
  } 

  cerr << '\n' << "choose which line to pass through: ";
  fgets(buffer, 80, term);

  cout << data[stoi(string(buffer))];

  return 0;
}
