#!/bin/bash

# Función para mostrar mensajes con formato
mostrar_mensaje() {
    echo "----------------------------------------"
    echo "$1"
    echo "----------------------------------------"
}

# Función para verificar si un comando se ejecutó correctamente
verificar_error() {
    if [ $? -ne 0 ]; then
        mostrar_mensaje "ERROR: $1"
        exit 1
    fi
}

# Actualizar el sistema e instalar drivers
mostrar_mensaje "Actualizando el sistema e instalando drivers gráficos..."
sudo apt update
verificar_error "No se pudo actualizar el sistema"

sudo apt install -y mesa-vulkan-drivers vulkan-tools
verificar_error "No se pudieron instalar los drivers"

# Actualizar Flatpak
mostrar_mensaje "Actualizando Flatpak..."
flatpak update -y
verificar_error "No se pudo actualizar Flatpak"

# Mostrar mensaje final
mostrar_mensaje "Instalación completada con éxito"
echo "Por favor, realice las siguientes acciones:"
echo "1. Reinicie el sistema"
echo "2. Después del reinicio, intente ejecutar Sober"
echo "3. Si Sober no funciona, verifique los logs o use Flatseal para revisar permisos"

# Preguntar si desea reiniciar ahora
read -p "¿Desea reiniciar el sistema ahora? (s/n): " respuesta
if [[ $respuesta =~ ^[Ss]$ ]]; then
    mostrar_mensaje "Reiniciando el sistema..."
    sudo reboot
else
    mostrar_mensaje "No olvide reiniciar el sistema más tarde"
fi

