CC=gcc
AR=ar
FLAGS= -Wall -c -g
OBJECTS_MAIN=main.o
OBJECTS_BASIC=basicClassification.o
OBJECTS_ADVANCED_LOOP=advancedClassificationLoop.o
OBJECTS_ADVANCED_REC=advancedClassificationRecursion.o
LIB_D_REC=libclassrec.so
LIB_S_REC=libclassrec.a
LIB_D_LOOP=libclassloops.so
LIB_S_LOOP=libclassloops.a

all: loops mains maindrec maindloop
main.o:
	$(CC) $(FLAGS) main.c -o $(OBJECTS_MAIN)

basicClassification.o:
	$(CC) $(FLAGS) basicClassification.c -o $(OBJECTS_BASIC)

advancedClassificationLoop.o:
	$(CC) $(FLAGS) advancedClassificationLoop.c -o $(OBJECTS_ADVANCED_LOOP)

advancedClassificationRecursion.o:
	$(CC) $(FLAGS) advancedClassificationRecursion.c -o $(OBJECTS_ADVANCED_REC)

$(LIB_S_LOOP):
	$(AR) rcs $(LIB_S_LOOP) $(OBJECTS_BASIC) $(OBJECTS_ADVANCED_LOOP)

$(LIB_S_REC):
	$(AR) rcs $(LIB_S_REC) $(OBJECTS_BASIC) $(OBJECTS_ADVANCED_REC)

$(LIB_D_LOOP):
	$(CC) -shared $(OBJECTS_BASIC) $(OBJECTS_ADVANCED_LOOP) -o $(LIB_D_LOOP)	
				
$(LIB_D_REC):
	$(CC) -shared $(OBJECTS_BASIC) $(OBJECTS_ADVANCED_REC) -o $(LIB_D_REC)
	
loops: $(OBJECTS_BASIC) $(OBJECTS_ADVANCED_LOOP) $(LIB_S_LOOP)

recursives: $(OBJECTS_BASIC) $(OBJECTS_ADVANCED_REC) $(LIB_S_REC)

recursived: $(OBJECTS_BASIC) $(OBJECTS_ADVANCED_REC) $(LIB_D_REC)

loopd: $(OBJECTS_BASIC) $(OBJECTS_ADVANCED_LOOP) $(LIB_D_LOOP)

mains: $(OBJECTS_MAIN) $(OBJECTS_BASIC) $(OBJECTS_ADVANCED_REC) $(LIB_S_REC)
	$(CC) -o mains $(OBJECTS_MAIN) -L. $(LIB_S_REC) -lm

maindloop: $(OBJECTS_MAIN) $(OBJECTS_BASIC) $(OBJECTS_ADVANCED_LOOP) $(LIB_D_LOOP)
	$(CC) -o maindloop $(OBJECTS_MAIN) -L. $(LIB_D_LOOP) -lm

maindrec: $(OBJECTS_MAIN) $(OBJECTS_BASIC) $(OBJECTS_ADVANCED_REC) $(LIB_D_REC)
	$(CC) -o maindrec $(OBJECTS_MAIN) -L. $(LIB_D_REC) -lm

.PHONY: clean all
	
clean:
	rm -f *.o *.a *.so "maindloop" "maindrec" "mains"
