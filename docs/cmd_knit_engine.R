library(knitr)
library(fs)

get_build_directory <- function(){
  build_dir <- fs::path_abs("./../../build")
  return(build_dir)
}

cmd_knit_engine <- function(options){
  code <- options$code
  build_dir <- get_build_directory()
  change_dir_cmd <- paste("cd", build_dir)
  out <- system2("cmd", input = c(change_dir_cmd, code), stdout = TRUE)
  knitr::engine_output(options, code, out)
}

knitr::knit_engines$set(cmd_passgen = cmd_knit_engine)

#system2("cmd", input = c("passgen -p 5"), stdout = TRUE)
