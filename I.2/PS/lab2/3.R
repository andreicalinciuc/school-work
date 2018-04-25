Ex3 = function()
{
  tablou = read.csv ("life_expect.csv", header = T, sep = ",");
  life_expect_male = tablou[['male']];
  life_expect_female = tablou[['female']];
  hist (life_expect_male, breaks = 7, right = F, freq = F, col = "blue");
  hist (life_expect_female, breaks = 7, right = F, freq = F, col = "red");
}
