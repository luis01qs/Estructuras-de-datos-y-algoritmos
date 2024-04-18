
datos <- read.table(file ="C:\\Users\\luis0\\Desktop\\Libreria c++\\Estructuras-de-datos-y-algoritmos\\Analisis Numerico\\Tarea\\output\\salida.txt", header=FALSE, sep = "")
head(datos)

x = datos[, 1]
y = datos[, 2]
z = datos[, 3]

x11()
plot(0, type = "n", xlim = c(min(x), max(x)), ylim = c(min(min(y), min(z)), max(max(y), max(z))),
     xlab = "X", ylab = "Y and Z", main = "Continuous Graph with Two Lines")
lines(x, y, col = "red")
lines(x, z, col = "blue")
