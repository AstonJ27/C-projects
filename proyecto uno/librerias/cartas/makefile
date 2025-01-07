ALL: compilar prueba eliminar 

compilar:
	@gcc -fPIC -c cartas.c # crea el objeto
	@gcc -shared -o libcartas.so cartas.o -lcolores #crear la libreria dinamica como tipo shared object y agregar la libreria colores
	@sudo mv libcartas.so /usr/lib #mover a la carpeta de librerias
	@sudo ldconfig #refrescar

eliminar:
	@rm prueba
	@rm *.o

prueba:
	@gcc -o prueba prueba.c -lcartas
	@./prueba
