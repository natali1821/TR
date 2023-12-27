parser: gram.tab.c lex.yy.c
	g++ -o parser gram.tab.c lex.yy.c -lfl

gram.tab.c: gram.y
	bison -d gram.y

lex.yy.c: gram.l
	flex gram.l

clean:
	rm -f parser gram.tab.* lex.yy.c
