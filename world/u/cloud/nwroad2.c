// Room: /u/cloud/nwroad2.c

inherit ROOM;

void create()
{
        set("short", "���г�");
        set("long", @LONG
���������������г��������Ǽҹײ��̣������ǼҲ�ׯ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : "/u/cloud/woodboxy",
  "north" : "/u/cloud/nwroad1",
  "south" : "/u/cloud/tailory",
  "east" : "/u/cloud/nwroad3",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

