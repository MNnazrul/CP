{
"cmd" : ["g++ -std=c++20 $file_name -o $file_base_name && timeout 5s ./$file_base_name<input.txt>output.txt"],
"selector" : "source.cpp",
"shell": true,
//"working_dir" : "$file_path"
}
// windows. : 
{
  "shell_cmd" : "powershell -ExecutionPolicy Bypass \"& 'C://Users/najib/Script.ps1' -file '$file' -PATH '$file_path'\"", 
  "selector" : "source.c,source.cpp,source.c++",
  "shell": true,
  "working_dir" : "$file_path"
}