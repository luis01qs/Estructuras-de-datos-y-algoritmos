
datos <- read.table(file ="C:\\Users\\luis0\\Desktop\\Libreria c++\\Estructuras-de-datos-y-algoritmos\\Analisis Numerico\\Tarea\\output\\salida.txt", header=FALSE, sep = "")
x11()
plot(datos[, 1], datos[, 2], col = "red", lwd = 2)
datos