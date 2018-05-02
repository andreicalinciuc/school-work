m = matrix ( c ( 1,    2,   3,   4,
               0.35, 0.05, 0.15, 0.45),
               nrow = 2, ncol = 4, byrow = TRUE)

Ex1 = function (M)
{
  u = runif (1, 0, 1);
  i = 0;
  aux = 0;
  while ( !(aux <= u & u <= aux + M[2, i+1]) & i < ncol (M) )
  {
    i = i+1;
    aux = aux + M[2, i];
  }
  return (M[1, i+1]);
}

#Ex1 (m)
