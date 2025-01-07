.SILENT:
	

ALL: compilar prueba eliminar

# compilar libreria listas
compilar:
	gcc -fPIC -c listas.c
	gcc -fPIC -c -o item.o ../item/item.c
	gcc -shared -o liblistas.so listas.o item.o
	sudo mv liblistas.so /usr/lib
	sudo ldconfig

eliminar:
	@rm prueba
	@rm *.o

prueba:
	@gcc -o prueba prueba.c -llistas
	@./prueba
