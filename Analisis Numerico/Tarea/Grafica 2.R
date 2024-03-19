# Install and load necessary packages
library(ggplot2)

# Define the x values
x <- seq(-10, 10, length.out = 100)  # You can adjust the length.out for smoother or coarser curves

# Define the functions
f1 <- function(x) sin(x) # Example function 1: x squared
f2 <- function(x) 0.87961*x  # Example function 2: sine function

# Create data frames for each function
data1 <- data.frame(x = x, y = f1(x))
data2 <- data.frame(x = x, y = f2(x))

# Plot the functions using ggplot2
x11()
ggplot() +
  geom_line(data = data1, aes(x = x, y = y), color = "blue", size = 1) +  # Plot function 1
  geom_line(data = data2, aes(x = x, y = y), color = "red", size = 1) +   # Plot function 2
 # xlim(-1, 1) +  # Set x-axis limits
  ylim(min(f1(x), f2(x)), max(f1(x), f2(x))) +  # Set y-axis limits to encompass both functions
  labs(x = "x", y = "y", title = "Graph of Two Functions") +  # Label axes and add title
  theme_minimal()  # Use a minimal theme
