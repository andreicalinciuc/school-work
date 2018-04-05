Ex6 = function (n, lambda)
{
  x = seq (0, n, 1);
  y = dpois (x, lambda);
  print (y);
}