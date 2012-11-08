CC = gcc

CFLAGS = -Wall -Lsrc

RM = rm -f

MAIN1 = tp2pd
MAIN2 = tp2g

OBJS1 = src/tp2pd.c src/arquivos.c src/matriz.c src/lcs.c
OBJS2 = src/tp2g.c src/arquivos.c src/guloso.c

VALGRIND = valgrind -v --read-var-info=yes --tool=memcheck --leak-check=yes --show-reachable=yes --track-origins=yes
#VALGRIND = valgrind  --read-var-info=yes --tool=memcheck --leak-check=yes -v
#VALGRIND = valgrind  --track-origins=yes --tool=memcheck --leak-check=yes -v
#VALGRIND = valgrind  --tool=memcheck

main: $(OBJS1) $(OBJS2)
	@echo ""
	@echo "------------------------"
	@echo " Compilando programa..."
	@echo "------------------------"
	@echo "--PROGRMAÇÃO-DINÂMICA---"
	@$(CC) $(CFLAGS) $(OBJS1) -g3 -std=c99 -o $(MAIN1)
	@echo "------------------------"
	@echo " Compilacao feita com sucesso!"
	@echo "------------------------"
	@echo ""
	@echo "------------------------"
	@echo " Compilando programa..."
	@echo "------------------------"
	@echo "---------GULOSO---------"
	@$(CC) $(CFLAGS) $(OBJS2) -g3 -std=c99 -o $(MAIN2)
	@echo "------------------------"
	@echo " Compilacao feita com sucesso!"
	@echo "------------------------"
	@echo ""

clean:
	$(RM) $(MAIN1) $(MAIN2) *.o *~ testes/*~
	$(RM) entrada/pd/* entrada/g/* saida/pd/* saida/g/* comp/*
	clear

val: main
	$(VALGRIND) ./$(MAIN1) input.txt output.txt
	$(VALGRIND) ./$(MAIN2) input.txt output.txt

run: main
	@echo "..Executando programa..."
	@echo "------------------------"
	@echo "--PROGRMAÇÃO-DINÂMICA---"
	@echo "------------------------"
	@echo ""
	./$(MAIN1) input.txt output.txt
	@echo "------------------------"
	@echo "..Executando programa..."
	@echo "------------------------"
	@echo "---------GULOSO---------"
	@echo "------------------------"
	@echo ""
	./$(MAIN2) input.txt output.txt

all: clean run val
