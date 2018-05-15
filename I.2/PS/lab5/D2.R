t_conf_interval = function (n, sample_mean, alfa, s)
{
  critical_t = qt (1 - alfa/2, n - 1);
  a = sample_mean - critical_t*(s/sqrt(n));
  b = sample_mean + critical_t*(s/sqrt(n));
  interval = c (a, b);
  print (interval);
}

t_conf_interval (144, 20, 0.1, sqrt(18))
