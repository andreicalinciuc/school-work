zconfidence_interval = function (n, sample_mean, alfa, sigmap)
{
  critical_z = qnorm (1 - alfa/2, mean = 0, sd = 1);
  a = sample_mean - critical_z*(sqrt(sigmap)/sqrt(n));
  b = sample_mean + critical_z*(sqrt(sigmap)/sqrt(n));
  interval = c (a, b);
  print (interval);
}

zconfidence_interval (100, 20, 0.1, 9)
