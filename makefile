#Bank Management Sys C project
#Copy Right : Magdy

# %.x all files end with .x
# $@ replace by name of target
# $< replace by first prerequisite
# $^ replace by all prerequisites

CC= gcc

SRCDIR = src
OBJDIR = obj
INCDIR = inc

SRC=$(wildcard $(SRCDIR)/*.c)
OBJ=$(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all : bankSystem 
#make rule to generate the final binary 

bankSystem : $(OBJ) $(OBJDIR)/main.o
	$(CC) $(OBJ) $(OBJDIR)/main.o -o bankSystem 

#$(OBJ): $(ODIR)/%.o: src/%.c $(DEPS)
$(OBJDIR)/main.o : main.c 
	$(CC) main.c -c -o $(OBJDIR)/main.o
	
$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -c -o $@ $<




