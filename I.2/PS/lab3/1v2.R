Ex1 = function (k)
{
  x = 1:k;
  y = runif (k, 0, 1);
  s = sum(y);
  rap = 1 / s;
  y = y * rap;
  m = matrix (c (x, y), nrow = 2, ncol = k, byrow = T);
  print (m);
}

#Ex1 (5);
