// Room: /u/cloud/nwroad3.c

inherit ROOM;

void create()
{
        set("short", "���г�");
        set("long", @LONG
���������������г��������ǲ�¥���������ӻ��̡�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : "/u/cloud/nwroad2",
  "north" : "/u/cloud/tearoom",
  "south" : "/u/cloud/zaihuoy",
  "east" : "/u/cloud/nroad1",
]));
        set("outdoors", "cloud");

        set("objects", ([
                "/obj/npc/garrison" : 2,
        ]) );

        setup();
        replace_program(ROOM);
}

