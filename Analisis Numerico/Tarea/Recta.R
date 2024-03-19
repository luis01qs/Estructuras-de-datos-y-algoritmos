library(ggplot2)

df <- read.table(file ="C:\\Users\\luis0\\Desktop\\Libreria c++\\Estructuras-de-datos-y-algoritmos\\Analisis Numerico\\Tarea\\output\\salida.txt", header=FALSE, sep = "")
b = df[1, 1]
m = df[1, 2]
df <- df[-c(1, 2), ]
x11()
ggplot(df, aes(V1, V2)) +
  labs(title = "Gráfica de Mínimos Cuadrados",
       x = "Valores de X",
       y = "Valores de f(X)") +
  geom_point(col="blue", size = 2, alpha=0.5) +
  geom_abline(intercept = b, slope = m, color = "red")