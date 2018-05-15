normal_density = function (limit, miu, sigmap)
{
  t = seq (-limit, limit, length = 400);
  f = (1/(sqrt(sigmap)*sqrt(2*pi)))*exp(-((t-miu)^2/(2*sigmap)));
  plot (t, f, type = "l", lwd = 1);
}

normal_density (6, 0, 1)
