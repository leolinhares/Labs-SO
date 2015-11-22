# Labs-SO Workflow

Each lab has its own branch. The idea is to checkout that branch and work on it. When the work is completed, the branch is merged into master. Hence there will be no need for many repositories, one for each lab.

###Get all branches:
git fetch

###Update the current branch:
git pull

###Checkout an existing branch:
git checkout branch-name 

###Create a new branch:
git checkout -b branch-name

###Commit your changes:
git add file-name

git commit -m "commit-message"

###Push changes to the remote server:
git push -u origin HEAD
