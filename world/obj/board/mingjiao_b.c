// /clone/board/wudang_b.c

#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
        set_name(YEL "����" NOR + CYN "���԰�" NOR, ({ "board" }) );
        set("location", "/d/mingjiao/dadian");
        set("board_id", "mingjiao_b");
        set("long", "����һ�����������½��������԰ࡣ\n" );
        setup();
        set("capacity", 30);
        replace_program(BULLETIN_BOARD);
}
