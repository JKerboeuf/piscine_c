find ./* -type f | cut -c3- > tmp_files
git ls-tree -r HEAD --full-tree | cut -f 2 > tmp_git
diff tmp_files tmp_git
rm tmp_files tmp_git