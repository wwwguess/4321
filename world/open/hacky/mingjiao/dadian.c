#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "���̴��");
        set("long", "�����ǹ������������̻�͵ĵص㡣\n");
        set("valid_startroom", 1);
        set("exits", ([
                "south" : __DIR__"zoulang",
                "north" : __DIR__"houhuayuan1",
 ]));
        set("objects", ([
                CLASS_D("mingjiao") + "/zhang" : 1,
 ]));
        setup();
        "/obj/board/mingjiao_b"->foo();
	replace_program(ROOM);

}


