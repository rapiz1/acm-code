program bubble_sort;

var counter, n :longint;
var a :array[1..1000000] of longint;

procedure bubble_sort_main;
var i, j, temp :longint;
begin
	inc(counter);
	readln(n);
	inc(counter);
	for i := 1 to n do begin
		inc(counter);
		readln(a[i]);
	end;
	inc(counter);
	for i := n - 1 downto 1 do begin
		inc(counter);
		for j := 1 to i do begin
			inc(counter);
			if a[j] > a[j + 1] then begin
				inc(counter);
				temp := a[j];
				inc(counter);
				a[j] := a[j + 1];
				inc(counter);
				a[j + 1] := temp;
			end;
		end;
	end;
	inc(counter);
	for i := 1 to n do begin
		inc(counter);
		write(a[i], ' ');
	end;
end;

begin
	counter := 0;
	bubble_sort_main;
	writeln;
	if counter <= 2000000 then begin
		writeln('Accepted! The counter value is :', counter);
	end else begin
		writeln('Time Limit Exceeded because the counter value is :', counter);
	end;
end.