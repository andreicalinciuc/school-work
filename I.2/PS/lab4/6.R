MC_improved_integration = function (N)
{
  sum = 0;
  for (i in 1:N)
  {
    u = rexp (1, 1);
    sum = sum + exp (-(u * u) / 2) / exp (-u);
  }
  return (sum / N);
}

MC_improved_integration_average = function (k, N)
{
  estimates = vector();
  for (i in 1:k)
  {
    estimates[i] = MC_improved_integration (N);
  }
  print (mean (estimates));
  print (sd (estimates));
  return (mean (estimates));
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
  return (sqrt (pi / 2));
}

margin_of_error (MC_improved_integration_average (30, 40000), actual_result());
