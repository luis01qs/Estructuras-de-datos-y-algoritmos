library(ggplot2)

df <- read.table(file ="C:\\Users\\luis0\\Desktop\\Libreria c++\\Estructuras-de-datos-y-algoritmos\\Analisis Numerico\\Tarea\\output\\salida.txt", header=FALSE, sep = "")
b <- df[1, 1]
m <- df[1, 2]
df <- df[-c(1, 2), ]

f <- function(x)
{
    res <- exp(b) * x^m
    return(res)
}

x11()
ggplot(df, aes(exp(V1), exp(V2))) +
  labs(title = "Gráfica de Mínimos Cuadrados",
       x = "Valores de X",
       y = "Valores de f(X)") +
  geom_point(col="blue", size = 2, alpha=0.5) +
  stat_function(fun = function(x) f(x), color = "red")