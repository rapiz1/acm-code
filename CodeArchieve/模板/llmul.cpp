inline long long mul(long long x, long long y, long long m) {
  return ((x * y - (long long)((long double)x * y / m) * m) % m + m) % m;
}
