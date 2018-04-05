Ex7 = function ()
{
  y = read.table ("test.txt", header = TRUE);
  x1 = y [["AA"]];
  x2 = y [["BB"]];
  plot (x1, x2);
}