// Room: /u/cloud/eroad3.c

inherit ROOM;

void create()
{
        set("short", "�����ֵ�");
        set("long", @LONG
�����������ͷ���������żң����Ϸ����ǲ賡��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : "/u/cloud/rich",
  "southwest" : "/u/cloud/eroad2",
  "southeast" : "/u/cloud/eroad4",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

