sphere_volume = function (N)
{
  N_C = 0;
  for (i in 1:N)
  {
    x = runif(1, -1, 1);
    y = runif(1, -1, 1);
    z = runif(1, -1, 1);
    if (x*x + y*y + z*z <= 1)
      N_C = N_C + 1;
  }
  return (8 * N_C / N);
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
actual_volume = 4 * pi / 3;

margin_of_error (sphere_volume (50000), actual_volume);
