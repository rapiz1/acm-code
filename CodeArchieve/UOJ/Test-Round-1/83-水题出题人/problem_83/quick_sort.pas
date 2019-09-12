program quick_sort;

var n, counter :longint;
var a :array[1..1000000] of longint;

procedure quick_sort_r(l, r :longint);
var i, j, x, y :longint;
begin
	inc(counter);
	i := l;
	inc(counter);
	j := r;
	inc(counter);
	x := a[(l + r) div 2];
	inc(counter);
	repeat
		inc(counter);
		while a[i] < x do begin
			inc(counter);
			inc(i);
		end;
		while x < a[j] do begin
			inc(counter);
			dec(j);
		end;
		inc(counter);
		if i <= j then begin
			inc(counter);
			y := a[i];
			inc(counter);
			a[i] := a[j];
			inc(counter);
			a[j] := y;
			inc(counter);
			inc(i);
			inc(counter);
			dec(j);
		end;
	until i > j;
	inc(counter);
	if l < j then begin
		inc(counter);
		quick_sort_r(l, j);
	end;
	inc(counter);
	if i < r then begin
		inc(counter);
		quick_sort_r(i, r);
	end;
end;

procedure quick_sort_main;
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
	quick_sort_r(1, n);
	inc(counter);
	for i := 1 to n do begin
		inc(counter);
		write(a[i], ' ');
	end;
end;

begin
	counter := 0;
	quick_sort_main;
	writeln;
	if counter <= 2000000 then begin
		writeln('Accepted! The counter value is :', counter);
	end else begin
		writeln('Time Limit Exceeded because the counter value is :', counter);
	end;
end.