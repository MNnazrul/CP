set number           " Show line numbers
set relativenumber   " Relative line numbers
set autoindent       " Auto-indent new lines
set tabstop=4        " Tab width
set shiftwidth=4     " Auto-indent width
set expandtab        " Use spaces instead of tabs
set cursorline       " Highlight the current line
set clipboard=unnamedplus " System clipboard access
set nocursorline

" enable smart indentation
" set autoindent
" set smartindent
" set cindent


syntax on            " Enable syntax highlighting
filetype plugin on   " Enable filetype-specific plugins

call plug#begin('~/.vim/plugged')

Plug 'scrooloose/nerdtree'             " File explorer
Plug 'vim-airline/vim-airline'         " Status bar
Plug 'vim-airline/vim-airline-themes'  " Status bar themes
Plug 'ervandew/supertab'               " Autocomplete
Plug 'sirver/ultisnips'                " Snippet manager
Plug 'honza/vim-snippets'              " Predefined snippets
Plug 'neoclide/coc.nvim', {'branch': 'release'} " Intellisense

call plug#end()

function! OpenInputFile()
    " Check if input.txt exists; create it if not
    if !filereadable("input.txt")
        call writefile([], "input.txt")
    endif
    " Open input.txt in a vertical split
    vsplit input.txt
    wincmd H
    " Focus back to the main file
    wincmd p
endfunction

" Automatically open input.txt in a split when opening a .cpp file
"autocmd BufRead,BufNewFile *.cpp call OpenInputFile()


nnoremap <F5> :w<CR>:!gnome-terminal -- bash -c "g++ % -o %:r && ./%:r < input.txt; exec bash" &<CR>:redraw!<CR>
nnoremap <F6> :w<CR>:!gnome-terminal -- bash -c "g++ % -o %:r && ./%:r; exec bash" &<CR>:redraw!<CR>


" Enable auto-pairing for parentheses, braces, and brackets
""inoremap ( ()<Left>
""inoremap [ []<Left>
""inoremap { {}<Left>
"inoremap " ""<Left>
"inoremap ' ''<Left>

" Automatically indent after entering closing brace
"inoremap { {}<Esc>O



