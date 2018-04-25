Ex10 = function (k)
{
  k = 20; #this can be commented out
  k = k-1; #for correctitude of the plots
  p = 0.4
  lambda = 12;
  x = seq (0, k, 1);
  barplot (dbinom (x, k, p));
  barplot (dpois (x, lambda));
  barplot (dgeom (x, p));
}
