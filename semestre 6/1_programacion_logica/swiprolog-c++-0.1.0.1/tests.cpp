#include <algorithm>
#include <vector>

/*
void atom_to_term_test(void)
{
  list<Term::Binding> tt_bindings;
  Term                tt_term;
  logvar(atom_to_term("blub(bla, X, blu, _, Y)", &tt_term, &tt_bindings));
  logvar(tt_term.to_string());
  logvar(tt_bindings);
}
*/

void unify_test(void)
{
  Term a("x(A,2)");
  Term b("x(1,B)");
  logvar(a);
  logvar(b);
  unify(a,b);
  logvar(a);
  logvar(b);
}

void construct_unify_test(void)
{
  Term vv;
  Term vv1 = vv;
  Term tv[] = { Term("1"), Term("abc"), Term("a(b,c)"), vv };
  Term tvt("foo", tv, tv+4);
  logvar(tvt);
  logvar(vv);

  vv = 99;
  logvar(tvt);
  logvar(vv);

  unify(vv1, 99);
  logvar(tvt);
  logvar(vv);

}

void bindings_test(void)
{
  Term t0;
  Term t1(t0);
  logvar(t0);
  logvar(t1);
  unify(t0, 66);
  logvar(t0);
  logvar(t1);
}

void copy_test(void)
{
  Term t0;
  Term t1(t0);
  logvar(t0);
  logvar(t1);
  t1.copy();
  logvar(t0);
  logvar(t1);
  unify(t0, 66);
  logvar(t0);
  logvar(t1);
}

void query1_test(void)
{
  Query q("permutation", 2);
  Term t("[1,2,3]");
  Term p;
  q(t,p);
  while (q.next()) logvar(p);
}

extern "C" unsigned long pl_write_term(Prolog_impl::term_t, Prolog_impl::term_t);
extern "C" unsigned long pl_flush_output();

void write_test(void)
{
  Term testtext(Atom("bl)ub, /[§$ bla"));
  logvar(testtext.to_str(CVT_ATOM));
  logvar(testtext.to_str());
}

void query2_test(void)
{
  Query q1("samelength", 2);
  Query q2("true", 0);

  Term t1, t2;
  q1(t1, t2);
  cout << "causing error...\n";
  q2();  // error
}

void query3_test(void)
{
  Query q("true",0);
  cout << "query 'true', normal execution\n"; 
  logp; q();
  logp; q.next(); q.next();

  cout << "query 'true', closing\n";
  logp; q();
  logp; q.close();

  cout << "query 'true', cutting\n";
  logp; q();
  logp; q.cut();

  cout << "causing error...\n";
  logp; q.next();  // error
}

void module_test(void)
{
  Module new_module("New Module");
  logvar(new_module);
  logvar(Module::context());
  logvar(Module::user());
  logvar(Module());
}

void functor_test(void)
{
  Functor f1("My Functor", 2);
  Functor f2(string("My Functor"), 2);
  Functor f3("My Functor", 3);
  logvar(f1);
  logvar(f2);
  logvar(f3);
  logvar(Term(f1));
  logvar((f1 == f2));
  logvar((f1 == f3));
  logvar((f2 > f3));
  logvar((f3 > f2));
  logvar(f1.name());
  logvar(f1.arity());
  f2.swap(f3);
  logvar((f1 == f3));
  logvar(Term("x(y,Z)").functor());
}

void staticfunctor_test(void)
{
  static StaticFunctor f("static functor", 77);
  logvar(f);
  prolog_halt();
  prolog_init(argc,argv);
  logvar(f);
}

void atom_test(void)
{
  Atom a(string("blub blub"));
  logvar(a);
  logvar((const char*) a);
  Atom a2("blub blub");
  logvar((a == a2));
  Term t("tri(tra, 2)");
  a = (Atom) t;  // error
}

StaticAtom sa1("static atom 1");

void staticatom_test(void)
{
  static StaticAtom sa2("static atom 2");
  logvar(sa1);
  logvar(sa2);
  prolog_halt();
  prolog_init(argc,argv);
  logvar(sa1);
  logvar(sa2);
}

void term1_test(void)
{
  Term t1;
  Term t2;
  Term t3;
  unify(t1, t2);
  logvar(t1);
  logvar(t2);
  logvar(t3);

  unify(t2, t3);
  logvar(t1);
  logvar(t2);
  logvar(t3);

  unify(t1, 42);
  logvar(t1);
  logvar(t2);
  logvar(t3);
}

template <typename T>
void totermandback(const T x) {
  Term t(x);
  logvar(t);
  logvar((T) t);
}

void termconv_test(void)
{
  totermandback(1000000000);
  totermandback(Atom("atom"));
  totermandback(42);
  totermandback(3.1415);
  totermandback<void*>(termconv_test);
  totermandback("hello");
  totermandback(string("hello string"));
}

void recorded_test(void)
{
  cout << "- saving/restoring\n";
  RecordedTerm rt("foo(X,Y)");  // convert string to Term
  logvar(rt);                   // convert RecordedTerm to Term
}


bool FoPre(Term t1, Term t2)
{
  cout << "Foreign Predicate --->\n";
  logvar(t1);
  logvar(t2);
  cout << "<--- Foreign Predicate\n";
  return true;
}

foreign(FoPre, "fopre", 2)


void fp_test(void)
{
  Query q("fptest",0);
  q();
  q.next();
}

void query4_test(void)
{
  Query q("one_result", 1);
  Term t;
  q(t);
  cout << "get one result:\n";
  logvar(q.next());
  logvar(t);
  cout << "get next result (does not exist). term is deunified:\n";
  logvar(q.next());
  logvar(t);
}


void delete_charp(char* p) {
  delete p;
}

void list_test(void)
{
  Term t("[bli, 4, a(b,c), X]");
  logvar(t);

  list<char*> l1 = t;
  logvar(l1);
  for_each(l1.begin(), l1.end(), delete_charp);

  list<string> l2 = t;
  logvar(l2);

  Term t1("[1,2,3]");
  list<int> l3 = t1;
  logvar(l3);

  cout << "causing conversion error...\n";
  l3 = t;
}


StaticTerm st1("'1abc'");
StaticTerm st2;

void staticterm_test(void)
{
  logvar(&st1);
  logvar(&st2);
  RecordedTerm* z = &st1;
  logvar(st1.term());
  logvar(st2.term());
  st2 = Term("'2xyz'");
  logvar(st1.term());
  logvar(st2.term());
  prolog_halt();
  prolog_init(argc,argv);
  logvar(st1.term());
  logvar(st2.term());
  st1.swap(st2);
  logvar(st1.term());
  logvar(st2.term());
  prolog_halt();
  prolog_init(argc,argv);
  logvar(st1.term());
  logvar(st2.term());
}


StaticQuery sq1("permutation", 2);
StaticQuery sq2("permutation(X,Y)");

void staticquery1_test(void)
{
  Term t("[1,2,3]");
  Term p;
  cout << "call by predicate\n";
  sq1(t,p);
  while (sq1.next()) logvar(p);
  cout << "call by callterm\n";
  sq2(t,p);
  while (sq2.next()) logvar(p);
}

void termcopy_test(void)
{
  const char* l[] = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
                      "k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
                      "u", "v", "w", "x", "y", "z", "list(  of( terms,  ''))" };
  Term t(l, l+27);
  logvar(t);

  vector<char*> v;
  t.copy_list<char*>(back_inserter(v));
  cout << "contents of the vector: ";
  copy(v.begin(), v.end(), ostream_iterator<const char*>(cout," "));
  cout << endl;
  for_each(v.begin(), v.end(), delete_charp);
}
