#!/bin/bash
# Сборка всех примеров эволюционного расширения
# с повторным использованием ранее написанных файлов.
# Запускать скрипт нужно из его текущего каталога

# Cоздаются исполняемые файлы для всех шагов
for var in "01-start" "02-new-spec" "03-new-func" "04-new-field" \
           "05-rect-only-out" "06-mm" "07-mm-new-spec" "08-more-gen"
do
  echo $var/build:
  cd $var/build/
  cmake ..
  make
  rm -rf ../build/*
  cd ../../
done
