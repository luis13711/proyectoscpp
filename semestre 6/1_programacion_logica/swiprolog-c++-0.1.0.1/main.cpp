#include <iostream.h>
#include <string>
#include <list>

#define logvar(x) \
cout << __FILE__ << ":" << __LINE__ << " " << #x << " = " << x << endl;
#define logp \
cout << __FILE__ << ":" << __LINE__ << endl;
#define log(x) \
cout << __FILE__ << ":" << __LINE__ << " " << x << endl;

ostream& operator << (ostream&, const list<string>&);
ostream& operator << (ostream&, const list<const char*>&);
ostream& operator << (ostream&, const list<char*>&);
ostream& operator << (ostream&, const list<int>&);

#include "prolog.hpp"

using namespace Prolog;

int argc;
char** argv;

#include "tests.cpp"

void dotest(void (*func)(void), const char* name);
#define test(n) dotest(n ## _test, #n)


main(int argc, char** argv)
{
  cout << "This program is for testing SwiProlog-C++.\n\n";

  ::argc = argc;
  ::argv = argv;
  try {
    prolog_init(argc, argv);

    /*
    test(atom_to_term);
    test(unify);
    test(construct_unify);
    test(bindings);
    test(copy);
    test(write);
    test(module);
    test(functor);
    test(staticfunctor);
    test(atom);
    test(term1);
    test(termconv);
    test(module);
    test(staticatom);
    test(recorded);
    test(list);
    test(staticterm);
    test(fp);
    test(query1);
    test(query2);
    test(query3);
    test(query4);
    */
    test(staticquery1);
    test(termcopy);

  } catch (PlError& err) {
    cout << "PlError in main() -\nmessage: " << err.message() << endl;
    cout << "as term: " << err.as_term() << endl;
  } catch (const char* err) {
    cout << "char* exception in main(): " << err << endl;
  } catch (...) {
    cout << "unknown exception in main()" << endl;
  }
}

void dotest(void (*func)(void), const char* name)
{
  cout << name << ":" << endl;
  try {
    func();
  } catch (PlError& err) {
    cout << "PlError -\nmessage: " << err.message() << endl;
    cout << "as term: " << err.as_term() << endl;
  } catch (const char* err) {
    cout << "char* exception: " << err << endl;
  } catch (...) {
    cout << "unknown exception" << endl;
  }
  cout << endl << endl;
}


#define AUSG(Cont) \
{ \
  bool first = true; \
  os << "["; \
  for (Cont::const_iterator it = cont.begin(); \
       it != cont.end(); \
       ++it) \
    { \
      if (!first) os << ", "; \
      first = false; \
      os << *it; \
    } \
  os << "]"; \
  return os; \
}

ostream& operator << (ostream& os, const list<string>      & cont) AUSG(list<string>)
ostream& operator << (ostream& os, const list<const char*> & cont) AUSG(list<const char*>)
ostream& operator << (ostream& os, const list<char*>       & cont) AUSG(list<char*>)
ostream& operator << (ostream& os, const list<int>         & cont) AUSG(list<int>)
