MC_integration = function (N)
{
  sum = 0;
  for (i in 1:N)
  {
    u = runif (1, 0, 3);
    sum = sum + ((u*u*u) / ((u*u*u*u)+1));
  }
  return (3 * sum / N);
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

actual_result = function()
{
  return (1.01168); #enuntul e gresit, wolfram alpha spune 1.10
}

margin_of_error (MC_integration (50000), actual_result());
