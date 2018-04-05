Ex2 = function (file)
{
  x = scan (file);
  v1 = vector();
  v2 = vector();
  for (i in 1 : length (x))
  {
    v1[i] = log (x[i]);
    v2[i] = (x[i] - max (x)) / min (x);
  }
  print (v1);
  print (v2);
}