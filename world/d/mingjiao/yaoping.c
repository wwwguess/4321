// yaopin.c
inherit ROOM;
void create()
{
        set("short", "ҩƷ��");
        set("long", @LONG
        ������ҩƷ����
LONG
        );
        set("exits", ([
                "south" : __DIR__"zoulang2",
        ]));
       
        setup();
        replace_program(ROOM);
}

