// Room: /u/sunhill/southriver.c

inherit ROOM;

void create()
{
        set("short", "��ˮ�ϲ�");
        set("long", @LONG
���￿���ϰ�����ˮ���Ǻ��䡣�������������ɽ���µ�һ�ǡ�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"midriver",
  "south" : __DIR__"dukou",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

