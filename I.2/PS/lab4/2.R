ellipse_area = function (N)
{
  N_C = 0;
  for (i in 1:N)
  {
    x = runif(1, -2, 2);
    y = runif(1, -1, 1);
    if (x*x + 4*y*y <= 4)
      N_C = N_C + 1;
  }
  return (8 * N_C / N);
}

margin_of_error = function (MC_value, actual_value)
{
  abs_error = abs (MC_value - actual_value);
  rel_error = abs (abs_error / actual_value);
  percent_error = rel_error * 100;
  print (MC_value);
  print (actual_value);
  print (abs_error);
  print (rel_error);
  print (percent_error);
}

pi = 3.1415;
actual_area = 2 * pi;

margin_of_error (ellipse_area (50000), actual_area);
