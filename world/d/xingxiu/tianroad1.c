// room: /d/xingxiu/tianroad1.c
// Jay 3/18/96

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
������һ��ɽ·��ɽ���ɽ�ϴ����������ɪɪ������·����һƬ
��ԭ����ԭ��һλ�����˸���һȺ�������򶫿�����ɽ�����ߴ�����
�����޵�Х����
LONG
        );
        set("exits", ([
            "eastdown" : "/d/road/xingsuhai",
            "north" : __DIR__"tianroad2",
            "westup" : __DIR__"tianroad3",
]));
        set("objects", ([
                __DIR__"npc/herdsman" : 1,
        ]));

        setup();
        replace_program(ROOM);
}

