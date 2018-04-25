Ex6 = function ()
{
  maxi = -1;
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
      sol = i;
    }
  }
  print (sol);
  print (maxi);
}
