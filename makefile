all: main.cpp BST.cpp BST.h BSTNode.cpp BSTNode.h
	g++ -o BST main.cpp BST.cpp BST.h BSTNode.cpp BSTNode.h
run:
	./BST
clean:
	rm -fr BST main.o BST.o BSTNode.o *~