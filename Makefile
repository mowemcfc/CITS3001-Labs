all: unitTest.c
	gcc  Week1/sort.c Week2/stringalg.c -lm helpers.c unitTest.c Unity/src/unity.c -o unitTest -g

clean:
	$(RM) unitTest