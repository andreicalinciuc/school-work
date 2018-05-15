selection_mean = function (filename)
{
  x = scan (filename);
  m = mean (x);
  print (m);
}

selection_mean ("history.txt")
