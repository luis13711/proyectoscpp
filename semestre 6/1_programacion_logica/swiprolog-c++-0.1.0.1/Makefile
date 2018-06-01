VERSION   = 0.1.0
DATE      = 2002-01-14
XSLHTML   = db.xsl
XSLTPROC  = /usr/local/bin/xsltproc
FILES     = db.xsl main.cpp Makefile manual.html manual.xml prolog.cpp \
	    prolog.hpp test.pl tests.cpp README readme-tmpl LICENSE \
	    status.xml requirements.xml
CC        = gcc-2.95

main : main.o prolog.o test.pl
	plld -o $@ -ld $(CC) $^ -lstdc++

main.o : main.cpp tests.cpp prolog.hpp
prolog.o : prolog.cpp prolog.hpp

%.o : %.cpp
	$(CC) -g -c -o $@ $<

dist :: $(FILES)
	rm -rf swiprolog-c++-$(VERSION)
	mkdir swiprolog-c++-$(VERSION)
	cp $^ swiprolog-c++-$(VERSION)
	tar cfz swiprolog-c++-$(VERSION).tar.gz swiprolog-c++-$(VERSION)

manual.html :: manual.xml
	$(XSLTPROC) $(XSLHTML) $< > $@
	@realpath $@

doc ::
	rm -f manual.html
	make manual.html

README : readme-tmpl
	sed "s/-VERSION-/$(VERSION)/g; s/-DATE-/$(DATE)/g;" < $< > $@
