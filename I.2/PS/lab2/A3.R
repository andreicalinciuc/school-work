A3 = function ()
{
  sample = scan ("studenti.txt");
  m1 = mean (sample);
  m2 = median (sample);
  s = sd (sample);
  q = quantile (sample);
  Q1 = as.vector(q)[2];
  Q2 = as.vector(q)[3];
  Q3 = as.vector(q)[4];
  Q4 = as.vector(q)[5];
  print (m1);
  print (m2);
  print (s);
  print (Q1);
  print (Q2);
  print (Q3);
  print (Q4);
  source ('7.R');
  outliers_mean (sample);
  source ('8.R');
  outliers_iqr (sample);
}
