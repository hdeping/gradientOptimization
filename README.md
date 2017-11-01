# Gradient Optimization

The code is aiming to solve the following problem:

when one is  given a little dataset , how to get the parameters if we use f(x) to fit it? 

The formula of f(x) is below:
$$
\color{blue}
\Huge
\begin{equation}
    f(x) = ae^{-\frac{x}{b}} + c
\end{equation}
$$

I try an example dataset , which is :

|  x   |  y   |
| :--: | :--: |
| 22.0 | 8.0  |
| 30.0 | 10.6 |
| 38.0 | 14.0 |
| 46.0 | 18.2 |



Finally , I get the following result:
$$
\color{blue}
\Huge
\begin{equation}
    f(x) = 5.20\times e^{\frac{x}{33.94}} -1.95
\end{equation}
$$
