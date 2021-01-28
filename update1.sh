git add .
echo "enter your description:"
read description
git commit -m $description
git push origin master
