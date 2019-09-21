namespace IO {
  const int L = 1 << 15;
  char buf[L], *s, *t;
  inline char gc() {
    if (s == t) t = (s=buf) + fread(buf, 1, L, stdin);
    if (s == t) {
      exit(0);
    }
    return *s++;
  }
  inline int gi() {
    int f = 1, ch = gc(), r = 0;
    while (!isdigit(ch)) {
      if (ch == '-') f = -1;
      ch = gc();
    }
    while (isdigit(ch)) r = r*10 + ch - '0', ch = gc();
    return r*f;
  }
}
using IO::gi;
