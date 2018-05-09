generate = function()
{
  x = rpois (1, 3);
  y = rpois (1, 5);
  return (x > y);
}

MC_generate = function (N)
{
  apx = 0;
  for (i in 1:N)
  {
    if (generate() > 0)
    {
      apx = apx + 1;
    }
  }
  return (apx / N);
}

N_min = function()
{
  alfa = 1 - 0.95;
  z = qnorm (alfa / 2);
  epsilon = 0.01;
  p = 0.185; #presumed beforehand
  return (p * (1 - p) * ((z / epsilon) ^ 2));
}

print (MC_generate(N_min() + 1));
