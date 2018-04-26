Ex6 = function ()
{
  maxi = -1;
  n = 0;
  sol = vector();
  v = scan ("sample1.txt");
  sort(v);
  max = v[length(v)];
  viz = vector(,max);
  for (i in 1 : length (v))
  {
    viz[v[i]] = viz[v[i]] + 1;
  }
  for (i in 1 : max)
  {
    if (viz[i] > maxi)
    {
      maxi = viz[i];

    }
  }
  for (i in 1 : max)
  {
    if (viz[i] == maxi)
    {
      n = n + 1;
      sol[n] = i;
    } 
  }
  print (maxi);
  print (n);
  print (sol);
}
