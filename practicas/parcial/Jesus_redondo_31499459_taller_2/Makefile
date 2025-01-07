fondo = "\e[48;5;0m"
rojo = "\e[38;5;196m"
verde = "\e[38;5;40m"
reset = "\033[0m"
resetf = "\033[0;m"
amarillo = "\e[38;5;226m"

programa: TDA/listas.o
	@echo -n $(fondo)"Ingrese el nombre del programa"$(rojo)" (sin .c): "$(reset)$(fondo)
	@read PROG; \
	if [ -f "$${PROG}.c" ]; then \
		gcc  $${PROG}.c TDA/listas.o -o $${PROG} 2> archivo_temporal; \
		if [ $$? -eq 0 ]; then \
			if [ -s archivo_temporal ]; then \
				echo $(fondo)$(amarillo)"Advertencia $${PROG}.c no compilo correctamente"$(reset)$(fondo); \
				cat archivo_temporal; \
				rm -f archivo_temporal; \
				echo $(reset); \
				exit 1; \
			else \
				echo $(fondo)$(verde)"Programa compilado con éxito"$(reset)$(resetf); \
				rm -f archivo_temporal; \
			fi \
		else \
			echo $(fondo)$(rojo)"Error al compilar $${PROG}.c"$(reset)$(fondo); \
			cat archivo_temporal; \
			rm -f archivo_temporal; \
			echo $(reset); \
			exit 1; \
		fi \
	else \
		echo $(fondo)$(rojo)"Error: el archivo $${PROG}.c no existe"$(reset); \
		exit 1; \
	fi

TDA/listas.o: TDA/listas.c TDA/listas.h
	@gcc -c TDA/listas.c -o TDA/listas.o

#------------------------------------------------------------------------------DOCUMENTACION DE LA LIBRERIA (o slgo asi)----------------------------------------------------------------------------------#
guide: listas pilas colas
	

#listas
listas:
	@cat TDA/guia/listas.txt
	@read -p 'Presione Enter para continuar' var
	@clear
listaS:
	@cat TDA/guia/listas/listaS.txt
	@read -p 'Presione Enter para continuar' var
	@clear
listaD:
	@cat TDA/guia/listas/listaD.txt
	@read -p 'Presione Enter para continuar' var
	@clear
listaSC:
	@cat TDA/guia/listas/listaSC.txt
	@read -p 'Presione Enter para continuar' var
	@clear
listaDC:
	@cat TDA/guia/listas/listaDC.txt
	@read -p 'Presione Enter para continuar' var
	@clear

#pilas
pilas:
	@cat TDA/guia/pilas.txt
	@read -p 'Presione Enter para continuar' var
	@clear
#colas
colas:
	@cat TDA/guia/colas.txt
	@read -p 'Presione Enter para continuar' var
	@clear
#trabajar con strings
string:
	@cat TDA/guia/strings.txt
	@read -p 'Presione Enter para continuar' var
	@clear
#PROG := $(shell read -p "nombre del programa (sin extension '.c'): " prog && echo $$prog)

