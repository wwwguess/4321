// room: /d/xingxiu/tianroad1.c
// Jay 3/18/96

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
������ɽ�Ķ�´��ɽ���ɽ�ϴ����������ɪɪ������·����һƬ��ԭ��
·��ͷ������һλ׳�����ڳ�Х������
LONG
        );
        set("exits", ([
            "northdown" : __DIR__"xxh1",
            "south" : __DIR__"tianroad1",
		    "northup" : "/d/lingjiu/shanjiao"
]));
        set("objects", ([
                CLASS_D("xingxiu")+"/shihou" : 1,
                __DIR__"npc/gushou"  : 1,
                __DIR__"npc/haoshou" : 1,
                __DIR__"npc/boshou" : 1,
        ]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        replace_program(ROOM);
}

