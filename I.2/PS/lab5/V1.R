test_proportion = function (alfa, n, succese, p0)
{
  p_prim = succese / n;
  z = (p_prim - p0) / sqrt (p0 * (1 - p0) / n);
  critical_z = qnorm (1 - alfa, 0, 1);
  print (z);
  print (critical_z);
}

test_proportion (0.01, 100, 63, 0.6)
