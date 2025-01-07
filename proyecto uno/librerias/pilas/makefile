.SILENT:
	

ALL: compilar prueba eliminar

# compilar libreria pilas
compilar:
	gcc -fPIC -c pilas.c
	gcc -fPIC -c -o item.o ../item/item.c
	gcc -shared -o libpilas.so pilas.o item.o
	sudo mv libpilas.so /usr/lib
	sudo ldconfig

eliminar:
	@rm prueba
	@rm *.o

prueba:
	@gcc -o prueba prueba.c -lpilas
	@./prueba
