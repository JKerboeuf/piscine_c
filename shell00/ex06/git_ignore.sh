#!/bin/bash/

git status -s --ignored | grep '!!' | cut -d ' ' -f 2 | rev | cut -d '/' -f 1 | rev 
