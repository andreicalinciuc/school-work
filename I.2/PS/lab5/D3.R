test_proportion = function (alfa, n, succese, p0)
{
  p_prim = succese / n;
  z = (p_prim - p0) / sqrt (p0 * (1 - p0) / n);
  critical_z = qnorm (1 - alfa, 0, 1);
  print (z);
  print (critical_z);
  if (z > 0)
  {
    print ("asimetrica la dreapta");
    if (z > critical_z)
    {
      print ("ipoteza nula respinsa");
    }
    else
    {
      print ("nu exista suficiente dovezi");
    }
  }
  if (z < 0)
  {
    print ("asimetrica la stanga");
    if (z < critical_z)
    {
      print ("ipoteza nula respinsa");
    }
    else
    {
      print ("nu exista suficiente dovezi");
    }
  }
}

test_proportion (0.01, 112, 14, 0.1)
test_proportion (0.05, 112, 14, 0.1)
