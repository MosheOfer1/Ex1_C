main.o:
	gcc -c -Wall main.c -o main.o -lm

basicClassification.o:
	gcc -c -Wall basicClassification.c -o basicClassification.o -lm

advancedClassificationLoop.o:
	gcc -c -Wall advancedClassificationLoop.c -o advancedClassificationLoop.o -lm

advancedClassificationRecursion.o:
	gcc -c -Wall advancedClassificationRecursion.c -o advancedClassificationRecursion.o -lm

loops: basicClassification.o advancedClassificationLoop.o
	ar rcs libclassloops.a basicClassification.o advancedClassificationLoop.o

recursives: basicClassification.o advancedClassificationRecursion.o
	ar rcs libclassrec.a basicClassification.o advancedClassificationRecursion.o

recursived: basicClassification.o advancedClassificationRecursion.o
	gcc  -shared basicClassification.o advancedClassificationRecursion.o -o libclassrec.so

loopd: basicClassification.o advancedClassificationLoop.o
	gcc basicClassification.o advancedClassificationLoop.o -shared -o libclassloops.so

mains: main.o recursives
	gcc -o mains main.o -L. libclassrec.a -lm

maindloop: main.o loopd
	gcc -o maindloop main.o -L. libclassloops.so -lm

maindrec: main.o recursived
	gcc -o maindrec main.o -L. libclassrec.so -lm

.PHONY: clean all
	
all: mains maindrec maindloop loops
	
clean:
	rm *.o *.a *.so "maindloop" "maindrec" "mains"

