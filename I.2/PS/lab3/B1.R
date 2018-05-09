v = c (1, 5, 2, 3, 4);

qs = function (S)
{
  if (length(S) <= 1) return (S);
  x = sample (1:length (S), 1);
  pivot = S[x];
  return (c (qs (S[S < pivot]), pivot, qs (S[S > pivot])));
}

#qs (v);
