// Room: /u/cloud/nroad2.c

inherit ROOM;

void create()
{
        set("short", "���г�");
        set("long", @LONG
���������������г����������ӻ��̣��򶫿ɿ��� ����Ժ �Ķ�¥��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : "/u/cloud/zaihuoy",
  "north" : "/u/cloud/nroad1",
  "south" : "/u/cloud/cross",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

