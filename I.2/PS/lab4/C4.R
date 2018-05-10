MC_web = function (N)
{
  s = 0;
  for (i in 1:N)
  {
    x = rexp (1,1);
    g1 = rgamma (1, shape = 5, scale = 3);
    g2 = rgamma (1, shape = 7, scale = 5);
    g3 = rgamma (1, shape = 5, scale = 2);
    u = runif (1,0,1);
    if (u < 0.5)
    {
      s = s + g1;
    }
    if (u >= 0.5 && u < 0.8)
    {
      s = s + g2;
    }
    if (u >= 0.8)
    { 
      s = s + g3;
    }
    s = s + x;
  }
  return (s / N);
}

print (MC_web (10000));
