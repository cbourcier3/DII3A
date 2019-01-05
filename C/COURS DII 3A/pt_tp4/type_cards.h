enum c_val
{
    SEPT,
    HUIT,
    NEUF,
    DIX,
    VALET,
    REINE,
    ROI,
    AS,
    MAX_VAL
};
enum c_color
{
    PIC,
    COEUR,
    CARREAU,
    TREFLE,
    MAX_COLOR
};

typedef struct s_card
{
    enum c_val value;
    enum c_color color;
    struct s_card *next;
} t_card;
