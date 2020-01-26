// starX.cpp

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void assertEquals(string expected, string actual, string message);
string starX(int width);
void runTests(void);

string starX(int width){
    string result = "";
    if (width< 2 || width% 2 == 0)
    {
        return (result);
    }
    for(int lineNum=1; lineNum<=width; lineNum++)
        { for (int pos = 1; pos<= width; pos++){
           if (pos == lineNum || pos == (width- lineNum+1)){
            result += "*";
           }
           else {
                result += " ";
           }

        } result += "\n";
        }
        return result;
}



// Test-Driven Development;
// check expected results against actual

void runTests(void)
{

  // The following line works because in C and C++ when string literals
  // are separated only by whitespace (space, tab, newline), they
  // automatically get concatenated into a single string literal

  string starX3Expected =
      "* *\n"
      " * \n"
      "* *\n";

  assertEquals(starX3Expected, starX(3), "starX(3)");

  string starX5Expected =
      "*   *\n"
      " * * \n"
      "  *  \n"
      " * * \n"
      "*   *\n";

  assertEquals(starX5Expected, starX(5), "starX(5)");

  string starX7Expected =
      "*     *\n"
      " *   * \n"
      "  * *  \n"
      "   *   \n"
      "  * *  \n"
      " *   * \n"
      "*     *\n";

  assertEquals(starX7Expected, starX(7), "starX(7)");

  assertEquals("", starX(0), "starX(0)");
  assertEquals("", starX(2), "starX(2)");
  assertEquals("", starX(4), "starX(4)");
}

void assertEquals(string expected, string actual, string message = "")
{
  if (expected == actual)
  {
    cout << "PASSED: " << message << endl;
    ;
  }
  else
  {
    cout << "   FAILED: " << message << endl
         << "   Expected:[\n"
         << expected << "] actual = [\n"
         << actual << "]\n"
         << endl;
  }
}

// Main function

int main(int argc, char *argv[])
{

  if (argc != 2)
  {
    cerr << "Usage: " << argv[0] << " width" << endl;
    exit(1);
  }

  int width = stoi(argv[1]);

  if (width == -1)
  {
    runTests();
    exit(0);
  }

  cout << starX(width);
  return 0;
}
