# Nombre del directorio a copiar
DIR_NAME = .beccom

# Objetivo predeterminado
all: compile copy set-alias

compile:
	@gcc beccom/beccom.c -o beccom/beccom
	@echo "compilacion exitosa\n"
# Copiar el directorio actual a la ruta home
copy:
#	@echo "Copiando el directorio actual a ~/${DIR_NAME}..."
	@cp -r ./beccom ~/$(DIR_NAME)

# Crear el alias en .bashrc si no existe
#	@echo "Comprobando si el alias 'beccom' ya existe..."
set-alias:
	@if ! grep -q 'alias beccom=' ~/.bashrc; then \
		echo 'alias beccom="~/$(DIR_NAME)/beccom"' >> ~/.bashrc; \
		echo "Programa Instalado. Recuerda ejecutar 'source ~/.bashrc' para aplicar los cambios."; \
	else \
		echo "El programa 'beccom' ya existe."; \
	fi

#@echo "Comprobando si el alias 'beccom' y la carpeta ~/${DIR_NAME} existen..."
uninstall:
	@if grep -q 'alias beccom=' ~/.bashrc; then \
		echo "Eliminando 'beccom'..."; \
		sed -i '/alias beccom=/d' ~/.bashrc; \
	else \
		echo "'beccom' no existe."; \
	fi
	@if [ -d ~/$(DIR_NAME) ]; then \
		echo "Eliminando archivos ~/${DIR_NAME}..."; \
		rm -rf ~/$(DIR_NAME); \
	else \
		echo "La carpeta ${DIR_NAME} no existe."; \
	fi
	@echo "Programa desinstalado. Recuerda ejecutar 'source ~/.bashrc' para aplicar los cambios."

.PHONY: all copy set-alias uninstall

