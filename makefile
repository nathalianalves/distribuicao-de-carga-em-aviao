parametrosCompilacao = -Wall
nomePrograma = carga

all: $(nomePrograma)

$(nomePrograma): main.c
	gcc main.c -o $(nomePrograma) $(parametrosCompilacao)

clean:
	rm -f *.o *.gch

purge:
	make clean
	rm -f $(nomePrograma)