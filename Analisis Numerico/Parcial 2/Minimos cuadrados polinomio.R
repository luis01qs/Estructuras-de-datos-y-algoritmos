library(pracma)

df <- read.table(file ="C:\\Users\\luis0\\Desktop\\Libreria c++\\Estructuras-de-datos-y-algoritmos\\Analisis Numerico\\Parcial 2\\output\\prueba.txt", header=FALSE, sep = "")
head(df)

mat <- as.matrix((df))
mat <- log(mat)

a <- mat[, 1]
a <- cbind(a**0, a, a * a)
b <- mat[, 2]
aa <- t(a) %*% a
bb <- t(a) %*% b

m <- cbind(aa, bb)
r <- rref(m)
r

coeficientes <- r[, ncol(r)]
coeficientes

f <- function(x)
{
    res <- exp(coeficientes[1])*(x**coeficientes[2])*(exp(coeficientes[3]*(log(x))**2))
    return (res)
}

x11()
ggplot(df, aes(V1, V2)) +
  labs(title = "Gráfica de Mínimos Cuadrados",
       x = "Valores de X",
       y = "Valores de f(X)") +
  geom_point(col="blue", size = 2, alpha=0.5) +
  stat_function(fun = function(x) f(x), color = "red")

error <- 0
for(i in 1:(dim(df)[1]))
{
    error <- error + (f(df$V1[i]) - df$V2[i])**2
}
error
