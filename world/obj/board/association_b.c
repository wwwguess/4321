// association_b.c 

#include <ansi.h> 

inherit BULLETIN_BOARD;  

void create() {
        set_name( HIC "��Թ�Ƿ�¼" NOR, ({ "board" }) );
	set("location","/d/social_guild/gee/gee_room");
        set("board_id", "association_b"); 
        set("long", @LONG
	�� �� ֱ ֱ, �� �� �� ˵ �� ��
	�� �� Թ Թ, �� �� �� �� �� ��
LONG
	);
        setup(); 
        set("capacity", 50); 
        replace_program(BULLETIN_BOARD); 
}
