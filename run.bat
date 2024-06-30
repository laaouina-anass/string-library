@echo off



REM Initialize the Git repository if it hasn't been initialized already
git init

REM Create the .gitignore file and add run.bat to it
REM also main.exe

echo run.bat > .gitignore
echo main.exe > .gitignore

REM Stage all files
git add .

REM Commit the files
git commit -m "Initial commit"

REM Add the remote repository (replace the URL with your repository URL)
git remote add origin https://github.com/laaouina-anass/string-library

REM Push the files to the master branch of the remote repository
git push -u origin master

REM Remove the problematic files (replace file1 and file2 with actual filenames)
git rm string.cpp
git rm string.h

REM Push the changes to the remote repository
git push

pause
