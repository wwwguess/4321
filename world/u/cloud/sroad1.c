// Room: /u/cloud/sroad1.c

inherit ROOM;

void create()
{
        set("short", "�����ֵ�");
        set("long", @LONG
������������ϣ�ͨ�������Ķɿڡ�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : "/u/cloud/cross",
  "south" : "/u/cloud/dukou",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

