// Room: /d/xingxiu/xxroad1.c

inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
�����������ɽ��´�ˣ�ɽ����һƬï�ܵĺ����֣�����
��ǿ�˳�û��
LONG
        );
        set("exits", ([
  "northup" : __DIR__"xxroad3",
  "east" : __DIR__"rcatolz1",
]));

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

