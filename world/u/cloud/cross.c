// Room: /u/cloud/square.c

inherit ROOM;

void create()
{
        set("short", "ʮ��·��");
        set("long", @LONG
������������ʯ·�����ｻ�棬·�����ſùŻ������������Ӻ�
����ô�֡��������и���ʾ�����ǹٸ����ġ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : "/u/cloud/wroad2",
  "north" : "/u/cloud/nroad2",
  "south" : "u/cloud/sroad1",
  "east" : "/u/cloud/eroad1",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

