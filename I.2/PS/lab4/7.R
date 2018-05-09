Nr_days = function() {
  nr_days = 1;
  last_errors = c (11, 16, 18);
  nr_errors = 11;
  while (nr_errors > 0)
  {
    lambda = mean (last_errors); #dureaza foarte mult
    nr_errors = rpois (1, lambda);
    last_errors = c (nr_errors, last_errors[1], last_errors[2]) ;
    nr_days = nr_days + 1;
  }
  return (nr_days);
}

MC_Nr_days = function (N)
{
  s = 0;
  for (i in 1:N)
  {
    s = s + Nr_days();
  }
  return (s / N);
}

print (MC_Nr_days (10000)); #aprox 860 zile
