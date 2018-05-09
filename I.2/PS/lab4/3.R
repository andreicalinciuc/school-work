parabola_area = function (N)
{
  N_C = 0;
  for (i in 1:N)
  {
    x = runif (1, -1, 3);
    y = runif (1, 0, 4);
    if (y <= -(x*x) + 2*x + 3)
      N_C = N_C + 1;
  }
  return (16 * N_C / N);
}

margin_of_error = function (MC_value, actual_value)
{
  abs_error = abs (MC_value - actual_value);
  rel_error = abs (abs_error / actual_value);
  print (MC_value);
  print (actual_value);
  print (rel_error);
}

integrate = function (x)
{
  return (-(x*x*x)/3 + x*x + 3*x); //integrated equation on paper first
}

actual_area = function()
{
  return (integrate (3) - integrate (-1));
}

margin_of_error (parabola_area (50000), actual_area());
