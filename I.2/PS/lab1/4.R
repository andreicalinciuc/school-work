Ex4 = function (n, p)
{
  x = seq (0, n, 1);
  y = dbinom (x, n, p);
  barplot (y, space = 0, main = "Distributie Binomiala", sub = "Exercitiul 4", xlab = "Axa X", ylab = "Axa Y");
}