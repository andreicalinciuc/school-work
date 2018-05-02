m = matrix ( c (0, 1, 1, 0, 0, 1,
                1, 0, 1, 1, 0, 1,
                1, 1, 0, 1, 1, 0,
                0, 1, 1, 0, 0, 1,
                0, 0, 1, 0, 0, 1,
                1, 1, 0, 1, 1, 0),
             nrow = 6, ncol = 6, byrow = TRUE);

B2 = function (M)
{
  while (nrow (M) > 2)
  {
    repeat
    {
      e = sample (1:nrow (M), 2);
      if (M[e[1], e[2]] > 0) break;
    }
    for (i in 1:ncol (M))
    {
      if( (M[e[2], i] > 0 | M[i, e[2]] > 0) & i != e[1])
      {
        M[e[1], i] = M[e[1], i] + M[e[2], i];
        M[i, e[1]] = M[i, e[1]] + M[i, e[2]];
      }
    }
    M = M[-e[2], ];
    M = M[ ,-e[2]];
  }
  return (M);
}

#B2 (m);
