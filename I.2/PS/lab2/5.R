Ex5 = function()
{
  tablou = read.csv ("life_expect.csv", header = T, sep = ",");
  life_expect_male = tablou[['male']];
  life_expect_female = tablou[['female']];
  print (mean (life_expect_male));
  print (median (life_expect_male));
  print (mean (life_expect_female));
  print (median (life_expect_female));
}
