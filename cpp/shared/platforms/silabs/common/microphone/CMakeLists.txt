
set(NAME yzlite_sl_mic)
add_library(${NAME})
add_library(yzlite::sl_mic ALIAS ${NAME})

target_include_directories(${NAME}
PUBLIC
  .
)
target_sources(${NAME}
PRIVATE
  yzlite_sl_mic_i2s.c
)


target_link_libraries(${NAME}
PRIVATE
  ${YZLITE_PLATFORM}
  yzlite::cpputils
  yzlite::reram_sdk::dmadrv
  yzlite::reram_sdk::includes
)
