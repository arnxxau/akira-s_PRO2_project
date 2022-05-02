OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11
#
G++ = g++
#
program.exe: program.o player.o tournament.o ranking.o categories.o circuit.o
	$(G++) -o program.exe program.o player.o tournament.o ranking.o categories.o circuit.o
#
program.o: program.cc
	$(G++) -c program.cc $(OPCIONS)
#
player.o: player.cc player.hh
	$(G++) -c player.cc $(OPCIONS)
#
tournament.o: tournament.cc tournament.hh
	$(G++) -c tournament.cc $(OPCIONS)
#
ranking.o: ranking.cc ranking.hh
	$(G++) -c ranking.cc $(OPCIONS)
#
categories.o: categories.cc categories.hh
	$(G++) -c categories.cc $(OPCIONS)
#
circuit.o: circuit.cc circuit.hh
	$(G++) -c circuit.cc $(OPCIONS)
#
clean:
	rm -f *.o
	rm -f *.exe
