ALL: compilar prueba eliminar 

# compilar libreria colores
compilar:
	@gcc -fPIC -c colores.c
	@gcc -shared -o libcolores.so colores.o
	@sudo mv libcolores.so /usr/lib
	@sudo ldconfig

eliminar:
	@rm prueba
	@rm *.o

prueba:
	@gcc -o prueba prueba.c -lcolores
	@./prueba
