Ex1 = function (file)
{
  b = scan (file);
  max = b[1];
  min = b[1];
  sum = 0;
  l40 = 0;
  l35 = 0;
  for (i in 1 : length (b))
  {
    if (b[i] > max) max = b[i];
    if (b[i] < min) min = b[i];
    sum = sum + b[i];
    if (b[i] > 40) l40 = l40 + 1;
    if (b[i] < 35) l35 = l35 + 1;
  }
  print (max);
  print (min);
  print (sum);
  print (l40);
  print (l35 / length (b) * 100);
}