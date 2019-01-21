git filter-branch --commit-filter '
        if [ "$GIT_AUTHOR_EMAIL" = "<Wrong email Address>" ];
        then
                GIT_AUTHOR_NAME="Tarun";
                GIT_AUTHOR_EMAIL="tarun.pumca@gmail.com";
                git commit-tree "$@";
        else
                git commit-tree "$@";
        fi' HEAD