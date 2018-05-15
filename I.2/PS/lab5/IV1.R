t_conf_interval = function (n, sample_mean, alfa, s)
{
  critical_t = qt (1 - alfa/2, n - 1);
  a = sample_mean - critical_t*(s/sqrt(n));
  b = sample_mean + critical_t*(s/sqrt(n));
  interval = c (a, b);
  print (interval);
}

t_conf_interval (60, 3.3, 0.05, 0.4)
