// Room: /u/sunhill/road2.c

inherit ROOM;

void create()
{
        set("short", "��ɽС��");
        set("long", @LONG
��������᫵Ļ���С����
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"road1",
  "westup" : __DIR__"road3",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

