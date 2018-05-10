simulate = function()
{
  infected = vector(, 20);
  first = sample(1:20, 1);
  infected[first] = 1;
  count = 1;
  nr_days = 1;
  while (count != 0)
  {
    if (count > 0)
    {
      for (j in 1:count)
      {
        for (i in 1:20)
        {
          if (infected[i] == 0)
          {
            u = runif (1, 0, 1);
            if (u <= 0.1)
            {
              infected[i] = 1;
              count = count + 1;
            }
          }
        }
      }
    }
    if (count >= 8) return (1);
    if (count > 0)
    {
      u = sample (1:20, 1);
      while (infected[u] == 0) u = sample (1:20, 1);
      infected[u] = 0; count = count - 1;
    }
    if (count > 0)
    {
      u = sample (1:20, 1);
      while (infected[u] == 0) u = sample (1:20, 1);
      infected[u] = 0; count = count - 1;
    }
    nr_days = nr_days + 1;
  }
  return (0);
}

MC_simulate = function (N)
{
  occ = 0;
  for (i in 1:N)
  {
    if (simulate() > 0)
    {
      occ = occ + 1;
    }
  }
  return (occ / N);
}

N_min = function()
{
  alfa = 1 - 0.95;
  z = qnorm (alfa / 2);
  epsilon = 0.01;
  p = 0.38; #presumed beforehand
  return (p * (1 - p) * ((z / epsilon) ^ 2));
}

print (N_min());
print (MC_simulate (N_min() + 1));
