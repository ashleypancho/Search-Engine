#***************************
# Makefile - Search Engine *
# Ashley Pancho            *
#***************************

CXX = g++
CXXFLAGS = -c -std=c++0x

all 	 		: searchEngine

searchEngine	: avltree.o document.o main.o parser.o queryprocessor.o porter2_stemmer.o word.o
	${CXX} $^ ${CXXFLAGS} -o $@

avltree.o : AVLTree.cpp
	${CXX} $^ ${CXXFLAGS}

document.o : Document.cpp
	${CXX} $^ ${CXXFLAGS}

main.o : main.cpp
	${CXX} $^ ${CXXFLAGS}

parser.o : Parser.cpp
	${CXX} $^ ${CXXFLAGS}

queryprocessor.o : QueryProcessor.cpp
	${CXX} $^ ${CXXFLAGS}

porter2_stemmer.o : porter2_stemmer.cpp
	${CXX} $^ ${CXXFLAGS}

word.o : Word.cpp
	${CXX} $^ ${CXXFLAGS}

clean :
	\rm -f searchEngine avltree.o document.o main.o Parser.o QueryProcessor.o stemmer.o word.o

###### End of Makefile ######
