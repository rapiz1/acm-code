program selection_sort;

var counter, n :longint;
var a :array[1..1000000] of longint;

procedure selection_sort_main;
var i, j, min, minj, temp :longint;
begin
	inc(counter);
	readln(n);
	inc(counter);
	for i := 1 to n do begin
		inc(counter);
		readln(a[i]);
	end;
	inc(counter);
	for i := 1 to n do begin
		inc(counter);
		min := maxlongint;
		inc(counter);
		for j := i to n do begin
			inc(counter);
			if a[j] < min then begin
				inc(counter);
				min := a[j];
				inc(counter);
				minj := j;
			end;
		end;
		inc(counter);
		temp := a[minj];
		inc(counter);
		a[minj] := a[i];
		inc(counter);
		a[i] := temp;
	end;
	inc(counter);
	for i := 1 to n do begin
		inc(counter);
		write(a[i], ' ');
	end;
end;

begin
	counter := 0;
	selection_sort_main;
	writeln;
	if counter <= 2000000 then begin
		writeln('Accepted! The counter value is :', counter);
	end else begin
		writeln('Time Limit Exceeded because the counter value is :', counter);
	end;
end.