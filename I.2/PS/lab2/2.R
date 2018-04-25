Ex2 = function()
{
  tablou = read.csv ("unemploy2012.csv", header = T, sep = ';');
  rate = tablou[['rate']];
  interval = c (0, 4, 6, 8, 10, 12, 14, 30);
  hist (rate, breaks = interval, right = T, freq = F, col = "blue");
}
