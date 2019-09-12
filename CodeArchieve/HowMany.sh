NUM=`find . -daystart -mtime 0 -name "*.cpp"|wc -l`
echo "$NUM Problems today"
find . -daystart -mtime 0 -name "*.cpp"
