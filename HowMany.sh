NUM=`find . -daystart -mtime 0 -name "*.cxx"|wc -l`
echo "$NUM Problems today"
find . -daystart -mtime 0 -name "*.cxx"
