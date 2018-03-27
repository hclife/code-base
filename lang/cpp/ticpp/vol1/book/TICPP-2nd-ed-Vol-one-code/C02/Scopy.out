//: C02:Scopy.cpp
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// Copy one file to another, a line at a time

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

int main() {
  ifstream fin("Scopy.cpp"); // Open for reading
  ofstream fout("Scopy.out"); // Open for writing
  if (!fin || !fout) return 0;

  string s;
  while(getline(fin, s)) // Discards newline char
    fout << s << "\n"; // ... must add it back

  if (fin) fin.close();
  if (fout) fout.close();
} ///:~
