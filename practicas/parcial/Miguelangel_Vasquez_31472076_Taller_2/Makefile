fondo = "\e[48;5;0m"
rojo = "\e[38;5;196m"
verde = "\e[38;5;40m"
reset = "\033[0m"
resetf = "\033[0;m"
amarillo = "\e[38;5;226m"

programa: Lib/libreria.o
	@echo -n $(fondo)"Ingrese el nombre del programa"$(rojo)" (sin .c): "$(reset)$(fondo)
	@read PROG; \
	if [ -f "$${PROG}.c" ]; then \
		gcc  $${PROG}.c Lib/libreria.o -o $${PROG} 2> archivo_temporal; \
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

Lib/libreria.o: Lib/Libreria.c Lib/Libreria.h
	@gcc -c Lib/Libreria.c -o Lib/libreria.o
