output: driver.o pokedex.o pokemon.o 
	g++ -std=c++11 driver.o pokedex.o pokemon.o -o output

driver.o: driver.cpp
	g++ -std=c++11 -c driver.cpp

pokedex.o: pokedex.cpp
	g++ -std=c++11 -c pokedex.cpp

pokmon.o: pokemon.cpp
	g++ -std=c++11 -c pokemon.cpp

clean:
	rm *.o output
