flags = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11
#
#
program.exe: program.o player.o tournament.o ranking.o categories.o circuit.o match.o
	g++ -o program.exe program.o player.o tournament.o ranking.o categories.o circuit.o match.o
#
program.o: program.cc
	g++ -c program.cc $(flags)
#
player.o: player.cc player.hh
	g++ -c player.cc $(flags)
#
tournament.o: tournament.cc tournament.hh
	g++ -c tournament.cc $(flags)
#
ranking.o: ranking.cc ranking.hh
	g++ -c ranking.cc $(flags)
#
categories.o: categories.cc categories.hh
	g++ -c categories.cc $(flags)
#
circuit.o: circuit.cc circuit.hh
	g++ -c circuit.cc $(flags)

match.o: match.cc match.hh
	g++ -c match.cc $(flags)
#
clean:
	rm -f *.o
	rm -f *.exe
