Ex1 = function (M)
{
  M = matrix ( c ( 1,    2,   3,   4, #this can and should be commented out
                 0.35, 0.05, 0.15, 0.45), #this can and should be commented out
               nrow = 2, ncol = 4, byrow = TRUE) #this can and should be commented out
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
