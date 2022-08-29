library(knitr)
library(stringr)
library(fs)

get_build_directory <- function(){
  build_dir <- fs::path_abs("./../../build")
  return(build_dir)
}

get_cmd_output <- function(text){
  text <- text[-1:-5]
  fixed_text <- str_replace(
    text, 
    "^[C/]:?([-_.A-Za-z0-9/ ]|\\\\)+build>",
    "terminal$ "
  )
  n <- length(fixed_text)
  fixed_text <- fixed_text[-c(n, n - 1)]
  return(fixed_text)
}

cmd_knit_engine <- function(options){
  code <- options$code
  build_dir <- get_build_directory()
  change_dir_cmd <- paste("cd", build_dir)
  out <- system2(
    "cmd",
    input = c(change_dir_cmd, code),
    stdout = TRUE, stderr = TRUE
  )
  out <- get_cmd_output(out)
  knitr::engine_output(options, code, out)
}

knitr::knit_engines$set(cmd_passgen = cmd_knit_engine)