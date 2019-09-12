program merge_sort;

var n, counter :longint;
var a :array[1..1000000] of longint;
var b, c :array[0..1000000] of longint;
var bn, cn :longint;

procedure merge_sort_r(ll, rr :longint);
var lr, rl, i :longint;
begin
	inc(counter);
	if ll < rr then begin
		inc(counter);
		lr := (ll + rr) div 2;
		inc(counter);
		rl := lr + 1;
		inc(counter);
		merge_sort_r(ll, lr);
		inc(counter);
		merge_sort_r(rl, rr);
		inc(counter);
		for i := ll to lr do begin
			inc(counter);
			b[i - ll] := a[i];
		end;
		inc(counter);
		b[lr - ll + 1] := maxlongint;
		inc(counter);
		for i := rl to rr do begin
			inc(counter);
			c[i - rl] := a[i];
		end;
		inc(counter);
		c[rr - rl + 1] := maxlongint;
		inc(counter);
		bn := 0;
		inc(counter);
		cn := 0;
		inc(counter);
		for i := ll to rr do begin
			inc(counter);
			if b[bn] < c[cn] then begin
				inc(counter);
				a[i] := b[bn];
				inc(counter);
				inc(bn);
			end else begin
				inc(counter);
				a[i] := c[cn];
				inc(counter);
				inc(cn);
			end;
		end;
	end;
end;

procedure merge_sort_main;
var i :longint;
begin
	inc(counter);
	readln(n);
	inc(counter);
	for i := 1 to n do begin
		inc(counter);
		readln(a[i]);
	end;
	inc(counter);
	merge_sort_r(1, n);
	inc(counter);
	for i := 1 to n do begin
		inc(counter);
		write(a[i], ' ');
	end;
end;

begin
	counter := 0;
	merge_sort_main;
	writeln;
	if counter <= 2000000 then begin
		writeln('Accepted! The counter value is :', counter);
	end else begin
		writeln('Time Limit Exceeded because the counter value is :', counter);
	end;
end.
