idf_component_register(
    SRCS "app.c"
    INCLUDE_DIRS "."
    REQUIRES led buttons display u8g2 u8g2-hal-esp-idf
)
