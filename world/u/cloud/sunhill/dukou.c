// Room: /u/sunhill/dukou.c

inherit ROOM;

void create()
{
        set("short", "���϶ɿ�");
        set("long", @LONG
��������ˮ�ϰ��������ϲ�Զ��������ɽ�ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"southriver",
  "south" : __DIR__"road1",
]));
        set("outdoors", "cloud");

        setup();
}

