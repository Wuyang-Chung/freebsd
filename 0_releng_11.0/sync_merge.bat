cd ..
pwd
echo "$ git fetch upstream"
git fetch upstream
echo
echo "$ git merge upstream/releng/11.0"
git merge upstream/releng/11.0
echo
echo "*** NOTE *** Use GitSmart to sync commits to origin"

