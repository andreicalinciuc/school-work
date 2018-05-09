Nr_hours = function()
{
  u = runif (1, 0, 1);
  x = rexp (1, 20);
  y = rexp (1, 5);
  if (u >= 0.8)
  {
    return (x);
  }
  else
  {
    return (y);
  }
}

MC_Nr_hours = function (N)
{
  s = 0;
  for (i in 1:N)
  {
    s = s + Nr_hours();
  }
  return (s / N);
}

print (MC_Nr_hours (10000));
