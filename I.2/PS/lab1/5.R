Ex5 = function (n, p)
{
  x = seq (0, n, 1);
  y = dbinom (x, n, p);
  z = max (y);
  print (z);
}