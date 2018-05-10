ellipsoid_volume = function (N)
{
  N_C = 0;
  for (i in 1:N)
  {
    x = runif (1, -2, 2);
    y = runif (1, -3, 3);
    z = runif (1, -4, 4);
    if ((x * x / 4) + (y * y / 9) + (z * z / 16) <= 1)
      N_C = N_C + 1;
  }
  return (4 * 6 * 8 * N_C / N);
}

margin_of_error = function (MC_value, actual_value)
{
  abs_error = abs (MC_value - actual_value);
  rel_error = abs (abs_error / actual_value);
  print (MC_value);
  print (actual_value);
  print (abs_error);
  print (rel_error);
}

pi = 3.1415;
actual_volume = 4 * pi / 3 * 2 * 3 * 4;

margin_of_error (ellipsoid_volume (50000), actual_volume);
