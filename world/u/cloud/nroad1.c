// Room: /u/cloud/nroad1.c

inherit ROOM;

void create()
{
        set("short", "���г�");
        set("long", @LONG
�����������Ķ��г���������ҩ�꣬�����Ǳ����ꡣ
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : "/u/cloud/nwroad3",
  "north" : "/u/cloud/drugstore",
  "south" : "/u/cloud/nroad2",
  "east" : "/u/cloud/weapony",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

