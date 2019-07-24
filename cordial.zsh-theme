function collapse_pwd {
  echo $(pwd | sed -e "s,^$HOME,~,")
}

local ret_status="%(?:%{$fg_bold[green]%}»:%{$fg_bold[red]%}»%s)"
PROMPT='%{$fg_bold[cyan]%}%p$(collapse_pwd) %{$fg_bold[blue]%}$(git_prompt_info)${ret_status}%{$reset_color%} '

ZSH_THEME_GIT_PROMPT_PREFIX="%{$fg_bold[blue]%}("
ZSH_THEME_GIT_PROMPT_SUFFIX="%{$fg_bold[blue]%})%{$reset_color%} "
ZSH_THEME_GIT_PROMPT_DIRTY="%{$fg[red]%}✗"
ZSH_THEME_GIT_PROMPT_CLEAN="%{$fg[green]%}✓"

