outliers_mean = function (sample)
{
  sample = c (1, 91, 38, 72, 13, 27, 11, 85, 5, 22, 20, 19, 8, 17, 11, 15, 13, 23, 14, 17); #this can be commented out
  m = mean (sample);
  s = sd (sample);
  outliers = vector();
  j = 0;
  for (i in 1 : length (sample))
  {
    if (sample[i] < m - 2*s | sample[i] > m + 2*s)
    {
      j = j + 1;
      outliers[j] = sample[i];
    }
  }
  print (outliers);
}
