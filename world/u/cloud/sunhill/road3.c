// Room: /u/sunhill/road3.c

inherit ROOM;

void create()
{
        set("short", "��ɽС��");
        set("long", @LONG
��������᫵Ļ���С����
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"road2",
  "eastup" : __DIR__"road4",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

