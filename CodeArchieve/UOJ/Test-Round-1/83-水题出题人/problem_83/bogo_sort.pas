program bogo_sort;

{
	请Pascal选手注意，这里使用了自然溢出
	用命令行fpc code.pas方式直接编译在运行时不会报错
	如果用IDE默认的编译选项有可能报错

	For Pascal programmers, please note that we use natural integer overflow here
	If you compile this code with "fpc code.pas" in command line, it won't get a Runtime Error
	If you cmopile with IDE, Runtime Error may occur
}

var counter, n :longint;
var a :array[1..1000000] of longint;

{
	下面实现了一个伪随机数生成器

	Below is a random number generator
}

var seed, RNG_a, RNG_b :longword;

procedure RNG_init;
begin
	inc(counter);
	seed := 2166136261;
	inc(counter);
	RNG_a := 26648577;
	inc(counter);
	RNG_b := 10108929;
end;

function RNG_next :longint;
begin
	inc(counter);
	seed := seed * RNG_a + RNG_b;
	inc(counter);
	exit(seed and $7fffffff);
end;

function check :boolean;
var i: longint;
begin
	inc(counter);
	for i := 2 to n do begin
		inc(counter);
		if a[i - 1] > a[i] then begin
			inc(counter);
			exit(false);
		end;
	end;
	inc(counter);
	exit(true);
end;

procedure bogo_sort_main;
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
	RNG_init;
	inc(counter);
	while not check do begin
		inc(counter);
		for i := 1 to n do begin
			inc(counter);
			seed := (seed * 16777619) xor a[i];
		end;
		inc(counter);
		for i := 1 to n do begin
			inc(counter);
			j := RNG_next mod n + 1;
			inc(counter);
			temp := a[i];
			inc(counter);
			a[i] := a[j];
			inc(counter);
			a[j] := temp;
		end;
		inc(counter);
		RNG_a := (RNG_next shr 5) + 1;
		inc(counter);
		RNG_b := (RNG_next shr 5) + 3;
	end;
	inc(counter);
	for i := 1 to n do begin
		inc(counter);
		write(a[i], ' ');
	end;
end;

begin
	counter := 0;
	bogo_sort_main;
	writeln;
	if counter <= 2000000 then begin
		writeln('Accepted! The counter value is :', counter);
	end else begin
		writeln('Time Limit Exceeded because the counter value is :', counter);
	end;
end.
