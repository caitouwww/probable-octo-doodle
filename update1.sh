git add .
echo "enter your description:(one_line)"
read description
git commit -m $description
git push origin master
