// /d/xingxiu/silk2.c
// Jay 3/17/96

inherit ROOM;

void create()
{
        set("short", "˿��֮·");
        set("long", @LONG
����һ����ԭ������֮����̵����������������ɽ���������������
������һ���������������ԭ��������ͨ������
LONG
        );
        set("outdoors", "xingxiuhai");

        set("exits", ([
                "east" : __DIR__"silk1",
		"northwest" : __DIR__"rjygtodh0",
        ]));

        setup();
        replace_program(ROOM);
}

