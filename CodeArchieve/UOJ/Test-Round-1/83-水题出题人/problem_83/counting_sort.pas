program counting_sort;

var counter, n, max :longint;
var a :array[1..1000000] of longint;
var b :array[0..10000000] of longint;

procedure counting_sort_main;
var i, j :longint;
begin
	inc(counter);
	readln(n);
	inc(counter);
	max := 0;
	inc(counter);
	for i := 1 to n do begin
		inc(counter);
		readln(a[i]);
		inc(counter);
		if a[i] > max then begin
			inc(counter);
			max := a[i];
		end;
	end;
	inc(counter);
	for i := 0 to max do begin
		inc(counter);
		b[i] := 0;
	end;
	inc(counter);
	for i := 1 to n do begin
		inc(counter);
		inc(b[a[i]]);
	end;
	inc(counter);
	for i := 0 to max do begin
		inc(counter);
		for j := 1 to b[i] do begin
			inc(counter);
			write(i, ' ');
		end;
	end;
end;

begin
	counter := 0;
	counting_sort_main;
	writeln;
	if counter <= 2000000 then begin
		writeln('Accepted! The counter value is :', counter);
	end else begin
		writeln('Time Limit Exceeded because the counter value is :', counter);
	end;
end.
